n = int(input())
yo = []

for _ in range(n):
    yo.append(int(input()))
    
yo.sort(reverse = True)

res = 0
for i in range(n):
    if i % 3 == 2:
        pass
    else:
        res += yo[i]
print(res)
