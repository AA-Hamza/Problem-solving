'''
    Problem Link https://www.hackerrank.com/challenges/matrix-script/problem
'''
n, m = map(int, input().split())
matrix = [input() for x in range(n)]
columns = []
for i in range(m):
    columns.append(''.join([x[i] for x in matrix]))

all_string = ''.join(columns)
first_chars = ''
first_ptr = 0
while (first_ptr < len(all_string) and (all_string[first_ptr].isalnum() != 1 or all_string[first_ptr] == ' ')):
    first_chars += all_string[first_ptr]
    first_ptr += 1

all_string = all_string[first_ptr:]

last_chars = ''
ptr = len(all_string)-1
while (ptr > first_ptr and (all_string[ptr].isalnum() != 1 or all_string[ptr] == ' ')):
    last_chars += all_string[ptr]
    ptr -= 1
all_string = all_string[:ptr+1]

chars_to_delete = "!@#$%&"
for char in chars_to_delete:
    #spaces += all_string.count(char)
    all_string = all_string.replace(char, ' ')

spaces = all_string.count(' ')
spaces //=2
while (spaces):
    spaces -= 1
    all_string = all_string.replace('  ', ' ')
print(first_chars+all_string+last_chars[::-1])
