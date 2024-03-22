import sys
s = sys.stdin.readline()
st = []

answer = 0
for c in s:
    if answer == -1:
        break

    if c == '(':
        st.append('(')

    elif c == ')':
        add = 0
        while (True): 
            if (len(st) == 0): ## 뽑을게 없음
                answer = -1
                break
            top = st.pop()
            if top == '(':
                break
            if top == '[':
                answer = -1
                break
            add += top
        if add == 0:
            st.append(2)
        else:
            st.append(add * 2)
    
    elif c == '[':
        st.append('[')

    elif c == ']':
        add = 0
        while (True):
            if (len(st) == 0): ## 뽑을게 없음
                answer = -1
                break
            top = st.pop()
            if top == '[':
                break
            if top == '(':
                answer = -1
                break
            add += top
        if add == 0:
            st.append(3)
        else:
            st.append(add * 3)
    else:
        while (len(st) != 0):
            i = st.pop()
            if i != '(' and i != ')' and i != '[' and i != ']':
                answer += i
            else:
                answer = -1

if answer == -1:
    print(0)
else:
    print(answer)
    
