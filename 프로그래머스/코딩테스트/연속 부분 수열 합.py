def solution(elements):
    st = set()
    answer = 0
    for size in range(1, len(elements)+1):
        s = 0
        while s < len(elements):
            e = s + size
            tmp = sum(elements[s:e])
            if s + size > len(elements):
                e = (s+size) - len(elements)
                tmp = sum(elements[s:] + elements[:e])
            st.add(tmp)
            s+=1
    return len(st)
