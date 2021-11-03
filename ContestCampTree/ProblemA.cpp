// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector <int> num;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    void alt(Node* root, int peso){
        if(root == NULL){
            num.push_back(peso);
        }
        alt(root->left, peso++);
        
        alt(root->right, peso++);
    }

    int height(Node* root) {

        cout << "hola" << endl;
        cout << root->data << endl;
        cout << root->right->data << endl;
        cout << root->left->data << endl;
        alt(root,-1);

        auto it = max_element(std::begin(num), std::end(num)); // C++11

        return *it;
    }

}; //End of Solution

int main(){
    Node x1(4);

    Solution tree;

    tree.insert(&x1, 4);
    tree.insert(&x1, 2);
    tree.insert(&x1, 6);
    tree.insert(&x1, 1);
    tree.insert(&x1, 3);
    tree.insert(&x1, 5);
    tree.insert(&x1, 7);

    tree.height(&x1);

}