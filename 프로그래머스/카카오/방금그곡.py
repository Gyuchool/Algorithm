def solution(m, musicinfos):
    answer = ''
    changer = {'C#':'Z', 'D#':'X', 'F#':'V', 'G#':'N', 'A#':'M','E#':'P'}
    for k, v in changer.items():
        m = m.replace(k, v)
    candidate =[]
    id = 1
    for info in musicinfos:
        st, et, title, music = info.split(',')
        for k, v in changer.items():
            music = music.replace(k, v)
        hh, mm = st.split(':')
        startTime = int(hh)*60 + int(mm)
        hh, mm = et.split(':')
        endTime = int(hh)*60 + int(mm)
        time = endTime - startTime
        tmp = ''
        size = len(music)
        for i in range(time):
            tmp+=music[i%size]
        if m in tmp:
            candidate.append([time, id, title])
        id+=1
    candidate.sort(key = lambda x : (-x[0], x[1]))
    if not candidate:
        return "(None)"
    else:
        answer= candidate[0][2]
    return answer
