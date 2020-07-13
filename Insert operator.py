N = int(input())
num = list(map(int, input().split()))
oper = list(map(int, input().split()))
global Max
Max = -1000000000
global Min
Min = 1000000000


def cal(val, c, idx):
    global Max, Min
    if c == N - 1:
        if Max < val:
            Max = val
        if Min > val:
            Min = val
        return
    for i in range(idx, N):
        for j in range(4):
            if oper[j] > 0:
                oper[j] -= 1
                if j == 0:
                    cal(val + num[i], c + 1, i + 1)
                if j == 1:
                    cal(val - num[i], c + 1, i + 1)
                if j == 2:
                    cal(val * num[i], c + 1, i + 1)
                if j == 3:
                    if val < 0:
                        cal(-(-val // num[i]), c + 1, i + 1)
                    else:
                        cal(val // num[i], c + 1, i + 1)
                oper[j] += 1


cal(num[0], 0, 1)
print(Max)
print(Min)
