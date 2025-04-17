def solution(citations):
    val = sorted(citations,reverse=True)
    
    for i, ans in enumerate(val):
        if(ans < i+1):
            return i
    
    return len(val)