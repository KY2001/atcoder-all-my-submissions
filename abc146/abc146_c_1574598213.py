A, B , X = map(int,input().split())
if A+B > X:
    print(0)
else:
    for i in range(1, 1000):
        if (X-(i*B))/A < 10**i:
            if ((X-i*B)/A)//1 > 10**9:
                print(int(10**9))
            else:
                print(int(((X-i*B)/A)//1))
            break