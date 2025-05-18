% clear 
close all

q0 = cos(-pi/4);
q1 = 0;
q2 = sin(-pi/4);
q3 = 0;

% q0 = q_ref(1); 
% q1 = q_ref(2); 
% q2 = q_ref(3);
% q3 = q_ref(4);

pitch = 0.3;
roll = 0;
p = 1;


vec_x_Aircraft = [1-2*(q2^2+q3^2); 2*(q1*q2 + q0*q3); 2*(q1*q3 - q0*q2)];
vec_y_Aircraft = [2*(q1*q2 - q0*q3); 1 - 2*(q1^2 + q3^2); 2*(q2*q3 + q0*q1)];
vec_z_Aircraft = [2*(q1*q3 + q0*q2); 2*(q2*q3 - q0*q1); 1-2*(q1^2+q2^2)];


vec_x_World = [0;0;1];
vec_z_World = cross(vec_x_World,vec_y_Aircraft);
vec_y_World = cross(vec_z_World,vec_x_World);


%% 3) Build base rotation matrix R0 = [x_w, y_w, z_w]
R0 = [vec_x_World, vec_y_World, vec_z_World];

%% 4) Build small rotations about world-frame X then Y
Rx = [ 1,         0,          0;
       0, cos(-roll), -sin(-roll);
       0, sin(-roll),  cos(-roll)];
   
Ry = [ cos(pitch), 0, sin(pitch);
             0, 1,       0;
      -sin(pitch), 0, cos(pitch)];

Rz = [cos(p/2), -sin(p/2), 0;
      sin(p/2), cos(p/2),  0;
      0,      0,      1];

% Composite: first roll (Rx), then pitch (Ry) in the *world frame*
R_ref = Rz * R0 * Ry * Rx;

% Extract reference axes
x_ref = R_ref(:,1);
y_ref = R_ref(:,2);
z_ref = R_ref(:,3);

%% 5) Convert R_ref into quaternion [q0_ref q1_ref q2_ref q3_ref]
% Using MATLAB Aerospace Toolbox function rotm2quat
q_ref = rotm2quat(R_ref)  % returns [w x y z]
q_ref_unactive = rotm2quat(R0)

%% 6) Plot everything
figure; hold on; axis equal; grid on;
xlabel('X'); ylabel('Y'); zlabel('Z');
view(30,20);

scale = 0.5;  % arrow length

% Body frame (solid lines)
quiver3(0,0,0, vec_x_Aircraft(1), vec_x_Aircraft(2), vec_x_Aircraft(3), scale, ...
    'Color','r','LineWidth',2,'MaxHeadSize',0.5);
quiver3(0,0,0, vec_y_Aircraft(1), vec_y_Aircraft(2), vec_y_Aircraft(3), scale, ...
    'Color','g','LineWidth',2,'MaxHeadSize',0.5);
quiver3(0,0,0, vec_z_Aircraft(1), vec_z_Aircraft(2), vec_z_Aircraft(3), scale, ...
    'Color','b','LineWidth',2,'MaxHeadSize',0.5);

% World-yaw frame (dashed)
quiver3(0,0,0, vec_x_World(1), vec_x_World(2), vec_x_World(3), scale, ...
    'Color','r','LineStyle','--','LineWidth',1.5);
quiver3(0,0,0, vec_y_World(1), vec_y_World(2), vec_y_World(3), scale, ...
    'Color','g','LineStyle','--','LineWidth',1.5);
quiver3(0,0,0, vec_z_World(1), vec_z_World(2), vec_z_World(3), scale, ...
    'Color','b','LineStyle','--','LineWidth',1.5);

% Reference frame (thinner solid)
quiver3(0,0,0, x_ref(1), x_ref(2), x_ref(3), scale, ...
    'Color','r','LineWidth',1,'MaxHeadSize',0.5);
quiver3(0,0,0, y_ref(1), y_ref(2), y_ref(3), scale, ...
    'Color','g','LineWidth',1,'MaxHeadSize',0.5);
quiver3(0,0,0, z_ref(1), z_ref(2), z_ref(3), scale, ...
    'Color','b','LineWidth',1,'MaxHeadSize',0.5);

legend('body-X','body-Y','body-Z', ...
       'world-X','world-Y','world-Z', ...
       'ref-X','ref-Y','ref-Z', 'Location','best');

title('Frames: Body (solid bold), World-yaw (dashed), Reference (thin)');