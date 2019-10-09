import time
import numpy as np


def get_matrices():
    a = np.array([[3, 6, 7], [5, -3, 0], [2, 7, 8], [1, 9, 2]])
    b = np.array([[1, 1], [2, 1], [3, -3]])
    return a, b


def matrix_multiplication_numpy():
    a, b = get_matrices()
    result = a.dot(b)
    return result


def matrix_multiplication_manually():
    a, b = get_matrices()
    result = [[0 for _ in range(len(b[0]))] for _ in range(len(a))]
    for i in range(len(a)):
        for j in range(len(b[0])):
            for k in range(len(b)):
                result[i][j] += a[i][k] * b[k][j]
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
