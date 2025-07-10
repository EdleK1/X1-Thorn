function new_roots_vec = root_locus_plot_func(roots_vec)

% roots_vec = poles_z_vec;


new_roots_vec = zeros(size(roots_vec));
new_roots_vec(1,:) = roots_vec(1,:);

for ind_i = 2:size(roots_vec,1)

    vec_perm = perms(roots_vec(ind_i,:));

    norm_min = 9999999;

    for ind_j = 1:size(vec_perm,1)

        new_norm = norm(new_roots_vec(ind_i-1,:) - vec_perm(ind_j,:)  );

        if new_norm <= norm_min
            norm_min = new_norm;
            new_roots_vec(ind_i,:) = vec_perm(ind_j,:);
        end       
    end

end






