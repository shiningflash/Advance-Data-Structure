from functools import cmp_to_key


def compare(a: str, b: str) -> bool:
    return len(a) - len(b)


words = ["ax", "vbsx", "2443d", "a"]
print(sorted(words, key=cmp_to_key(compare)))
