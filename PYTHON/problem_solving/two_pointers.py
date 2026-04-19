"""
Two Pointers Technique

Problem: Container With Most Water

Time Complexity: O(N)
Space Complexity: O(1)

height = [1,8,6,2,5,4,8,3,7]
Output → 49
"""


def max_area(height: list[int], output) -> int:
    left = 0
    right = len(height) - 1
    max_water = 0

    while left < right:
        width = right - left
        height_water = min(height[left], height[right])

        max_water = max(max_water, width * height_water)

        if height[left] < height[right]:
            left += 1
        else:
            right -= 1

    return max_water


print(max_area([1, 8, 6, 2, 5, 4, 8, 3, 7], 49))
