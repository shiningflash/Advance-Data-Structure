"""
nums = [3,2,1,5,6,4]
k = 2
Output → 5
"""

import heapq


def find_kth_largest(nums: list[int], k: int) -> int:
    heap = []

    for num in nums:
        heapq.heappush(heap, num)

        if len(heap) > k:
            heapq.heappop(heap)

    return heap[0]


def find_kth_largest_alternative(nums: list[int], k: int) -> int:
    return heapq.nlargest(k, nums)[-1]


print(find_kth_largest([3, 2, 1, 5, 6, 4], 2))
print(find_kth_largest_alternative([3, 2, 1, 5, 6, 4], 2))
