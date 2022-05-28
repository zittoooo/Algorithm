n, m = map(int, input().split())
strings = []

for _ in range(n):
    strings.append(input())

dna = ''
dist = 0
for i in range(m):
    dic = {}
    for j in range(n):
        if strings[j][i] not in dic:
            dic[strings[j][i]] = 1
        else:
            dic[strings[j][i]] += 1
    ans = list(dic.items())
    ans.sort(key = lambda x : (-x[1], x[0]))
    dist += n - ans[0][1]
    dna += ans[0][0]
    
print(dna, dist, sep = "\n")
    
