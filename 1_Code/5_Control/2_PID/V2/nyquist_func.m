function [points_s, points_z] = nyquist_func(Ts_val, K_G_val, Kq_val, Kp_val, Ki_val, Kd_val, Nd_val)



syms Ts K_G K_q Kp Ki Kd Nd z s


L_theta = K_G * Ts^2/2 * (z+1)/(z-1)^2;
L_q = K_G * Ts/(z-1);

Cz = Kp + Kd * (Nd*z - Nd)/(z + Nd*Ts - 1) + Ki * Ts/(z-1);


T = (L_theta * Cz) / (1 + Cz*K_q*L_q );

T = collect(simplify(T));

Tf_Final_z_val = subs(T, [Ts, K_G, K_q, Kp, Ki, Kd, Nd], [Ts_val, K_G_val, Kq_val, Kp_val, Ki_val, Kd_val, Nd_val]);

collect(simplify(Tf_Final_z_val));

points_z = [];

for omega_val = 0.01*pi/Ts_val:0.01*pi/Ts_val:pi/Ts_val

    points_z = [points_z; double(subs(Tf_Final_z_val, z, exp(1i*omega_val*Ts_val)))] ;

end




PID = Kd*s + Kp + Ki/s;
L1 = PID * K_G * 1/s;
L2 = L1/(1+L1*K_q);
Tf_Final_s = L2 * 1/s;

Tf_Final_s_val = subs(Tf_Final_s, [K_G, K_q, Kp, Ki, Kd], [K_G_val, Kq_val, Kp_val, Ki_val, Kd_val]);

points_s = [];

for omega_val = exp([0.1:0.1:10])

    points_s = [points_s; double(subs(Tf_Final_s_val, s, 1i*omega_val)) ];

end

