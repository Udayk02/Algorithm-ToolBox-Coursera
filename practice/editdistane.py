"""
T = dict()

def edit_distance(a, b, i, j):
    if not (i, j) in T:
        if i == 0: T[i, j] = j
        elif j == 0: T[i, j] = i
        else:
            diff = 0 if a[i-1] == b[j-1] else 1
            T[i, j] = min (
                edit_distance(a, b, i - 1, j) + 1,
                edit_distance(a, b, i, j - 1) + 1,
                edit_distance(a, b, i - 1, j - 1) + diff)
        print("T: ", T)
    return T[i, j]

print(edit_distance("EDITING", "DISTANCE", 7, 8))
"""
def edit_distance(a, b):
    T = [[float("inf")] * (len(b) + 1)
            for _ in range(len(a) + 1)]
    for i in range(len(a) + 1):
        T[i][0] = i
    for j in range(len(b) + 1):
        T[0][j] = j

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            if a[i-1] == b[j-1]:
                T[i][j] = T[i-1][j-1]
            else:
                T[i][j] = min(
                    T[i-1][j] + 1,
                    T[i][j-1] + 1,
                    T[i-1][j-1] + 1
                )
    return T[i][j]

print(edit_distance("editing", "distance"))