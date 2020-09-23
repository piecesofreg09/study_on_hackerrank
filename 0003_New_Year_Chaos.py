#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumBribes function below.
def minimumBribes(q):
    res = 0
    flag = False
    for i, val in enumerate(q):
        if val - (i + 1) > 2:
            flag = True
            break
        else:
            '''
            no need start earlier than 2 positions ahead of the val
            '''
            for j in range(max(0, val - 3), i):
                if q[j] > val:
                    res += 1
    if flag:
        print('Too chaotic')
    else:
        print(res)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
