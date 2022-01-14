from collections import Counter

n = int(input())
for i in range(1, n+1):
    lst = str(input())
    alph = []
    for s in lst:
        if s.isalpha():
            alph.append(s.lower())  # 알파벳만 전부 소문자로 바꿔서 alph 리스트에 저장
    cnt = Counter(alph)

    mx = 0
    mn = int(1e9)
    for key, value in cnt.items():
        mx = max(mx, int(value))   # 가장 많이 등장한 알파벳의 등장 횟수
        mn = min(mn, int(value))   # 가장 적게 등장한 알파벳의 등장 횟수

    if len(cnt) == 26:             # 모든 알파벳 다 들어 있을 때
        if mx >= mn and mn  == 2:
            print("Case {}: Double pangram!!".format(i))
        elif mx >= mn and mn == 3:
            print("Case {}: Triple pangram!!!".format(i))
        else:
            print('Case {}: Pangram!'.format(i))
    else:
        print('Case {}: Not a pangram'.format(i))
