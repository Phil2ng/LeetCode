# DFS

class Solution:
    def permutation(self, s: str) -> List[str]:
        ans = []
        cs = list(s)

        def dfs(n):
            if n == len(cs):
                ans.append(''.join(cs))
            st = set()
            for i in range(n, len(cs)):
                if cs[i] in st:
                    continue
                st.add(cs[i])
                cs[i], cs[n] = cs[n], cs[i]
                dfs(n+1)
                cs[i], cs[n] = cs[n], cs[i]

        dfs(0)
        return ans
