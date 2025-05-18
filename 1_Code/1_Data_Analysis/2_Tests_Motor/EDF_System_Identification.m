data = readmatrix("test_stand_results_step_1400pwm_11_78V.csv");

data(:,2) = data(:,2) - data(1,2);

rpm = data(:,1);
time = data(:,2);
signal = data(:,3);


figure();

yyaxis left
plot(time, rpm); % Blue line for RPM
ylabel('RPM'); % Label for the left y-axis
yyaxis right
plot(time, signal); % Red line for Signal
ylabel('Signal'); % Label for the right y-axis
xlabel('Time');
title('RPM and Signal vs Time');
grid on;
legend('RPM', 'Signal');