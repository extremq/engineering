import funcs as fc

A = [0, 1, 2, 3, 4]
B = [0, 1, 2, 3]

eq  = lambda x, y: x == y
sm  = lambda x, y: x + y == 4
gt  = lambda x, y: x > y
sau = lambda x, y: x | y
gcd = lambda x, y: fc.gcd(x, y) == 1
lcm = lambda x, y: fc.lcm(x, y) == 2

checks = [eq, sm, gt, sau, gcd, lcm]

for i in range(len(checks)):
    valids = []
    for a in A:
        for b in B:
            if checks[i](a, b) == True:
                valids.append((a, b))
                
    print(valids)
