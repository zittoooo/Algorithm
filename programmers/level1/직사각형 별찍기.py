a, b = map(int, input().strip().split(' '))
#print(a + b)

for i in range(b):
    for j in range(a):
        print('*',end='')
    print()