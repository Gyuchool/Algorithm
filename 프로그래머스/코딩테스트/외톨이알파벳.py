visited = [0]*26
def solution(input_string):
    answer = ''
    candidate = []
    for id in range(len(input_string)):
        if visited[ord(input_string[id])-97] == 1 and input_string[id-1] != input_string[id]:
            candidate.append(input_string[id])
        else:
            visited[ord(input_string[id])-97] = 1
    candidate = set(candidate)
    candidate = sorted(list(candidate))
    if not candidate:
        answer="N"
    else:
        answer = ''.join(candidate)
    return answer
