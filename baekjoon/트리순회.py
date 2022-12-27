n = int(input())

tree = dict()
for i in range(n):
    a, b, c = map(str, input().split())
    tree[a] = [b, c]


def preOrder(start):
    if start == '.':
        return
    print(start, end='')
    preOrder(tree[start][0])
    preOrder(tree[start][1])


def inOrder(start):
    if start == '.':
        return
    inOrder(tree[start][0])
    print(start, end='')
    inOrder(tree[start][1])


def postOrder(start):
    if start == '.':
        return
    postOrder(tree[start][0])
    postOrder(tree[start][1])
    print(start, end='')


preOrder('A')
print()
inOrder('A')
print()
postOrder('A')
print()
