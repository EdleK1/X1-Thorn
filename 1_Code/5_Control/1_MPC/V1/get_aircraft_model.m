function model = get_aircraft_model()

import casadi.*


%% Define variables

nx = 14;
nu = 4;
x = SX.sym('x', nx);  % State vector (U, V, W, p, q, r, q0, q1, q2, q3)
u = SX.sym('u', nu);    % Control inputs (omega1, omega2, alfa1, alfa2)

%% Define constant parameters

m = 1.0;       % Mass (kg)
g = -9.81;      % Gravity (m/s^2)
Ixx = 0.1;    % Rotational Inertia (kg*m^2)
Iyy = 0.1;    % Rotational Inertia (kg*m^2)
Izz = 0.2;    % Rotational Inertia (kg*m^2)

%% Extract state variables

U = x(1);
V = x(2);
W = x(3);
p = x(4);
q = x(5);
r = x(6);
q0 = x(7);
q1 = x(8);
q2 = x(9);
q3 = x(10);

omega1 = x(11); % rpms
omega2 = x(12);
alfa1 = x(13); % servo PWM
alfa2 = x(14);

%% Extract control variables

domega1 = u(1);
domega2 = u(2);
dalfa1 = u(3);
dalfa2 = u(4);

%% Compute Forces based on inputs

% Test Stand Constants

setpoint_R = 1570; % Servo setpoint (neutral 0 deg)
setpoint_L = 1570;

A_Tx = 3.45e-8;
B_Tx = 3e-3;

A_Tz = -1.0e-8;
B_Tz = 7e-3;

A_My = -1.3e-9;
B_My = 8e-3;

% Thrust calculation

Tx_R = A_Tx*omega1^2*cos((alfa1-setpoint_R)*B_Tx);
Tz_R = A_Tz*omega1^2*sin((alfa1-setpoint_R)*B_Tz);
My_R = A_My*omega1^2*sin((alfa1-setpoint_R)*B_My);

Tx_L = A_Tx*omega2^2*cos((alfa2-setpoint_L)*B_Tx);
Tz_L = A_Tz*omega2^2*sin((alfa2-setpoint_L)*B_Tz);
My_L = A_My*omega2^2*sin((alfa2-setpoint_L)*B_My);

% Airframe parameters

x_CoG = 10e-3; % m
z_CoG = 5e-3; % m
lt_x = 60e-3; % m
lt_y = 72.5e-3; % m

% Control forces calculation

Tx_ctrl = Tx_R + Tx_L;
Ty_ctrl = 0;
Tz_ctrl = Tz_R - Tz_L;

Mx_ctrl = (Tz_R + Tz_L) * lt_y;
My_ctrl = My_R - My_L + (Tz_R * (x_CoG - lt_x)) - (Tz_L * (x_CoG - lt_x)) - (Tx_L + Tx_R) * z_CoG;
Mz_ctrl = (Tx_L - Tx_R) * lt_y;



%% Continuous-time dynamics function

f_expl_expr = [
    
    (2*m*g*(q1*q3 - q0*q2) + Tx_ctrl)/m + r*V - q*W;
    (2*m*g*(q0*q1 + q2*q3) + Ty_ctrl)/m + p*W - r*U;
    (m*g*(1-2*(q1^2 + q2^2)) + Tz_ctrl)/m + q*U - p*V;

    (Mx_ctrl + (Iyy-Izz)*q*r)/Ixx;
    (My_ctrl - (Ixx-Izz)*p*r)/Iyy;
    (Mz_ctrl + (Ixx-Iyy)*p*q)/Izz;

    (-p*q1 -q*q2 - r*q3)/2;
    (p*q0 + r*q2 - q*q3)/2;
    (q*q0 - r*q1 + p*q3)/2;
    (r*q0 + q*q1 - p*q2)/2;

    domega1;
    domega2;
    dalfa1;
    dalfa2
    
    ];



%% Define the model

model = AcadosModel();
model.x = x;
model.u = u;

model.f_expl_expr = f_expl_expr;
model.name = 'Aircraft';









% %% RK4 Integration
% k1 = f_continuous(x, u);
% k2 = f_continuous(x + (dt/2) * k1, u);
% k3 = f_continuous(x + (dt/2) * k2, u);
% k4 = f_continuous(x + dt * k3, u);
% 
% x_next = x + (dt/6) * (k1 + 2*k2 + 2*k3 + k4);
% x_next()
% 
% %% Define discrete function for Acados
% 
% model.f_disc_expr = Function('f_disc_expr', {x, u, dt}, {x_next});

end