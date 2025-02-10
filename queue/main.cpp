#include <iostream>
//using namespace std;

class Node
{
    private:
        int data;
        Node* next;
    
    public:
    Node(int data)
    {
        this->data = data;
        this->next =NULL;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
            
};

class queue
{

    private:
        Node* head;
        Node* tail;

    public:
        queue()
        {
            this->head = NULL;
            this->tail = NULL;

        }

        bool isEmpty()
        {
            return head == NULL;
        }

        void isEmptyMessage()
        {
           std:: cout <<  "Queue is empty\n" ;
        }

        void enqueue(int data)
        {
            
            Node* newNode = new Node(data);
            if(isEmpty())
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->setNext(newNode);
                tail = newNode;
            }

        }

        void dequeue()
        {
            if(isEmpty())
            {
                isEmptyMessage();
                return;
            }
            else
            {
                Node* temp = head;
                head = head->getNext();
                free(temp);

            }
        }

        void display()
        {
            if(isEmpty())
            {
                isEmptyMessage();
                return;
            }

            else
            {
                Node* temp = head;
                while(temp != NULL)
                {
                    std:: cout <<temp->getData() <<" ";
                    temp = temp->getNext();
                }
                std::cout<<"\n";;
            }
        }

        void front()
        {
            if(isEmpty())
            {
                isEmptyMessage();
                return;
            }
            else
            {
                std:: cout << "Front element is: " << head->getData() << "\n";
            }
        }

        void peak()
        {
            front();
        }

        void rear()
        {
            if(isEmpty())
            {
                isEmptyMessage();
                return;
            }
            else
            {
                std:: cout << "Rear element is: " << tail->getData() << "\n";
            }
        }

        void size()
        {
            if(isEmpty())
            {
                isEmptyMessage();
                return;
            }

            else
            {
                Node* temp = head;
                int count = 0;
                while(temp != NULL)
                {
                    count++;
                    temp = temp->getNext();
                }
                std:: cout << "Size of the queue is: " << count << "\n";


            }
        }
};
int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.display();
    q.front();
    q.peak();
    q.rear();
    q.size();
   
    
    return 0;
}
