def solution(record):
    log = []
    user = dict()
    for st in record:
        state = st.split(' ')[0]
        if state == 'Leave':
            state, uid = st.split(' ')
            log.append([uid, state])
        else:
            state, uid, name = st.split(' ')
            if state == 'Change':
                user[uid] = name
            else:
                user[uid] = name
                log.append([uid, state])

    result = []
    for id, status in log:
        if status == 'Enter':
            result.append(user[id] + '님이 들어왔습니다.')
        elif status == 'Leave':
            result.append(user[id] + '님이 나갔습니다.')
    return result
print(solution(["Enter uid1234 Muzi", "Leave uid1234"]))
