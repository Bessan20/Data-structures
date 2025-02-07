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

int countList() {

    int count = 0;
    Node* temp = head;
    while(temp != NULL) {

        count++;
        temp = temp->next;
    }
    return count;
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

      if(givenNode == head->data) 
          insertAtBeginning(newValue);
     
     else {
      bool found = false;
      Node* curr = head;
      Node* prev = head;
      while(curr != NULL) {

        
        if(curr->data == givenNode) {

                     
            Node* newNode = new Node();
            newNode->data = newValue;
            newNode->next = curr; 
            cout<<curr->data<<" "<<prev->data<<"\n";
            prev->next = newNode;
            found = true;
            
            break;
        }
        prev = curr;
        curr = curr->next;

      }
      
      if(found == false ) {

         cout<<"The node is not found.\n";
         return;

      }
    }
    cout<<"The given node added successfully.\n";
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
                newNode->next = after;
                curr->next = newNode;
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

void insertAtMiddle(int newValue) {

    if(isEmpty()) 
      
      cout<<"The list is empty";

    else {

        Node* temp = head;
        Node* prev = head;
        Node* newNode = new Node();
        newNode->data = newValue;
        int count = 1 ;
        while(count<(countList()>>1))
        {
            temp = temp->next;
            count++;
        } 
        prev = temp;
        temp = temp->next;
        newNode->next = temp;
        prev->next = newNode;
        
    }
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

void printKthNode(float k) {

    if(isEmpty())

       cout<<"The list is empty!\n";

    else {

        if((int(k) == k) && (k>0) && (k<=countList())) {

            Node* temp = head;
            int count = 1;
            while(temp != NULL) {

                if(count == k) {

                    cout<<temp->data<<"\n";
                    break;
                }
                temp = temp->next;
                ++count;
            }
        }

        else 

           cout<<"Invalid postion!";
    }
}

void printEveryKthNode(int k) {

    if(isEmpty()) {

        cout<<"The list is empty!";

    }

    else {

        int count = 1 ;
        Node* temp = head;
        while(temp != NULL ) {

            if(count%k == 0) {

                cout<<temp->data<<" ";
            } 
            ++count;
            temp = temp->next;
        }
        cout<<"\n";
    }
}

void printMiddleOfList() {

    if(isEmpty()) 
       
       cout<<"The list is empty!";

    else {
          
          int listLength = countList();
          Node* temp = head;
          int count = 1;
        
            while((count)<((listLength>>1))) {
                
                
                temp = temp->next;
                count++;

            }
        (listLength&1)?cout<<(temp->next)->data<<"\n":
         cout<<(temp->data)<<" "<<(temp->next)->data<<"\n";
            
            

        
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
        
        cout << (found ? "found.\n" : "not found.\n");
    }
}

void reverseList() {

    if(isEmpty())

       cout<<"The list is empty!";

    else {

        Node* prev = NULL;
        Node* curr = head;
        Node* after = NULL;

        while(curr != NULL) {

            after = curr->next;
            curr->next = prev;
            prev = curr;
            curr = after;
        }
        head = prev;
    }
}

void printKthNodeFromEnd(int k) {

    reverseList();
    printKthNode(k);
    reverseList();

}

void deleteNode(int delValue) {

    if(isEmpty()) 

       cout<<"The list is Empty!";

    else {

        Node* curr = head;
        if(delValue == head->data) {
             head = head->next;
             free(curr);
             return;
        }

        else {
        
        Node* prev = NULL;
        while(curr != NULL) {

            if(curr->data == delValue) {
                prev->next = curr->next;
                free(curr);
                break;
            }
            prev = curr;
            curr = curr->next;
        } 
    }
    }
}

void deleteAtBeginning() {

    if(isEmpty())

         cout<<"The list is empty!";

    else {

        Node* temp = head->next;
        free(head);
        head = temp;
    }
}

void deleteAtTheEnd() {

    if(isEmpty())

         cout<<"The list is empty!";

    else {

       Node* temp = head;
       Node* prev = head;
       while(temp != NULL) {
        
        if(temp->next == NULL){

            if(temp == head) {

                head = NULL;
                free(temp);
                break;
            }
            prev->next = NULL;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
        
       }
       
    }
}

void deleteAtPosition(int postion) {

    int length = countList();
    if(postion <= 0 || postion > length) {

        cout<<"Invalid position!";
        return;
    }

    else {

        if(isEmpty()) {
            
            cout<<"The list is empty!";

        }

        else {

            if(postion ==1) {

                deleteAtBeginning();
                return;
            }

            else {

                if(postion == length) {

                    deleteAtTheEnd();
                    return;

                }

                else {
                    Node* temp = head;
                    Node* prev = head;
                    int count = 1;
                    while(temp != NULL) {

                        if(count == postion) {
                            
                            prev->next = temp->next;
                            free(temp);
                            break;
                        }
                        count++;
                        prev = temp;
                        temp = temp->next;
                    }
                }
                
            }
        }
        }
}

/*void deleteEveryKthNode(int k) {

    if(isEmpty()) {

        cout<<"The list is empty!";
        return;
    }

    else {

        Node* temp = head;
        Node* prev = NULL;
        Node* store = NULL;
        int count = 1;
        while(temp != NULL) {

            if(count%k == 0) {

                prev->next = temp->next;
                store = temp;
                free(store);
            }
            ++count;
            prev = temp;
            temp = temp->next;

        }
    }
}*/

void countOccurrences(int value) {

    if(isEmpty()) {
        
        cout<<"The list is empty!";
    }

    else {

        int count = 0 ;
        Node* temp = head;
        while(temp !=NULL) {

            if(temp->data == value)
               count++;
               temp = temp->next;
        }
        cout<<"The number of occurrences of "<<value<<" is : "<<count<<"\n";
    }
}
int main() {
    
    
   insertAtTheEnd(2);
    insertAtTheEnd(3);
    insertAtTheEnd(4);
    insertAtTheEnd(5);
    insertAtTheEnd(6);
    insertAtTheEnd(7);
    insertAtTheEnd(3);
    insertAtTheEnd(2);
    insertAtTheEnd(1);
    insertAtBeginning(1);
    
    cout<<"The number of elements in the list is : "<<countList()<<"\n";
    printList(); 
    //insertBeforeGivenNode(1,4);
    //insertAtMiddle(10);
    //printList();
    //reverseList();
    //deleteNode(2);
   // deleteList();
  // deleteAtBeginning();
    //deleteAtTheEnd();
    //deleteAtPosition(3);
    //deleteEveryKthNode(3);
   // printList();
    printKthNodeFromEnd(6);  
    //countOccurrences(3);
    //countOccurrences(1);
    countOccurrences(10);
    printEveryKthNode(2);
    /*insertAfterGivenNode(4,6);
    printList();
    printKthNode(2); 
    printMiddleOfList();
    printOddList(); 
    printEvenList(); 
    searchList(30); 
    searchList(70); */
    //1 2 3 4 5 6 7 8 9 10 
    
    return 0;
}