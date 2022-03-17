#include <iostream>
#include <vector>

//#include "linked_list.h"

template<class Type>
class linked_list
{
   public:
        //linked_list() : head{NULL}, last{NULL}, size{0} {} 

        struct element
        {
            element *next;
            element *prev;
            Type data;
        };
        typedef struct element element;
        
        bool check_exists(Type key) {
            element *tmp = head;
            while (tmp != NULL) {
                if (tmp->data == key)
                    return true;

                tmp = tmp->next;
            }
            return false;
        }
        unsigned int length() {
            return size;
        }

        void append(Type value) {
            if (head == NULL) {
                head = new element;
                head->prev = NULL;
                head->data = value;
                last = head;
                size = 1;
                return;
            }
            element *tmp = last;
            last->next = new element;
            last = last->next;
            last->data = value;
            last->prev = tmp;
            last->next = NULL;
            size++;
            return;
        }
        
        void append(std::vector<Type> values) {
            for (int i = 0; i < values.size(); i++) {
                append(values[i]);
                size++;
            }
        }

        void print_all(void) {
            element *tmp = head;
            while (tmp != NULL) {
                std::cout << tmp->data << std::endl;
                tmp = tmp->next;
            }
        }

        element *get_element(Type value) {
            element *tmp = head;
            while (tmp != NULL) {
                if (tmp->data == value)
                    return tmp;
                tmp = tmp->next;
            }
            return NULL;
        }

        void insert_after(Type key, Type value) {             
            // Insert a new element after the element containing key
            /*
                +  (+) .adding here  +
            */
            element *intrest = get_element(key);
            if (intrest != NULL) {
                element *tmp = intrest->next;
                intrest->next = new element;
                intrest->next->prev = intrest;
                intrest->next->next = tmp;
                tmp->prev = intrest->next;
                intrest->next->data = value;
                size++;
            }
        }

        // Same as insert_after, using get_element then adding to it's prev
        void insert_before(Type key, Type value) {
            /*
                + .adding here  (+)  +
            */
            element *intrest = get_element(key);
            if (intrest != NULL) {
                element *tmp;
                if (intrest->prev != NULL) {
                    tmp = intrest->prev;
                    tmp->next = new element;
                    tmp->next->next = intrest;
                    tmp->next->prev = tmp;
                    tmp->next->data = value;
                    intrest->prev = tmp->next;
                }
                else {          //Changing head
                    tmp = head;
                    head = new element;
                    head->data = value;
                    head->next = tmp;
                    tmp->prev = head;
                    head->prev = NULL;
                }
                size++;
            }
            
        }

    private:
        unsigned int size = 0;
        element *head = NULL;
        element *last = NULL;
};

int main()
{
    linked_list<int> first;

    std::vector<int> tmp;
    for (int i = 0; i < 100; i++) {
        tmp.push_back(i);
    }
    first.append(tmp);

    first.insert_after(5, 66); 
    first.insert_before(-1, 325); 
    first.print_all();
}
