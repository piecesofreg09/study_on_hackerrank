'''
Presum
x[a - 1] += k
x[b] -= k
'''
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    x = [0 for i in range(n + 1)]
    for a, b, k in queries:
        x[a-1] += k
        x[b] -= k
    
    res = x[0]
    dp = x[0]
    for i in range(1, n + 1):
        dp = dp + x[i]
        res = max(dp, res)
    
    return res

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nm = input().split()

    n = int(nm[0])

    m = int(nm[1])

    queries = []

    for _ in range(m):
        queries.append(list(map(int, input().rstrip().split())))

    result = arrayManipulation(n, queries)

    fptr.write(str(result) + '\n')

    fptr.close()
