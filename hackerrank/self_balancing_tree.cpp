/*
    Problem Link https://www.hackerrank.com/challenges/self-balancing-tree/problem
*/

/*
struct node
{
    int val;            //value
    struct node* left;  //left child
    struct node* right; //right child
    int ht;             //height of the node
} node;
*/

node *insert(node *root, int val)
{
    node *search = root;
    while (search != NULL) {
        if (val < search->val) {
            if (search->left != NULL) {
                serach = serach->left;
            }
        }
        else {      //Every val is unique
            if (search->right != NULL) {
                serach = serach->right;
            }
        }
    }

    node *element = new node{val, NULL, NULL, 0};

    if (search->ht > 0) {
        if (val < serach->val) {
            search->left = element;
        }
        else {
            search->right = element;
        }
        return root;
    }
    else {
        node *tmp = search;
        if (val < search->val) {

        }
    }
}

