import itertools

visited = [0] * 8
st = set()


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def dfs(arr, can):
    if can != '' and isPrime(int(can)):
        print('answer: ', int(can))
        st.add(int(can))
        return
    for i in range(len(arr)):
        if not visited[i]:
            visited[i] = 1
            dfs(arr, can + arr[i])
            visited[i] = 0


def solution(numbers):
    for i in range(1, len(numbers) + 1):
        nPr = itertools.permutations(list(numbers), i)
        for x in nPr:
            x = ''.join(x)
            if isPrime(int(x)):
                st.add(int(x))
    return len(st)


