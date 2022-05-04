import funcs as fc

n = 3

A = fc.read_matrix(n)
fc.print_matrix(A)
B = fc.read_matrix(n)
fc.print_matrix(B)

C = fc.and_mat(A, B)
fc.print_matrix(C)
C = fc.or_mat(A, B)
fc.print_matrix(C)
C = fc.prod_mat(A, B)
fc.print_matrix(C)
C = fc.exp_mat(B, 3)
fc.print_matrix(C)
