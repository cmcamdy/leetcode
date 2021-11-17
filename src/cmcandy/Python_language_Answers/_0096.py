class Solution:
    def catalan(self, n: int) -> int:
        if n == 0 or n == 1:
            return 1
        return (4 * n - 2) * self.catalan(n - 1) // (n + 1)

    def numTrees(self, n: int) -> int:
        return self.catalan(n)