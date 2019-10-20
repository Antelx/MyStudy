import numpy as np
import sklearn.preprocessing


def normalize(matrix):
    return sklearn.preprocessing.normalize(matrix, norm="l1", axis=0)


def inflate(matrix, power=1.2):
    return matrix ** power


def expand(matrix, p, power=2):
    t = matrix
    for _ in range(power - 1):
        t = np.matmul(p, t)
    return t


def prune(matrix, threshold):
    pruned = matrix.copy()
    for i in range(len(pruned)):
        for j in range(len(pruned)):
            if pruned[i, j] < threshold:
                pruned[i, j] = 0
    return pruned


def iterate(matrix, p, expansion, inflation, pruning_threshold):
    matrix = expand(matrix, p, expansion)
    matrix = inflate(matrix, inflation)
    matrix = prune(normalize(matrix), pruning_threshold)
    return normalize(matrix)


def get_result(matrix, p, size=2):
    return sum([np.matmul(np.linalg.matrix_power(p, power), matrix) for power in range(size)])/float(size)


def run_mcl(matrix, expansion=2, inflation=1.2, iterations=200, pruning_threshold=0.001):
    assert matrix.shape[0] == matrix.shape[1]
    m = matrix.copy()
    p = normalize(m)
    t = normalize(m)

    for _ in range(iterations):
        t = iterate(t, p, expansion, inflation, pruning_threshold)

    return get_result(t, p)


def get_clusters(matrix):
    res = matrix.argmax(axis=0)
    d = {}
    for i in range(len(res)):
        if res[i] in d:
            d[res[i]].append(i)
        else:
            d[res[i]] = [i]
    return [sorted(i) for i in d.values()]
