import sys
input = sys.stdin.readline

string = input().strip()
string += "-" 

# + 끼리 모두 묶고 -로 빼줌
nums = []
num = ""
tmp = 0
for i in range(len(string)):
    if string[i] != '+' and string[i] != '-':
        num += string[i]
    else:
        tmp += int(num)
        num = ""
        if string[i] == '-':
            nums.append(tmp)
            tmp = 0

answer = nums.pop(0)
for i in nums:
    answer -= i
print(answer)