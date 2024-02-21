#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100


struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};


void initializeGraph(struct Graph *graph, int vertices) {
	int i,j;
    graph->vertices = vertices;
    for ( i = 0; i < vertices; i++) {
        for ( j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; 
}

void bfs(struct Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = -1;

    visited[startVertex] = true;
    queue[++rear] = startVertex;

    printf("BFS Traversal: ");

    while (front <= rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);
        int i;

        for ( i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    struct Graph graph;
    int vertices, edges,i;
    int src, dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    initializeGraph(&graph, vertices);

    // Calculate the maximum number of edges based on the number of vertices
    int max_edges = (vertices * (vertices - 1)) / 2;

    printf("Maximum number of edges for %d vertices: %d\n", vertices, max_edges);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Validate the number of edges
    if (edges > max_edges) {
        printf("Error: Number of edges exceeds the maximum possible for %d vertices.\n", vertices);
        return 1; // Exit with error code
    }

    printf("Enter the edges (source destination): \n");
    for ( i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);
    bfs(&graph, startVertex);

    return 0;
}


