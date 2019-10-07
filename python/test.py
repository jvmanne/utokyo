import time
import numpy as np


def get_matrices():
    a = np.array([[3, 6, 7], [5, -3, 0]])
    b = np.array([[1, 1], [2, 1], [3, -3]])
    return a, b


def matrix_multiplication_numpy():
    a, b = get_matrices()
    result = a.dot(b)
    time.sleep(2)
    return result


def matrix_multiplication_manually():
    a, b = get_matrices()
    result = []
    for i in range(len(a)):
        row = []
        for j in range(len(a)):
            product = 0
            for k in range(len(a[i])):
                product += a[i][k] * b[k][j]
            row.append(product)
        result.append(row)
    time.sleep(3)
    return np.array(result)


start = time.time()
resultNumpy = matrix_multiplication_numpy()
end = time.time()
totalTimeNumpy = end - start

start = time.time()
resultManually = matrix_multiplication_manually()
end = time.time()
totalTimeManually = end - start

print("Numpy:")
print(resultNumpy)
print(totalTimeNumpy)
print()
print("Manually:")
print(resultManually)
print(totalTimeManually)
