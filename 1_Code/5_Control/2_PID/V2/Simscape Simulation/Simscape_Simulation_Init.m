clear
% close all

X1_Thorn_SIMSCAPE_DataFile


Ts_val = 0.01;

%% Pitch Controller

Kp_PitchRate_val = 20;          % 15
Ki_PitchRate_val = 7;           % 7 
Kd_PitchRate_val = 1;           % 1
Kq_PitchRate_val = 3;           % 2
N_PitchRate_val = 20;           % 20

%% Yaw Controller

Kp_YawRate_val = 40e6;         % OK  80
Ki_YawRate_val = 35e6;         % OK  40
Kd_YawRate_val = 2.5e6;           % OK  0
Kr_YawRate_val = 4;             % OK  4
N_YawRate_val = 20;             % OK


%% Roll Controller


Kp_RollRate_val = 20;           % OK 15
Ki_RollRate_val = 5;            % OK 5
Kd_RollRate_val = 1.2;            % OK 1
N_RollRate_val = 20;            % OK 


%% Thrust Controller

Kp_Thrust_val = 2e6;            % OK
Ki_Thrust_val = 200e6;          % OK