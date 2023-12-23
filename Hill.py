import string
table = string.ascii_lowercase
R = IntegerModRing(26)
M = MatrixSpace(R,2,2)
 
Key = M([[11,8],[3,7]])
message = "thang"
 
message = message.lower() 
if len(message)%2 != 0:
    message+='z'
     
def encrypt(message):
    ciphertext = ''
    for i in range(0,len(message),2):
        M1 = MatrixSpace(R,1,2)
        matrix_tmp = M1([[table.index(message[i]),table.index(message[i+1])]])
        res_matrix_tmp = matrix_tmp*Key
        ciphertext += table[int(res_matrix_tmp[0][0])] + table[int(res_matrix_tmp[0][1])]
    return ciphertext
 
ciphertext = encrypt(message)
print(f'ciphertext : {ciphertext}')
 
def decrypt(ciphertext):
    plaintext = ''
    for i in range(0,len(ciphertext),2):
        M1 = MatrixSpace(R,1,2)
        matrix_tmp = M1([[table.index(ciphertext[i]),table.index(ciphertext[i+1])]])
        res_matrix_tmp = matrix_tmp*Key.inverse()
        plaintext += table[int(res_matrix_tmp[0][0])] + table[int(res_matrix_tmp[0][1])]
    return plaintext   
 
plaintext = decrypt(ciphertext)
print(f'plaintext : {plaintext}')
# https://sagecell.sagemath.org/