d = [0 for i in range(1002)]

n = int(input())
a = list(map(int, input().split()))
d[0] = 1


for i in range(1, n):
    d[i] = 1
    for j in range(0, i):
        if a[j] < a[i]:
            d[i] = max(d[i], d[j] + 1)

print(max(d))
