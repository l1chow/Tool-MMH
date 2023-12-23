#thuật toán 4
def legendre(a, p):
    return pow(a, (p - 1) // 2, p)
 
def tonelli_shanks(a, p):
    if legendre(a, p) == -1%p :
         return f"{a} không có căn bậc hai theo mod {p}"
 
    b = 2
    while legendre(b, p) != -1%p:
        b+=1
 
    t = p-1
    s = 0
    while t%2 == 0:
        t = t//2
        s = s + 1
 
    c = pow(b,t,p)
    r = pow(a,(t+1)//2,p)
 
    for i in range(1,s):
        d = pow(pow(r,2,p) * pow(a,-1,p),2**(s-i-1),p)
        if d == -1%p:
            r = r*c%p
        c = pow(c,2,p)
 
    return r,-r%p
 
a = 47
p = 97
 
print(tonelli_shanks(a,p))