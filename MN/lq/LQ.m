function [L, Q] = LQ(A)
    A = A';
    [Q, R] = qr(A);
    Q = Q';
    L = R';
end