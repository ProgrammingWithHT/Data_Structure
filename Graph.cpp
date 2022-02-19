
#include<iostream>
#include <list>
#include<vector>
#include<stack>
#define V 6  //V means How many Vertex of graph
using namespace std;

list<int> adj[V];

 
// Insert Element In a Directed Graph | Used Adjacency List
void addEdgeDirected(int v, int w)
{
    adj[v].push_back(w);
}

// Insert Element in a undirected graph | Used Adjacency List
void addEdgeUndirected(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Simple Way To Print Adjacency List of Graph
void printGraph()
{
    for (int v = 0; v < V; ++v) {
        cout << "\n Adjacency list of vertex " << v
             << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        printf("\n");
    }
}

// Breadth-First Traversal In Graph
void BFS(int root)
{
    bool visited[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    list<int> queue;
    visited[root] = true;
    queue.push_back(root);
    list<int>::iterator i;
 
    while(!queue.empty())
    {
        root = queue.front();
        cout << root << " ";
        queue.pop_front();

        for (i = adj[root].begin(); i != adj[root].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

// Depth First Search in graph
void DFS(int s)
{
	vector<bool> visited(V, false);

	stack<int> stack;
	stack.push(s);

	while (!stack.empty())
	{
		int s = stack.top();
		stack.pop();
		if (!visited[s])
		{
			cout << s << " ";
			visited[s] = true;
		}
		for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
			if (!visited[*i])
				stack.push(*i);
	}
}

int main()
{
    
    // addEdgeDirected(0, 1);
    // addEdgeDirected(0, 2);
    // addEdgeDirected(1, 2);
    // addEdgeDirected(2, 0);
    // addEdgeDirected(2, 3);
    // addEdgeDirected(3, 3);
    addEdgeDirected(5, 0);
    addEdgeDirected(5, 2);
    addEdgeDirected(2, 3);
    addEdgeDirected(3, 1);
    addEdgeDirected(4, 1);
    addEdgeDirected(4, 0);




    // addEdgeUndirected(0, 1);
    // addEdgeUndirected(0, 3);
    // addEdgeUndirected(1, 2);
    // addEdgeUndirected(1, 3);
    // addEdgeUndirected(1, 5);
    // addEdgeUndirected(2, 1);
    // addEdgeUndirected(2, 3);
    // addEdgeUndirected(2, 5);
    // addEdgeUndirected(3, 0);
    // addEdgeUndirected(3, 1);
    // addEdgeUndirected(3, 2);
    // addEdgeUndirected(3, 4);
    // addEdgeUndirected(4, 2);
    // addEdgeUndirected(4, 3);
    // addEdgeUndirected(4, 6);
    // addEdgeUndirected(5, 1);
    // addEdgeUndirected(5, 2);
    // addEdgeUndirected(6, 1);
    // addEdgeUndirected(6, 4);

    // printGraph();

    DFS(5);
    cout << endl;
    BFS(5);
 
    return 0;
}