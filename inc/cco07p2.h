#ifndef cco07p2
#define cco07p2

// int identify_vals(int[], int);
int solve_snowflakes(int[][6], int);
int code(int[]);

typedef struct snowflake_node {
  int snowflakes[6];
  struct snowflake_node *next;
} snowflake_node;

#endif // cco07p2
