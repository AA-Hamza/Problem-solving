/*
 * Problem Link https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/areas-0475fb6e/
 * I started this with determination to finish it with bad design, I succeeded YAY. Pls kill me
 * This is the opposite of clean code don't read it, head for v2
*/
#include <stdio.h>
#include <stdlib.h>

struct vector {
    int *data;
    int size;
    void (*initialize)(struct vector *self);
    void (*insert)(struct vector *self, int e);
};
typedef struct vector vector;

void vector_insert(vector *self, int e) {
    self->size++;
    self->data = realloc(self->data, sizeof(int) * self->size);
    self->data[self->size-1] = e;
}
void vector_initialize(vector *self) {
    self->data = malloc(1*sizeof(int));
    self->size = 0;
    self->insert = vector_insert;
}

int **get_matrix(int rows, int columns) {
    int **matrix = malloc((rows+1)*sizeof(int *));
    for (int i = 0; i <= rows; ++i) {
        matrix[i] = malloc((columns+1)*sizeof(int));
        matrix[i][columns] = 1;
    }
    for (int i = 0; i < columns; ++i) {
        matrix[rows][i] = 1;
    }
    char *buffer = malloc(columns*sizeof(char));
    for (int r = 0; r < rows; ++r) {
        scanf("%s", buffer);
        for (int c = 0; c < columns; ++c) {
            if (buffer[c] == '#')
                matrix[r][c] = 1;
            else 
                matrix[r][c] = 0;
        }
    }
    return matrix;
}

void print_visited(int *visited, int n) {
    printf("Printing visiting\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", visited[i]);
    }
    printf("\nEnd of Visiting\n");
}

void print_adj_list(vector *elements, int num_of_elements) {
    for (int i = 0; i < num_of_elements; ++i) {
        printf("%d: ", i);
        for (int j = 0; j < elements[i].size; ++j) {
            printf("%d ", elements[i].data[j]);
        }
        printf("\n");
    }
}

int dfs(vector *elements, int at, int *visited) {
    if (visited[at] != 0) {
        return 0;
    }
    visited[at] = 1;
    int *next = elements[at].data;
    int result = 1;
    for (int i = 0; i < elements[at].size; ++i) {
        result += dfs(elements, next[i], visited);
    }
    return result;
}

vector *dfs_wrapper(vector *elements, int num_of_elements) {
    vector *result = malloc(sizeof(vector));
    result->initialize = vector_initialize;
    result->initialize(result);

    int *visited = malloc(sizeof(int) * num_of_elements);
    for (int i = 0; i < num_of_elements; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < num_of_elements; ++i) {
        if (elements[i].size != 0 && visited[i] == 0) {
            result->insert(result, dfs(elements, i, visited));
            //print_visited(visited, num_of_elements);
        }
    }
    return result;
}

int generate_adj_list(vector *elements, int **matrix, int rows, int columns) {
    const int num_of_elements = rows*columns;
    int areas_of_ones = 0;
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < columns; ++c) {
            if (matrix[r][c] == 0) {
                int ele_index = r*columns+c;
                if (matrix[r+1][c] == 0) {
                    elements[ele_index].insert(&elements[ele_index], (r+1)*columns+c);
                }
                if (matrix[r][c+1] == 0) {
                    elements[ele_index].insert(&elements[ele_index], r*columns+c+1);
                }
                if (matrix[r][c+1] && matrix[r+1][c]) {
                    //printf("trapped %d %d\n", r, c);
                    if (r > 0) {
                        if (matrix[r-1][c] == 0)
                            continue;
                    }
                    if (c > 0) {
                        if (matrix[r][c-1] == 0)
                            continue;
                    }
                    areas_of_ones++;
                }
            }
        }
    }
    return areas_of_ones;
}


int main()
{
    int t;
    scanf("%d", &t);

    while (t--) {
        int rows, columns;
        scanf("%d %d", &rows, &columns);
        int **matrix = get_matrix(rows, columns);

        int num_of_elements = rows*columns;
        vector *elements = malloc(sizeof(vector)*num_of_elements);
        for (int i = 0; i < num_of_elements; ++i) {
            elements[i].initialize = vector_initialize;
            elements[i].initialize(&elements[i]);
        }

        int areas_of_ones = generate_adj_list(elements, matrix, rows, columns);
        //print_adj_list(elements, num_of_elements);
        vector *result = dfs_wrapper(elements, num_of_elements);

        printf("%d\n", areas_of_ones+result->size);
        for (int i = 0; i < areas_of_ones; ++i) {
            printf("1 ");
        }
        for (int i = 0; i < result->size; ++i) {
            printf("%d ", result->data[i]);
        }
        printf("\n");
    }
}
