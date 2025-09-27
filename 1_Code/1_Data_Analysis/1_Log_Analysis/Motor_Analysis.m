%--------------------------------------------------------------------
% Reads 'LOGX.csv', plots grouped signals with LaTeX labels,
% and animates vehicle orientation using quaternion data.
%--------------------------------------------------------------------

clear; close all; clc;

% 1) Load data
T = readtable('LOG1.csv');
time       = (T.Timestamp - T.Timestamp(1)) / 1000;  % seconds
ax         = T.curr_ax;           thrust_ref = T.thrust_ref;
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
throttle2  = T.Throttle2;         throttle4  = T.Throttle4;
current    = T.Current;           errors     = T.ErrorCodes;


rpm_to_throttle2 = T.RPM2 ./ T.Throttle2;
rpm_to_throttle4 = T.RPM4 ./ T.Throttle4;


% Figure 1: RPM / Throttle 
figure('Name','RPM / Throttle','NumberTitle','off');
plot(time, rpm_to_throttle2,'LineWidth',1); hold on
plot(time, rpm_to_throttle4,'LineWidth',1); hold off

xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('RPM / Throttle','Interpreter','latex',"FontSize",16)
title('RPM / Throttle','Interpreter','latex',"FontSize",20)
grid on


% Figure 2: RPM / Throttle Normalitzat
figure('Name','RPM / Throttle Normalitzat','NumberTitle','off');
plot(time, rpm_to_throttle2./ volt,'LineWidth',1); hold on
plot(time, rpm_to_throttle4./ volt,'LineWidth',1); hold off

xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('RPM / Throttle','Interpreter','latex',"FontSize",16)
title('RPM / Throttle','Interpreter','latex',"FontSize",20)
grid on


% Figure 3: Temperature & Voltage
figure('Name','Temp & Voltage','NumberTitle','off');
yyaxis left
plot(time, temp,'-','LineWidth',1)
ylabel('Temperature ($^\circ$C)','Interpreter','latex',"FontSize",16)
yyaxis right
plot(time, volt,'--','LineWidth',1)
ylabel('Voltage (V)','Interpreter','latex',"FontSize",16)
xlabel('Time (s)','Interpreter','latex',"FontSize",16)
title('Temperature and Voltage','Interpreter','latex',"FontSize",20)
legend({'Temp','Volt'},'Interpreter','latex','Location','best',"FontSize",14)
grid on


% Figure 4: Motor Speeds
figure('Name','Throttle','NumberTitle','off');
subplot(2,1,1)
plot(time, throttle2);
xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('Throttle 2','Interpreter','latex',"FontSize",16)
title('Left Motor','Interpreter','latex',"FontSize",20)
grid on

subplot(2,1,2)
plot(time, throttle4);
xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('Throttle 4','Interpreter','latex',"FontSize",16)
title('Right Motor','Interpreter','latex',"FontSize",20)
grid on


% Figure 5: Motor Speeds
figure('Name','Motor Speeds','NumberTitle','off');
subplot(2,1,1)
plot(time, rpm2,'LineWidth',1); hold on
plot(time, omegaL_ref,'--','LineWidth',1); hold off
xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('RPMs','Interpreter','latex',"FontSize",16)
legend({'$\omega_L$','Target'},'Interpreter','latex',"FontSize",14)
title('Left Motor','Interpreter','latex',"FontSize",20)
grid on

subplot(2,1,2)
plot(time, rpm4,'LineWidth',1); hold on
plot(time, omegaR_ref,'--','LineWidth',1); hold off
xlabel('Time (s)','Interpreter','latex',"FontSize",16)
ylabel('RPMs','Interpreter','latex',"FontSize",16)
legend({'$\omega_R$','Target'},'Interpreter','latex',"FontSize",14)
title('Right Motor','Interpreter','latex',"FontSize",20)
grid on


%% FeedForward Pre-Calculations

% FFW coeffs

% 1.3654 CSV2
% 1.3585 CSV1
% 1.3497 CSV3

time_0 = 31;
time_1 = 78;
% time_0 = 80;
% time_1 = 129;

best = median(rpm_to_throttle2(time_0*10:time_1*10)./ volt(time_0*10:time_1*10))
1/best

figure()
scatter(rpm2,throttle2)

FeedForwardcoef = volt*best;

FeedForward_Thtl = rpm2./FeedForwardcoef;

hold on

scatter(rpm2,FeedForward_Thtl)


diference = FeedForward_Thtl - throttle2;

figure()
plot(diference)

median(diference(time_0*10:time_1*10))