clc
clear variables
clear figures

terms = 1;
maxterm = 12; % The amount of terms computed by the Taylor series
maxdiffs = zeros(1, maxterm);

x = -7:.02:7; % Range of computation

% Iterate through the number of terms to be used by series
while terms < maxterm + 1
    outputs = zeros(1, 10/.02); % Output of taylorcos
    tests = zeros(1, 10/.02); % Output of cos
    diff = zeros(1, 10/.02); % Their difference

    counter = 1;
    for i = x
        outputs(counter) = taylorcos(i, terms);
        tests(counter) = cos(i);
        diff(counter) = outputs(counter) - tests(counter);
    
        counter = counter + 1;
    end
    
    maxdiffs(terms) = max(abs(diff));
    terms = terms + 1;
end

tiledlayout(2,1)

% Plot the error by number of terms
nexttile
plot(1:maxterm, maxdiffs, "-|");
title('Error by number of terms')
xlabel('Terms computed by Taylor Series')
ylabel('Maximum difference')
set(gca, 'YScale', 'log')
xlim([1 maxterm])

% Plot the function taylorcos
nexttile
plot(x, outputs, "-");
title('Output of taylorcos(x)')
xlabel('x')
ylabel('taylorcos(x)')
xlim([min(x) max(x)])


