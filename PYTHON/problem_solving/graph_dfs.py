"""
Graph (BFS / DFS)
Problem: Number of Islands

Given a grid of "1" (land) and "0" (water), count islands.

Example:

grid =
[
["1","1","0","0"],
["1","1","0","0"],
["0","0","1","0"],
["0","0","0","1"]
]

Output: 3
"""


def dfs(grid: list[list[str]], r: int, c: int) -> None:
    if r < 0 or c < 0 or r >= len(grid) or c >= len(grid[0]) or grid[r][c] == "0":
        return

    grid[r][c] = "0"

    dfs(grid, r + 1, c)
    dfs(grid, r - 1, c)
    dfs(grid, r, c + 1)
    dfs(grid, r, c - 1)


def count_island(grid: list[list[str]]) -> int:
    if not grid:
        return 0

    count = 0

    rows, cols = len(grid), len(grid[0])
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == "1":
                count += 1
                dfs(grid, r, c)

    return count


grid = [
    ["1", "1", "0", "0"],
    ["1", "1", "0", "0"],
    ["0", "0", "1", "0"],
    ["0", "0", "0", "1"],
]
print(count_island(grid))
