import heapq
import networkx as nx
import matplotlib.pyplot as plt



def calculate_distances(graph, starting_vertex):
    distances = {vertex: float('infinity') for vertex in graph}
    parents = {vertex:None for vertex in graph}

    distances[starting_vertex] = 0

    pq = [(0, starting_vertex)]
    heapq.heapify(pq)
    while len(pq) > 0:
        current_distance, current_vertex = heapq.heappop(pq)


        # Nodes can get added to the priority queue multiple times. We only
        # process a vertex the first time we remove it from the priority queue.
        if current_distance > distances[current_vertex]:
            continue

        for neighbor, weight in graph[current_vertex].items():
            distance = current_distance + weight

            # Only consider this new path if it's better than any path we've
            # already found.
            if distance < distances[neighbor]:
                distances[neighbor] = distance
                parents[neighbor] = current_vertex
                #Note that this is not perfect, since we will have multiple distances for one node.
                #This will be popped out at the end, but it will increase the run time.
                #It should have been possible to update the weight
                #Note that this is not perfect, since we will have multiple distances for one node.
                #This will be popped out at the end, but it will increase the run time.
                #It should have been possible to update the weight
                heapq.heappush(pq, (distance, neighbor))
        print(pq)
    return distances,parents

def shortest_path(graph,distances,parents,starting_vertex,ending_vertex):
    path = [ending_vertex]
    parent= None 
    current_node= ending_vertex
    while parent != starting_vertex: 
        parent = parents[current_node]
        path.append(parent)
        current_node = parent
    path.reverse()
    return path

#Run the program
example_graph = {
    'X': {'V': 7, 'W': 5,'S':6},
    'W': {'F': 4},
    'S': {'T': 4},
    'T': {'F': 3},
    # 'G': {'F':1 },
    'V': {'F': 1},
    'F': {},
}
distances,parents = calculate_distances(example_graph, 'X')
path = shortest_path(example_graph,distances,parents,'X','F')
print(distances)
print(parents)
print(path)

#Plot with weights
gr = {
    from_: {
        to_: {'weight': w}
        for to_, w in to_nodes.items()
    }
    for from_, to_nodes in example_graph.items()
}
G = nx.from_dict_of_dicts(gr, create_using=nx.DiGraph)
pos=nx.spring_layout(G) # pos = nx.nx_agraph.graphviz_layout(G)
# pos = {'X': [0 ,0],
#  'W':     [0.5 ,0.5],
#  'V':     [0.5 ,-0.5],
#  # 'G':     [0.54,0.03],
#  'F':     [1 ,0]
#  }

nx.draw_networkx(G,pos)
labels = nx.get_edge_attributes(G,'weight')
nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
plt.show()
