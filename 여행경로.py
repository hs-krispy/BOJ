global ans
ans = []


def path(tickets, airport, answer, check):
    global ans
    if check.count(True) == len(check):
        ans = answer
        return

    for idx, i in enumerate(tickets):
        if check[idx] == False and i[0] == airport:
            check[idx] = True
            answer.append(tickets[idx][1])
            path(tickets, tickets[idx][1], answer, check)
            if check.count(True) == len(check):
                break
            answer.pop()
            check[idx] = False


def solution(tickets):
    global ans
    answer = ["ICN"]
    tickets = sorted(tickets)
    check = [False for i in range(len(tickets))]
    path(tickets, "ICN", answer, check)
    answer = ans
    return answer