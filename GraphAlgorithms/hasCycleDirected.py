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


'''
Improvised code for cycle detection in graph using iterative DFS.
Using 3 color dfs problem, -1 indicates undiscivered nodes, 0 indicated discovered nodes, 1 indicates processed nodes.
When the node's state is already discovered and it encounters in the stack to be discovered again, then there exists cycle.
'''
UNDISCOVERED = -1
DISCOVERED = 0
PROCESSED = 1
state = [UNDISCOVERED] * len(graph)
def hasCycle(v: int) -> bool:
    stack = [(v, 0)]
    while stack:
        curr, pos = stack[-1]
        #print(curr,pos)
        if state[curr] == PROCESSED:
            stack.pop()
            continue
        if state[curr] == DISCOVERED and pos == 0:
            return True
        if pos == 0:
            state[curr] = DISCOVERED

        for i in range(pos, len(graph[curr])):
            stack[-1] = curr, pos + 1
            descendant = graph[curr][i]
            stack.append((descendant, 0))
            break
        else:
            #print(curr)
            state[curr] = PROCESSED
            #print(state)
    return False
