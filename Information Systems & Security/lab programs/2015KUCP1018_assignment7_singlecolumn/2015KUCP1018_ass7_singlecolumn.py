import random as rn

pt=input("Enter Plain Text: ")
m=len(pt)
n=int(input("Column Count: "))

#construct matrix
mat1=[list(pt[i:i + n]) for i in range(0,m, n)]
k1=m%n

# pad 'x' 
if(k1!=0):
    for i in range(k1,n):
        mat1[len(mat1)-1].append('x')
l=len(mat1)

#generate random array of lenth n
arr=rn.sample(range(0,n),n)

#calculate ct
ct=""
for i in range(0,n):
    k=arr[i]
    for j in mat1:
        ct+=j[k]
print("Cipher Text:",ct)

#construct matrix
mat2=[list(ct[i:i + l]) for i in range(0, len(ct), l)]

#calculate pt
dt=""
for i in range(0,l):
    for j in range(0,n):
        k=arr.index(j)
        dt+=mat2[k][i]
dt=dt[:m]    
print("Decipher Text:",dt) 