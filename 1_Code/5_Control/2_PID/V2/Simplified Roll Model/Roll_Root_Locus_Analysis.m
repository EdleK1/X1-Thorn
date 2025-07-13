clear;
close all;
clc;

% --- Fixed parameters
Kp_val   = 15;
Ki_val   = 1;
Kd_val   = 1;
K_G_val  = 0.51447;
Nd_val   = 20;
Ts_val = 0.01; 
tau_act_val = 0.1;

%% Kp Swipe

% --- Parameter sweep ranges
Kp_vals  = 1:30;

zeros_z_vec = [];
poles_z_vec = [];
zeros_s_vec = [];
poles_s_vec = [];

for i = 1:length(Kp_vals)

    [zeros_z, poles_z, zeros_s, poles_s] = root_locus_roll_func(Ts_val, K_G_val, Kp_vals(i), Ki_val, Kd_val, Nd_val, tau_act_val);

    zeros_z_vec = [zeros_z_vec; zeros_z'];
    poles_z_vec = [poles_z_vec; poles_z'];
    zeros_s_vec = [zeros_s_vec; zeros_s'];
    poles_s_vec = [poles_s_vec; poles_s'];

end

figure(1)
subplot(2,2,1)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Zeros Kp Swipe','Interpreter','latex','FontSize',16);

new_zeros_z_vec = root_locus_plot_func(zeros_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_z_vec,2), 1 );

for traj = 1:size(new_zeros_z_vec,2)
    thisCol = new_zeros_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kp_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(1)
subplot(2,2,2)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Poles Kp Swipe','Interpreter','latex','FontSize',16);

new_poles_z_vec = root_locus_plot_func(poles_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_z_vec,2), 1 );

for traj = 1:size(new_poles_z_vec,2)
    thisCol = new_poles_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kp_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(1)
subplot(2,2,3)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Zeros Kp Swipe','Interpreter','latex','FontSize',16);

new_zeros_s_vec = root_locus_plot_func(zeros_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_s_vec,2), 1 );

for traj = 1:size(new_zeros_s_vec,2)
    thisCol = new_zeros_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kp_vals;
    hs(traj).UserData.trajValues = thisCol;
end


figure(1)
subplot(2,2,4)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Poles Kp Swipe','Interpreter','latex','FontSize',16);

new_poles_s_vec = root_locus_plot_func(poles_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_s_vec,2), 1 );

for traj = 1:size(new_poles_s_vec,2)
    thisCol = new_poles_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kp_vals;
    hs(traj).UserData.trajValues = thisCol;
end

% Turn on data‑cursor with custom callback
dcm = datacursormode(gcf);
set(dcm, 'Enable', 'off', 'DisplayStyle', 'datatip', 'SnapToDataVertex',  'on', 'UpdateFcn', @showParameterInDataTip);



%% Ki Swipe

% --- Parameter sweep ranges
Ki_vals  = 1:30;

zeros_z_vec = [];
poles_z_vec = [];
zeros_s_vec = [];
poles_s_vec = [];

for i = 1:length(Ki_vals)

    [zeros_z, poles_z, zeros_s, poles_s] = root_locus_roll_func(Ts_val, K_G_val, Kp_val, Ki_vals(i), Kd_val, Nd_val, tau_act_val);

    zeros_z_vec = [zeros_z_vec; zeros_z'];
    poles_z_vec = [poles_z_vec; poles_z'];
    zeros_s_vec = [zeros_s_vec; zeros_s'];
    poles_s_vec = [poles_s_vec; poles_s'];

end

figure(2)
subplot(2,2,1)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Zeros Ki Swipe','Interpreter','latex','FontSize',16);

new_zeros_z_vec = root_locus_plot_func(zeros_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_z_vec,2), 1 );

for traj = 1:size(new_zeros_z_vec,2)
    thisCol = new_zeros_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Ki_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(2)
subplot(2,2,2)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Poles Ki Swipe','Interpreter','latex','FontSize',16);

new_poles_z_vec = root_locus_plot_func(poles_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_z_vec,2), 1 );

for traj = 1:size(new_poles_z_vec,2)
    thisCol = new_poles_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Ki_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(2)
subplot(2,2,3)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Zeros Ki Swipe','Interpreter','latex','FontSize',16);

new_zeros_s_vec = root_locus_plot_func(zeros_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_s_vec,2), 1 );

for traj = 1:size(new_zeros_s_vec,2)
    thisCol = new_zeros_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Ki_vals;
    hs(traj).UserData.trajValues = thisCol;
end


figure(2)
subplot(2,2,4)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Poles Ki Swipe','Interpreter','latex','FontSize',16);

new_poles_s_vec = root_locus_plot_func(poles_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_s_vec,2), 1 );

for traj = 1:size(new_poles_s_vec,2)
    thisCol = new_poles_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Ki_vals;
    hs(traj).UserData.trajValues = thisCol;
end

% Turn on data‑cursor with custom callback
dcm = datacursormode(gcf);
set(dcm, 'Enable', 'off', 'DisplayStyle', 'datatip', 'SnapToDataVertex',  'on', 'UpdateFcn', @showParameterInDataTip);




%% Kd Swipe

% --- Parameter sweep ranges
Kd_vals  = 1:30;

zeros_z_vec = [];
poles_z_vec = [];
zeros_s_vec = [];
poles_s_vec = [];

for i = 1:length(Kd_vals)

    [zeros_z, poles_z, zeros_s, poles_s] = root_locus_roll_func(Ts_val, K_G_val, Kp_val, Ki_val, Kd_vals(i), Nd_val, tau_act_val);

    zeros_z_vec = [zeros_z_vec; zeros_z'];
    poles_z_vec = [poles_z_vec; poles_z'];
    zeros_s_vec = [zeros_s_vec; zeros_s'];
    poles_s_vec = [poles_s_vec; poles_s'];

end

figure(3)
subplot(2,2,1)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Zeros Kd Swipe','Interpreter','latex','FontSize',16);

new_zeros_z_vec = root_locus_plot_func(zeros_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_z_vec,2), 1 );

for traj = 1:size(new_zeros_z_vec,2)
    thisCol = new_zeros_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kd_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(3)
subplot(2,2,2)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Poles Kd Swipe','Interpreter','latex','FontSize',16);

new_poles_z_vec = root_locus_plot_func(poles_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_z_vec,2), 1 );

for traj = 1:size(new_poles_z_vec,2)
    thisCol = new_poles_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kd_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(3)
subplot(2,2,3)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Zeros Kd Swipe','Interpreter','latex','FontSize',16);

new_zeros_s_vec = root_locus_plot_func(zeros_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_s_vec,2), 1 );

for traj = 1:size(new_zeros_s_vec,2)
    thisCol = new_zeros_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kd_vals;
    hs(traj).UserData.trajValues = thisCol;
end


figure(3)
subplot(2,2,4)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Poles Kd Swipe','Interpreter','latex','FontSize',16);

new_poles_s_vec = root_locus_plot_func(poles_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_s_vec,2), 1 );

for traj = 1:size(new_poles_s_vec,2)
    thisCol = new_poles_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Kd_vals;
    hs(traj).UserData.trajValues = thisCol;
end

% Turn on data‑cursor with custom callback
dcm = datacursormode(gcf);
set(dcm, 'Enable', 'off', 'DisplayStyle', 'datatip', 'SnapToDataVertex',  'on', 'UpdateFcn', @showParameterInDataTip);


%% Nd Swipe

% --- Parameter sweep ranges
Nd_vals  = [1,2,3,4,5,6,7,8,9,10:10:200];

zeros_z_vec = [];
poles_z_vec = [];
zeros_s_vec = [];
poles_s_vec = [];

for i = 1:length(Nd_vals)

    [zeros_z, poles_z, zeros_s, poles_s] = root_locus_roll_func(Ts_val, K_G_val, Kp_val, Ki_val, Kd_val, Nd_vals(i), tau_act_val);

    zeros_z_vec = [zeros_z_vec; zeros_z'];
    poles_z_vec = [poles_z_vec; poles_z'];
    zeros_s_vec = [zeros_s_vec; zeros_s'];
    poles_s_vec = [poles_s_vec; poles_s'];

end

figure(4)
subplot(2,2,1)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Zeros Nd Swipe','Interpreter','latex','FontSize',16);

new_zeros_z_vec = root_locus_plot_func(zeros_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_z_vec,2), 1 );

for traj = 1:size(new_zeros_z_vec,2)
    thisCol = new_zeros_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Nd_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(4)
subplot(2,2,2)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Discrete Poles Nd Swipe','Interpreter','latex','FontSize',16);

new_poles_z_vec = root_locus_plot_func(poles_z_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_z_vec,2), 1 );

for traj = 1:size(new_poles_z_vec,2)
    thisCol = new_poles_z_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Nd_vals;
    hs(traj).UserData.trajValues = thisCol;
end
ztheta = linspace(0,2*pi,200);
plot(cos(ztheta), sin(ztheta), 'k:');  % unit circle


figure(4)
subplot(2,2,3)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Zeros Nd Swipe','Interpreter','latex','FontSize',16);

new_zeros_s_vec = root_locus_plot_func(zeros_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_zeros_s_vec,2), 1 );

for traj = 1:size(new_zeros_s_vec,2)
    thisCol = new_zeros_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Nd_vals;
    hs(traj).UserData.trajValues = thisCol;
end


figure(4)
subplot(2,2,4)
hold on; grid on; axis equal
xline(0,'k:'); yline(0,'k:');
title('Continuous Poles Nd Swipe','Interpreter','latex','FontSize',16);

new_poles_s_vec = root_locus_plot_func(poles_s_vec);

% Pre‑allocate array of scatter handles
hs = gobjects( size(new_poles_s_vec,2), 1 );

for traj = 1:size(new_poles_s_vec,2)
    thisCol = new_poles_s_vec(:,traj);    
    hs(traj) = scatter(real(thisCol), imag(thisCol), 20, 'filled');
    % Store all Kp_vals in the UserData (same length as thisCol)
    hs(traj).UserData.Parameter_vals    = Nd_vals;
    hs(traj).UserData.trajValues = thisCol;
end

% Turn on data‑cursor with custom callback
dcm = datacursormode(gcf);
set(dcm, 'Enable', 'off', 'DisplayStyle', 'datatip', 'SnapToDataVertex',  'on', 'UpdateFcn', @showParameterInDataTip);

