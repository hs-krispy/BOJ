def cal(A, B, val1, val2):
    A.remove(val1)
    B.remove(val2)
    Sum = val1 * val2
    return A, B, Sum


def solution(A,B):
    answer = 0
    A.sort()
    B.sort(reverse=True)
    while(len(A) > 0):
        Min = A[0]
        Max = B[0]
        A, B, Sum = cal(A, B, Min, Max)
        answer += Sum

    return answer