% --- read and prepare data (keep as you had) ---
data = readmatrix("test_stand_results_step_1400pwm_11_78V.csv");
data(:,2) = data(:,2) - data(1,2);

rpm    = data(:,1);
time   = data(:,2);
signal = data(:,3);

% --- figure with improved styling ---
fig = figure('Units','centimeters','Position',[2 2 20 10]); % wider figure
tiledlayout(1,1,'Padding','compact','TileSpacing','compact');

ax = axes(fig); hold(ax,'on');

% Use yyaxis but get handles to each plotted line
yyaxis left
h1 = plot(time, rpm, '-','LineWidth',2.5,'Marker','none', ...
    'Color',[0 0.4470 0.7410]);            % MATLAB blue (solid)

ylabel('\textbf{RPM}','Interpreter','latex','FontSize',16)

yyaxis right
h2 = plot(time, signal, '--','LineWidth',2.2,'Marker','o','MarkerSize',4, ...
    'Color',[0.8500 0.3250 0.0980]);      % MATLAB orange (dashed + markers)

ylabel('\textbf{Signal}','Interpreter','latex','FontSize',16)

% Axis labels and title (LaTeX + font sizes)
xlabel('\textbf{Time (s)}','Interpreter','latex','FontSize',16)
title('\textbf{RPM and Signal vs Time}','Interpreter','latex','FontSize',20)

% Axis appearance (tick labels use LaTeX interpreter and set font size)
ax = gca;
ax.YAxis(1).FontSize = 16;    % left y-axis tick font size
ax.YAxis(2).FontSize = 16;    % right y-axis tick font size
ax.XAxis.FontSize      = 16;  % x-axis tick font size
ax.TickLabelInterpreter = 'latex';

grid on
box on

% Legend: use LaTeX and place it so it doesn't overlap the curves
lg = legend([h1,h2],{'RPM','Signal'},'Interpreter','latex','FontSize',14,'Location','northwest');
lg.Box = 'off';

% Improve contrast and visibility for presentations
set(fig,'Color','w');    % white background for exports
set(gca,'LineWidth',1);