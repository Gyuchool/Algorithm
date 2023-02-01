def merge(A, left, mid, right):
    answer= 0 
    i = left
    j = mid + 1
    sortedArray = []
    while i<= mid and j <= right:
        if A[i] <= A[j]:
            sortedArray.append(A[i])
            i+=1
        else:
            answer+=(mid-i+1)
            sortedArray.append(A[j])
            j+=1
    while i<= mid:
        sortedArray.append(A[i])
        i+=1
    while j<= mid:
        sortedArray.append(A[j])
        j+=1
    k = len(sortedArray) - 1
    while k>=0:
        A[left + k] = sortedArray[k]
        k-=1
    return answer
    

def mergeSort(A, left, right):
    answer = 0
    if left < right:
        mid = (left + right)//2
        answer += mergeSort(A, left, mid)
        answer += mergeSort(A, mid + 1, right)
        answer += merge(A, left, mid, right)
    return answer
def solution(A):
    return mergeSort(A, 0, len(A)-1)
    
