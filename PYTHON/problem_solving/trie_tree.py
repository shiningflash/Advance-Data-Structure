"""
Trie (Prefix Tree) Implementation

Example:
word = "hello"
search = "hello"
Output: True
"""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.end_of_word = False


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root

        for c in word:
            if c not in node.children:
                node.children[c] = TrieNode()
            node = node.children[c]

        node.end_of_word = True

    def search(self, word: str) -> bool:
        node = self.root

        for c in word:
            if c not in node.children:
                return False
            node = node.children[c]

        return node.end_of_word


word = "hello"
search = "hello"

trie = Trie()
trie.insert(word)
print(trie.search(search))
