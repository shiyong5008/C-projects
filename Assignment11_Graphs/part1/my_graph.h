// =================== Support Code =================
// Graph.
//
//
//
// - Implement each of the functions to create a working graph.
// - Do not change any of the function declarations
//   - (i.e. graph_t* create_graph() should not have additional arguments)
// - You should not have any 'printf' statements in your graph functions.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// ==================================================
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include "my_dll.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef unsigned long long ull;
// Create a graph data structure
typedef struct graph {
    int numNodes;
    int numEdges;
    dll_t *nodes;     //an array of nodes storing all of our nodes.
} graph_t;

typedef struct graph_node {
    int visited;
    int data;
    dll_t *inNeighbors;
    dll_t *outNeighbors;
} graph_node_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
// Returns NULL if we cannot allocate memory.
graph_t *create_graph() {
    // Modify the body of this function as needed.
    graph_t *myGraph = malloc(sizeof(graph_t));
    if (myGraph != NULL) {
        myGraph->numEdges = 0;
        myGraph->numNodes = 0;
        myGraph->nodes = create_dll();

        if (myGraph->nodes == NULL) {
            free(myGraph);
            return NULL;
        }
    }
    return myGraph;
}



// Returns the node pointer if the node exists.
// Returns NULL if the node doesn't exist or the graph is NULL
graph_node_t *find_node(graph_t *g, int value) {
    if (g == NULL) return NULL;

    node_t *node = g->nodes->head;
    for (int i = 0; i < g->nodes->count; i++, node = node->next) {
        graph_node_t *graphNode = (graph_node_t *) node->data;
        if (graphNode->data == value) {
            return graphNode;
        }
    }
    return NULL;
}

// Returns dll_t* of all the in neighbors of this node.
// Returns NULL if the node doesn't exist or if the graph is NULL.
dll_t *getInNeighbors(graph_t *g, int value) {
    if (g == NULL) return NULL;
    graph_node_t *graphNode = find_node(g, value);
    if (graphNode != NULL) return graphNode->inNeighbors;
    else return NULL;
}

// Returns the number of in neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumInNeighbors(graph_t *g, int value) {
    if (g == NULL) return -1;
    graph_node_t *graphNode = find_node(g, value);
    if (graphNode != NULL) return graphNode->inNeighbors->count;
    else return -1;
}

// Returns dll_t* of all the out neighbors of this node.
// Returns NULL if the node doesn't exist or if the graph is NULL.
dll_t *getOutNeighbors(graph_t *g, int value) {
    if (g == NULL) return NULL;
    graph_node_t *graphNode = find_node(g, value);
    if (graphNode != NULL) return graphNode->outNeighbors;
    else return NULL;
}

// Returns the number of out neighbors of this node.
// Returns -1 if the graph is NULL or the node doesn't exist.
int getNumOutNeighbors(graph_t *g, int value) {
    if (g == NULL) return -1;
    graph_node_t *graphNode = find_node(g, value);
    if (graphNode != NULL) return graphNode->outNeighbors->count;
    else return -1;
}

// Returns the number of nodes in the graph
// Returns -1 if the graph is NULL.
int graph_num_nodes(graph_t *g) {
    if (g == NULL) return -1;
    return g->numNodes;
}

// Returns the number of edges in the graph,
// Returns -1 on if the graph is NULL
int graph_num_edges(graph_t *g) {
    if (g == NULL) return -1;
    return g->numEdges;
}


// Creates a graph node
// Note: This relies on your dll implementation.
graph_node_t *create_graph_node(int value) {
    graph_node_t *graph_node = malloc(sizeof(graph_node_t));
    if (graph_node != NULL) {
        graph_node->data = value;
        graph_node->visited = 0;
        graph_node->inNeighbors = create_dll();
        graph_node->outNeighbors = create_dll();

        if (graph_node->inNeighbors == NULL || graph_node->outNeighbors == NULL) {
            free(graph_node->inNeighbors);
            free(graph_node->outNeighbors);
            free(graph_node);
            return NULL;
        }
    }
    return graph_node;
}

// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist )
// Returns -1 if the graph is NULL.
int contains_edge(graph_t *g, int source, int destination) {
    if (g == NULL) return 0;
    graph_node_t *src = find_node(g, source);
    if (src == NULL) return 0;
    node_t *node = src->outNeighbors->head;
    for (int i = 0; i < src->outNeighbors->count; i++, node = node->next) {
        graph_node_t *neighbor = (graph_node_t *) node->data;
        if (neighbor->data == destination) {
            return 1;
        }
    }
    // destination node not exist
    return 0;
}

// The function adds an edge from source to destination but not the other way.
// Make sure you are not adding the same edge multiple times.
// Make sure you modify the in and out neighbors appropriately. destination will be an out neighbor of source.
// Source will be an in neighbor of destination.
// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge already exists )
// Returns -1 if the graph is NULL.
int graph_add_edge(graph_t *g, int source, int destination) {
    if (g == NULL) return -1;
    graph_node_t *src = find_node(g, source);
    graph_node_t *dst = find_node(g, destination);
    if (src == NULL || dst == NULL || contains_edge(g, source, destination)) return 0;
    dll_push_back(src->outNeighbors, dst);
    dll_push_back(dst->inNeighbors, src);
    g->numEdges++;
    return 1;
}

//The function removes an edge from source to destination but not the other way.
//Make sure you remove destination from the out neighbors of source.
//Make sure you remove source from the in neighbors of destination.
// Returns 1 on success
// Returns 0 on failure ( or if the source or destination nodes don't exist, or the edge doesn't exists )
// Returns -1 if the graph is NULL.
int graph_remove_edge(graph_t *g, int source, int destination) {
    if (g == NULL) return -1;
    graph_node_t *src = find_node(g, source);
    graph_node_t *dst = find_node(g, destination);
    if (src == NULL || dst == NULL || !contains_edge(g, source, destination)) return 0;

    node_t *node = src->outNeighbors->head;
    for (int i = 0; i < src->outNeighbors->count; i++, node = node->next) {
        graph_node_t *neighbor = (graph_node_t *) node->data;
        if (neighbor->data == destination) {
            dll_remove(src->outNeighbors, i);
            break;
        }
    }

    node = dst->inNeighbors->head;
    for (int i = 0; i < dst->inNeighbors->count; i++, node = node->next) {
        graph_node_t *neighbor = (graph_node_t *) node->data;
        if (neighbor->data == source) {
            dll_remove(dst->inNeighbors, i);
            break;
        }
    }
    g->numEdges--;
    return 1;
}


// Returns 1 on success
// Returns 0 on failure ( or if the node already exists )
// Returns -1 if the graph is NULL.
int graph_add_node(graph_t *g, int value) {
    if (g == NULL) return -1;
    if (find_node(g, value) != NULL) return 0;

    graph_node_t *newNode = create_graph_node(value);
    // this supposed to be considered a failure
    if (newNode == NULL) return 0;

    dll_push_back(g->nodes, newNode);
    g->numNodes++;
    return 1;
}

// The function removes the node from the graph along with any edges associated with it.
// That is, this node would have to be removed from all the in and out neighbor's lists that contain it.
// Returns 1 on success
// Returns 0 on failure ( or if the node doesn't exist )
// Returns -1 if the graph is NULL.
int graph_remove_node(graph_t *g, int value) {
    if (g == NULL) return -1;
    graph_node_t *graphNode = find_node(g, value);
    if (graphNode == NULL) return 0;

    //from inNeighbors' outNeighbors remove this node
    node_t *inNode = graphNode->inNeighbors->head;
    for (int i = 0; i < graphNode->inNeighbors->count; i++, inNode = inNode->next) {
        graph_node_t *neighbor = (graph_node_t *) inNode->data;

        node_t *outNode = neighbor->outNeighbors->head;
        for (int j = 0; j < graphNode->outNeighbors->count; j++, outNode = outNode->next) {
            if (((graph_node_t *) (outNode))->data == graphNode->data)
                dll_remove(neighbor->outNeighbors, j);
        }
    }
    //from outNeighbors' inNeighbors remove this node
    node_t *outNode = graphNode->outNeighbors->head;
    for (int i = 0; i < graphNode->outNeighbors->count; i++, outNode = outNode->next) {
        graph_node_t *neighbor = (graph_node_t *) outNode->data;

        node_t *inNode = neighbor->inNeighbors->head;
        for (int j = 0; j < graphNode->inNeighbors->count; j++, inNode = inNode->next) {
            if (((graph_node_t *) (inNode))->data == graphNode->data)
                dll_remove(neighbor->inNeighbors, j);
        }
    }
    g->numNodes--;
    return 1;
}

void graph_clear_visited(graph_t *g) {
    node_t *node = g->nodes->head;
    for (int i = 0; i < g->numNodes; i++) {
        graph_node_t *g_node = node->data;
        g_node->visited = 0;
        node = node->next;
    }
}

// returns 1 if we can reach the destination from source
// returns 0 if it is not reachable
// returns -1 if the graph is NULL (using BFS)
int is_reachable(graph_t *g, int source, int dest) {
    if (g == NULL) return -1;
    graph_clear_visited(g);
    graph_node_t *src = find_node(g, source);
    if (src == NULL) return 0;
    dll_t *queue = create_dll();
    src->visited = 1;
    dll_push_back(queue, src);
    while (dll_empty(queue) != 1) {
        graph_node_t *node = dll_pop_front(queue);
        if (node->data == dest) {
            free_dll(queue);
            return 1;
        }
        // unnecessarily O(e^2)
        for (int i = 0; i < dll_size(node->outNeighbors); i++) {
            graph_node_t *next = dll_get(node->outNeighbors, i);
            if (!next->visited) {
                next->visited = 1;
                dll_push_back(queue, next);
            }
        }
    }
    free_dll(queue);
    return 0;
}

int has_cycle_dfs(graph_node_t *start) {
    if (start->visited == 2) return 0;
    if (start->visited == 1) return 1;
    start->visited = 1;

    for (int i = 0; i < dll_size(start->outNeighbors); i++) {
        graph_node_t *next = dll_get(start->outNeighbors, i);
        if (has_cycle_dfs(next)) return 1;
        next->visited = 2;
    }
    return 0;
}

// returns 1 if there is a cycle in the graph
// returns 0 if no cycles exist in the graph
// returns -1 if the graph is NULL
// You may use either BFS or DFS to complete this task.
// visited 0: not visited yet, 1: visited & in dfs stack, 2: visited & not in dfs stack
int has_cycle(graph_t *g) {
    if (g == NULL) return -1;
    graph_clear_visited(g);

    // at least once traverse for each connection component
    for (int i = 0; i < g->numNodes; i++) {
        graph_node_t *start = dll_get(g->nodes, i);
        if (has_cycle_dfs(start)) {
            return 1;
        }
        start->visited = 2;
    }
    return 0;
}

// prints any path from source to destination if there
// exists a path from the source to the destination.
// Note: Consider using one of the other functions to help you
//       determine if a path exists first
// (Choose either BFS or DFS, typically DFS is much simpler)
//
// Returns 1 if there is a path from source to destination
// Returns 0 if there is not a path from a source to destination
// Returns -1 if the graph is NULL

bool print_path_dfs(graph_node_t *this, int dest, dll_t *list) {
    dll_push_back(list, this);
    if (this->visited) return false;
    if (this->data == dest) {
        printf("%d", ((graph_node_t *) dll_get(list, 0))->data);
        for (int i = 1; i < dll_size(list); i++) {
            printf(" -> %d", ((graph_node_t *) dll_get(list, i))->data);
        }
        putchar('\n');
        dll_pop_back(list);
        return true;
    } else {
        for (int i = 0; i < dll_size(this->outNeighbors); i++) {
            if (print_path_dfs(dll_get(this->outNeighbors, i), dest, list)) {
                dll_pop_back(list);
                return true;
            }

        }
    }
    dll_pop_back(list);
    return false;
}

int print_path(graph_t *g, int source, int dest) {
    if (g == NULL) return -1;
    if (is_reachable(g, source, dest) == 0) return 0;
    dll_t *list = create_dll();
    graph_clear_visited(g);
    print_path_dfs(find_node(g, source), dest, list);
    free_dll(list);
    return 1;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the program terminates.
// Make sure you free all the dll's too.
void free_graph(graph_t *g) {
    if (g == NULL) return;
    node_t *node = g->nodes->head;
    for (int i = 0; i < g->nodes->count; i++, node = node->next) {
        graph_node_t *graphNode = node->data;
        free_dll(graphNode->inNeighbors);
        free_dll(graphNode->outNeighbors);
        free(graphNode);
    }
    free_dll(g->nodes);
    free(g);
}

#endif
