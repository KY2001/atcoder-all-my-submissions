import math
N,K = map(int,input().split())
r = 0
for i in range(1,N+1):
    if i>=K:
        continue
    else:
        l = math.ceil(math.log2(K / i))
        r += ((1 / 2) ** l)/N
print(float(r))

