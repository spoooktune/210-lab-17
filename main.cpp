// COMSC-210 | Lab 17 | Amrutha Sriprasana
// Made w/ VSCode

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// prototypes (may be changed later)
Node * addFront(Node *newNode, float val);
Node * addBack(Node *newNode, float val);
Node * deleteNode (Node *headNode);
Node * insertNode (Node *headNode, float val);
Node * deleteList(Node *headNode);
void output(Node *hd);

int main() {
    Node *head = nullptr;
    int index = 0;
    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE-1; i++) {
        int tmp_val = rand() % 100;
        head = addFront(head, tmp_val);
    }

    head = addBack(head, 9800);
    output(head);

    head = deleteNode(head);
    output(head);
    
    head = insertNode(head, 1000);
    output(head);
   
    head = deleteList(head);
    output(head);

    return 0;
}

Node * addFront(Node *headNode, float val){
    Node * newVal = new Node;
    // adds node at head
    if (!headNode) { // if this is the first node, it's the new head
        newVal->next = nullptr;
        newVal->value = val;
        headNode = newVal;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = headNode;
        newVal->value = val;
        headNode = newVal;
    }
    cout << headNode->value << endl;
    return headNode;
}

Node * addBack(Node * headNode, float val){
    Node * newVal = new Node;
    Node * current = headNode;
    // adds node at head
    if (!headNode) { // if this is the first node, it's the new head
        newVal->next = nullptr;
        newVal->value = val;
        headNode = newVal;
        cout << headNode->value << endl;
    }
    else {
        while ((current->next)->next){ // traverses array till next points to nullptr
            current = current->next;
        }
        newVal->next = nullptr;
        newVal->value = val;
        current = newVal;
        cout << current->value << endl;
    }
    return headNode;
}

Node * insertNode(Node * headNode, float val){
    Node *current = headNode;
    Node *prev = headNode;
    int entry;

    output(headNode);
    cout << "After which node should " << val << " be added: ";
    cin >> entry;
    
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // insert new node between prev and current
    Node * newnode = new Node;
    newnode->value = val;
    newnode->next = current;
    prev->next = newnode;

    return headNode;
}

Node * deleteNode(Node * headNode){
    int entry;
    Node * current = headNode;
    output(headNode);
    cout << "Choose node to be deleted: ";
    cin >> entry;

    // traverse array
    current = headNode;
    Node *prev = headNode;
    for (int i = 0; i < (entry-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // delete current, change pointers
    if (current) {  
        prev->next = current->next;
        delete current;
        current = nullptr;
    }

    return headNode;
}

Node * deleteList(Node *headNode){
    Node *current = headNode;
    while (current){
        headNode = current->next;
        delete current;
        current = headNode;
    }
    headNode = nullptr;
    return headNode;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}