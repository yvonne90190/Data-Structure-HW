import networkx as nx
import matplotlib
matplotlib.use('TkAgg')
import matplotlib.pyplot as plt
import random
import math
import sys
import csv
import dijkstra
import time
import os
import numpy as np

#n=input()
#n=int(n)

def OrigiVertex():
    row=[]
    col=[]
    # Create the Orginal 1000 vertexs 
    for i in range(0, origiVertex_num):
        row.append(math.sin(i*2*math.pi/origiVertex_num))
        col.append(math.cos(i*2*math.pi/origiVertex_num))
        G.add_node(i,pos=(row[i],col[i]))
    # Connect the 1000 vertexs one by one 
    for i in range(0, origiVertex_num):
        vertex1 = i
        vertex2 = (i+1)%origiVertex_num
        G.add_edge(vertex1, vertex2, weight=1, color='r')
        weightArr[vertex1][vertex2]=1 #做djikstra會用到
        weightArr[vertex2][vertex1]=1 #做djikstra會用到   

def addAddiEdges():
    # Selet vertex pairs and add edge between the two vertexs
    for i in range(0, addiEdge_num):
        for i in range (0,5):
            vertex1 = random.randint(0, origiVertex_num-1)
            vertex2 = random.randint(0, origiVertex_num-1)
            if (vertex1 != vertex2) and weightArr[vertex1][vertex2]==0:
                break
        G.add_edge(vertex1, vertex2, weight=addiEdge_weight, color='b')
        weightArr[vertex1][vertex2]=addiEdge_weight #做djikstra會用到
        weightArr[vertex2][vertex1]=addiEdge_weight #做djikstra會用到

def SavePrintGraph():
    # Print the Graph
    pos=nx.get_node_attributes(G,'pos')
    edges = G.edges()
    colors = [G[u][v]['color'] for u,v in edges]
    nx.draw(G,pos, with_labels=True, edge_color=colors)
    labels = nx.get_edge_attributes(G,'weight')
    nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)
    script_dir = os.path.dirname(__file__)
    results_dir = os.path.join(script_dir, 'ResultsPhoto/')
    sample_file_name = str(origiVertex_num) + "_" + str(addiEdge_num) + "_" + str(sample_num) + "_" + str(addiEdge_weight)
    if not os.path.isdir(results_dir):
        os.makedirs(results_dir)
    plt.savefig(results_dir + sample_file_name)

def SampleAvgShortestDistance():
    samples = np.random.choice(shortest_distance_arr, size=sample_num, replace=False)
    #print("multiple random choice from numpy 1-D array without replacement ", samples)
    return sum(samples)/sample_num

    
if __name__ == '__main__':
    origiVertex_num = int(sys.argv[1])
    addiEdge_num = int(sys.argv[2])
    sample_num = int(sys.argv[3])
    addiEdge_weight = int(sys.argv[4])
    filename = sys.argv[5]
    
    G=nx.Graph()
    weightArr = [[0]*(origiVertex_num)  for i in range(origiVertex_num)]
        
    OrigiVertex()
    addAddiEdges()
    SavePrintGraph()
            
    g = dijkstra.Graph(origiVertex_num)
    g.graph = weightArr
    real_shortest_distance = 0
    sample_shortest_distance = 0
    Time = 0
    
    for src in range(0,1000):
        start = time.time()
        shortest_distance_arr = g.dijkstra(src)
        end=time.time()
        Time += end-start
            
        real_shortest_distance += sum(shortest_distance_arr) / (origiVertex_num+addiEdge_num)
        sample_shortest_distance += SampleAvgShortestDistance()
        
    with open(filename, 'a') as csvfile:
            writer=csv.writer(csvfile)
            writer.writerow([origiVertex_num, addiEdge_num, sample_num, addiEdge_weight, sample_shortest_distance/1000, real_shortest_distance/1000, Time/1000])

        #nx.draw_networkx_edge_labels(G, nx.get_node_attributes(G,'pos'),edge_labels=edge_labels)
        #nx.draw(G,nx.get_node_attributes(G,'pos'),with_labels=True,node_size=300,node_color=color_map)
        #plt.show()    