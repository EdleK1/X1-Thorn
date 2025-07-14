clear

Kp_PitchRate_val = -150;
Ki_PitchRate_val = -90;
Kd_PitchRate_val = -70;
Kq_val = 0.15;
Kg_val = -0.22365;
tau_act_val = 0.1;

%% Symbolic Analysis

syms Kd Ki Kp s Kq tau_act


PID = s*Kd + Kp + Ki/s;
G = Kg_val * 1/(tau_act*s + 1);

L1 = PID * G * 1/s;
L2 = L1/(1+L1*Kq);
Tf_Final_qdot = L2*1/s/(1+L2*1/s);
Tf_Final_qdot = simplify(Tf_Final_qdot);
Tf_Final_qdot = collect(Tf_Final_qdot, s)


%% Continuous time Analysis

G = Kg_val * tf(1, [tau_act_val, 1]);
PID = tf([Kd_PitchRate_val, 0],1) + tf(Kp_PitchRate_val,1) + tf(Ki_PitchRate_val,[1,0]);
L1 = PID * G * tf(1,[1,0]);
L2 = L1/(1+L1*Kq_val);
Tf_Final_val = (L2*tf(1,[1,0]))/(1+L2*tf(1,[1,0]));
Tf_Final_val = minreal(Tf_Final_val)

poles = pole(Tf_Final_val)
zeros = zero(Tf_Final_val)

figure(10);
step(Tf_Final_val);
grid on
hold on

%% Discrete time Analysis:

clear

Kp_PitchRate_val = -400;
Ki_PitchRate_val = -80;
Kd_PitchRate_val = -50;
Kq_val = -200;

Kg_val = -0.22365;
N_PitchRate_val = 20;
Ts_val = 0.01;
tau_act_val = 0.1;

%%
% syms tau Ts s
% G_theta_s = (1/tau)/(s + 1/tau) * 1/s^3;
% partfrac(G_theta_s,s)
% G_q_s = (1/tau)/(s + 1/tau) * 1/s^2;
% partfrac(G_q_s,s)



syms Ts K_G K_q Kp Ki Kd Nd z tau_act

G_theta = K_G * (tau_act^2  +  Ts^2/2*(z+1)/((z-1)^2)  -  Ts*tau_act/(z-1)  -  tau_act^2*(z-1)/(z-exp(-Ts/tau_act)) );
pretty(G_theta)

G_q = K_G * (tau_act*(z-1)/(z-exp(-Ts/tau_act))   -  tau_act    +   Ts/(z-1) );
pretty(G_q)


 
Cz = Kp + Kd * (Nd*z - Nd)/(z + Nd*Ts - 1) + Ki * Ts/(z-1);


T = (G_theta * Cz) / (1 + Cz*(G_theta + K_q*G_q));

T = collect(simplify(T));

T_val = subs(T, [Ts, K_G, K_q, Kp, Ki, Kd, Nd, tau_act], [Ts_val, Kg_val, Kq_val, Kp_PitchRate_val, Ki_PitchRate_val, Kd_PitchRate_val, N_PitchRate_val, tau_act_val]);

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



