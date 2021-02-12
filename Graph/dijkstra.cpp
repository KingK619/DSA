#include <iostream>
#include <climits>
#include <bits/stdc++.h>
using namespace std;

int minimumDist(int dist[], bool Tset[])
{
    int min = INT_MAX, index;

    for (int i = 0; i < 6; i++)
    {
        if (Tset[i] == false && dist[i] <= min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void printMST(int dist[])
{
    cout << "Vertex  Dist\n";
    for (int i = 0; i < 6; i++)
        cout << i << " \t" << dist[i] << " \n";
}

void Dijkstra(int graph[6][6])
{
    int dist[6];
    bool Tset[6];

    memset(dist, INT_MAX, 6);
    dist[0] = 0;
    memset(Tset, false, 6);

    for (int i = 0; i < 6; i++)
    {
        int u = minimumDist(dist, Tset);
        Tset[u] = true;

        for (int i = 0; i < 6; i++)
        {
            if (graph[u][i] && Tset[i] == false && dist[u] + graph[u][i] < dist[i])
                dist[i] = dist[u] + graph[u][i];
        }
    }
    printMST(dist);
}

int main()
{
    int graph[6][6] = {
        {0, 10, 20, 0, 0, 0},
        {10, 0, 0, 50, 10, 0},
        {20, 0, 0, 20, 33, 0},
        {0, 50, 20, 0, 20, 2},
        {0, 10, 33, 20, 0, 1},
        {0, 0, 0, 2, 1, 0}};
    Dijkstra(graph);
    return 0;
}
