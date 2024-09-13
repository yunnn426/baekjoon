import sys
input = sys.stdin.readline

string = input().rstrip()
st = []

for i in range(len(string)):
    st.append(string[i])
    if st[-4:] == ['P', 'P', 'A', 'P']:
        for i in range(4):
            st.pop()
        st.append('P')

if st == ['P', 'P', 'A', 'P'] or st == ['P']:
    print('PPAP')
else:
    print('NP')