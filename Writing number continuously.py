N = input()
num = len(N)
digit = [1] * 10
ans = 0
for i in range(1, num + 1):
    if i == num:
        digit[i] = int(N) - 10 ** (i - 1) + 1
    else:
        digit[i] = 10 ** i - 1 - 10 ** (i - 1) + 1

for i in range(1, num + 1):
    ans += digit[i] * i

print(ans)