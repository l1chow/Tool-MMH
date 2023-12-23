def prime_factors(n):
    i = 2
    factors = []
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    k = [(x, factors.count(x)) for x in set(factors)]
    return dict(k)
 
def phi(n):
    phi_n = n
    for i in prime_factors(n):
        phi_n *= (1-1/i)
    return int(phi_n)
 
def find_min_generator(n):
    phi_n = phi(n)
    a = prime_factors(phi_n)
    check = 0
    for i in range(2,phi_n):
        for p in a:
            if pow(i,phi_n//p,n) == 1:
                check = 0
                break
            else:
                check = 1
        if check : return i
 
print(find_min_generator(41))