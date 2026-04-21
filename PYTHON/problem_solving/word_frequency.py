"""
Write a Python function:

word_frequency(text: str) -> dict[str, int]
Requirements
Count how many times each word appears in the text.
The counting should be case-insensitive.
Ignore punctuation (.,!?;: etc).
Return a dictionary with:
{
    "word": count
}
Example

Test case:

text = "Hello, hello world! Hello Python."

Expected output:

{
    "hello": 3,
    "world": 1,
    "python": 1
}
"""

import re
from collections import Counter


def word_frequency(text: str) -> dict[str, int]:
    text_lower = text.lower()
    text_cleaned = re.findall(r"\b[a-z]+\b", text_lower)
    print(text_cleaned)
    return dict(Counter(text_cleaned))


text = "Hello, hello world! Hello Python."
print(word_frequency(text))
