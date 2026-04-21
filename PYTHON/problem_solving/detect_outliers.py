"""
Write a Python function:

detect_outliers(data, threshold=3)

Requirements:

Compute z-score for each value.
Return a list of values that are outliers.
Use the rule:
if |z| > threshold → outlier

Assume population standard deviation.

Test Case
data = [10, 12, 11, 13, 12, 14, 100]

detect_outliers(data)

Expected result:

[100]
"""

import math

import numpy as np


def mean(data: list[float]) -> float:
    return sum(data) / len(data)


def variance(data: list[float], mu: float) -> float:
    return sum((x - mu) ** 2 for x in data) / len(data)


def standard_deviation(variance: float) -> float:
    return math.sqrt(variance)


def detect_outliers(data: list[float], threshold: float = 1.2) -> list[float]:
    if not data:
        return []

    mu = mean(data)
    var = variance(data, mu)
    sigma = standard_deviation(var)

    if sigma == 0:
        return []

    outliers = []
    for x in data:
        z_score = (x - mu) / sigma
        if abs(z_score) > threshold:
            outliers.append(x)

    return outliers


def detect_outliers_using_numpy(
    data: list[float], threshold: float = 1.2
) -> list[float]:
    data = np.asarray(data)

    if data.size == 0:
        return []

    mu = data.mean()
    sigma = data.std()

    if sigma == 0:
        return []

    z_scores = (data - mu) / sigma

    return data[np.abs(z_scores) > threshold].tolist()


data = [10, 12, 11, 13, 12, 14, 100]

print(detect_outliers(data))
print(detect_outliers_using_numpy(data))
