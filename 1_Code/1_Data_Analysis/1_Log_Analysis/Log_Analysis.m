% analyzeTelemetryWithAnimation.m
%--------------------------------------------------------------------
% Reads 'LOG16.csv', plots grouped signals with grid on,
% and animates vehicle orientation using quaternion data.
%--------------------------------------------------------------------

clear; close all; clc;

%% 1) Load data
T = readtable('LOG16.csv');
% Convert timestamp to seconds, zero-based
time = (T.Timestamp - T.Timestamp(1)) / 1000;  % assuming ms to s

% Extract signals
ax         = T.curr_ax;           ax_ref     = T.ax_ref;
p_rate     = T.curr_roll_rate;    q_rate     = T.curr_pitch_rate;
r_rate     = T.curr_yaw_rate;
qw         = T.curr_qw;           qx         = T.curr_qx;
qy         = T.curr_qy;           qz         = T.curr_qz;
p_ref      = T.p_ref;             q_ref      = T.q_ref;
r_ref      = T.r_ref;
omegaL_ref = T.omega_L_ref;       rpm2       = T.RPM2;
omegaR_ref = T.omega_R_ref;       rpm4       = T.RPM4;
servoL_ref = T.servo_L_ref;       servoR_ref = T.servo_R_ref;
temp       = T.Temperature;       volt       = T.Voltage;

%% 2) Plot grouped signals
% Figure 1: Accel & Body Rates
figure('Name','Accel & Body Rates','NumberTitle','off');
subplot(2,2,1)
plot(time, ax, '-', 'LineWidth', 1); hold on
plot(time, ax_ref, '--', 'LineWidth', 1); hold off
xlabel('Time (s)'); ylabel('a_x'); title('Accel X');
legend('curr','ref'); grid on;

subplot(2,2,2)
plot(time, q_rate, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('Pitch Rate'); title('Pitch Rate'); grid on;

subplot(2,2,3)
plot(time, r_rate, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('Yaw Rate'); title('Yaw Rate'); grid on;

subplot(2,2,4)
plot(time, p_rate, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('Roll Rate'); title('Roll Rate'); grid on;

% Figure 2: Quaternion Components
figure('Name','Quaternion','NumberTitle','off');
subplot(2,2,1)
plot(time, qw, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('q_w'); title('Quaternion W'); grid on;

subplot(2,2,2)
plot(time, qx, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('q_x'); title('Quaternion X'); grid on;

subplot(2,2,3)
plot(time, qy, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('q_y'); title('Quaternion Y'); grid on;

subplot(2,2,4)
plot(time, qz, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('q_z'); title('Quaternion Z'); grid on;

% Figure 3: Reference Body Rates
figure('Name','Ref Body Rates','NumberTitle','off');
subplot(3,1,1)
plot(time, p_ref, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('p_{ref}'); title('Roll Rate Ref'); grid on;

subplot(3,1,2)
plot(time, q_ref, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('q_{ref}'); title('Pitch Rate Ref'); grid on;

subplot(3,1,3)
plot(time, r_ref, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('r_{ref}'); title('Yaw Rate Ref'); grid on;

% Figure 4: Motor Speeds
figure('Name','Motor Speeds','NumberTitle','off');
subplot(2,1,1)
plot(time, omegaL_ref, 'LineWidth', 1); hold on
plot(time, rpm2, '--', 'LineWidth', 1); hold off
xlabel('Time (s)'); ylabel('Left ω / RPM');
legend('\omega_{L,ref}','RPM2'); title('Left Motor'); grid on;

subplot(2,1,2)
plot(time, omegaR_ref, 'LineWidth', 1); hold on
plot(time, rpm4, '--', 'LineWidth', 1); hold off
xlabel('Time (s)'); ylabel('Right ω / RPM');
legend('\omega_{R,ref}','RPM4'); title('Right Motor'); grid on;

% Figure 5: Servo Commands
figure('Name','Servo Commands','NumberTitle','off');
subplot(2,1,1)
plot(time, servoL_ref, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('servo_L'); title('Servo L Command'); grid on;

subplot(2,1,2)
plot(time, servoR_ref, 'LineWidth', 1);
xlabel('Time (s)'); ylabel('servo_R'); title('Servo R Command'); grid on;

% Figure 6: Temperature & Voltage
figure('Name','Temp & Voltage','NumberTitle','off');
yyaxis left
plot(time, temp, '-', 'LineWidth', 1)
ylabel('Temperature (°C)')
yyaxis right
plot(time, volt, '--', 'LineWidth', 1)
ylabel('Voltage (V)')
xlabel('Time (s)'); title('Temperature and Voltage');
legend('Temp','Volt','Location','best'); grid on;

%% Quaternion Animation Integration for Log Analysis (Manual Drawing)
% This version draws body axes manually, captures frames off-screen, and
% uses implay with a larger window size.

%--- Build MATLAB quaternion array ---
Q = quaternion(qw, qx, qy, qz);  % requires Aerospace Toolbox

%--- Set up figure ---
figA = figure('Name','Orientation Animation','NumberTitle','off');
axA  = axes(figA);
set(axA, 'XLim', [-1 1], 'YLim', [-1 1], 'ZLim', [-1 1]);
view(3); grid on;
daspect(axA, [1 1 1]);  % equal data aspect ratio
xlabel('X'); ylabel('Y'); zlabel('Z');
title('Vehicle Orientation over Time');
hold on;

%--- Body frame scale ---
L = 1.0;

%--- Initial body axes ---
R0 = rotmat(Q(1), 'point');
ex0 = (R0 * [L;0;0])'; ey0 = (R0 * [0;L;0])'; ez0 = (R0 * [0;0;L])';
hX = line([0 ex0(1)], [0 ex0(2)], [0 ex0(3)], 'Color','r','LineWidth',2);
hY = line([0 ey0(1)], [0 ey0(2)], [0 ey0(3)], 'Color','g','LineWidth',2);
hZ = line([0 ez0(1)], [0 ez0(2)], [0 ez0(3)], 'Color','b','LineWidth',2);

%--- Ensure figure is large for capture ---
set(figA, 'Units', 'pixels', 'Position', [100 100 1200 900]);  % set capture size

%--- Hide figure and record frames ---
set(figA, 'Visible', 'off');
skip = 1; cnt = 0;

% view(axA, 90, 30);

for k = 1:skip:length(time)
    Rk = rotmat(Q(k), 'point');
    ex = (Rk * [L;0;0])'; ey = (Rk * [0;L;0])'; ez = (Rk * [0;0;L])';
    set(hX, 'XData', [0 ex(1)], 'YData', [0 ex(2)], 'ZData', [0 ex(3)]);
    set(hY, 'XData', [0 ey(1)], 'YData', [0 ey(2)], 'ZData', [0 ey(3)]);
    set(hZ, 'XData', [0 ez(1)], 'YData', [0 ez(2)], 'ZData', [0 ez(3)]);
    drawnow;
    cnt = cnt + 1;
    M(cnt) = getframe(figA);
end

%--- Show figure and launch implay ---
hPlayer = implay(M, 10);  % launch interactive player
% Resize the Video Player window (if present)
pause(0.1);  % allow window to open
vpFig = findall(0, 'Type', 'figure', 'Name', 'Video Player');
if ~isempty(vpFig)
    set(vpFig, 'Position', [100 100 800 600]);
end


