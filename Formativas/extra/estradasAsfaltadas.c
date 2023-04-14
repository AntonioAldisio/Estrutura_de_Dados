#include <stdio.h>
#include <stdlib.h>

typedef struct{
    unsigned from, to;
    int weight;
} Edge;

typedef struct{
    int **edges;
    unsigned V, E;
} Graph;

Graph graphInit(unsigned numberOfVertices){
    Graph g = {.V = numberOfVertices, .E = 0};
    g.edges = malloc(sizeof(int *) * g.V);
    for (unsigned i = 0; i < g.V; i++){
        g.edges[i] = malloc(sizeof(int) * g.V);
        for (unsigned j = 0; j < g.V; j++)
            g.edges[i][j] = 2147483647;
    }
    return g;
}

void graphFree(Graph g){
    for (unsigned i = 0; i < g.V; i++)
        free(g.edges[i]);
    free(g.edges);
}

void graphInsert(Graph *g, Edge e){
    if (e.from > g->V || e.to > g->V)
        return;

    g->E += (g->edges[e.from][e.to] == 2147483647);
    g->edges[e.from][e.to] = e.weight;
}

void graphComponents(Graph g, int start, int components[]){
    if (components[start] < 0)
        components[start] = start;
    for (unsigned i = 0; i < g.V; i++)
        if (g.edges[start][i] != 2147483647 && components[i] < 0){
            int mn = ((int)i < components[start] ? (int)i : components[start]);
            components[start] = mn;
            components[i] = mn;
            graphComponents(g, i, components);
        }
}

int tc[2001][2001];

int main(){
    int v;
    scanf(" %d", &v);

    Graph g = graphInit(v);
    int f, t, d;
    while (scanf(" %d %d %d", &f, &t, &d) == 3 && d){
        graphInsert(&g, (Edge){.from = f, .to = t, .weight = 1});
        if (d == 2)
            graphInsert(&g, (Edge){.from = t, .to = f, .weight = 1});
    }

    for (unsigned i = 0; i < g.V; i++){
        for (unsigned j = 0; j < g.V; j++)
            tc[i][j] = g.edges[i][j] != 2147483647;
        tc[i][i] = 1;
    }

    for (unsigned i = 0; i < g.V; i++)
        for (unsigned j = 0; j < g.V; j++)
            if (tc[j][i] == 1)
                for (unsigned k = 0; k < g.V; k++)
                    if (tc[i][k] == 1)
                        tc[j][k] = 1;

    graphFree(g);

    for (int t, x; scanf(" %d %d", &t, &x) == 2;)
        if(tc[t][x] && tc[x][t])
            printf("Ida e Volta \n");
        else if(tc[t][x])
            printf("Apenas Ida \n");
        else if(tc[x][t])
            printf("Apenas Volta \n");
        else
            printf("Impossibru \n");

    return 0;
}
