clear
close all

X1_Thorn_SIMSCAPE_DataFile


Ts_val = 0.01;

%% Pitch Controller

Kp_PitchRate_val = -60;         % OK % -80
Ki_PitchRate_val = -10;         % OK % -40
Kd_PitchRate_val = -5;         % OK % -12
Kq_PitchRate_val = 3;           % OK % 6
N_PitchRate_val = 20;           % OK

%% Yaw Controller

Kp_YawRate_val = 80e6;          % OK  80
Ki_YawRate_val = 20e6;          % OK  30
Kd_YawRate_val = 10e6;          % OK  10
Kr_YawRate_val = 4;             % OK  9
N_YawRate_val = 20;             % OK


%% Roll Controller


Kp_RollRate_val = 15;           % OK
Ki_RollRate_val = 1;            % OK
Kd_RollRate_val = 1;            % OK
N_RollRate_val = 20;            % OK


%% Thrust Controller

Kp_Thrust_val = 2e6;            % OK
Ki_Thrust_val = 200e6;          % OK