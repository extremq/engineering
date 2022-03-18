function [y] = taylorcos(x, terms)
    % The cos function has a periodicity of 2 * pi
    % Also, the cos function is an even function
    x0 = abs(mod(x, 2 * pi));
    coef = 1;
    % First reflection
    if x0 > pi
        x0 = 2 * pi - x0;
    end
    % Second reflection
    if x0 > pi / 2
        coef = -1;
        x0 = pi - x0;
    end
    y = 0;
    % Last optimization
    if x0 > pi / 4
        x0 = pi / 2 - x0;
        % Sine
        for i = 0:terms
            y = y + (-1) ^ i * x0 ^ (2 * i + 1) / factorial(2 * i + 1);
        end
    else
        % Cosine
        for i = 0:terms
            y = y + (-1) ^ i * x0 ^ (2 * i) / factorial(2 * i);
        end
    end
    % In case we reflected the second time
    y = coef * y;
end
