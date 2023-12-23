def convert_hex_to_coefficients(a):
    a = str(a)
    a = bin(int(a,16))[2:]
    return list(a)[::-1]
 
R.<x> = PolynomialRing(GF(2))
F.<t> = R.quotient(x^8 + x^4 + x^3 + x + 1)
 
def multiplicate_2_polynomias(a,b):
    coefficients_a = convert_hex_to_coefficients(a)
    coefficients_b = convert_hex_to_coefficients(b)
    a = F(coefficients_a)
    b = F(coefficients_b)
    res = a*b
    res = ''.join(str(x) for x in res.list())[::-1]
    return "{:02x}".format(int(res,2))
 
a = "57"
b = "13"
res = multiplicate_2_polynomias(a,b)
print(f'{a}*{b} = {res}(16) = {bin(int(res,16))[2:].zfill(8)}(2)')

# chạy trên https://sagecell.sagemath.org/