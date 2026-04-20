"""
Binary Search

Problem: Search in Rotated Sorted Array

Example:

nums = [4,5,6,7,0,1,2]
target = 0
Output = 4
Idea

Binary search but check which half is sorted.
"""


def search_in_rotated_sorted_array(nums: list[int], target: int) -> int:
    left, right = 0, len(nums) - 1

    while left <= right:
        mid = (left + right) // 2

        if nums[mid] == target:
            return mid

        if nums[left] <= nums[mid]:  # left half is sorted
            if nums[left] <= target < nums[mid]:  # target is in the left half
                right = mid - 1
            else:
                left = mid + 1
        else:  # right half is sorted
            if nums[mid] < target <= nums[right]:  # target is in the right half
                left = mid + 1
            else:
                right = mid - 1

    return -1


print(search_in_rotated_sorted_array([4, 5, 6, 7, 0, 1, 2], 0))
