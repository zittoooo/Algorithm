def solution(n):
    import math
    answer = 0

    sqrt = n ** (1 / 2)
    if sqrt % 1 == 0:
        return (sqrt + 1) ** 2

    return -1