t = int(input())
#angles = []
angles = [60, 90, 108, 120, 135, 140, 144, 150, 156, 160, 162, 165, 168, 170, 171, 172, 174, 175, 176, 177, 178, 179]
#for n in range(3, 1000):
#    if (((n-2)*180) % n == 0):
#        a = (n-2)*180//n
#        angles.append(a)
#        #angles[a] = n

#print(angles)
for _ in range(t):
    a = int(input())
    print("YES" if a in angles else "NO")
