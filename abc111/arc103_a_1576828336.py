n = int(input())
v = list(map(int, input().split()))
v1 = [v[i] for i in range(n) if i % 2 == 0]
v2 = [v[i] for i in range(n) if i % 2 == 1]
v1.sort()
v2.sort()
num1 = 0
num2 = 0
num11 = 0
num22 = 0
check1 = 1
check2 = 1
p = 0
for i in range(len(v1)-1):
    if v1[i] != v1[i+1]:
        if check1 > num1:
            num1 = check1
            p = v1[i]
        check1 = 1
    else:
        check1 += 1
        if check1 > num1:
            num1 = check1
            p = v1[i]

for i in range(len(v2)-1):
    if v2[i] != v2[i+1]:
        if check2 > num2 and v2[i] != p:
            num2 = check2
        check2 = 1
    else:
        check2 += 1
    if check2 > num2 and v2[i] != p:
        num2 = check2

check1 = check2 = 1
for i in range(len(v2)-1):
    if v2[i] != v2[i+1]:
        if check2 > num22:
            num22 = check2
            p = v2[i]
        check2 = 1
    else:
        check2 += 1
    if check2 > num22:
        num22 = check2
        p = v2[i]
        
for i in range(len(v1)-1):
    if v1[i] != v1[i+1]:
        if check1 > num11 and v1[i] != p:
            num11 = check1
        check1 = 1
    else:
        check1 += 1
        if check1 > num11 and v1[i] != p:
            num11 = check1

print(min(n-num1-num2, n-num11-num22))
