book = dict()

n = int(input())
mx = 0
for i in range(n):
    name = input()
    if name not in book:
        book[name] = 1
    else:
        book[name] += 1
    mx = max(mx, book[name])

book = dict(sorted(book.items()))
for item in book.items():
    name, cnt = item[0], item[1]
    if cnt == mx:
        print(name)
        break
