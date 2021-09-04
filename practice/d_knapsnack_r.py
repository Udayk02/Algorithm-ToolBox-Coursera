def knapsnack(W, w, v, items):
    weight = sum(w[i] for i in items)
    value = sum(v[i] for i in items)

    for i in range(len(w)):
        if weight + w[i] <= W:
            value = max(value, knapsnack(W, w, v, items + [i]))
    return value

print(knapsnack(10, [6, 3, 4, 2], [30, 14, 16, 9], []))