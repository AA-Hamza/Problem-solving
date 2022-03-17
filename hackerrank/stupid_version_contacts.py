def binary_search_on_string(arr, x):
    l = 0
    r = len(arr) - 1
    while (l <= r): 
        m = (l + r) // 2 
        if (arr[m].startswith(x)): 
            return m
        elif (arr[m] < x): 
            l = m + 1
        else: 
            r = m - 1
    return -1

def contacts(queries):
    names = []
    find_queries = []
    for query in queries:
        if (query[0] == "add"):
            names.append(query[1])
            names.sort()
        else:
            count = 0
            index = binary_search_on_string(names, query[1])
            if (index != -1):
                #lower ranges
                count += 1
                lower = index-1
                while (lower >= 0 and names[lower].startswith(query[1])):
                    count += 1
                    lower -= 1

                upper = index+1
                while (upper < len(names) and names[upper].startswith(query[1])):
                    count += 1
                    upper += 1

            print(count)
            #find_queries.append(query[1])
'''
    names.sort()
    #print(find_queries)
    for query in find_queries:
        count = 0
        index = binary_search_on_string(names, query)
        if (index != -1):
            #lower ranges
            count += 1
            lower = index-1
            while (lower >= 0 and names[lower].startswith(query)):
                count += 1
                lower -= 1

            upper = index+1
            while (upper < len(names) and names[upper].startswith(query)):
                count += 1
                upper += 1

        print(count)
'''
    
n = int(input())
queries = []
for _ in range(n):
    queries.append(input().split())

contacts(queries)
