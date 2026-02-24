#include <stdio.h>

#define INF 999999

int findMinNode(int *distance, int *visited, int n)
{
    int minValue = INF;
    int minIndex = -1;

    for (int index = 0; index < n; index++)
    {
        if (!visited[index] && distance[index] < minValue)
        {
            minValue = distance[index];
            minIndex = index;
        }
    }

    return minIndex;
}

int *Dijkstra(int *graph, int n)
{
    int *distance = new int[n];
    int *visited = new int[n];

    for (int index = 0; index < n; index++)
    {
        distance[index] = INF;
        visited[index] = 0;
    }

    distance[0] = 0;

    for (int count = 0; count < n - 1; count++)
    {
        int currentNode = findMinNode(distance, visited, n);

        if (currentNode == -1)
            break;

        visited[currentNode] = 1;

        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            int edgeWeight = graph[currentNode * n + neighbor];

            if (edgeWeight != -1 && !visited[neighbor])
            {
                int newDistance = distance[currentNode] + edgeWeight;

                if (newDistance < distance[neighbor])
                {
                    distance[neighbor] = newDistance;
                }
            }
        }
    }

    int *result = new int[n - 1];

    for (int index = 1; index < n; index++)
        result[index - 1] = distance[index];

    return result;
}

int main()
{
    int n = 5;
    int graphSize = n * n;

    int *graph = new int[graphSize];

    for (int index = 0; index < graphSize; index++)
        graph[index] = -1;

    graph[0 * n + 1] = 100;
    graph[0 * n + 2] = 80;
    graph[0 * n + 3] = 30;
    graph[0 * n + 4] = 10;

    graph[1 * n + 2] = 20;
    graph[3 * n + 1] = 20;
    graph[3 * n + 2] = 20;
    graph[4 * n + 3] = 10;

    int *distance = Dijkstra(graph, n);

    for (int index = 0; index < n - 1; index++)
        printf("%d ", distance[index]);

    return 0;
}