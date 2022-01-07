n = int(input())
s = set()
for _ in range(n):
    s.add(input())
s = sorted(s)                        # 사전 순 정렬
s = sorted(s, key=lambda x: len(x))  # 길이가 짧은것 부터
print("#" + str(test_case))
print("\n".join(s))
