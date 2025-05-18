close all


%% Load Results

yref = [2; 2; 2; 1; 0; 0; cos(-pi/4); 0; sin(-pi/4); 0; 0; 0; 0; 0];
yref_e = yref(1:10);

results = sim('Simulink_Simulation.slx');

U_sim = results.U.signals.values(:);
V_sim = results.V.signals.values(:);
W_sim = results.W.signals.values(:);

p_sim = results.p.signals.values(:);
q_sim = results.q.signals.values(:);
r_sim = results.r.signals.values(:);

q0_sim = results.q0.signals.values(:);
q1_sim = results.q1.signals.values(:);
q2_sim = results.q2.signals.values(:);
q3_sim = results.q3.signals.values(:);

W_1_sim = results.W_1.signals.values(:);
W_2_sim = results.W_2.signals.values(:);
alfa_1_sim = results.alfa_1.signals.values(:);
alfa_2_sim = results.alfa_2.signals.values(:);

domega1_sim = results.W_1.signals.values(:);
domega2_sim = results.W_2.signals.values(:);
alfa_1_sim = results.alfa_1.signals.values(:);
alfa_2_sim = results.alfa_2.signals.values(:);

t_sim = results.tout;
yref_repeated = repmat(yref(1:6)', length(t_sim), 1);

%% Metrics

SSE_U = sum((U_sim - yref(1)).^2);
SSE_V = sum((V_sim - yref(2)).^2);
SSE_W = sum((W_sim - yref(3)).^2);
SSE_p = sum((p_sim - yref(4)).^2);
SSE_q = sum((q_sim - yref(5)).^2);
SSE_r = sum((r_sim - yref(6)).^2);

figure;
titles = {'U', 'V', 'W', 'p', 'q', 'r'};
data_sim = {U_sim, V_sim, W_sim, p_sim, q_sim, r_sim};


for i = 1:6
    subplot(2,3,i); % Create 3x2 subplots
    hold on;
    grid on;
    
    % Plot previous runs if they exist
    if exist(['prev_' titles{i}], 'var')
        plot(t_sim, eval(['prev_' titles{i}]), 'k--', 'LineWidth', 0.5);
    end
    
    % Plot current simulation
    plot(t_sim, data_sim{i}, 'LineWidth', 1);
    
    % Plot reference
    plot(t_sim, yref_repeated(:,i), '--', 'LineWidth', 1);
    
    title(['Response of ', titles{i}]);
    xlabel('Time (s)');
    ylabel(titles{i});
    legend('Previous Run', 'Current Sim', 'Reference');
    
    % Store current run for next iteration
    assignin('base', ['prev_' titles{i}], data_sim{i});
end

% Display tracking error metric
fprintf('Tracking Errors (Sum of Squared Errors):\n');
fprintf('SSE_U: %.4f\n', SSE_U);
fprintf('SSE_V: %.4f\n', SSE_V);
fprintf('SSE_W: %.4f\n', SSE_W);
fprintf('SSE_p: %.4f\n', SSE_p);
fprintf('SSE_q: %.4f\n', SSE_q);
fprintf('SSE_r: %.4f\n', SSE_r);



figure;
titles = {'omega1', 'omega2', 'alfa1', 'alfa2'};
data_sim = {W_1_sim, W_2_sim, alfa_1_sim, alfa_2_sim};


for i = 1:4
    subplot(2,2,i); % Create 3x2 subplots
    hold on;
    grid on;
    
    % Plot previous runs if they exist
    if exist(['prev_' titles{i}], 'var')
        plot(t_sim, eval(['prev_' titles{i}]), 'k--', 'LineWidth', 0.5);
    end
    
    % Plot current simulation
    plot(t_sim, data_sim{i}, 'LineWidth', 1);
    
    % Plot reference
    plot(t_sim, yref_repeated(:,i), '--', 'LineWidth', 1);
    
    title(['Response of ', titles{i}]);
    xlabel('Time (s)');
    ylabel(titles{i});
    legend('Previous Run', 'Current Sim', 'Reference');
    
    % Store current run for next iteration
    assignin('base', ['prev_' titles{i}], data_sim{i});
end



figure;
titles = {'d_omega1', 'd_omega2', 'd_alfa1', 'd_alfa2'};
data_sim = {W_1_sim, W_2_sim, alfa_1_sim, alfa_2_sim};


for i = 1:4
    subplot(2,2,i); % Create 3x2 subplots
    hold on;
    grid on;
    
    % Plot previous runs if they exist
    if exist(['prev_' titles{i}], 'var')
        plot(t_sim, eval(['prev_' titles{i}]), 'k--', 'LineWidth', 0.5);
    end
    
    % Plot current simulation
    plot(t_sim, data_sim{i}, 'LineWidth', 1);
    
    % Plot reference
    plot(t_sim, yref_repeated(:,i), '--', 'LineWidth', 1);
    
    title(['Response of ', titles{i}]);
    xlabel('Time (s)');
    ylabel(titles{i});
    legend('Previous Run', 'Current Sim', 'Reference');
    
    % Store current run for next iteration
    assignin('base', ['prev_' titles{i}], data_sim{i});
end