#include <bits/stdc++.h>
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
        while(temp != NULL) {

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
        int flag = 0;
        while(temp != NULL) {

            if(temp->data == value) {

                flag = 1;
                break;
            }
            temp = temp->next;
        }
        
        (flag==1)?cout<<"The element is founded.\n":cout<<"The element is not founded.\n";
        
    }
}
int main()
{
    
    insertAtBeginning(10);
    insertAtTheEnd(60);
    insertAtBeginning(20);
    insertAtBeginning(30);
    insertAtBeginning(40);
    insertAtBeginning(50);
    
    cout<<"The number of elements in the list is : "<<countList()<<"\n";
    printList(); // Output: 50 40 30 20 10
    searchList(30);// Output: The element is founded.
    searchList(60); // Output: The element is not founded.*/
    
    
    return 0;
}