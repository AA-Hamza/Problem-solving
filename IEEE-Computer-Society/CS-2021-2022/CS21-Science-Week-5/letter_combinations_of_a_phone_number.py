'''
    Problem Link https://leetcode.com/problems/letter-combinations-of-a-phone-number/
'''

from itertools import product

number_to_text = {2: 'abc', 3: 'def', 4: 'ghi', 5: 'jkl', 6: 'mno', 7: 'pqrs', 8: 'tuv', 9:'wxyz'}

def letterCombinations(digits):
    l = []
    for i in digits:
        i = int(i)
        l.append(number_to_text[i])

    return [''.join(x) for x in product(*l) if x]

print(letterCombinations('23'))
