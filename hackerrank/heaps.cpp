/*
 * https://www.hackerrank.com/domains/data-structures/heap/
 */
#include <iostream>
#include <vector>

using namespace std;

template<typename Type>
class Heap {
    public:
        size_t get_size() const {
            return tree.size();
        }
        void insert(Type item) {
            tree.push_back(item);
            heapify_up();
        }
        void print_heap() const {
            for (const auto &i : tree) {
                cout << i << " ";
            }
            cout << endl;
        }
        size_t get_index(Type item) const {
            for (size_t i = 0; i < get_size(); ++i) {
                if (tree[i] == item)
                    return i;
            }
        }
        void remove(Type item) {
            size_t item_index = get_index(item);
            if (!has_right_child(item_index) && !has_left_child(item_index)) {
                tree.erase(tree.begin()+item_index);
            }
            else {  //At least has a left child
                Type left_child = tree[get_left_index(item_index)];
                if (has_right_child(item_index)) {
                    /* Means it has both */
                    Type right_child = tree[get_right_index(item_index)];
                    if (left_child > right_child) {
                        
                    }
                }
            }
        }
    private:
        vector<Type> tree;
        inline size_t get_parent_index(const size_t index) const {
            return ((index+1)/2)-1;
        }
        inline size_t get_left_index(const size_t index) const {
            return ((index+1)*2)-1;
        }
        inline size_t get_right_index(const size_t index) const {
            return (index+1)*2;
        }
        inline bool has_left_child(const size_t index) const {
            if (get_size() >= ((index+1)*2)-1) {
                return true;
            }
            else {
                return false;
            }
        }
        inline bool has_right_child(const size_t index) const {
            if (get_size() >= (index+1)*2) {
                return true;
            }
            else {
                return false;
            }
        }
        inline void swap(const size_t a, const size_t b) {
            Type tmp = tree[a];
            tree[a] = tree[b];
            tree[b] = tmp;
        }
        void heapify_up() {
            size_t curr_index = get_size()-1;
            if (curr_index == 0)
                return;
            size_t parent     = get_parent_index(curr_index);
            while (tree[parent] > tree[curr_index] && curr_index != 0) {
                swap(parent, curr_index);
                //cout << parent << " " << curr_index << endl;
                //print_heap();
                curr_index = parent;
                parent     = get_parent_index(parent);
            }
        }
};

int main()
{
    Heap<int> test;
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        test.insert(tmp);
    }
    test.print_heap();

}
