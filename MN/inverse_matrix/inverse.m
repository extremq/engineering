function [inv_mat] = inverse(mat)
    % Firstly, the LU decomposition must be done. Doolittle's method will
    % be used.

    n = length(mat);
    L = eye(n);
    U = zeros(n);
    inv_mat = zeros(n);

    for i = 1 : n

        % Upper
        for j = i : n
            U(i, j) = mat(i, j);

            for k = 1 : i - 1
                U(i, j) = U(i, j) - L(i, k) * U(k, j);
            end
        end

        % Lower
        for j = i + 1 : n
            L(j, i) = mat(j, i);

            for k = 1 : i - 1
                L(j, i) = L(j, i)- L(j, k) * U(k, i);
            end
            
            L(j, i) = L(j, i) / U(i, i);
        end
    end

    % Since A * X = I has the solution X as A ^ -1, we're going to solve
    % n systems using A = L * U.
    for k = 1 : n
        I = eye(n);
        e_k = I(:, k);
        
        % Solving L * y_k = e_k
        y_k = zeros(n, 1);
        for i = 1 : n
            sum = 0;
            % L_ij * y_ij + L_ij+1 * y_ij+1 + ... = e_k
            % L_ij+h * y_ij+h = e_k - (L_ik * y_ij + ...)
            for j = 1 : i - 1
                sum = sum + L(i, j) * y_k(j);
            end
            
            % No need to divide, Doolittle's method returns a Lower that
            % has 1s on the diagonal.
            y_k(i) = e_k(i) - sum;
        end
           
        % Now that we have y_k, retrieve x_k
        % Solving U * x_k = y_k
        x_k = zeros(n, 1);
        for i = n : -1 : 1
            sum = 0;
            for j = n : -1 : i
                sum = sum + U(i, j) * x_k(j);
            end
            x_k(i) = (y_k(i) - sum) / U(i, j);
        end
        inv_mat(:, k) = x_k;
    end
end
