#include <iostream>
using namespace std;

class Node 
{

    private :
    int data;
    Node* next;
    
    public : 
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    void setData(int data)
    {
        this->data = data;
    }

    int getData()
    {
        return data;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }

    Node* getNext()
    {
        return next;
    }
};

class linkedList
{
    private :
    Node* top;

    public :
    linkedList()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void emptyMessage()
    {
        cout << "Stack is empty.\n";
    }
    void push(int data)
    {
        Node* node = new Node(data);
        if(isEmpty())
        {
            top = node;
        }
        else
        {
            node->setNext(top);//top->next = node;
            top = node;
        }
    }

    void display()
    {
        Node* temp = top;
        while(temp != NULL)
        {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << "\n";
    }

    void peak()
    {
        if(isEmpty())
            
            emptyMessage();
        else
            cout << "Top element is : " << top->getData() << "\n";
    }

    void pop()
    {
        if(isEmpty())
            emptyMessage();
        else 
        {
            Node* temp = top;
            top = top->getNext();
            cout << "Popped element is : " << temp->getData() << "\n";
            free(temp);
            
        }
    }

    void countStack()
    {
        Node* temp = top;
        int count = 0;
        while(temp != NULL)
        {
            ++count;
            temp = temp ->getNext();
        }
        cout << "Number of elements in stack : " << count << "\n";
    }

    void clearStack()
    {
        Node* temp = top;
        Node* store = top;
        while(temp != NULL)
        {
           store = temp->getNext();
           free(temp);
           temp = store;
        }
        cout << "Stack is cleared.\n";
    }
};
int main()
{
   
   linkedList ls;
   ls.push(1);
   ls.push(2);
   ls.push(3);
   ls.push(4);
   ls.push(5);
   ls.display();
   ls.peak();
   ls.pop();
   ls.countStack();
   ls.clearStack();
   
    
    
    return 0;
}