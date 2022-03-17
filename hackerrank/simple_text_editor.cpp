/*
 * Problem Link https://www.hackerrank.com/challenges/simple-text-editor/problem
*/

#include <iostream>
#include <string>

using namespace std;


enum OperationTypes {APPEND, DELETE};

class Operation {
    public:
        Operation(OperationTypes type): oper_type{type} {}
        Operation(OperationTypes type, int k, string deleted): oper_type{type}, k{k}, appended{deleted} {}
        Operation(OperationTypes type, string appended): oper_type{type}, appended{appended} {}
        OperationTypes oper_type;
        int k;
        string appended;
};

typedef struct linked_list {
    linked_list *prev;
    Operation *ptr;
} linked_list;

int main()
{
    string curr;
    linked_list *head = NULL;
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            string tmp;
            cin >> tmp;
            curr.append(tmp);
            
            linked_list *new_node = new linked_list;
            new_node->ptr  = new Operation(APPEND, tmp);
            new_node->prev = head;
            head = new_node;
        }
        else if (type == 2) {
            int k;
            cin >> k;
            int deleted = (curr.size()-k >= 0) ? k: curr.size();

            linked_list *new_node = new linked_list;
            new_node->ptr  = new Operation(DELETE, deleted, curr.substr(curr.size()-deleted));
            curr.resize(curr.size()-deleted);
            new_node->prev = head;
            head = new_node;
        }
        else if (type == 3) {
            int pos;
            cin >> pos;
            cout << curr[pos-1] << endl;
        }
        else {  /* UNDO */
            if (head->ptr->oper_type == APPEND) {
                curr.resize(curr.size()-(head->ptr->appended.size()));
                linked_list *tmp = head->prev;
                delete head;
                head = tmp;
            }
            else {
                curr.append(head->ptr->appended);
                linked_list *tmp = head->prev;
                delete head;
                head = tmp;
            }
        }
    }

}
