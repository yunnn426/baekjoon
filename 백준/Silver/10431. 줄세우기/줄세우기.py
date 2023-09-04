P = int(input())

for i in range(P):
    nums = [int(x) for x in input().split()]
    TC = nums[0]
    
    count = 0
    for j in range(1, 21): #새로 들어온 사람
        for k in range(1, j): #비교할 사람 (앞쪽)
            if nums[k] > nums[j]:
                nums[j], nums[k] = nums[k], nums[j]
                count += 1
                
            
    print(TC, count)
