% y' = (sin(25y) + cos(0.1x) - 3y) / 2

% Initial values and step
disp('Press enter for default values (x0 = 0, y0 = 0, dx = .001, stop = 100)')
x0 = input('x0 = ');
x0 = default_val(x0, 0);

y0 = input('y0 = ');
y0 = default_val(y0, 0);

start = x0;
stop = input('stop = ');
stop = default_val(stop, x0 + 100);

dx = input('dx = ');
dx = default_val(dx, .001);

% Aproximating with the second order taylor polynomial
% You may wonder why would anyone do this. The answer is: I was told to do
% so. Please, never do such a thing again.
% (Second order means up to x^2. The sine doesn't even have such term)
my_sin = @(x) x;  
my_cos = @(x) 1 - 1 / 2 * x ^ 2;  

% Function returns the derivative of y
func = @(x, y) (my_sin(mod(25 * y, 2 * pi)) + my_cos(mod(.1 * x, 2 * pi)) - 3 * y) / 2;
func_correct = @(x, y) (sin(25 * y) + cos(.1 * x) - 3 * y) / 2;
n = (stop - start) / dx + 1;

% Plotting variables
x_plot = x0:dx:stop;
y_plot = zeros(1, n);
y_plot_correct = zeros(1, n);

% Don't forget to init the first member as we start from 2
y_plot(1) = y0;

iter = 2;
while iter <= n
    % From the limit of the derivative
    y_plot(iter) = dx * func(x_plot(iter - 1), y_plot(iter - 1)) + y_plot(iter - 1);
    y_plot_correct(iter) = dx * func_correct(x_plot(iter - 1), ...
        y_plot_correct(iter - 1)) + y_plot_correct(iter - 1);

    iter = iter + 1;
end

% Now we plot
tiledlayout(2,1)

nexttile
plot(x_plot, y_plot);
title(['Weird function with initial values x0 = ', num2str(x0), ' and y0 = ', num2str(y0)])
xlabel('x')
ylabel('y(x)')

nexttile
plot(x_plot, y_plot_correct);
title(['Correct function with initial values x0 = ', num2str(x0), ' and y0 = ', num2str(y0)])
xlabel('x')
ylabel('y(x)')