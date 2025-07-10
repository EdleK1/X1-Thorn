function txt = showParameterInDataTip(~, event)
    % event.Target is the scatter object
    h = event.Target;
    idx = event.DataIndex;       % which point in that scatter

    % Pull out the vectors we stored
    Parameter_vals    = h.UserData.Parameter_vals;
    trajValues = h.UserData.trajValues;

    % Now we can directly index
    Parameter  = Parameter_vals(idx);
    poleVal = trajValues(idx);

    txt = {['Paramter = ',    num2str(Parameter)], ['Pole = ',   num2str(poleVal)]};
    
end