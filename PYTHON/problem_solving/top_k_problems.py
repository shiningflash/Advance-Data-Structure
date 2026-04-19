"""
Problem: Top K Frequent Elements

Optimal Idea
- Count frequencies using HashMap
- Use heap of size k

nums = [1,1,1,2,2,3]
k = 2
Output → [1,2]

Time Complexity: O(N log K)
Space Complexity: O(N)
"""

import heapq
from collections import Counter


def top_k_problems(problems: list[int], k: int) -> list[int]:
    frequency = Counter(problems)

    heap = []
    for problem, freq in frequency.items():
        heapq.heappush(heap, (freq, problem))
        if len(heap) > k:
            heapq.heappop(heap)

    return [problem for _, problem in heap][::-1]


print(top_k_problems([1, 1, 1, 2, 2, 3], 2))
