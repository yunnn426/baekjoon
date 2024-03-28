import sys

n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
oper = list(map(int, sys.stdin.readline().split()))
add = oper[0]
minus = oper[1]
mul = oper[2]
div = oper[3]

maxa = -sys.maxsize - 1
mina = sys.maxsize

def search(idx, res, cnt):
    if cnt == n:
        global maxa, mina
        maxa = max(res, maxa)
        mina = min(res, mina)
        return

    global add, minus, mul, div
    if add > 0:
        add -= 1
        search(idx + 1, res + arr[idx], cnt + 1)
        add += 1
    if minus > 0:
        minus -= 1
        search(idx + 1, res - arr[idx], cnt + 1)
        minus += 1
    if mul > 0:
        mul -= 1
        search(idx + 1, res * arr[idx], cnt + 1)
        mul += 1
    if div > 0:
        div -= 1
        if res < 0: 
            newres = ((-1 * res) // arr[idx] * -1)
        else:
            newres = res // arr[idx]
        search(idx + 1, newres, cnt + 1)
        div += 1

search(1, arr[0], 1)
print(maxa)
print(mina)