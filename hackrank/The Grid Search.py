def gridSearch(G, P):
    # Write your code here
    n = len(P)
    m = len(P[0])
    success = False
    for i in range(len(G)-n+1):
        for j in range(len(G[i])-m+1):
            if G[i][j] == P[0][0]:
                for x in range(len(P)):
                    for y in range(len(P[x])):
                        if G[i+x][j+y] != P[x][y]:
                            success = False
                            break
                        else:
                            success = True
                    if not success:
                        break
                if success:
                    return "YES"
    return "NO"
