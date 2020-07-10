dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
dial = [list((input().split())) for _ in range(5)]
check = [False] * 1000000
S = ""
global count
count = 0


def make(i, j, s, c):
    global count
    if c == 5:
        if not check[int(s)]:
            check[int(s)] = True
            count += 1
        return
    temp = s
    for k in range(4):
        x = i + dx[k]
        y = j + dy[k]
        if x >= 0 and y >= 0 and x < 5 and y < 5:
            s += dial[x][y]
            make(x, y, s, c + 1)
            s = temp


for i in range(5):
    for j in range(5):
        S += dial[i][j]
        make(i, j, S, 0)
        S = ""


print(count)
