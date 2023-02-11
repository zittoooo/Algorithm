def solution(s):
    return "".join(sorted([letter for letter in s if s.count(letter) == 1]))
