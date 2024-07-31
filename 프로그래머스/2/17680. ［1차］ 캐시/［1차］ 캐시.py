def solution(cacheSize, cities):
    answer = 0
    
    cache = {}
    
    if cacheSize == 0:
        return len(cities) * 5
    
    for city in cities:
        city = city.upper()
        
        # 모든 캐시의 값 +1
        for k in cache.keys():
            cache[k] += 1
            
        # cache full
        if len(cache) > cacheSize:
            # 가장 오래된 것 찾기
            lru_city = ''
            lru_val = 0
            for k, v in cache.items():
                if v >= lru_val:
                    lru_val = v
                    lru_city = k
            
            del cache[lru_city]
            
        # cache miss 후 캐시에 추가
        if city not in cache:
            answer += 5
            cache[city] = 0
        # cache hit 후 값 0으로
        else:
            answer += 1
            cache[city] = 0
        
        
    
    return answer