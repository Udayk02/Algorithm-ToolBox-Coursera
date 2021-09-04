def lis(A, last_index):
    result = 0
    if last_index == -1:
        last_element = float("-inf")
    else:
        last_element = A[last_index]
    for i in range(last_index + 1, len(A)):
        if A[i] > last_element:
            result = max(result, 1 + lis(A, i))
    return result

print(lis([7, 2, 1, 3, 8, 4, 9], -1))
