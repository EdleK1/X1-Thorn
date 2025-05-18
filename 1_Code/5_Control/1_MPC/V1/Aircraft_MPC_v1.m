clear all
close all

addpath('C:\Users\marcv\acados\external\casadi-matlab\')
addpath('C:\Users\marcv\acados\interfaces\acados_matlab_octave\')
addpath('C:\Users\marcv\acados\interfaces\acados_template\acados_template\')

check_acados_requirements
simulink_opts = get_acados_simulink_opts;

%% Initial Conditions

x0 = [0; 0; 0; % U; V; W;
      0; 0; 0; % p; q; r;
      cos(-pi/4); 0; sin(-pi/4); 0; % q0; q1; q2; q3;
      12500; 12500; 1600; 1600]; % omega1; omega2; alfa1; alfa2

%% Define OCP

ocp = AcadosOcp();

%% Model

model = get_aircraft_model();
ocp.model = model;

%% Dimensions:

nx = model.x.rows();
nu = model.u.rows();

%% Solver Options

N = 100;         % shooting nodes
ts = 25e-3;     % Sampling Rate
tf = N*ts;      % Prediction Horizon


ocp.solver_options.integrator_type = 'ERK';
ocp.solver_options.sim_method_num_stages = 4;
ocp.solver_options.sim_method_num_steps = 1;

ocp.solver_options.tf = tf;
ocp.solver_options.N_horizon = N;

ocp.solver_options.globalization = 'FIXED_STEP';
ocp.solver_options.nlp_solver_type = 'SQP_RTI';
ocp.solver_options.qp_solver = 'PARTIAL_CONDENSING_HPIPM';
ocp.solver_options.nlp_solver_max_iter = 50;

ocp.simulink_opts = simulink_opts;

%% Costs

% ocp.cost.cost_type_0 = 'NONLINEAR_LS';
ocp.cost.cost_type = 'LINEAR_LS';
ocp.cost.cost_type_e = 'LINEAR_LS';

W = diag([100, 10, 10, ...    % U; V; W;
          100, 10, 10, ...       % p; q; r;
          0, 0, 0, 0, ...       % q0; q1; q2; q3;
          0, 0, 0, 0, ...       % omega1; omega2; alfa1; alfa2   
          3e-6, 3e-6, 1e-5, 1e-5]);         % domega1; domega2; dalfa1; dalfa2   

W_e = W(1:nx,1:nx);

Vx = zeros(nx+nu,nx);
Vx(1:nx,:) = eye(nx);
Vx_e = eye(nx);

Vu = zeros(nx+nu,nu);
Vu(nx+1:nx+nu,:) = eye(nu);


% model.cost_y_expr_0 = model.u;
model.cost_y_expr = vertcat(model.x, model.u);
model.cost_y_expr_e = model.x;

ocp.cost.W = W;
ocp.cost.W_e = W_e;

ocp.cost.Vx = Vx;
ocp.cost.Vu = Vu;
ocp.cost.Vx_e = Vx_e;

% ocp.cost.yref_0 = zeros(size(model.cost_y_expr_0));
ocp.cost.yref = zeros(size(model.cost_y_expr));
ocp.cost.yref_e = zeros(size(model.cost_y_expr_e));

%% Constraints

x_min = [-200; -200; -200; -200; -200; -200; -200; -200; -200; -200; 0; 0; 1500; 1500];
x_max = [200; 200; 200; 200; 200; 200; 200; 200; 200; 200; 20000; 20000; 1700; 1700];

u_min = [-1000; -1000; -150; -150];
u_max = [1000; 1000; 150; 150];

ocp.constraints.constr_type = 'AUTO';
ocp.constraints.constr_type_0 = 'AUTO';
ocp.constraints.constr_type_e = 'AUTO';

model.con_h_expr_0 = model.u;
ocp.constraints.lh_0 = u_min;
ocp.constraints.uh_0 = u_max;

ocp.constraints.lbu = u_min;
ocp.constraints.ubu = u_max;
ocp.constraints.lbx = x_min;
ocp.constraints.ubx = x_max;


ocp.constraints.idxbu = [0;1;2;3];
ocp.constraints.idxbx = [0;1;2;3;4;5;6;7;8;9;10;11;12;13];
ocp.constraints.x0 = x0;

%% OCP SOLVER

ocp_solver = AcadosOcpSolver(ocp);

ocp_solver.set('init_x', x0 * ones(1,N+1));
ocp_solver.set('init_u', zeros(nu, N));

%%

yref = [0; 1; 1;
        0; 0; 0; 
        cos(-pi/4); 0; sin(-pi/4); 0; 
        0; 0; 1600; 1600;
        0; 0; 0; 0];

yref_e = yref(1:nx);


%% Plant creation

sim = AcadosSim();

ocp.solver_options.integrator_type = 'ERK';
sim.solver_options.Tsim = ts;

sim.model = model;

%% Sim Solver (Plant solver)

sim_solver = AcadosSimSolver(sim);

% Simulation

N_sim = 500;

x_sim = zeros(nx, N_sim+1);
u_sim = zeros(nu, N_sim);
cost_sim = zeros(1, N_sim);

x_sim(:,1) = x0;

for i=1:N_sim

    % update initial state
    x0 = x_sim(:,i);
    ocp_solver.set('constr_x0', x0);

    for k=1:N-1 % intermediate stages
        ocp_solver.set('cost_y_ref', yref, k); % last argument is the stage
    end
    ocp_solver.set('cost_y_ref_e', yref_e, N);

    % solve
    ocp_solver.solve();

    % get solution
    u0 = ocp_solver.get('u', 0);

%     x1 = ocp_solver.get('x',1)


    status = ocp_solver.get('status'); % 0 - success

    if status ~= 0
        disp(['acados ocp returned error status ', num2str(status)])
    end

    % set initial state for the simulation
    sim_solver.set('x', x0);
    sim_solver.set('u', u0);

    % simulate one step
    sim_status = sim_solver.solve();
    if sim_status ~= 0
        disp(['acados integrator returned error status ', num2str(sim_status)])
    end

    % get simulated state
    x_sim(:,i+1) = sim_solver.get('xn');
    u_sim(:,i) = u0;
    cost_sim(i) = ocp_solver.get_cost();

end

figure()
subplot(2,3,1)
plot(x_sim(1,:))
subplot(2,3,2)
plot(x_sim(2,:))
subplot(2,3,3)
plot(x_sim(3,:))
subplot(2,3,4)
plot(x_sim(4,:))
subplot(2,3,5)
plot(x_sim(5,:))
subplot(2,3,6)
plot(x_sim(6,:))

figure()
plot(x_sim(11,:))
hold on
plot(x_sim(12,:))

figure()
plot(x_sim(13,:))
hold on
plot(x_sim(14,:))


figure()
plot(u_sim(1,:))
hold on
plot(u_sim(2,:))

figure()
plot(u_sim(3,:))
hold on
plot(u_sim(4,:))

figure()
plot(cost_sim)

%% Compile Sfunctions

cd c_generated_code
make_sfun; % ocp solver
make_sfun_sim;
cd ..