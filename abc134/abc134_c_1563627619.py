N = int(input())
L=[]
i = 0
s = 0
for i in range (0,N):
    L.append(int(input()))
M = L[0]
for s in range(1,N):
    if  L[s] > M:
        M = L[s]
i = 0
for i in range(0,N):
    F = L[0]
    for s in range(1,N):
        if F == M:
            continue
        else:
            if L[s] == L[i]:
                continue
            else:
                if L[s] > F:
                    F = L[s]
    print(F)

