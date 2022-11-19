from collections import Counter

def solution(topping):
    dic = Counter(topping)
    st = set()
    answer=0
    for tp in topping:
        dic[tp]-=1
        if dic[tp] == 0:
            del dic[tp]
            
        st.add(tp)
        if len(st) == len(dic):
            answer+=1

    return answer
