"""
BOJ 1991. 트리 순회
- 간단한 이진 트리 구현
    - Node는 Class로
    - Tree는 dict로 -> Key: 해당 노드의 값(str), value: Node
    - 이진트리고, 중복이 없으니까 가능한 구조다. 
- 항상 'A'가 루트노드가 된다
- 자식노드가 없는 경우에는 .으로 표현
"""
import sys
sys.stdin = open("input.txt", "r")

# 항상 'A'가 루트노드가 된다
# 자식노드가 없는 경우에는 .으로 표현

# Node 정의
class Node:
    # 생성자
    def __init__(self, item, left, right):
        self.item = item
        self.left = left
        self.right = right

# 순회 함수 정의
def preorder(node): # 루트 - 왼 - 오
    print(node.item, end='')
    if node.left != '.':
        preorder(tree[node.left])
    if node.right != '.':
        preorder(tree[node.right])

def inorder(node): # 왼 - 루트 - 오
    if node.left != '.':
        inorder(tree[node.left])
    print(node.item, end='')
    if node.right != '.':
        inorder(tree[node.right])

def postorder(node): # 왼 - 오 - 루트
    if node.left != '.':
        postorder(tree[node.left])
    if node.right != '.':
        postorder(tree[node.right])
    print(node.item, end='')
        
# 입력받기
n = int(input())
tree = {} # 신기하네.. 전역변수로 안줘도 잘 알아듣네 ...

for i in range(n):
    item, left, right = map(str, input().split() )
    tree[item] = Node(item, left, right)
    # print(f'{item}  {left}  {right}')

preorder(tree['A'])
print()

inorder(tree['A'])
print()

postorder(tree['A'])
print()