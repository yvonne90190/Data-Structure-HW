# Study the Properties of "Small World" and Compare Different Dyjkstra Implementation

## Steps
1.	Generate a cycle of 1000 nodes. Each edge has length 1.
2.	Add 𝑥 random edges. Each random edge has the same length 𝑦. 
3.	Sample 𝑧 pairs of source and destination, and compute the average shortest distance (𝑑) of these 𝑧 source-destination pairs.  
  
Use 2 different structures of heaps. (array and heap)  
  
## Report contain
1.	A picture of the graph with 𝑥 = 100.
2.	Responses to the following questions: 
a.	What is the relationship between 𝑥 and 𝑑? 
b.	What is the relationship between 𝑦 and 𝑑?
c.	How to choose 𝑧 to obtain a reasonable approximation of the true average shortest distance between all pairs of source and destination? 
d.	Which implementation of Dijkstra's Algorithm is faster?

## Execution
compile and run experiments:
```
./run.sh
```
