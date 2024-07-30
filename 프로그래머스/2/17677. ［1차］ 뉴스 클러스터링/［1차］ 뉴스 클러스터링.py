def solution(str1, str2):
    answer = 0
    len1 = len(str1)
    len2 = len(str2)
    
    # 문자열1을 다중집합으로
    arr1 = []
    for i in range(0, len1 - 1, 1):
        c1, c2 = str1[i].upper(), str1[i + 1].upper()
        if not (65 <= ord(c1) <= 90):
            continue
        if not (65 <= ord(c2) <= 90):
            continue
        tmpstr = str1[i : i + 2].upper()
        arr1.append(tmpstr)
    set1 = set(arr1)
    
    # 문자열2를 다중집합으로
    arr2 = []
    for i in range(0, len2 - 1, 1):
        c1, c2 = str2[i].upper(), str2[i + 1].upper()
        if not (65 <= ord(c1) <= 90):
            continue
        if not (65 <= ord(c2) <= 90):
            continue
        tmpstr = str2[i : i + 2].upper()
        arr2.append(tmpstr)
    set2 = set(arr2)
    
    
    # 다중집합에서의 교집합, 합집합 구하기
    inter = set1 & set2
    union = set1 | set2
    
    up = 0
    down = 0
    
    for it in union:
        n = min(arr1.count(it), arr2.count(it))
        m = max(arr1.count(it), arr2.count(it))
        print(n, m)
        up += n
        down += m
    
    
    # 자카드 유사도 
    j = 1
    if down != 0:
        j = up / down
    j *= 65536
    answer = j // 1
    
    return answer