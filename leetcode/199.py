"""
LeetCode - 199. Binary Tree Right Side View
- 트리문제인척하는 BFS문제
"""

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        
        ans = []
        # 예외처리
        if root is None:
            return ans
        
        # bfs 돌리기
        queue = []

        # 시작점 넣기
        queue.append(root)
        
        while len(queue) != 0:
            # 이번 루프의 큐 사이즈 미리 구해놓기
            size = len(queue)

            for i in range(size):
                # 큐에서 하나 꺼내기
                x = queue[0]
                queue.pop(0)

                # 정답 체크 (끝까지 다 왔으면 ..)
                if i == size-1:
                    ans.append(x.val)
                
                # 왼 -> 오 순서대로 다음 정점 방문
                if x.left is not None:
                    queue.append(x.left)
                if x.right is not None:
                    queue.append(x.right)
        
        return ans