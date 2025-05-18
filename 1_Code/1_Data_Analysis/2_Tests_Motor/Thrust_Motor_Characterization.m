clear
close all

data = readmatrix("timing_advance_15_brk_5_1.csv");

time = data(:,1) - data(1,1);
servo_PWM = data(:,2);
temperature = data(:,3);
rpm = data(:,4);
voltage = data(:,5);
current = data(:,6);
count = data(:,7);
power = current.*voltage;

load_1 = data(:,8);

Q1 = quantile(load_1, 0.25);
Q3 = quantile(load_1, 0.75);
IQR_value = Q3 - Q1;
lower_bound = Q1 - 1.5 * IQR_value;
upper_bound = Q3 + 1.5 * IQR_value;
outliers = (load_1 < lower_bound) | (load_1 > upper_bound);
load_1(outliers) = NaN; % Replace outliers with NaN
load_1 = fillmissing(load_1, 'previous');


load_2 = data(:,9);

Q1 = quantile(load_2, 0.25);
Q3 = quantile(load_2, 0.75);
IQR_value = Q3 - Q1;
lower_bound = Q1 - 1.5 * IQR_value;
upper_bound = Q3 + 1.5 * IQR_value;
outliers = (load_2 < lower_bound) | (load_2 > upper_bound);
load_2(outliers) = NaN; % Replace outliers with NaN
load_2 = fillmissing(load_2, 'previous');

load_3 = data(:,10);

Q1 = quantile(load_3, 0.25);
Q3 = quantile(load_3, 0.75);
IQR_value = Q3 - Q1;
lower_bound = Q1 - 1.5 * IQR_value;
upper_bound = Q3 + 1.5 * IQR_value;
outliers = (load_3 < lower_bound) | (load_3 > upper_bound);
load_3(outliers) = NaN; % Replace outliers with NaN
load_3 = fillmissing(load_3, 'previous');

%% --------------------Time Plots-----------------------%%

figure("Name","rpm vs time")
plot(time,rpm,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("EDF RPM","Interpreter","Latex")
title("EDF RPM vs time","Interpreter","Latex")
grid on


figure("Name","voltage vs time")
plot(time,voltage,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("Battery voltage (V)","Interpreter","Latex")
title("Battery voltage vs time","Interpreter","Latex")
grid on


figure("Name","current vs time")
plot(time,current,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("Battery current (A)","Interpreter","Latex")
title("Battery current vs time","Interpreter","Latex")
grid on


figure("Name","Thrust vs time")
plot(time,load_2,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("Thrust (g)","Interpreter","Latex")
title("Thrust vs time","Interpreter","Latex")
grid on

figure("Name","Temperature vs time")
plot(time,temperature,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("temperature (degrees)","Interpreter","Latex")
title("Temperature vs time","Interpreter","Latex")
grid on

%% -------------------- Thrust vs RPM -----------------------%%

valid_idx = ~isnan(load_2);
rpm_clean = rpm(valid_idx);
thrust_clean = load_2(valid_idx);

thrust_rpm = polyfit(rpm_clean,thrust_clean,2);


figure("Name","Thrust vs rpm")
plot(rpm_clean,thrust_clean,".")
hold on
plot(rpm_clean,polyval(thrust_rpm,rpm_clean))

xlabel("EDF RPM","Interpreter","Latex","FontSize",16)
ylabel("Thrust (g)","Interpreter","Latex","FontSize",16)
title("Thrust vs EDF RPM","Interpreter","Latex","FontSize",16)
legend("Test Data","Second Order Fitment","Interpreter","Latex","FontSize",12)
grid on
