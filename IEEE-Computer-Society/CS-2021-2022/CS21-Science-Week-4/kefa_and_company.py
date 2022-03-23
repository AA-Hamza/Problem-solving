'''
    Problem Link http://codeforces.com/contest/580/problem/B
'''
num_of_friends, d = map(int, input().split())
friends = []

for i in range(num_of_friends):
    friends.append(tuple(map(int, input().split())))

friends.sort()
max_friendship = 0
curr_friendship = friends[0][1]
start_index = 0
index_end = 1
while (start_index < num_of_friends):
    index_end = max(index_end, start_index)
    while (index_end < num_of_friends and friends[index_end][0]-friends[start_index][0] < d):
        curr_friendship += friends[index_end][1]
        index_end += 1
    max_friendship = max(max_friendship, curr_friendship)
    curr_friendship -= friends[start_index][1]
    start_index += 1
print(max_friendship)
