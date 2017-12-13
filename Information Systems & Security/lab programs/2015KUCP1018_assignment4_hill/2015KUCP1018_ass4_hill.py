import numpy as np

pt=input("Enter Plain Text: ")
n=len(pt)

#generate p matrix from pt
p=[]
flag=[]
for i in range(0,n):
    if(pt[i].isalpha()):#alphabets
        p.append(ord(pt[i].upper())-65)
        flag.append(0)
    else:#other chars
        p.append(ord(pt[i]))
        flag.append(1)
p=np.array(p)

#random key matrix of nxn
k=np.random.randint(26,size=(n,n))

#matrix mult to generate c
c=(np.matmul(k,p))

#convert c to ct
ct=""
for i in range(0,n):
    if(flag[i]==0):#alphabets
        ct+=chr(c[i]%26+65)
    else:#other chars
        ct+=pt[i]
print("Cipher Text:",ct)

#inverse of key matrix
k1=(np.linalg.inv(k))

#matrix mult to generate d
d=np.around(np.matmul(k1,c)).astype(int)

#convert d to dt/pt
dt=""
for i in range(0,n):
    if(flag[i]==0):#alphabets
        dt+=chr(d[i]%26+65)
    else:#other chars
        dt+=pt[i]
print("Decipher Text:",dt)

