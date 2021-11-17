from typing import List


class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        # 找出度为1的节点
        map = {}
        for path in paths:
            if path[0] in map.keys():
                map[path[0]] += 1
            else:
                map[path[0]] = 1

            if path[1] in map.keys():
                map[path[1]] -= 1
            else:
                map[path[1]] = -1

        for key in map.keys():
            if map[key] <= -1:
                return key