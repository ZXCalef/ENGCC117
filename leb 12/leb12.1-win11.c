#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *Dijkstra(int *L, int n) {
    int *dist = (int *)malloc(n * sizeof(int));
    int *visited = (int *)malloc(n * sizeof(int));
    int start = 0;
    
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[start] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int minDist = INT_MAX;
        int u = -1;
        
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                u = v;
            }
        }
        
        if (u == -1) break;
        
        visited[u] = 1;
        
        for (int v = 0; v < n; v++) {
            int weight = L[u * n + v];
            if (!visited[v] && weight != -1 && dist[u] != INT_MAX && 
                dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    
    free(visited);
    return dist;
}

int main() {
    int n = 5, i = 0, j = 0, *d, *g;
    
    g = (int *)malloc(n * n * sizeof(int));
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            g[i * n + j] = -1;
        }
    }
    
    g[0 * n + 1] = 100;
    g[0 * n + 2] = 80;
    g[0 * n + 3] = 30;
    g[0 * n + 4] = 10;
    g[1 * n + 2] = 20;
    g[2 * n + 3] = 40;
    g[3 * n + 1] = 20;
    g[3 * n + 2] = 20;
    g[4 * n + 3] = 10;
    
    d = Dijkstra(g, n);
    
    for (i = 1; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
    
    free(g);
    free(d);
    
    return 0;
}