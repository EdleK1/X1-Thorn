function model = get_aircraft_model()

import casadi.*


%% Define variables

nx = 11;
nu = 3;
x = SX.sym('x', nx);  % State vector (U, V, W, p, q, r, q0, q1, q2, q3)
u = SX.sym('u', nu);    % Control inputs (omega1, omega2, alfa1, alfa2)

%% Define constant parameters

m = 1.0;      % Mass (kg)
g = -9.81;    % Gravity (m/s^2)
Ixx = 0.1;    % Rotational Inertia (kg*m^2)
Iyy = 0.1;    % Rotational Inertia (kg*m^2)
Izz = 0.2;    % Rotational Inertia (kg*m^2)

%% Extract state variables

p = x(1);
q = x(2);
r = x(3);
q0 = x(4);
q1 = x(5);
q2 = x(6);
q3 = x(7);

omega1 = x(8); % rpms
omega2 = x(9);
alfa1 = x(10); % servo PWM
alfa2 = x(11);

%% Extract control variables

domega = u(1);
dalfa1 = u(2);
dalfa2 = u(3);

%% Compute Forces based on inputs

% Test Stand Constants

% setpoint_R = 1570; % Servo setpoint (neutral 0 deg)
% setpoint_L = 1570;

A_Tx = 3.45e-8;
B_Tx = 3e-3;

A_Tz = -1.0e-8;
B_Tz = 7e-3;

A_My = -1.3e-9;
B_My = 8e-3;

% Thrust calculation

Tx_R = A_Tx*omega1^2*cos(alfa1*B_Tx);
Tz_R = A_Tz*omega1^2*sin(alfa1*B_Tz);
My_R = A_My*omega1^2*sin(alfa1*B_My);

Tx_L = A_Tx*omega2^2*cos(alfa2*B_Tx);
Tz_L = A_Tz*omega2^2*sin(alfa2*B_Tz);
My_L = A_My*omega2^2*sin(alfa2*B_My);

% Airframe parameters

x_CoG = 10e-3; % m
z_CoG = 5e-3; % m
lt_x = 60e-3; % m
lt_y = 72.5e-3; % m

% Control moments calculation

Mx_ctrl = (Tz_R + Tz_L) * lt_y;
My_ctrl = My_R - My_L + (Tz_R * (x_CoG - lt_x)) - (Tz_L * (x_CoG - lt_x)) - (Tx_L + Tx_R) * z_CoG;
Mz_ctrl = (Tx_L - Tx_R) * lt_y;

%% Continuous-time dynamics function

f_expl_expr = [

    (Mx_ctrl + (Iyy-Izz)*q*r)/Ixx;
    (My_ctrl - (Ixx-Izz)*p*r)/Iyy;
    (Mz_ctrl + (Ixx-Iyy)*p*q)/Izz;

    (-p*q1 -q*q2 - r*q3)/2;
    (p*q0 + r*q2 - q*q3)/2;
    (q*q0 - r*q1 + p*q3)/2;
    (r*q0 + q*q1 - p*q2)/2;

    domega;
    -domega;
    dalfa1;
    dalfa2
    
    ];



%% Define the model

model = AcadosModel();
model.x = x;
model.u = u;

model.f_expl_expr = f_expl_expr;
model.name = 'Aircraft_Attitude';

end