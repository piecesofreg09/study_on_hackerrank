#!/bin/python3

import os
import sys
import math

#
# Complete the downToZero function below.
#
res = [-1 for i in range(1001000)]
res[0] = 0
res[1] = 1
res[2] = 2
res[3] = 3
def precal():
    for i in range(2, len(res)):
        if res[i] == -1 or res[i] > (res[i - 1] + 1):
            res[i] = 1 + res[i - 1]
        j = 1
        while j <= i and j * i < len(res):
            if res[i * j] == -1:
                res[j * i] = res[i] + 1
            else:
                res[j * i] = min(res[j * i], res[i] + 1)
            j += 1
        

def downToZero(n):
    return res[n]

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    precal()
    q = int(input())

    for q_itr in range(q):
        n = int(input())

        result = downToZero(n)

        fptr.write(str(result) + '\n')

    fptr.close()
