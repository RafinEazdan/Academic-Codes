 #include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <limits.h>
#define V 200

int minDistance(int dist[], bool check[])
{
	int min = 10000, min_index;
	for (int v = 0; v < V; v++)
		if (check[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}
void print(int dist[])
{
	for (int i = 1; i <V; i++)
		cout << "s -> " << char('A'+i-1) <<" = "<< dist[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
	int dist[V];

	bool check[V];
	for (int i = 0; i < V; i++)
		dist[i] = 10000, check[i] = false;
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, check);

		check[u] = true;

		for (int v = 0; v < V; v++)

			if (!check[v] && graph[u][v]
				&& dist[u] != 10000
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	print(dist);
}

int main()
{

	int graph[V][V];
    ifstream file;
    file.open("file.txt");
    
    for (int i = 0; i < V; i++)
    {
        for (int  j = 0; j < V; j++)
        {
            file>>graph[i][j];
        }
        
    }
	clock_t start = clock();
	dijkstra(graph, 0);
	clock_t end = clock();
	cout<<"Time required: "<< ((float)(end - start) / CLOCKS_PER_SEC)*1000<<"ms"<<endl;
    file.close();
	return 0;
}
