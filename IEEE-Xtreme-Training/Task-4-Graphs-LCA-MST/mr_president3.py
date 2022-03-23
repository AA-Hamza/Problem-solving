n, m, k = map(int, input().split())

edges = []
for _ in range(m):
    edges.append(tuple(map(int, input().split())))

edges.sort(key = lambda x : x[2])

groups = [[] for _ in range(n) ]
which_group = [-1]*(n+1)
groups_counter = 0

for edge in edges:
    e_from = edge[0]
    e_to   = edge[1]
    if which_group[e_from] == -1 and which_group[e_to] == -1:
        which_group[e_from] = groups_counter
        which_group[e_to]   = groups_counter
        groups[groups_counter].append(edge)
        groups_counter += 1
    else:
        if which_group[e_to] == -1:
            which_group[e_to] = which_group[e_from]
            groups[ which_group[e_from] ].append(edge)
        elif which_group[e_from] == -1:
            which_group[e_from] = which_group[e_to]
            groups[ which_group[e_to] ].append(edge)
        else:       #both are in groups
            from_group, to_group = which_group[e_from], which_group[e_to]
            if (from_group != to_group):
                for i in range(len(groups[to_group])):      #move every thing from the to group into the from group, and point to the same group
                    which_group[ groups[to_group][i][0] ] = from_group
                    which_group[ groups[to_group][i][1] ] = from_group
                    groups[from_group].append(groups[to_group][i])
                groups[to_group].clear()
                #groups_counter -= 1

maybe_groups = [x for x in groups if len(x) > 0]
if len(maybe_groups) > 1:
    print('-1')
else:
    valid_group = maybe_groups[0]
    print(valid_group)
    '''
    print(len(valid_group))
    if (len(valid_group) != n-1): #wrong, no correct
        print('-1')
    else:
        #print(valid_group)
        costs = [x[2] for x in valid_group]
        total_cost = sum(x for x in costs)
        if (total_cost < k):
            print('0')
        else:
            costs.sort(reverse=True)
            transformed = 0
            for c in costs:
                total_cost = total_cost - c + 1
                transformed += 1
                if (total_cost <= k):
                    print(transformed)
                    break;
    '''
