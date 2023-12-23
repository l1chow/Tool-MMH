import math
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
 
def list_element_Zn(n):
    return [i for i in range(1,n) if math.gcd(i,n)==1]
 
def order_of_element_a_in_Zn(a,n):
    phi_n = phi(n)
    for i in range(1,phi_n+1):
        if phi_n%i == 0:
            if pow(a,i,n) == 1:
                return i
 
if __name__ == '__main__':
    n = 20
    print(f"trong Z{n}")
    for i in list_element_Zn(n):
        print(f'{i} có bậc là {order_of_element_a_in_Zn(i,n)}')
