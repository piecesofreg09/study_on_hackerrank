'''
Binary search
driver(machines, days) is the number of products produced in days
if driver are the required number, days -= 1
if driver is less than target, days += 1
if driver(m, days) is more than target, compare the driver(m, days - 1) with the target
'''
#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minTime function below.
def driver(machines, days):
    res = sum([days // m for m in machines])
    return res
def minTime(machines, goal):
    #print(goal)
    #print([driver(machines, i) for i in range(1, goal + 1)])
    left = 1
    right = int(goal // sum([1/m for m in machines])) + max(machines)
    #print(right)
    while left <= right:
        m = left + (right - left) // 2
        pro = driver(machines, m)
        #print([m, pro])
        if pro == goal:
            prolittle = driver(machines, m - 1)
            #print([m - 1, prolittle])
            if prolittle == goal:
                right = m - 1
            else:
                return m
        elif pro < goal:
            left = m + 1
        else:
            #print('in big')
            prolittle = driver(machines, m - 1)
            #print([m - 1, prolittle])
            if prolittle >= goal:
                right = m - 1
            else:
                return m
    return m

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nGoal = input().split()

    n = int(nGoal[0])

    goal = int(nGoal[1])

    machines = list(map(int, input().rstrip().split()))

    ans = minTime(machines, goal)

    fptr.write(str(ans) + '\n')

    fptr.close()
