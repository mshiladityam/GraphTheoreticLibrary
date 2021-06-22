# GraphTheoreticLibrary by mshiladityam

Source.cpp consists of a pbject oriented programming template for Graph Theoretic Problems in Competitive Programming. This serves as a blackbox to solve graph problems.

# Documentation

<h1> Graph Class </h1>
This C++ source file has a class named Graph, which represents a graph G(V, adj, dist), where V is the vertex set, represented by an integer n, which denotes the number of vertices in the graph. adj is the adjacency list of vertex and dist represents the distance of a vertex from a source vertex.

<h1> Djikstra class</h1>
this is invoked using class which takes the object Graph and the index of the source vertex as its parameter in its constructor function and updates the minimum distance
of each vertex from the source vertex. It also has a public member function, which outputs the parent vertex in the djikstra path from 
the source to the target vertex.
Works for both directed and undirected Graph objects

<h1> Floyd Warshall Class</h1> 
It has one 2D member vector: d[n][n].
It takes an object of class Graph as a parameter in its constructor function and applies the O(V^3) algorithm to represent d[i][j] = minimum distance from i to j.
Works for both directed and undirected Graph objects

<h1> DSU class </h1>
This has the path compression optimisation. This works in O(logn) per query on an average. This class is used for other algorithms as 
an object in there class (for example, for Kruskal's MST)

<h1> Prim's Clas </h1>
This is the O((V+E)LOG) algorithm to find out the weight of the minimum spanning tree of an object Graph.

It takes an object of class Graph as a parameter in its constructor function and returns the value of the weight of any MST of the graph, 
as well as any MST in the form of vector<pair<int, int>> (represents edges)

<h1> MultisourceBFS Class </h1>
It takes an object of class Graph as a parameter in its constructor function and changes the value of the public member vector dist[]
of class Graph object.
