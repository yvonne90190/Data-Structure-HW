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
        vertex1 = i
        vertex2 = (i+1)%origiVertex_num
        G.add_edge(vertex1, vertex2, weight=1, color='r')
        graph.addEdge(vertex1, vertex2, 1)
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
        graph.addEdge(vertex1, vertex2, addiEdge_weight)
        weightArr[vertex1][vertex2]=addiEdge_weight #做djikstra會用到
        weightArr[vertex2][vertex1]=addiEdge_weight #做djikstra會用到

def SavePrintGraph():
    pos=nx.get_node_attributes(G,'pos')   # get the position of each node, used latter in order to draw
    edges = G.edges()  # get the edges, used latter
    colors = [G[u][v]['color'] for u,v in edges]   # get the color of the edges, used latter
    nx.draw(G,pos, with_labels=True, edge_color=colors)    # draw nodes with labels on it, and colored edges (lable is the number on the vertex)
    labels = nx.get_edge_attributes(G,'weight')   # get the edge weight, used latter
    nx.draw_networkx_edge_labels(G,pos,edge_labels=labels)  # put edge weight on the edges
    script_dir = os.path.dirname(__file__)      # get the current directory address
    results_dir = os.path.join(script_dir, 'ResultsPhoto/')   # go to the directory 'ResultsPhoto' under current directory
    sample_file_name = str(origiVertex_num) + "_" + str(addiEdge_num) + "_" + str(sample_num) + "_" + str(addiEdge_weight)  # create file name
    if not os.path.isdir(results_dir):  # if the directory do not exit, create one
        os.makedirs(results_dir)
    plt.savefig(results_dir + sample_file_name)   # Save into the directory as the file name 
    #plt.show() # Show on screen

def SampleAvgShortestDistance():
    samples = np.random.choice(shortest_distance_arr, size=sample_num, replace=False)
    #print("multiple random choice from numpy 1-D array without replacement ", samples)
    #print("sample:", sum(samples)/sample_num)
    return sum(samples)/sample_num

    
if __name__ == '__main__':
    origiVertex_num = int(sys.argv[1])
    addiEdge_num = int(sys.argv[2])
    sample_num = int(sys.argv[3])
    addiEdge_weight = int(sys.argv[4])
    filename = sys.argv[5]
    
        
    G=nx.Graph()
    weightArr = [[0]*(origiVertex_num)  for i in range(origiVertex_num)]
    graph = dijkstra.Graph(origiVertex_num)
    
    OrigiVertex()
    addAddiEdges()
    real_shortest_distance = 0
    sample_shortest_distance = 0
    Time = 0
    
    for src in range(0,1000):   # average 1000 times of dijkstra (source vertex = 0, 1, 2, ..., 1000)
        start = time.time()
        shortest_distance_arr = graph.dijkstra(src)
        end=time.time()
        Time += end-start
        
        real_shortest_distance += sum(shortest_distance_arr) / (origiVertex_num+addiEdge_num)
        sample_shortest_distance += SampleAvgShortestDistance()
        
    SavePrintGraph()
    with open(filename, 'a') as csvfile:
            writer=csv.writer(csvfile)
            writer.writerow([origiVertex_num, addiEdge_num, sample_num, addiEdge_weight, sample_shortest_distance/1000, real_shortest_distance/1000, Time/1000])
    
    




#nx.draw_networkx_edge_labels(G, nx.get_node_attributes(G,'pos'),edge_labels=edge_labels)
#nx.draw(G,nx.get_node_attributes(G,'pos'),with_labels=True,node_size=300,node_color=color_map)
#plt.show()    



