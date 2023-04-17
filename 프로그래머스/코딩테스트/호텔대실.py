    
def solution(book_time):
    answer = 0
    new_book = []
    for book in book_time:
        start, end = book
        sh = int(start.split(':')[0])
        sm = int(start.split(':')[1])
        
        eh = int(end.split(':')[0])
        em = int(end.split(':')[1])
        if em + 10 >=60:
            eh +=1
            em = (em+10) - 60
        else:
            em+=10
        new_book.append([[sh, sm], [eh, em]])
    new_book.sort()
    repo = []
    last = [-1, -1]
    repo.append(last)
    
    for time in new_book:
        ss = time[0]
        ee = time[1]
        new=True
        for i in range(len(repo)):
            if max(repo[i], ss) == ss:
                repo.remove(repo[i])
                repo.append(ee)
                new = False
                break
        if new:
            repo.append(ee)
    answer = len(repo)
    return answer
