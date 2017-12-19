import queue

def dijkstra(graph, source):
  for key in graph:
    dist[key] = 2**32 # Dist�ncia de todos os vertices com infinito 
  dist[source] = 0
  pq = queue.PriorityQueue()
  pq.put( [0,source] )
  while(not pq.empty()):
    node = pq.get() # Primeiro valor � a dist�ncia e o segundo o v�rtice
    if( dist[ node[1] ] < node[0] ): continue
    for e in graph[ node[1] ]:
        if dist[ e[0] ] > node[0] + e[1] : # Verifica se dimunimos a dist�ncia
          dist[ e[0] ] = node[0] + e[1] # Atualiza a dist�ncia
          pq.put( [dist[ e[0] ],e[0] ] ) # Adiciona na fila de prioridade
  return dist

t = int(input())
for num in range(t):
  graph = {}
  dist = {}
  pedidos = []
  vertex, edges = map(int,input().split())
  for i in range(edges):
    u, v, c = map(int,input().split())
    if u not in graph:
      graph[u] = []
    if v not in graph:
      graph[v] = []
    graph[u] += [[v,c]]
    graph[v] += [[u,c]]
  ans = 0
  k = int(input())
  pedidos = list(map(int, input().split(' ')))
  dijkstra(graph, 1)
  for i in range(k):
    ans += 2*dist[pedidos[i]]
  print('caso ' + str(num + 1) + ': ' + str(ans))