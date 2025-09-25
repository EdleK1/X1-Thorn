clear;
% close all;
clc;

% --- Fixed parameters
Kp_PitchRate_val = 20;
Ki_PitchRate_val = 7;
Kd_PitchRate_val = 1;
Kq_val = 3;

Kg_val = 0.4956;
N_PitchRate_val = 20;
Ts_val = 0.01;
tau_act_val = 0.1;


[points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_val);
GainMargin = GM


figure(1);
plot(real(points_z), imag(points_z));
hold on; grid on; axis equal;

% draw real and imaginary axes
xline(0, 'k--', 'LineWidth',1);
yline(0, 'k--', 'LineWidth',1);

% mark the -1 point
plot(-1, 0, 'r.', 'MarkerSize',20, 'LineWidth',2);

xlabel('Real Axis',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Imaginary Axis',"Interpreter","Latex", "Fontsize", 16);  
title('Discrete Time Nyquist',"Interpreter","Latex", "Fontsize", 20); 


%% Kp Swipe


figure(2)
hold on; grid on;

xlabel('Kp Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different Kp Values',"Interpreter","Latex", "Fontsize", 20); 


Kp_vals  = [-1,-2,-3,-4,-5,-6,-7,-8,-9,-10:-10:-100];
GM_vec = [];

for i = 1:length(Kp_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_vals(i), Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_val);
    GM_vec = [GM_vec,GM];

end

plot(Kp_vals, GM_vec);



%% Kd Swipe


figure(3)
hold on; grid on;

xlabel('Kd Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different Kd Values',"Interpreter","Latex", "Fontsize", 20); 


Kd_vals  = [-1,-2,-3,-4,-5,-6,-7,-8,-9,-10:-10:-100];
GM_vec = [];

for i = 1:length(Kd_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_PitchRate_val, Kd_vals(i), N_PitchRate_val, tau_act_val);
    GM_vec = [GM_vec,GM];

end

plot(Kd_vals, GM_vec);


%% Ki Swipe


figure(4)
hold on; grid on;

xlabel('Ki Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different Ki Values',"Interpreter","Latex", "Fontsize", 20); 


Ki_vals  = [-1,-2,-3,-4,-5,-6,-7,-8,-9,-10:-10:-100];
GM_vec = [];

for i = 1:length(Ki_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_vals(i), Kd_PitchRate_val, N_PitchRate_val, tau_act_val);
    GM_vec = [GM_vec,GM];

end

plot(Ki_vals, GM_vec);



%% Kq Swipe


figure(5)
hold on; grid on;

xlabel('Kq Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different Kq Values',"Interpreter","Latex", "Fontsize", 20); 


Kq_vals  = [1:20];
GM_vec = [];

for i = 1:length(Kq_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_vals(i), Kp_PitchRate_val, Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_val);
    GM_vec = [GM_vec, GM];

end

plot(Kq_vals, GM_vec);



%% tau actuator Swipe


figure(6)
hold on; grid on;

xlabel('$tau_{act}$ Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different tau_{act} Values',"Interpreter","Latex", "Fontsize", 20); 


tau_act_vals  = [0.01:0.01:0.2];
GM_vec = [];

for i = 1:length(tau_act_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_vals(i));
    GM_vec = [GM_vec,GM];

end

plot(tau_act_vals, GM_vec);



%% K_G Swipe


figure(7)
hold on; grid on;

xlabel('K_G Values',"Interpreter","Latex", "Fontsize", 16); 
ylabel('Gain Margin',"Interpreter","Latex", "Fontsize", 16);  
title('Gain Margin for different $K_G$ Values',"Interpreter","Latex", "Fontsize", 20); 


tau_act_vals  = [0.05:0.01:0.2];
GM_vec = [];

for i = 1:length(tau_act_vals)

    [points_z, GM] = nyquist_func(Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_vals(i));
    GM_vec = [GM_vec,GM];

end

plot(tau_act_vals, GM_vec);