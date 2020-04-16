d = [0]*256
d[0] = 1
d[1] = 1
d[2] = 3
for i in range(2, 255):
    d[i] = d[i-1] + 2 * d[i-2]
while True:
    try:
        n = int(input())
        print(d[n])
    except:
        break
