clear

Kp_RollRate_val = 15;
Ki_RollRate_val = 1;
Kd_RollRate_val = 1;
Kg_val = 0.53887;
tau_act_val = 0.1;

%% Symbolic Analysis

syms Kd Ki Kp s tau_act


PID = s*Kd + Kp + Ki/s;
G = Kg_val * 1/(tau_act*s + 1);

L1 = PID * G * 1/s;
Tf_Final_qdot = L1/(1+L1);


Tf_Final_qdot = simplify(Tf_Final_qdot);
Tf_Final_qdot = collect(Tf_Final_qdot, s)


%% Continuous time Analysis

G = Kg_val * tf(1, [tau_act_val, 1]);
PID = tf([Kd_RollRate_val, 0],1) + tf(Kp_RollRate_val,1) + tf(Ki_RollRate_val,[1,0]);
L1 = PID * G * tf(1,[1,0]);
Tf_Final_val = L1/(1+L1);
Tf_Final_val = minreal(Tf_Final_val)

poles = pole(Tf_Final_val)
zeros = zero(Tf_Final_val)

figure(10);
step(Tf_Final_val);
grid on
hold on

%% Discrete time Analysis:

clear

Kp_RollRate_val = 15;
Ki_RollRate_val = 1;
Kd_RollRate_val = 1;
Kg_val = 0.53887;
N_RollRate_val = 20;
Ts_val = 0.01;
tau_act_val = 0.1;

syms Ts K_G Kp Ki Kd Nd z tau_act




G_p = K_G * (tau_act*(z-1)/(z-exp(-Ts/tau_act))   -  tau_act    +   Ts/(z-1) );
pretty(G_p)



Cz = Kp + Kd * (Nd*z - Nd)/(z + Nd*Ts - 1) + Ki * Ts/(z-1);


T = (Cz*G_p) / (1 + Cz*G_p);

T = collect(simplify(T));

T_val = subs(T, [Ts, K_G, Kp, Ki, Kd, Nd, tau_act], [Ts_val, Kg_val, Kp_RollRate_val, Ki_RollRate_val, Kd_RollRate_val, N_RollRate_val, tau_act_val]);

simplify(T_val)


[num_sym, den_sym] = numden(T_val);


% 2) Turn them into vectors of coefficients
num_coeffs = sym2poly(num_sym);
den_coeffs = sym2poly(den_sym);
% 3) Convert to doubles (in case they're still symbolic)
num_coeffs = double(num_coeffs);
den_coeffs = double(den_coeffs);

% 4) Build the discrete‑time TF
Tf_auto = tf(num_coeffs, den_coeffs, Ts_val);

% 5) (Optional) simplify & compare
Tf_auto = minreal(Tf_auto);
pole(Tf_auto)

figure(11)
step(Tf_auto)
grid on
hold on



