clear

Kp_PitchRate_val = 15;
Ki_PitchRate_val = 7;
Kd_PitchRate_val = 1;
Kq_val = 2;
Kg_val = 0.4956;
tau_act_val = 0.1;

%% Symbolic Analysis

syms Kd Ki Kp s Kq tau_act


PID = s*Kd + Kp + Ki/s;
G = Kg_val * 1/(tau_act*s + 1);

L1 = PID * G * 1/s;
L2 = L1/(1+L1);
Tf_Final_qdot = Kq*L2*1/s/(1+Kq*L2*1/s);
Tf_Final_qdot = simplify(Tf_Final_qdot);
Tf_Final_qdot = collect(Tf_Final_qdot, s)


%% Continuous time Analysis

G = Kg_val * tf(1, [tau_act_val, 1]);
PID = tf([Kd_PitchRate_val, 0],1) + tf(Kp_PitchRate_val,1) + tf(Ki_PitchRate_val,[1,0]);
L1 = PID * G * tf(1,[1,0]);
L2 = L1/(1+L1);
Tf_Final_val = (Kq_val*L2*tf(1,[1,0]))/(1 + Kq_val*L2*tf(1,[1,0]));
Tf_Final_val = minreal(Tf_Final_val)

poles = pole(Tf_Final_val)
zeros = zero(Tf_Final_val)

figure(10);
step(Tf_Final_val);
grid on
hold on

%% Discrete time Analysis:

clear

Kp_PitchRate_val = 15;  % 20
Ki_PitchRate_val = 7;   % 7
Kd_PitchRate_val = 1;   % 2
Kq_val = 2;             % 4

Kg_val = 0.4956;
N_PitchRate_val = 20;
Ts_val = 0.01;
tau_act_val = 0.1;

%
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


T = (K_q * G_theta * Cz) / (1 + Cz*(K_q * G_theta + G_q));

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

S = stepinfo(Tf_auto, 'RiseTimeLimits', [0 0.95], 'SettlingTimeThreshold', 0.02);
rise_time  = S.RiseTime;        % time to reach 95% (because we set RiseTimeLimits [0 0.95])
settle_time = S.SettlingTime;   % settling time (2% band)
overshoot_percent = S.Overshoot; % overshoot in percent

fprintf('Rise time (to 95%%): %.4g s\n', rise_time);
fprintf('Settling time (2%%): %.4g s\n', settle_time);
fprintf('Overshoot: %.2f %%\n', overshoot_percent);


