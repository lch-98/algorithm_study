def solution(operations):
    answer = []
    for i in range(len(operations)):
        x, y = operations[i].split(" ")
        
        if x == "I":
            answer.append(int(y))
            
        if x == "D" and y == "1":
            if answer:
                answer.pop(answer.index(max(answer)))
            else:
                continue
                
        if x == "D" and y == "-1":
            if answer:
                answer.pop(answer.index(min(answer)))
            else:
                continue
        
    if answer:
        final = [max(answer), min(answer)]
        return final
    else:
        return [0, 0]