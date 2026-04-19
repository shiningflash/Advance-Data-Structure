"""
Sliding Window

Problem: Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example:

Input:  "abcabcbb"
Output: 3
Explanation: "abc"
"""


def length_of_longest_substring_without_repeating_character(s: str) -> int:
    seen = set()

    left = 0
    max_length = 0

    for right in range(len(s)):
        while s[right] in seen:
            seen.remove(s[left])
            left += 1

        seen.add(s[right])
        max_length = max(max_length, right - left + 1)

    return max_length


print(length_of_longest_substring_without_repeating_character("abcabcbb"))
