function [y] = estimatetaylorerr(x, terms)
    x0 = abs(mod(x, 2 * pi));
    coef = 1;

    if x0 > pi
        x0 = 2 * pi - x0;
    end

    if x0 > pi / 2
        coef = -1;
        x0 = pi - x0;
    end

    y = zeros(1, terms);
    cnt = 1;
    while cnt < terms
        y(cnt) = 0;
        for i = 0:terms
            y(cnt) = y(cnt) + (-1) ^ i * x0 ^ (2 * i) / factorial(2 * i);
        end
        
        y(cnt) = coef * y(cnt);
    end
end