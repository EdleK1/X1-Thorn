function [zeros_z, poles_z, zeros_s, poles_s] = root_locus_func(Ts_val, K_G_val, K_q_val, Kp_val, Ki_val, Kd_val, Nd_val, tau_act_val)


syms Ts K_G K_q Kp Ki Kd Nd z tau_act



G_theta = K_G * (tau_act^2  +  Ts^2/2*(z+1)/((z-1)^2)  -  Ts*tau_act/(z-1)  -  tau_act^2*(z-1)/(z-exp(-Ts/tau_act)) );


G_q = K_G * (tau_act*(z-1)/(z-exp(-Ts/tau_act))   -  tau_act    +   Ts/(z-1) );


Cz = Kp + Kd * (Nd*z - Nd)/(z + Nd*Ts - 1) + Ki * Ts/(z-1);


T = (G_theta * Cz) / (1 + Cz*(G_theta + K_q*G_q));

T = collect(simplify(T));

T_val = subs(T, [Ts, K_G, K_q, Kp, Ki, Kd, Nd, tau_act], [Ts_val, K_G_val, K_q_val, Kp_val, Ki_val, Kd_val, Nd_val, tau_act_val]);


[num_sym, den_sym] = numden(simplify(T_val));


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
poles_z = pole(Tf_auto);
zeros_z = zero(Tf_auto);



%% Continuous part

syms s

PID = s*Kd + Kp + Ki/s;
Gs = K_G * 1/(tau_act*s + 1);

L1 = PID * Gs * 1/s;
L2 = L1/(1+L1*K_q);
Tfs = L2*1/s/(1+L2*1/s);

Tfs = collect(simplify(Tfs));

Tfs_val = subs(Tfs, [K_G, K_q, Kp, Ki, Kd, tau_act], [K_G_val, K_q_val, Kp_val, Ki_val, Kd_val, tau_act_val]);


[num_sym, den_sym] = numden(simplify(Tfs_val));


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
poles_s = pole(Tf_auto);
zeros_s = zero(Tf_auto);




% 
% Gs = K_G_val * tf(1, [tau_act_val, 1]);
% 
% PID = tf([Kd_val, 0],1) + tf(Kp_val,1) + tf(Ki_val,[1,0]);
% L1 = PID * Gs * tf(1,[1,0]);
% L2 = L1/(1+L1*K_q_val);
% Tf_Final_val = (L2*tf(1,[1,0]))/(1+L2*tf(1,[1,0]));
% Tf_Final_val = minreal(Tf_Final_val);
% 
% 
% zeros_s = zero(Tf_Final_val);
% poles_s = pole(Tf_Final_val);