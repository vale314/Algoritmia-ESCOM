#include <bits/stdc++.h>

//https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem?isFullScreen=true

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    
    SinglyLinkedListNode * start = NULL;
    SinglyLinkedListNode * current = start;
    
    SinglyLinkedListNode * aux1 = head1;
    SinglyLinkedListNode * aux12 = head2;
    
    while(aux1){
        cout << aux1 -> data << " - ";
        aux1 = aux1 -> next;
    }
    cout<<endl<<endl;
    
    while(aux12){
        cout << aux12 -> data << " - ";
        aux12 = aux12 -> next;
    }
    cout<<endl;
    
    while( head1 || head2 ){
        
        if(head1 == NULL){
            current -> next = head2;
            return start;
        }
        if(head2 == NULL){
            current -> next = head1;
            return start;
        }
        SinglyLinkedListNode * X = new SinglyLinkedListNode(0);
        
        // cout<< X -> data;
        
        if(head1 -> data <= head2 -> data){
            X -> data = head1 -> data;
            
            head1 = head1 -> next;
            
        }else {
            X -> data = head2 -> data;
            head2 = head2 -> next;
        }
        
        X -> next = NULL;
        
        cout << X -> data << endl;
        
        if(current == NULL)
            current = X;
        else{
            current -> next = X;
            current = current -> next;
        }
        
        if(start == NULL){
            start = current;
        }
        
    }
    
    return start;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
