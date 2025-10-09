def solution(maps):
    n = len(maps)
    m = len(maps[0])
    
    queue = [(0, 0, 1)]
    maps[0][0] = 0
    
    while queue:
        x, y, dist = queue.pop(0)
        
        if x == n - 1 and y == m - 1:
            return dist

        for dx, dy in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and maps[nx][ny] == 1:
                queue.append((nx, ny, dist + 1))
                maps[nx][ny] = 0        
            
    return -1