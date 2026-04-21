"""
Sort words by:

frequency
alphabetical order

Example input:

["apple","banana","apple","orange","banana","banana"]

Expected sorted order:

banana
apple
orange
"""

from collections import Counter


def sort_by_freq(words: list[str]) -> list[str]:
    freq = Counter(words)
    return sorted(freq.keys(), key=lambda x: (-freq[x], x))


words = ["apple", "banana", "apple", "orange", "banana", "banana"]
print(sort_by_freq(words))
