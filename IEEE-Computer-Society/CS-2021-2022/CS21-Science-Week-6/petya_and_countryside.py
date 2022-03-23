n = int(input())
heights = list(map(int, input().split()))

max_watered = 0
for i in range(n):
    max_right = 0
    max_left  = 0
    '''
    max_right = i
    max_left = i
    while max_right < n:
        if (heights[max_right] <= heights[i]):
            max_right += 1
            continue
        break

    while max_left >= 0:
        if (heights[max_left] <= heights[i]):
            max_left -= 1
            continue
        break
    '''
    for r in range(i+1, n):
        if (heights[r] > heights[r-1]):
            break;
        max_right += 1

    for l in range(i-1, -1, -1):
        #print("Entered")
        if (heights[l] > heights[l+1]):
            break;
        max_left += 1
    #print(i, max_left, max_right)
    max_watered = max(max_watered, max_right+max_left+1)

    #print(i, max_left, max_right)
    #max_watered = max(max_watered, max_right-max_left+1)


print(max_watered)
