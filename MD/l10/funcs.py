import numpy as np

def read_matrix(n):
    A = np.zeros((n, n))
    A = A.astype(int)
    
    for i in range(n):
        for j in range(n):
            A[i][j] = int(input(f"[{i}][{j}] = "))

    return A

def print_matrix(A):
    n = len(A)
    for i in range(n):
        for j in range(n):
            print(f"{A[i][j]} ", end='')
        print()
    print()

def prod_mat(A, B):
    n = len(A)

    C = np.zeros((n, n))
    C = C.astype(int)

    for i in range(n):
        for j in range(n):
            for k in range(n):
                C[i][j] = C[i][j] or (A[i][k] and B[k][j])
    
    return C

def exp_mat(A, n):
    if n == 1:
        return A
    A = prod_mat(A, A)
    return exp_mat(A, n - 1)

def or_mat(A, B):
    n = len(A)

    C = np.zeros((n, n))
    C = C.astype(int)

    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] or B[i][j] 

    return C

def and_mat(A, B):
    n = len(A)

    C = np.zeros((n, n))
    C = C.astype(int)

    for i in range(n):
        for j in range(n):
            C[i][j] = A[i][j] and B[i][j] 

    return C

def gcd(x, y):
    if x == 0 and y == 0:
        return -1
    if y == 0:
        return x
    return gcd(y, x % y)

def lcm(x, y):
    if x == 0 and y == 0:
        return -1
    return x * y / gcd(x, y)
