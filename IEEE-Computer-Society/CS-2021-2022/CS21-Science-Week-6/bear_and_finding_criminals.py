'''
    Problem Link https://codeforces.com/contest/680/problem/B
'''

n, a = map(int, input().split())
cities = list(map(int, input().split()))

left_cities = a-1
right_cities = n-a

max_double_distance = min(left_cities, right_cities)

criminals = 0
a = a-1
for distance in range(1, max_double_distance+1):
    if (cities[a-distance] == cities[a+distance] == 1):
        criminals += 2

criminals += cities[a]
if (left_cities > right_cities):
    criminals += sum(cities[:n-2*right_cities-1])
elif (right_cities > left_cities):
    criminals += sum(cities[2*left_cities+1:])

print(criminals)
