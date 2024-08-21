from collections import deque
import sys
input = sys.stdin.readline

while True:
    string = input().rstrip()
    if string == '.': break

    idx = 0
    st = deque()
    balanced = True
    while string[idx] != '.':
        if string[idx] in '([':
            st.append(string[idx])
        elif string[idx] in ')]':
            if len(st) == 0:
                balanced = False
                break

            bracket = st.pop()
            if (string[idx] == ')' and bracket != '(') or (string[idx] == ']' and bracket != '['):
                balanced = False
                break
        
        idx += 1
    
    if len(st) != 0:
        balanced = False

    if balanced:
        print('yes')
    else:
        print('no')