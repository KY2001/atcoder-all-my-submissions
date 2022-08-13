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
import bisect

MOD = 10 ** 9 + 7
INF = float('inf')
input = lambda: sys.stdin.readline().strip()

H, W = map(int, input().split())
if H >= 2 and W >= 2:
    ans = math.ceil(H / 2) * math.ceil(W / 2) + (H // 2) * (W // 2)
else:
    ans = 1
print(ans)
