'''
    Problem Link https://csacademy.com/ieeextreme-practice/task/9ca8fafd184f553a903734761546a224/
'''
from math import floor, log, ceil

def get_same_level_distance(level, a, b):
    distance = 0
    while (a!=b):
        a = a//2
        b = b//2
        distance += 2
    return distance


'''     LOL NOT NEEDED
def _get_same_level_distance(level, a, b):
    start_of_level = 2**level
    end_of_level = 2**(level+1)-1
    length_of_level = end_of_level-start_of_level
    #0...7
    mid = length_of_level/2
    a -= start_of_level
    b -= start_of_level
    distance = level*2
    def cal():
        nonlocal a, mid, b, distance, start_of_level, end_of_level
        #print(mid, start_of_level, end_of_level)
        if (start_of_level >= end_of_level):
            return
        if (a < mid and b < mid):
            distance -=2
            end_of_level = floor(mid)
            mid = (start_of_level+end_of_level)/2
        elif (a > mid and b > mid):
            distance -=2
            end_of_level = ceil(mid)
            mid = (start_of_level+end_of_level)/2
        else:
            return
        cal()
    cal()
    return distance
'''

q = int(input())
for _ in range(q):
    a, b = map(int, input().split())
    if (a == b):
        print(0)
        continue
    a_level, b_level = floor(log(a, 2)), floor(log(b, 2))
    b_distance = 0
    a_distance = 0
    if (a_level < b_level):
        while (b_level != a_level):
            b_distance+=1
            b_level = b_level-1
            b = b//2
    elif (b_level < a_level):
        while (b_level != a_level):
            a_distance+=1
            a_level = a_level-1
            a = a//2

    if (a == b):
        print(a_distance+b_distance)
        continue
    same_level_distance = get_same_level_distance(a_level, a, b)
    print(a_distance+b_distance+same_level_distance)

exit(0)
