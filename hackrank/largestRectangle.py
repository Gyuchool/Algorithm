def largestRectangle(h):
    # Write your code here
    answer = 0
    for i in range(len(h)):
        mh = h[i]
        lx = i-1
        rx = i+1
        size = 1
        while lx>=0:
            if h[lx] >= mh:
                size+=1
                lx-=1
            else:
                break
            
                
        while rx < len(h):
            if h[rx] >= mh:
                size+=1
                rx+=1
            else:
                break
            
        answer = max(answer, mh*size)
    return answer  
