#include <iostream>
using namespace std;

struct Node { //*class to represent node (userdefined data type)
     
    int data = 0; 
    Node* next; //*pointer to point to the node (same data type of node)
};

Node* head = NULL;

bool isEmpty() {

    return (head == NULL);
}

void insertAtBeginning(int newValue) {
    
    Node* newNode = new Node();//*allocate memory for new node
    newNode->data = newValue;//*store the value in the new node (int the data part)

    if(isEmpty())
    {
        head = newNode;
        newNode->next = NULL;
    }

    else 
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTheEnd(int newValue) {

    Node* newNode = new Node();
    newNode->data = newValue;
    if(isEmpty()) {

        newNode->next = NULL;
        head = newNode;
    }

    else {
        Node* temp = head;
        while(temp->next != NULL) {

            temp = temp->next;
        }
        
        newNode->next  = NULL;
        temp->next = newNode;
    }
}
int countList() {

    int count = 0;
    Node* temp = head;
    while(temp != NULL) {

        count++;
        temp = temp->next;
    }
    return count;
}
void printList() {

   if(isEmpty()) {

    cout<< "The list is Empty !\n";
   }

   else {
    Node* temp = head;
    cout<<"The list elemets are :" <<" ";
    while(temp != NULL) {
        
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<"\n";
   }
}

void searchList(int value) {

    if(isEmpty()) {

        cout<<"The list is Empty!\n";
    }

    else {
        
        Node* temp = head;
        bool found = false;
        while(temp != NULL) {

            if(temp->data == value) {

                found = true;
                break;
            }
            temp = temp->next;
        }
        
        cout << (found ? "The element is found.\n" : "The element is not found.\n");
    }
}
int main() {
    
    insertAtBeginning(10);
    insertAtTheEnd(60);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);
    insertAtBeginning(50);
    
    cout<<"The number of elements in the list is : "<<countList()<<"\n";
    printList(); // Output: 50 40 30 20 10 60
    searchList(30); // Output: The element is found.
    searchList(70); // Output: The element is not found.*/
    
    
    return 0;
}