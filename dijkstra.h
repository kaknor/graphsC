#ifndef DIJKSTRA_H
# define DIJKSTRA_H
# include "graphs.h"

void dijkstra(int x_x, int x_y, struct graph *g, int *ppd, int *pred);

void print_path(int *pr, int x, int y);

struct stack *get_path(int *pr, int x, int y);

#endif
