%
% Copyright (c) The acados authors.
%
% This file is part of acados.
%
% The 2-Clause BSD License
%
% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
% 1. Redistributions of source code must retain the above copyright notice,
% this list of conditions and the following disclaimer.
%
% 2. Redistributions in binary form must reproduce the above copyright notice,
% this list of conditions and the following disclaimer in the documentation
% and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
% IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
% ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
% LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.;

%

classdef Aircraft_Attitude_mex_sim_solver < handle

    properties
        C_sim
        name
        code_gen_dir
    end % properties



    methods

        % constructor
        function obj = Aircraft_Attitude_mex_sim_solver()
            make_mex_sim_Aircraft_Attitude();
            obj.C_sim = acados_sim_create_Aircraft_Attitude();
            % to have path to destructor when changing directory
            addpath('.')
            obj.name = 'Aircraft_Attitude';
        end

        % set -- borrowed from MEX interface
        function set(obj, field, value)
            if ~isa(field, 'char')
                error('field must be a char vector, use '' ''');
            end
            acados_sim_set_Aircraft_Attitude(obj.C_sim, field, value);
        end

        % get -- borrowed from MEX interface
        function value = get(obj, field)
            if ~isa(field, 'char')
                error('field must be a char vector, use '' ''');
            end
            value = sim_get(obj.C_sim, field);
        end

        % solve
        function status = solve(obj)
            status = sim_solve(obj.C_sim);
        end

        % destructor
        function delete(obj)
            disp("delete template...");
            if ~isempty(obj.C_sim)
                acados_sim_free_Aircraft_Attitude(obj.C_sim);
            end
            disp("done.");
        end

    end % methods

end % class
