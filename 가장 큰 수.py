def solution(num):
    num = list(map(str, num)) # 각 원소를 문자열로
    num.sort(key=lambda x: x*3, reverse=True) # 원소가 1000이하이므로 3자리
    return str(int(''.join(num)))