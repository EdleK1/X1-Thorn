clear
close all

X1_Thorn_SIMSCAPE_DataFile


Ts_val = 0.01;

%% Pitch Controller

Kp_PitchRate_val = -200;        % OK % -150
Ki_PitchRate_val = -90;         % OK % -90
Kd_PitchRate_val = -10;         % OK % -70
Kq_PitchRate_val = 0.25;        % OK % 0.15
N_PitchRate_val = 20;           % OK

%% Yaw Controller


Kp_YawRate_val = 40e6;          % OK % 20e6
Ki_YawRate_val = 9e6;           % OK % 9e6
Kd_YawRate_val = 7e6;           % OK % 18e6
Kr_YawRate_val = 0.2;           % OK % 0.1
N_YawRate_val = 10;             % OK


%% Roll Controller


Kp_RollRate_val = 15;           % OK
Ki_RollRate_val = 1;            % OK
Kd_RollRate_val = 1;            % OK
N_RollRate_val = 20;            % OK


%% Thrust Controller

Kp_Thrust_val = 1e6;            % OK
Ki_Thrust_val = 100e6;          % OK