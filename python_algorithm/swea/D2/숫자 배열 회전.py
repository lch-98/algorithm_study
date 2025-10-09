T = int(input())

for tc in range(T):
    N = int(input())
    maze = [list(map(int, input().split())) for _ in range(N)]
    clock_90 = list(map(list, zip(*maze[::-1])))
    clock_180 = list(map(list, zip(*clock_90[::-1])))
    clock_270 = list(map(list, zip(*clock_180[::-1])))
    
    print(f"#{tc+1}")
    for i in range(len(maze)):
        print("".join(map(str,clock_90[i])), end=" ")
        print("".join(map(str,clock_180[i])), end=" ")
        print("".join(map(str,clock_270[i])), end="\n")