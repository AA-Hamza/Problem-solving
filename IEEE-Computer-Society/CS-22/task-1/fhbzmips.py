'''
    Problem link https://www.beecrowd.com.br/judge/en/problems/view/2536
'''

threshold = 1000
def excute():
    try:
        num_of_lines = int(input())
        instructions = []
        for _ in range(num_of_lines):
            line = input().split()
            instructions.append(tuple(line))
        max_num_of_operations = num_of_lines * threshold
        r = 0
        in_ptr = 0
        while (max_num_of_operations > 0):
            curr = instructions[in_ptr]
            if (curr[1] == 'add'):
                r += int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'sub'):
                r -= int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'mul'):
                r *= int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'div'):
                r = r // int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'and'):
                r = r & int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'or'):
                r = r | int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'xor'):
                r = r ^ int(curr[2])
                r = r % 256
                in_ptr += 1
            elif (curr[1] == 'gotoif'):
                if r >= int(curr[2]):
                    in_ptr = int(curr[3])-1
                else:
                    in_ptr += 1
            else:
                print(r)
                return 1
            max_num_of_operations -= 1
        print("execucao infinita")
        return 1
    except EOFError:
        return 0

while excute():
    pass
