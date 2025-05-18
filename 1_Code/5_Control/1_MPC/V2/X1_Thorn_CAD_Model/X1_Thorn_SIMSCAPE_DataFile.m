% Simscape(TM) Multibody(TM) version: 7.6

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(5).translation = [0.0 0.0 0.0];
smiData.RigidTransform(5).angle = 0.0;
smiData.RigidTransform(5).axis = [0.0 0.0 0.0];
smiData.RigidTransform(5).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [-85 114.5 0];  % mm
smiData.RigidTransform(1).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(1).axis = [-0.57735026918962562 -0.57735026918962573 -0.57735026918962573];
smiData.RigidTransform(1).ID = "B[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [40 37.5 0];  % mm
smiData.RigidTransform(2).angle = 2.0943951023931957;  % rad
smiData.RigidTransform(2).axis = [-0.57735026918962584 -0.57735026918962573 -0.57735026918962573];
smiData.RigidTransform(2).ID = "F[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [-85 -114.49999999999999 0];  % mm
smiData.RigidTransform(3).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(3).axis = [0.57735026918962584 -0.57735026918962584 0.57735026918962584];
smiData.RigidTransform(3).ID = "B[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [40 37.499999999999972 6.3917109909319087e-15];  % mm
smiData.RigidTransform(4).angle = 2.0943951023931953;  % rad
smiData.RigidTransform(4).axis = [-0.57735026918962584 -0.57735026918962584 -0.57735026918962584];
smiData.RigidTransform(4).ID = "F[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [0 0 0];  % mm
smiData.RigidTransform(5).angle = 0;  % rad
smiData.RigidTransform(5).axis = [0 0 0];
smiData.RigidTransform(5).ID = "RootGround[X1_THORN_BODY_SIMSCAPE-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(2).mass = 0.0;
smiData.Solid(2).CoM = [0.0 0.0 0.0];
smiData.Solid(2).MoI = [0.0 0.0 0.0];
smiData.Solid(2).PoI = [0.0 0.0 0.0];
smiData.Solid(2).color = [0.0 0.0 0.0];
smiData.Solid(2).opacity = 0.0;
smiData.Solid(2).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 1.0151337566488243;  % kg
smiData.Solid(1).CoM = [25.334257237086589 2.6482763339147435 0.96030703929951611];  % mm
smiData.Solid(1).MoI = [2446.8739526175837 4469.6605301477566 6433.2365600936264];  % kg*mm^2
smiData.Solid(1).PoI = [0.81903289426382597 -33.062087932967835 -49.783355214482036];  % kg*mm^2
smiData.Solid(1).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "X1_THORN_BODY_SIMSCAPE*:*Predeterminado";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.016896419138389334;  % kg
smiData.Solid(2).CoM = [19.313533425038983 0.1180215935748644 -0.00025138130875922935];  % mm
smiData.Solid(2).MoI = [16.028911339204022 7.2207591842822891 12.37225335211342];  % kg*mm^2
smiData.Solid(2).PoI = [0.00029596395782855464 6.3597160360141718e-05 -0.041347669279507185];  % kg*mm^2
smiData.Solid(2).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "#P_PWR_Nozzle*:*Predeterminado";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = 2.1097413007245635e-14;  % deg
smiData.RevoluteJoint(1).ID = "[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-1]";

smiData.RevoluteJoint(2).Rz.Pos = -179.99999999999997;  % deg
smiData.RevoluteJoint(2).ID = "[X1_THORN_BODY_SIMSCAPE-1:-:#P_PWR_Nozzle-2]";

