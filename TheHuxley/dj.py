import queue

def dijkstra(graph, source):
  
  dist = {}
  
  for key in graph:
    dist[key] = 2**32 # Distância de todos os vertices com infinito 
  dist[source] = 0
  pq = queue.PriorityQueue()
  pq.put( [0,source] )
  while not pq.empty():
    node = pq.get() # Primeiro valor é a distância e o segundo o vértice
    if( dist[ node[1] ] < node[0] ):
    	continue
    for e in graph[ node[1] ] :
    	if dist[ e[0] ] > node[0] + e[1] :
    		dist[ e[0] ] = node[0] + e[1]
    		pq.put( [dist[ e[0] ], e[0] ] )
  return dist

t = int(input())
print(t, "TC")
for num in range(t):
	graph = {}
	vertex, edges = map(int,input().split())
	print(vertex, edges, "vertices e arestas")
	for i in range(edges):
		u,v,c = map(int,input().split())
		print(u,v,c)
		if u not in graph:
			graph[u] = []
		if v not in graph:
			graph[v] = []
		graph[u] += [[v,c]]
		graph[v] += [[u,c]]

		ans = 0

		delivery = map(int,input())
		home = list( map(int,input().split()) )
		dist = dijkstra(graph,1)
		for i in home:
			ans += dist[i]*2
	print( "caso {}: {}".format(num+1,ans) )	