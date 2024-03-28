import sys

n = int(sys.stdin.readline())
tree = []
for _ in range(n):
    arr = list(map(str, sys.stdin.readline().split()))
    tree.append(arr)

root = tree[0][0]

def preorder(node):
    # node에 연결된 다른 정점 찾기
    print(node, end="")
    for i in range(n):
        if tree[i][0] == node: # 첫 열이 찾고자 하는 노드
            for j in range(1, 3):
                if tree[i][j] != ".":
                    preorder(tree[i][j])

def inorder(node):
    for i in range(n):
        if tree[i][0] == node:
            if tree[i][1] != '.':
                inorder(tree[i][1])
            print(node, end="")
            if tree[i][2] != '.':
                inorder(tree[i][2])
                

def postorder(node):
    for i in range(n):
        if tree[i][0] == node:
            for j in range(1, 3):
                if tree[i][j] != '.':
                    postorder(tree[i][j])
    
    print(node, end="")

preorder(root)
print()
inorder(root)
print()
postorder(root)
print()