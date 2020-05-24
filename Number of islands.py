dx = [-1, -1, 0, 1, 1, 1, 0, -1]
dy = [0, 1, 1, 1, 0, -1, -1, -1]
def bfs(a, b):
    q = [[a, b]]
    check[a][b] = True
    while q:
        x = q[0][0]
        y = q[0][1]
        q.pop(0)
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w and arr[nx][ny] == 1 and check[nx][ny] == False:
                q.append([nx, ny])
                check[nx][ny] = 1
while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
    check = [[0 for j in range(w)] for i in range(h)]
    arr = [list(map(int, input().split())) for _ in range(h)]
    res = 0
    for i in range(h):
        for j in range(w):
            if arr[i][j] == 1 and check[i][j] == 0:
                bfs(i, j)
                res += 1
    print(res)
