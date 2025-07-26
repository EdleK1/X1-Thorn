function [points_z, GM] = nyquist_func(Ts_val, K_G_val, Kq_val, Kp_val, Ki_val, Kd_val, Nd_val, tau_act_val)



syms Ts K_G K_q Kp Ki Kd Nd z s tau_act


G_theta = K_G * (tau_act^2  +  Ts^2/2*(z+1)/((z-1)^2)  -  Ts*tau_act/(z-1)  -  tau_act^2*(z-1)/(z-exp(-Ts/tau_act)) );


G_q = K_G * (tau_act*(z-1)/(z-exp(-Ts/tau_act))   -  tau_act    +   Ts/(z-1) );


Cz = Kp + Kd * (Nd*z - Nd)/(z + Nd*Ts - 1) + Ki * Ts/(z-1);


T = (K_q * G_theta * Cz) / (1 + Cz*G_q);

T = collect(simplify(T));

Tf_Final_z_val = subs(T, [Ts, K_G, K_q, Kp, Ki, Kd, Nd, tau_act], [Ts_val, K_G_val, Kq_val, Kp_val, Ki_val, Kd_val, Nd_val, tau_act_val]);

collect(simplify(Tf_Final_z_val));

points_z = [];

for omega_val = 0.01*pi/Ts_val:0.005*pi/Ts_val:pi/Ts_val

    points_z = [points_z; double(subs(Tf_Final_z_val, z, exp(1i*omega_val*Ts_val)))] ;

end



omega_vec = 0.01*pi/Ts_val:0.005*pi/Ts_val:pi/Ts_val;

% ---- compute gain margin ----
  ph = unwrap(angle(points_z));
%   find first crossing of -pi
  idx = find(ph <= -pi, 1, 'first');

  if ~isempty(idx) && idx > 1
%     linear interpolation between idx-1 and idx
    ph1 = ph(idx-1); ph2 = ph(idx);
    mag1 = abs(points_z(idx-1)); mag2 = abs(points_z(idx));
    w1   = omega_vec(idx-1); w2   = omega_vec(idx);

    alpha = ( -pi - ph1 ) / (ph2 - ph1);
    mag_pc = mag1 + alpha*(mag2 - mag1);

    GM    = 1/mag_pc;
  else
%     no phase crossover → infinite GM
    GM    = Inf;
  end

