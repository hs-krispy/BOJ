N = int(input())
A = list(map(int, input().split()))
check = [False] * N
global Max
Max = 0


def cal(l):
    global Max
    Sum = 0
    for i in range(N - 1):
        Sum += abs(l[i] - l[i + 1])
    if Sum > Max:
        Max = Sum


def change(l):
    if len(l) == N:
        cal(l)
        return
    for i in range(N):
        if not check[i]:
            check[i] = True
            l.append(A[i])
            change(l)
            check[i] = False
            l.pop()

l = []
change(l)
print(Max)