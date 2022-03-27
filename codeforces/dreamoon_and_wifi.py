'''
    Problem Link https://codeforces.com/problemset/problem/476/B
'''

from math import factorial
def combinations(a, b):
    return factorial(a)/(factorial(b)*factorial(a-b))

original = input()
orig_pluses  = original.count('+')
orig_minuses = original.count('-')

recieved = input()
reci_pluses   = recieved.count('+')
reci_minuses  = recieved.count('-')
reci_question = recieved.count('?')

if (orig_pluses == reci_pluses and orig_minuses == reci_minuses):
    print("{:.12f}".format(1))
else:
    orig_position = orig_pluses - orig_minuses
    reci_position = reci_pluses - reci_minuses
    places = abs(orig_position-reci_position)
    if (reci_question < places):
        print("{:.12f}".format(0))
        exit(0)
    same_direction = places
    different_couples = reci_question - places
    if (different_couples % 2 != 0):
        print("{:.12f}".format(0))
        exit(0)
    same_sign = int(same_direction+different_couples/2)
    combs = combinations(reci_question, same_sign)
    percentage = combs/(2**reci_question)
    print("{:.12f}".format(percentage))
