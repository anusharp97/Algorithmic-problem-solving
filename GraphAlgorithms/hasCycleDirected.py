WHITE = 0
GRAY = 1
BLACK = 2
ENTER = 0
EXIT = 1
def hasCycleDirected(start):
    state = {v: WHITE for v in range(len(graph))}
    stack = [(ENTER, start)]
    while stack:
        act, v = stack.pop()
        if act == EXIT:
            #print('Exit', v)
            state[v] = BLACK
        else:
            #print('Enter', v)
            state[v] = GRAY
            stack.append((EXIT, v))
            for n in graph[v]:
                if state[n] == GRAY:
                    #print('Found cycle at', n)
                    return True
                elif state[n] == WHITE:
                    stack.append((ENTER, n))
    return False
graph = [[],[0,2,3,4],[3],[4],[]] #no cycle
graph = [[],[0,2,3,4],[3],[4],[1]] # has cycle at node 1
print(hasCycleDirected(1))
