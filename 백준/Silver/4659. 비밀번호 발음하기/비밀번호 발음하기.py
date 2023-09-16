vowel = 'aeiou'
consonants = 'bcdfghjklmnpqrstvxyz'

def func1(pw):
    isValid = False
    #1) a e i o u 있는지 체크
    for a in vowel:
        if a in pw:
            isValid = True
    
    return isValid

def func2(pw):
    isValid = True
    #2) 모음 세개, 자음 3개 연속 X
    for i in range(len(pw)-2):
        if (pw[i] in vowel) and (pw[i+1] in vowel) and (pw[i+2] in vowel):
            isValid = False
            break
        elif (pw[i] in consonants) and (pw[i+1] in consonants) and (pw[i+2] in consonants):
            isValid = False
            break
    
    return isValid
    
def func3(pw):
    isValid = True
    #3) 같은 글자가 연속적으로 두번 오면 안되나, ee 와 oo는 허용한다.
    for i in range(len(pw)-1):
        if pw[i] == pw[i+1]:
            if pw[i] == 'e' or pw[i] == 'o':
                continue
            else:
                isValid = False
                break
    
    return isValid


while(True):
    pw = input()
    if pw == "end":
        break

    if func1(pw) and func2(pw) and func3(pw):
        print("<" + pw + "> is acceptable.")
    else:
        print("<" + pw + "> is not acceptable.")
    