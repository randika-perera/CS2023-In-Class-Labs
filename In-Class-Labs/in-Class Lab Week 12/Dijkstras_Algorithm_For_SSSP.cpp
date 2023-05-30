#include <iostream>
#include <climits>
#include <vector>
using namespace std;
const int V=6;      //Number of vertices. In this case, vertices are cities




/* Function that will find the vertex with the minimum distance */
int minDistance(int dist[], bool visited[]) 
{
    int minDist = INT_MAX;     //Initialize the minimum distance as maximum possible value
    int minIndex;
    for (int v=0;v<V;v++) 
    {
        if (!visited[v] && dist[v] <= minDist) 
        {
            minDist=dist[v];   //Update the minimum distance
            minIndex=v;        //Update the index of the vertex with minimum distance
        }
    }
    return minIndex;
}


/* Function that will print the shortest distance as well as the path taken for shortest distance from the source to each city */
void printShortestPaths(int dist[], const vector<int>& parent) 
{
    cout<<"City\tShortest Distance\tShortest Path"<<endl;
    for (int i=0;i<V;i++) 
    {
        cout<<i<<"\t"<<dist[i]<<"\t\t\t";
        vector<int> path;
        int j = i;
        while (j!=-1) 
        {
            path.push_back(j);      //Add the current city to the path
            j=parent[j];            //Move to the parent city
        }
        for (int k=path.size()-1;k>= 0;k--) 
        {
            cout<<path[k];          //Print the cities in the path
            if (k!=0) 
            {
                cout<<" -> ";
            }
        }
        cout<<endl;
    }
}


/* Dijkstra's algorithm to find the shortest path from the source city to all other cities */
void dijkstra(int graph[V][V], int source) 
{
    int dist[V];                              //Array to store the shortest distances from the source
    bool visited[V];                          //Array to track visited cities
    vector<int> parent(V,-1);                 //Array to store the parent of each city in the shortest path
    for (int i=0;i<V;i++) 
    {
        dist[i]=INT_MAX;                      //Initialize all distances as maximum possible value
        visited[i]=false;                     //Mark all cities as not visited
    }
    dist[source]=0;                           //Distance to source city from itself is always 0
    for (int count=0;count<V-1;count++) 
    {
        int u=minDistance(dist,visited);      //Find the vertex with minimum distance
        visited[u]=true;                      //Mark the vertex as visited
        for (int v=0;v<V;v++)                 //Update distances of adjacent cities if they are not visited and the new distance is shorter
        {
            if ( (!visited[v]) && (graph[u][v]) && (dist[u]!=INT_MAX) && ((dist[u]+graph[u][v])<dist[v]) ) 
            {
                dist[v]=dist[u]+graph[u][v];  // Update the distance
                parent[v]=u;                  // Update the parent city
            }
        }
    }
    printShortestPaths(dist, parent);         //Print the shortest distance as well as the path taken for shortest distance from the source to each city
}




int main() 
{

    //Weighted adjacency matrix for the graph in figure 1
    int graph[V][V] = 
    {
        {  0, 10,  0,  0, 15,  5 },
        { 10,  0, 10, 30,  0,  0 },
        {  0, 10,  0, 12,  5,  0 },
        {  0, 30, 12,  0,  0, 20 },
        { 15,  0,  5,  0,  0,  0 },
        {  5,  0,  0, 20,  0,  0 }
    };
    
    //Choose the source city
    int source = 0;   
    
    dijkstra(graph, source);
    
    return 0;

}

