import sys
input = sys.stdin.readline

n = int(input())

cities = list(map(int, input().split()))
budget = int(input())
cities.sort()

start = 0
end = max(cities)

while start <= end:
    mid = (start + end) // 2
    money = 0
    # print(mid)

    money = sum(city if mid >= city else mid for city in cities)
    # print(money)
    if money > budget:
        end = mid - 1
    else:
        start = mid + 1
print(end)
