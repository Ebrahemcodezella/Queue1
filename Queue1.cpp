#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;Node()
    {
        data = 0;
        next = NULL;
    }
};
class LinkedQueue
{
public:
    Node* front;
    Node* back;
    LinkedQueue()
    {
        front = back = nullptr;
    }
    bool isEmpty()
    {
        return(front == NULL);
    }
    void Enqueue(int val)
    {
        Node *node = new Node();
        node->data = val;
        if (isEmpty())
        {
            front = node;
            back = node;
        }
        else {
            back->next = node;
            back= node;
        }
    }
    void Dequeue() {
        Node* del = front;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else if (front == back)
        {
            delete front;
            front = back = nullptr;
        }
        else {
            front = front->next;
            delete del;
        }
    }

    void display() {
        Node* temp = front;
        while (temp!=nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    int getfront()
    {
        return front->data;
    }
    int getback()
    {
        return back->data;
    }
    void Search(int val)
    {
        Node* sea = front;
        bool flage = true;
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else {
            while (sea != nullptr)
            {
                if (sea->data == val)
                {
                    cout << "Value is exist " << endl;
                    flage = false;
                }
                sea = sea->next;
            }
            if (flage)
            {
                cout << "Value not exist" << endl;
            }
        }
    }

};
   
int main()
{
    LinkedQueue lq;
    lq.Enqueue(1);
    lq.Enqueue(2);
    lq.Enqueue(3);
    lq.Enqueue(4);
    lq.Enqueue(5);
    lq.Enqueue(6);
    lq.Enqueue(7);
    lq.Dequeue();
    lq.Search(4);
    lq.Search(7);
    cout<<lq.getback()<<endl;
    cout<<lq.getfront()<<endl;
    lq.display();

    
}

