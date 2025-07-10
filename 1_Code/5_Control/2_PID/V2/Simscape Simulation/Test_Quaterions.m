% --- Main test script ---
clc; % Clear command window
clearvars -except plotOrderGlobalCounter; % Clear variables except the one for interactive plot if used

% Define quaternions as [w, x, y, z]
dt = 0.01; % Example time step

disp('--- Example 1: Small rotation around Z-axis (yaw) ---');
% q_curr = identity
q_curr = [1.0, 0.0, 0.0, 0.0];
% q_ref = small yaw rotation (e.g., 0.02 rad around Z)
% angle = 0.02 rad, axis = [0,0,1]
% q_ref.w = cos(0.02/2) = cos(0.01)
% q_ref.z = sin(0.02/2) = sin(0.01)
angle_rad = 0.02;
q_ref = [cos(angle_rad/2), 0.0, 0.0, sin(angle_rad/2)];

disp('Method 1 (Based on user''s hinted derivation):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt1, q_dt1, r_dt1] = get_angular_rates_dt_from_quaternion_diff(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt1, q_dt1, r_dt1);
fprintf('Expected r_dt should be close to %.6f\n', angle_rad); % For small angles, this is approx true

disp(' ');
disp('Method 2 (Standard q_delta error quaternion):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt2, q_dt2, r_dt2] = get_angular_rates_dt_from_q_delta(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt2, q_dt2, r_dt2);
fprintf('Expected r_dt should be close to %.6f (actually 2*sin(angle/2))\n', angle_rad);


disp(' ');
disp('--- Example 2: More complex rotation ---');
% q_curr = 90 deg pitch
q_curr_angle_deg = 90;
q_curr_axis = [0, 1, 0]; % y-axis
q_curr_angle_rad = deg2rad(q_curr_angle_deg);
q_curr = [cos(q_curr_angle_rad/2), q_curr_axis(1)*sin(q_curr_angle_rad/2), q_curr_axis(2)*sin(q_curr_angle_rad/2), q_curr_axis(3)*sin(q_curr_angle_rad/2)]; % Should be [0.7071, 0, 0.7071, 0]

% q_ref: apply a small roll (e.g. 5 deg about x-axis) to q_curr
q_roll_angle_deg = 5;
q_roll_axis = [1,0,0];
q_roll_angle_rad = deg2rad(q_roll_angle_deg);
q_small_roll = [cos(q_roll_angle_rad/2), q_roll_axis(1)*sin(q_roll_angle_rad/2), q_roll_axis(2)*sin(q_roll_angle_rad/2), q_roll_axis(3)*sin(q_roll_angle_rad/2)];
q_ref = quat_multiply(q_small_roll, q_curr); % Apply roll in global frame sense, then rotate by q_curr
                                            % Or if roll is in body frame of q_curr: q_ref = quat_multiply(q_curr, q_small_roll_body_frame)

disp('Method 1 (Complex rotation):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt1, q_dt1, r_dt1] = get_angular_rates_dt_from_quaternion_diff(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt1, q_dt1, r_dt1);

disp(' ');
disp('Method 2 (Standard q_delta error quaternion):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt2, q_dt2, r_dt2] = get_angular_rates_dt_from_q_delta(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt2, q_dt2, r_dt2);



disp(' ');
disp('--- Example 3: 180 degree rotation (test limits) ---');
q_curr = [1.0, 0.0, 0.0, 0.0];
% q_ref = 180 deg about x-axis
angle_rad_180 = pi;
q_ref = [cos(angle_rad_180/2), sin(angle_rad_180/2), 0.0, 0.0]; % [0, 1, 0, 0]

disp('Method 1 (180 deg rotation):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt1, q_dt1, r_dt1] = get_angular_rates_dt_from_quaternion_diff(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt1, q_dt1, r_dt1);
fprintf('Assuming dt=%.4f: p = %.6f, q = %.6f, r = %.6f rad/s\n', dt, p_dt1/dt, q_dt1/dt, r_dt1/dt);
% Expected p_dt1 = 2

disp(' ');
disp('Method 2 (180 deg rotation):');
print_quaternion('q_curr', q_curr);
print_quaternion('q_ref', q_ref);
[p_dt2, q_dt2, r_dt2] = get_angular_rates_dt_from_q_delta(q_ref, q_curr);
fprintf('p*dt = %.6f, q*dt = %.6f, r*dt = %.6f\n', p_dt2, q_dt2, r_dt2);
fprintf('Assuming dt=%.4f: p = %.6f, q = %.6f, r = %.6f rad/s\n', dt, p_dt2/dt, q_dt2/dt, r_dt2/dt);
% Expected p_dt2 = 2*sin(pi/2) = 2
% The "angle" for the rates would be pi. The vector 2*vector_part(q_delta) has magnitude 2.
% So p = 2/dt in this case, not pi/dt if interpreting the output as omega_x * dt = angle_x directly.
% This output [2,0,0] is what's often used as error term in controllers.


% --- Quaternion Helper Functions ---

function q_conj = quat_conjugate(q)
    % q is a 1x4 vector [w, x, y, z]
    q_conj = [q(1), -q(2), -q(3), -q(4)];
end

function qr = quat_multiply(q1, q2)
    % q1, q2 are 1x4 vectors [w, x, y, z]
    w1 = q1(1); x1 = q1(2); y1 = q1(3); z1 = q1(4);
    w2 = q2(1); x2 = q2(2); y2 = q2(3); z2 = q2(4);

    qr = zeros(1, 4);
    qr(1) = w1*w2 - x1*x2 - y1*y2 - z1*z2; % w
    qr(2) = w1*x2 + x1*w2 + y1*z2 - z1*y2; % x
    qr(3) = w1*y2 - x1*z2 + y1*w2 + z1*x2; % y
    qr(4) = w1*z2 + x1*y2 - y1*x2 + z1*w2; % z
end

function qr = quat_subtract(q1, q2)
    % q1, q2 are 1x4 vectors [w, x, y, z]
    qr = q1 - q2;
end

function print_quaternion(name, q)
    fprintf('%s: w=%.4f, x=%.4f, y=%.4f, z=%.4f\n', name, q(1), q(2), q(3), q(4));
end

% --- Method 1: Based on user's hinted derivation ---
% (q_dot approx (q_ref - q_curr)/dt leads to [p*dt, q*dt, r*dt]' = 2 * vector_part(conjugate(q_curr) * (q_ref - q_curr)))
function [p_dt, q_dt, r_dt] = get_angular_rates_dt_from_quaternion_diff(q_ref, q_curr)
    % q_ref, q_curr are 1x4 vectors [w, x, y, z]

    % 1. Calculate dq = q_ref - q_curr
    dq = quat_subtract(q_ref, q_curr);

    % 2. Get conjugate of q_curr
    q_curr_conj = quat_conjugate(q_curr);

    % 3. Calculate temp_q = conjugate(q_curr) * dq
    temp_q = quat_multiply(q_curr_conj, dq);

    % 4. The angular rates (times dt) are 2 * vector_part(temp_q)
    p_dt = 2.0 * temp_q(2); % x component
    q_dt = 2.0 * temp_q(3); % y component
    r_dt = 2.0 * temp_q(4); % z component
end

% --- Method 2: Standard q_delta error quaternion ---
% (q_delta = q_ref * conjugate(q_curr), then [p*dt, q*dt, r*dt]' approx 2 * vector_part(q_delta))
function [p_dt, q_dt, r_dt] = get_angular_rates_dt_from_q_delta(q_ref, q_curr)
    % q_ref, q_curr are 1x4 vectors [w, x, y, z]

    % 1. Get conjugate of q_curr
    q_curr_conj = quat_conjugate(q_curr);

    % 2. Calculate q_delta = q_ref * conjugate(q_curr)
    q_delta = quat_multiply(q_ref, q_curr_conj);

    % 3. Ensure shortest path rotation (q_delta.w should be positive)
    if q_delta(1) < 0.0
        q_delta = -q_delta; % Flip all components
    end

    % 4. The angular rates (times dt) are approximately 2 * vector_part(q_delta)
    p_dt = 2.0 * q_delta(2); % x component
    q_dt = 2.0 * q_delta(3); % y component
    r_dt = 2.0 * q_delta(4); % z component
end
