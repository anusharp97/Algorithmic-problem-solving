def iterativeDFS(node):
    visited = [0]*len(graph)
    stack = []
    stack.append(node)
    while stack:
        v = stack.pop()
        if visited[v]:
            continue
        visited[v] = True
        print(v, end='')
        adj = graph[v]
        for i in (range(len(adj))):
            u = adj[i]
            if not visited[u]:
                stack.append(u)

graph = [[2,3],[0,4],[1],[],[]]
iterativeDFS(0)

#output : 0 3 2 1 4
