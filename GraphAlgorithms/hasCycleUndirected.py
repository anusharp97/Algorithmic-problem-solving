def hasCycleUndirected(node):
    stack = []
    stack.append((node,-1))
    visited = [0]*len(graph)
    while stack:
        v,f = stack.pop()
        adj = graph[v]
        for i in (range(len(adj))):
            u = adj[i] 
            if not visited[u]:
                stack.append((u,v))
                visited[u] = True
            elif u!=f:
                return True
    return False
  
graph = [[2,3],[0,4],[1],[],[]]
# from node 0 edges exist to node 2 and node 3
# from node 1 edges exist to node 0 and node 4
#graph = [[1],[2],[0]]
print(hasCycleUndirected(0))


