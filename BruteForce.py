import decimal
import math
import string
import re
import random
import functools

stupper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
stlower = "abcdefghijklmnopqrstuvwxyz"
stnum = "0123456789"

st = [stupper+stlower+stnum, stupper+stnum+stlower]

def rot(s, cirphetext):
    print("Khong gian ky tu: ", s)
    for k in range(len(s)):
        tmp = ""
        for i in cirphetext:
            if i not in s:
                tmp += i
            else:
                tmp += s[(s.index(i) - k)%len(s)]
        print("Rot", k, ":", tmp)

        # Luu lai cac truong hop nhieu kha nang la ban ro (khi xuat hien tu 'and' hoac tu 'the')
        if tmp.find("and") != -1 or tmp.find("the") != -1:
            lst.append([s, k, tmp])
    print("-----------------------")

cipher = str(input("Nhap ban ma: "))

lst = []

# Vet can cac khong gian ky tu
for s in st:
    rot(s, cipher)

# In ra cac truong hop nhieu kha nang la ban ro
print("Cac truong hop co nhieu kha nang la ban ro: ")
for t in lst:
    print(t)

