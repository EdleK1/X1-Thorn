% clear
% close all

file = "timing_advance_15_brk_5_2.csv";

data = readmatrix(file);

time = data(:,1) - data(1,1);
servo_PWM = data(:,2);
temperature = data(:,3);
rpm = data(:,4);
voltage = data(:,5);
current = data(:,6);
count = data(:,7);
power = current.*voltage;

if exist('legend_vec', 'var')
    legend_vec = [legend_vec,file];
else
    legend_vec = [file];
end



%% --------------------Time Plots-----------------------%%

figure(1)
plot(time,rpm,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("EDF RPM","Interpreter","Latex")
title("EDF RPM vs time","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")


figure(2)
plot(time,voltage,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("Battery voltage (V)","Interpreter","Latex")
title("Battery voltage vs time","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")


figure(3)
plot(time,current,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("Battery current (A)","Interpreter","Latex")
title("Battery current vs time","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")


figure(4)
plot(time,temperature,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("temperature (degrees)","Interpreter","Latex")
title("Temperature vs time","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")


figure(5)
plot(time,power,".")
xlabel("time(s)","Interpreter","Latex")
ylabel("power (Xd)","Interpreter","Latex")
title("Power vs time","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")


%% RPM Analysis

figure(6)

plot(rpm,power,".")
xlabel("rpm","Interpreter","Latex")
ylabel("power","Interpreter","Latex")
title("power vs rpm","Interpreter","Latex")
grid on
hold on
legend(legend_vec,"Interpreter","none")