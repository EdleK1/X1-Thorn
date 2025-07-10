clear
close all

X1_Thorn_SIMSCAPE_DataFile


Ts_val = 0.01;

%% Pitch Controller

Kp_PitchRate_val = -150;        % OK
Ki_PitchRate_val = -90;         % OK
Kd_PitchRate_val = -70;         % OK
Kq_PitchRate_val = 0.15;        % OK
N_PitchRate_val = 20;           % OK

%% Yaw Controller


Kp_YawRate_val = 20e6;          % OK
Ki_YawRate_val = 9e6;           % OK
Kd_YawRate_val = 18e6;          % OK
Kr_YawRate_val = 0.1;           % OK
N_YawRate_val = 10;             % OK


%% Roll Controller


Kp_RollRate_val = 10;          % OK
Ki_RollRate_val = 9;           % OK
Kd_RollRate_val = 7;          % OK
N_RollRate_val = 20;             % OK