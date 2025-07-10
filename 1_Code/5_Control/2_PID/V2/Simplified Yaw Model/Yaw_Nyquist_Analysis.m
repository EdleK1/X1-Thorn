clear;
close all;
clc;

% --- Fixed parameters
Kp_val   = 150;
Ki_val   = -90;
Kd_val   = -70;
Kq_val   = 0.05;
K_G_val  = -0.22365;
Nd_val   = 20;
Ts_val = 0.01;


% [points_s, points_z] = nyquist_func(Ts_val, K_G_val, Kq_val, Kp_val, Ki_val, Kd_val, Nd_val);




% PID = Kd*s + Kp + Ki/s;
% L1 = PID * K_G * 1/s;
% L2 = L1/(1+L1*K_q);
% Tf_Final_s = L2 * 1/s;

PID = tf([Kd_val, 0],1) + tf(Kp_val,1) + tf(Ki_val,[1,0]);
L1 = PID * K_G_val * tf(1,[1,0]);
L2 = L1/(1+L1*Kq_val);
Tf_Final_s = L2 * tf(1,[1,0]);

minreal(Tf_Final_s)

nyquist(minreal(Tf_Final_s))
axis equal
 
% figure;
% plot(real(points_z), imag(points_z), 'b-', 'LineWidth',1.5);
% hold on; grid on; axis equal;
% 
% % draw real and imaginary axes
% xline(0, 'k--', 'LineWidth',1);
% yline(0, 'k--', 'LineWidth',1);
% 
% % mark the -1 point
% plot(-1, 0, 'ro', 'MarkerSize',8, 'LineWidth',2);
% 
% % optional: add an arrow showing increasing ω
% midIdx = round(length(points_z)/2);
% dx = real(points_z(midIdx+1)) - real(points_z(midIdx));
% dy = imag(points_z(midIdx+1)) - imag(points_z(midIdx));
% quiver(real(points_z(midIdx)), imag(points_z(midIdx)), dx, dy, 0, ...
%        'MaxHeadSize',0.5, 'Color','b');
% 
% xlabel('Re\{L(e^{j\omega T_s})\}'); 
% ylabel('Im\{L(e^{j\omega T_s})\}');
% title('Discrete‑Time Nyquist (ω≥0 only)');
% legend('L(e^{jωT_s})','Axes','-1','Location','Best');
% 
% %% Continuous‐time version
% 
% figure;
% plot(real(points_s), imag(points_s), 'r-', 'LineWidth', 1.5);
% hold on; grid on; axis equal;
% plot(real(conj(points_s(2:end-1))), imag(conj(points_s(2:end-1))), 'r-', 'LineWidth', 1.5);
% 
% xline(0, 'k--', 'LineWidth',1);
% yline(0, 'k--', 'LineWidth',1);
% plot(-1, 0, 'ro', 'MarkerSize',8, 'LineWidth',2);  % usually you mark -1+0j for both
% 
% xlabel('Re\{L(j\omega)\}'); 
% ylabel('Im\{L(j\omega)\}');
% title('Continuous‑time Nyquist Plot');
% legend('ω ≥ 0','ω < 0','Axes','-1','Location','Best');