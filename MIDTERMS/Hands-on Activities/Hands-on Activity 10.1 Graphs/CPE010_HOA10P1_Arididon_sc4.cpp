#include <iostream>
#include <queue>
using namespace std;

int graph[7][7] = {
    // A  B  C  D  E  F  G
    { 0, 1, 1, 1, 0, 0, 0 }, // A
    { 0, 0, 0, 0, 1, 1, 0 }, // B
    { 0, 0, 0, 0, 0, 0, 0 }, // C
    { 0, 0, 0, 0, 0, 0, 1 }, // D
    { 0, 0, 0, 0, 0, 0, 0 }, // E
    { 0, 0, 0, 0, 0, 0, 0 }, // F
    { 0, 0, 0, 0, 0, 0, 0 }  // G
};

bool visited[7];

// DFS
void DFS(int vertex)
{
    visited[vertex] = true;
    cout << char('A' + vertex) << " ";

    for (int i = 0; i < 7; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

// BFS
void BFS(int start)
{
    bool visited[7] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        cout << char('A' + vertex) << " ";

        for (int i = 0; i < 7; i++)
        {
            if (graph[vertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main()
{
    cout << "DFS: ";
    DFS(0);

    cout << "\nBFS: ";
    BFS(0);

    return 0;
}