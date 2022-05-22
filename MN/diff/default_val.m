function [ret] = default_val(x, default)
    if isempty(x)
        ret = default;
    else
        ret = x;
    end
end