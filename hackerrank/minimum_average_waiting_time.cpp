/*
 * Problem Link https://www.hackerrank.com/challenges/minimum-average-waiting-time/problem
 * Time complexity O(shit)
*/

#include <iostream>

using namespace std;

typedef unsigned long long ull;

typedef struct {
    ull arrival;
    ull pizza_time;
} customer;

typedef struct node {
    customer *data;
    struct node *next;
} node;

node *new_node(ull arrival, ull pizza_time) {
    customer *person= new customer;
    person->arrival = arrival;
    person->pizza_time = pizza_time;
    node *node_in_list = new node;
    node_in_list->data = person;
    node_in_list->next = NULL;
    return node_in_list;
}

void sortedInsert(struct node** head_ref, struct node* new_node) 
{ 
    struct node* current; 
    if (*head_ref == NULL || (*head_ref)->data->pizza_time >= new_node->data->pizza_time) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data->pizza_time < new_node->data->pizza_time) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 

void delete_node(node *ptr, node *prev) {
    if (ptr->next != NULL) {
        prev->next = ptr->next;
    }
    else {
        prev->next = NULL;
    }
    free(ptr);
}

int main()
{
    int n;
    cin >> n;
    ull arrival;
    ull pizza_time;

    cin >> arrival >> pizza_time;
    node *linked_list = new_node(arrival, pizza_time);

    for (int i = 1; i < n; ++i) {
        cin >> arrival >> pizza_time;
        sortedInsert(&linked_list, new_node(arrival, pizza_time));
    }


    //node *it = linked_list->next;
    node *prev = linked_list;
    ull result = 0;
    for (int t = 0; t <= 10e5; ++t) {
        node *it = linked_list->next;
        while (it != NULL) {
            if (it->data->arrival > (ull)t) {   //possible
                result += it->data->pizza_time;
                delete_node(it, prev);
                break;
            }
            prev = it;
            it = it->next;
        }
    }
    
}
