clear
% close all

X1_Thorn_SIMSCAPE_DataFile


Ts_val = 0.01;

%% Pitch Controller

Kp_PitchRate_val = 15;          % OK
Ki_PitchRate_val = 7;           % OK 
Kd_PitchRate_val = 1;           % OK
Kq_PitchRate_val = 2;           % OK
N_PitchRate_val = 20;           % OK

%% Yaw Controller

Kp_YawRate_val = 80e6;          % OK  80
Ki_YawRate_val = 40e6;          % OK  30
Kd_YawRate_val = 0e6;           % OK  10
Kr_YawRate_val = 4;             % OK  9
N_YawRate_val = 20;             % OK


%% Roll Controller


Kp_RollRate_val = 15;           % OK
Ki_RollRate_val = 5;            % OK
Kd_RollRate_val = 1;            % OK
N_RollRate_val = 20;            % OK


%% Thrust Controller

Kp_Thrust_val = 2e6;            % OK
Ki_Thrust_val = 200e6;          % OK