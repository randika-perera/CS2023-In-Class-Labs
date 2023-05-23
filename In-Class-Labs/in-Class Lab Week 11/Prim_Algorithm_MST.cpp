#include <iostream>
#include <vector>
#include <climits>
using namespace std;



// Function to find the vertex with the minimum key value
int min_key(const vector<int>& key , const vector<bool>& mst_set , int V) 
{

    int min=INT_MAX,min_index;

    for (int v=0;v<V;v++) 
    {
        // If the vertex is not in the minimum spanning tree set and has a smaller key value, update the minimum
        if ((!(mst_set[v])) && (key[v]<min)) 
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;

}




// Function to print the minimum spanning tree
void print_mst(const vector<int>& parent , const vector<vector<int>>& graph , int V) 
{

    cout<<"Edge\tWeight\n";

    for (int i=1;i<V;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<"\n";
    }

}




// Prim's algorithm to find the minimum spanning tree
void prims_algorithm(const vector<vector<int>>& graph , int V) 
{

    vector<int> parent(V);              // Store the parent of each vertex in the minimum spanning tree    
    vector<int> key(V, INT_MAX);        // Store the key value of each vertex
    vector<bool> mst_set(V, false);     // Track vertices included in the minimum spanning tree

    key[0]=0;          // Start with the first vertex
    parent[0]=-1;      // First vertex is the root of the minimum spanning tree

    for (int count=0;count<(V-1);count++) 
    {

        int u=min_key(key, mst_set , V);     // Find the vertex with the minimum key value
        mst_set[u]=true;                     // Include the vertex in the minimum spanning tree

        // Update the key values and parent pointers of the adjacent vertices
        for (int v=0;v<V;v++) 
        {
            if ( (graph[u][v]) && (!mst_set[v]) && (graph[u][v])<key[v] )
            {
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    // Print the minimum spanning tree
    print_mst(parent, graph, V);

}




int main() 
{
    
    // Expressing the adjacency matrix of the given graph as 2D vector
    vector<vector<int>> graph = { 
                                { 0 ,  3 , 0 , 0 ,  0 , 1 },
                                { 3 ,  0 , 2 , 1 , 10 , 0 },
                                { 0 ,  2 , 0 , 3 ,  0 , 5 },
                                { 0 ,  1 , 3 , 0 ,  5 , 0 },
                                { 0 , 10 , 0 , 5 ,  0 , 4 }, 
                                { 1 ,  0 , 5 , 0 ,  4 , 0 },
                                };
    
    int V = graph.size();

    prims_algorithm(graph, V);

    return 0;

}

