% Example: 
% >> x = 1:.1:10
% >> y = exp(x)
% >> simpson(x, y)
% ans =
%   2.2024e+04
% Check with the integral of e^x which is e^x.
% >> exp(10) - exp(1)
% ans =
%   2.2024e+04

function [area] = simpson(x, y)
    n = length(x); % Number of points
    coef = (x(2) - x(1)) / 3; % The dx/3 coefficient

    % area of f(x) from x(1) to x(n) =
    % coef * [f(x(1)) + 4 * f(x(2)) + 2 * f(x(3)) + 4 * f(x(4)) + ... + 
    % + 4 * f(x(n - 1)) + f(x(n))]
    area = y(1); 

    by4 = 1;
    for i = 2 : n - 1
        if by4 == 1 % Do we multiply by 4?
            area = area + 4 * y(i);
        else % No, then by 2
            area = area + 2 * y(i);
        end

        % Oscillate by4 between 0 and 1
        by4 = 1 - by4;
    end
    
    area = area + y(n);
    area = coef * area; % We are done
end