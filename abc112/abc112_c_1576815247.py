import sys
N = int(input())
xyh = [list(map(int,input().split())) for _ in range(N)]
for Cx in range(0,101):
    for Cy in range(0,101):
        ans = []
        for i in xyh:
            H = i[2]+abs(i[0]-Cx)+abs(i[1]-Cy)
            if i[2] != 0:
                ans.append(H)
        if len(set(ans)) == 1:
            print(Cx, Cy, H)
            sys.exit()
