N = int(input())
L=[]
i = 0
s = 0
M2 = 0
for i in range (0,N):
    L.append(int(input()))
M = L[0]
for s in range(1,N):
    if  L[s] > M:
        M = L[s]
for s in range(1,N):
    if L[s] == M:
        continue
    else:
        if L[s] > M2:
            M2 = L[s]
for i in range(0,N):
    if L[i] == M:
        print(M2)
    else:
        print(M)
N = int(input())
L=[]
i = 0
s = 0
M2 = 0
for i in range (0,N):
    L.append(int(input()))
M = L[0]
for s in range(1,N):
    if  L[s] > M:
        M = L[s]
for s in range(1,N):
    if L[s] == M:
        continue
    else:
        if L[s] > M2:
            M2 = L[s]
for i in range(0,N):
    if L[i] == M:
        print(M2)
    else:
        print(M)
