clear all

syms omega rudder aileron elevator psi theta p ax s

% Test Stand Constants

setpoint_R = 1570; % Servo setpoint (neutral 0 deg)
setpoint_L = 1570;

A_Tx = 3.45e-8;
B_Tx = 3e-3;

A_Tz = -1.0e-8;
B_Tz = 7e-3;

A_My = -1.3e-9;
B_My = 8e-3;

% Control Variables

omega_0 = 12000^2;

omega_R = omega - rudder + omega_0; 
omega_L = omega + rudder + omega_0;
servo_R = -aileron - elevator + setpoint_R;
servo_L = -aileron + elevator + setpoint_L;

% Thrust calculation

Tx_R = A_Tx*omega_R;
Tz_R = A_Tz*omega_0*(servo_R-setpoint_R)*B_Tz;
My_R = A_My*omega_0*(servo_R-setpoint_R)*B_My;

Tx_L = A_Tx*omega_L;
Tz_L = A_Tz*omega_0*(servo_L-setpoint_L)*B_Tz;
My_L = A_My*omega_0*(servo_L-setpoint_L)*B_My;

% Airframe parameters

x_CoG = 10e-3; % m
z_CoG = 5e-3; % m
lt_x = 60e-3; % m
lt_y = 72.5e-3; % m
m = 1.0;       % Mass (kg)
g = -9.81;      % Gravity (m/s^2)
Ixx = 0.1;    % Rotational Inertia (kg*m^2)
Iyy = 0.1;    % Rotational Inertia (kg*m^2)
Izz = 0.2;    % Rotational Inertia (kg*m^2)

% Control forces calculation

Tx_ctrl = Tx_R + Tx_L;
Ty_ctrl = 0;
Tz_ctrl = Tz_R - Tz_L;

Mx_ctrl = (Tz_R + Tz_L) * lt_y;
My_ctrl = My_R - My_L + (Tz_R * (x_CoG - lt_x)) - (Tz_L * (x_CoG - lt_x)) - (Tx_L + Tx_R) * z_CoG;
Mz_ctrl = (Tx_L - Tx_R) * lt_y;



eq = [...
Ixx * p*s == Mx_ctrl;
Iyy * theta*s^2 == My_ctrl;
Izz * psi*s^2 == Mz_ctrl;
m * ax == Tx_ctrl - m*g];

sols.p  = vpa(solve(eq(1), p),5);
sols.theta = vpa(expand(solve(eq(2), theta)),5);
sols.psi      = vpa(solve(eq(3), psi),5);
sols.ax       = vpa(solve(eq(4), ax),5)




