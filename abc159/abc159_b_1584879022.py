import sys
import math
import string
import fractions
import random
from operator import itemgetter
import itertools
from collections import deque
import copy
import heapq
from bisect import bisect, bisect_left, bisect_right

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

sys.setrecursionlimit(10 ** 8)

S = list(input())
N = len(S)
S_ = [S[i] for i in range(len(S) - 1, -1, -1)]
if S_ != S:
    print("No")
    sys.exit()
S1 = [S[i] for i in range(0, (N - 1) // 2)]
S = S1
S_ = [S[i] for i in range(len(S) - 1, -1, -1)]
if S != S_:
    print("No")
    sys.exit()
N = len(S)
S2 = [S[i] for i in range((N + 3) // 2 - 1, N)]
S = S2
S_ = [S[i] for i in range(len(S) - 1, -1, -1)]
if S != S_:
    print("No")
    sys.exit()
print("Yes")