#include<iostream>
using namespace std ;

class Node {

    public :
    int val ; 
    Node* next ; 

    Node(int val) {
        this->next = NULL ; 
        this->val = val ; 
    }
};

class Linkedlist {
    public : 
    Node * head ; 
    Node * tail ; 
    int size ; 
    Linkedlist() {
        head = tail = NULL ; 
        size = 0 ; 
    }
    void insertAtend(int val) {
        Node* temp = new Node(val) ; 

        if(size == 0) {
            head = tail = temp ;
        }
        else {
            tail->next = temp ; 
            tail = temp ; 
        }
        size++ ; 
    }
void InsertAtbegin(int val){
    Node *temp = new Node(val);
    if(size == 0){
        head = tail = temp; // Head and tail both should point to the new node.
    }
    else {
        temp->next = head; // Point the new node to the current head.
        head = temp; // Update the head to the new node.
    }
    size++; 
}

    void InsertAtidx(int idx , int val) {
        if(idx == 0) InsertAtbegin(val) ; 
        else if(idx == size) insertAtend(val) ; 
        else if (idx < 0 || idx > size) cout << "Enter valid index" << "\n"   ; 
        else {
            Node* temp = head ; 
            int mn = 0 ; 
            while (idx > mn) {
                if(idx-1 == mn) {
                    Node* t = new Node(val) ; 
                    t->next = temp->next ; 
                    temp->next = t ; 
                    break;
                }
                else {
                    temp = temp->next ; 
                    mn++ ; 
                }
            } 
            size++ ; 
        }
    }

    void deletAThead() {
        if(size == 0) {
            cout << "LL is empty " ; 
            return ;
        }
        else {
            head = head->next ; 
            size-- ; 
        }

    }
    void display() {
        if(size == 0)   cout << "Nothing to print ??? \n" ; 
        Node * ans = head ; 
        while(ans != NULL) {
            cout << ans->val << " -->  "; 
            ans = ans->next ; 
        }
        cout << endl ; 
    }
};

int main() {
    Linkedlist n; 
    bool flag = true; 
    do {
        cout << "1. Display \n"; 
        cout << "2. Delete head \n"; 
        cout << "3. Insert at head \n"; 
        cout << "4. Insert at index \n"; 
        cout << "5. Insert at end \n";
        cout << "6. Exit \n"; 
        int x = 0; 
        cin >> x; 
        if(x == 1) {
            n.display(); 
        }
        else if(x == 2) {
            n.deletAThead(); 
        }
        else if(x == 3) {
            cout << "Enter what to insert: "; 
            int val; 
            cin >> val; 
            n.InsertAtbegin(val); 
        }
        else if(x == 4) {
            cout << "Enter index and value: "; 
            int idx, val; 
            cin >> idx >> val; 
            n.InsertAtidx(idx, val); 
        }
        else if(x == 5) {
            cout << "Enter value to insert at end: "; 
            int val; 
            cin >> val; 
            n.insertAtend(val); 
        }
        else if(x == 6) {
            flag = false; 
        }
    } while(flag); 
}
