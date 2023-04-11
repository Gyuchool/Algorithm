n = int(input())
max_first=True
min_first = True
ca = cb = cc = -1
mna = mnb = mnc = 111
for _ in range(n):
    a, b, c = map(int, input().split())
    maximum_a, maximum_b, maximum_c = a, b, c
    minimum_a, minimum_b, minimum_c = a, b, c
    if max_first:
        ca, cb, cc = maximum_a, maximum_b, maximum_c
        max_first = False
    elif not max_first:
        max_a = max(ca, cb) + maximum_a
        max_b = max(ca, cb, cc) + maximum_b
        max_c = max(cb, cc) + maximum_c
        ca = max_a
        cb = max_b
        cc = max_c

    if min_first:
        mna, mnb, mnc = minimum_a, minimum_b, minimum_c
        min_first=False
    elif not min_first:
        min_a = min(mna, mnb) + minimum_a
        min_b = min(mna, mnb, mnc) + minimum_b
        min_c = min(mnb, mnc) + minimum_c
        mna = min_a
        mnb = min_b
        mnc = min_c
print(max(ca, cb, cc), min(mna, mnb, mnc))
