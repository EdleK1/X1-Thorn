function results = PID_Pitch_Evaluation_func(MPar)

X1_Thorn_SIMSCAPE_DataFile
Ts = 0.005;

Kp_PitchRate1 = MPar(1);
Ki_PitchRate1 = MPar(2);
Kd_PitchRate1 = MPar(3);
N_PitchRate1 = MPar(4);


data = sim('Simulink_Simulation.slx');

time = data.tout;
error = data.q_error_data.signals.values;

results.overshoot = -min(error)/0.2;
sign_change_idx = find(error(1011:end-1) .* error(1012:end) < 0, 1, 'first') + 1010;

if ~isempty(sign_change_idx)
    t1 = time(sign_change_idx);
    t2 = time(sign_change_idx + 1);
    e1 = error(sign_change_idx);
    e2 = error(sign_change_idx + 1);

    results.zero_cross_time = t1 - e1 * (t2 - t1) / (e2 - e1) - 0.5;  % linear interpolation and take into account step time
else
    results.zero_cross_time = 9999;  % No zero crossing found
end

results.RMS = rms(error);
results.error = error;
results.time = time;

end