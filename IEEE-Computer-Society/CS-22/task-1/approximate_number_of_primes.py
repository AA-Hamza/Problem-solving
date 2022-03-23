'''
    Problem Link https://www.beecrowd.com.br/judge/en/problems/view/2159
'''
from math import log

n = int(input())
formula = n / log(n)
print(round(formula, 1), round(formula*1.25506, 1))
