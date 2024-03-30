H, W, N, M = input().split()
H = int(H)
W = int(W)
N = int(N)
M = int(M)

count = 0

if (H % (N + 1) != 0):
    a = H // (N + 1) + 1
else:
    a = H / (N + 1)

if (W % (M + 1) != 0):
    b = W // (M + 1) + 1
else:
    b = W / (M + 1)

count = int(a * b)
 
print(count)