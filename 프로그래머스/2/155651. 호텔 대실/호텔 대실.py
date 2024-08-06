def solution(book_time):
    answer = 0
    n = len(book_time)
    book_time = sorted(book_time)
    
    # 종료 시간을 청소 이후로 갱신
    for i in range(n):
        clean = int(book_time[i][1][3])
        
        # string 수정을 위해 리스트 사용
        lst = list(book_time[i][1])
        if clean < 5:
            clean += 1
            lst[3] = str(clean)
        # 50~59분 사이
        else:
            clean = 0
            lst[3] = str(clean)
            # 09시, 19시
            if lst[1] == '9':
                hour = int(book_time[i][1][0])
                lst[0] = str(hour + 1)
                lst[1] = '0'
            else:
                hour = int(book_time[i][1][1])
                lst[1] = str(hour + 1)
            
        book_time[i][1] = ''.join(lst)
    
    # 각 객실의 종료 시간
    end_time = []
    end_time.append(book_time[0][1])
    
    for i in range(1, n):
        start = book_time[i][0]
        end = book_time[i][1]
        
        isFull = True
        for j in range(len(end_time)):
            room_end = end_time[j]

            # 시작 시간이 종료 시간보다 늦으면 해당 객실 배정 가능
            if start >= room_end:
                end_time[j] = end
                isFull = False
                break
        
        # 새로운 객실이 필요
        if isFull:
            end_time.append(end)
              
    return len(end_time)