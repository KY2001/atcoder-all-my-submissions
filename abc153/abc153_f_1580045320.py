import math
input = sys.stdin.readline
N, D, A = map(int,input().split())
XH = [list(map(int,input().split())) for i in range(N)]
XH.sort()
ans = 0
for i in range(N):
    if XH[i][1] > 0:
        p = XH[i][0]
        t = A*math.ceil(XH[i][1] / A)
        ans += math.ceil(XH[i][1] / A)
        for l in range(i, N):
            if XH[l][0] <= p + 2 * D:
                XH[l][1] -= t
            else:
                break
print(ans)