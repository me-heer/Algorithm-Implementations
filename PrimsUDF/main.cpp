#include <iostream>

using namespace std;
const int graphSize = 6;
static int minCost = 0;
int graph[graphSize][graphSize] = { {0,4,3,5,-1,-1},
                        {4,0,6,-1,3,-1},
                        {3,6,0,4,8,-1},
                        {5,-1,4,0,5,6},
                        {-1,3,8,5,0,7},
                        {-1,-1,-1,6,7,0}
                        };
    int edges[graphSize][graphSize] = {0};
    int selectedNode[graphSize] = {0,0,0,0,0,0};
    int totalSelectedNodes = 0;

int initializeGraph(int graph[graphSize][graphSize],int edges[graphSize][graphSize])
{
    //returns initialNode
    int temp_min = 99,temp_min_index_i,temp_min_index_j;
    for(int i = 0; i < graphSize; i++)
    {
        for(int j = 0; j < graphSize; j++)
        {
            if(graph[i][j] < temp_min && graph[i][j] != -1 && graph[i][j] != 0)
                {
                    temp_min = graph[i][j];
                    temp_min_index_i = i;
                    temp_min_index_j = j;
                }
        }
    }
    edges[temp_min_index_i][temp_min_index_j] = 1;
    edges[temp_min_index_j][temp_min_index_i] = 1;
    return temp_min_index_i;
}

int findMin(int graph[graphSize][graphSize],int edges[graphSize][graphSize])
{
    int temp_min = 99,temp_min_index_i,temp_min_index_j;
    for(int i = 0; i < graphSize; i++)
            for(int j = 0; j < graphSize; j++)
                if(graph[i][j] < temp_min && edges[i][j]==1 && graph[i][j] != -1 && graph[i][j] != 0 && (selectedNode[i] != 1 || selectedNode[j] != 1))
                {
                    temp_min = graph[i][j];
                    temp_min_index_i = i;
                    temp_min_index_j = j;
                }
        edges[temp_min_index_i][temp_min_index_j] = 2;
        edges[temp_min_index_j][temp_min_index_i] = 2;
        minCost += graph[temp_min_index_i][temp_min_index_j];
        return temp_min_index_j;
}

int main()
{
    int currentNode = initializeGraph(graph,edges);

    for(int i = 0; i < graphSize; i++)
            if(edges[currentNode][i] != 2)
            {
                edges[currentNode][i] = 1;
                edges[i][currentNode] = 1;
            }
    totalSelectedNodes++;
    selectedNode[currentNode] = 1;
    while(totalSelectedNodes != graphSize)
    {

        //findMinimum
        currentNode = findMin(graph,edges);
        selectedNode[currentNode]=1;
        totalSelectedNodes++;
        //cout << "Selected Node: " << currentNode << endl;
        //cout << "Selected an edge: " << "i: " << temp_min_index_i << " j: " << temp_min_index_j << endl;
        //discover
        for(int i = 0; i < graphSize; i++)
            if(edges[currentNode][i] != 2)
            {
                edges[currentNode][i] = 1;
                edges[i][currentNode] = 1;
            }
        //0: undiscovered
        //1: discovered
        //2: chosen
    }
    cout << "Minimum Cost: " << minCost << endl;
}
