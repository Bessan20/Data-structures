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

void insertBeforeGivenNode(int givenNode, int newValue) {

    if(isEmpty()) {

        cout<<"The list is empty !";
    }

    else {

      bool found = false;
      Node* curr = head;
      Node* prev = head;
      while(curr != NULL) {

        
        if(curr->data == givenNode) {

            if(curr == head) 
                 insertAtBeginning(newValue);  

            else {         
            Node* newNode = new Node();
            newNode->data = newValue; 
            newNode->next = curr; 
            prev->next = newNode;
            }
            found = true;
            cout<<"The given node added successfully.\n";
            break;
        }
        prev = curr;
        curr = curr->next;

      }

      if(found == false )
         cout<<"The node is not found.\n";
    }

}

void insertAfterGivenNode(int givenNode , int newValue) {

    if(isEmpty()) 
       
       cout<<"The list is Empty!";
    
    else {

        bool found = false;
        Node* curr = head;
        Node* after = head;
        while(curr != NULL) {

            if(curr->data == givenNode) {

                Node* newNode = new Node();
                newNode->data = newValue;
                after = curr->next;
                cout<<after->data<<" "<<curr->data<<" "<<newNode->data<<" ";
                newNode->next = after;
                cout<<"The given node added successfully.\n";
                found = true;
                break;
            }
            after = after->next;
            curr = curr->next;
        }
        if(found == false)cout<<"The node is not found.\n";
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

    cout<< "The list is Empty!\n";
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

void printOddList() {

    if(isEmpty()) {

        cout<<"The list is empty!\n";
    }

    else {

        Node* temp = head;
        bool found = false;
        while(temp != NULL) {

            if((temp->data)&1) {
                
                cout << temp->data <<" ";
                found = true;
            }
            
            temp = temp->next;
        }
        if(found == false)
         cout<<"No odd numbers found in the list.";


        cout<<"\n";
    }
}

void printEvenList() {

    if(isEmpty())
        
        cout<<"The list is empty!";
    
    else {

        Node* temp = head;
        bool found = false;
        while(temp != NULL) {

            if(!((temp->data)&1)) {

                cout<<temp->data<<" ";
                found = true;
            }
            temp = temp->next;
        }

        if(found == false)

           cout<<"No even numbers found in the list.";
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
    
    insertAtTheEnd(1);
    insertAtTheEnd(2);
    insertAtTheEnd(3);
    insertAtTheEnd(4);
    insertAtTheEnd(5);
    insertAtTheEnd(6);
    
    
    cout<<"The number of elements in the list is : "<<countList()<<"\n";
    printList(); // Output: 50 40 30 20 10 60
    insertBeforeGivenNode(1,3);
    printList();
    insertAfterGivenNode(1,6);
    printList();
    cout<<"9";
    /*printOddList(); // Output: 10 30 50
    printEvenList(); // Output: 20 40 60
    searchList(30); // Output: The element is found.
    searchList(70); // Output: The element is not found.*/
    
    
    return 0;
}