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

a, b, c = map(int, input().split())

if c - a - b > 0 and (c - a - b) ** 2 > 4 * a * b:
    print("Yes")
else:
    print("No")
