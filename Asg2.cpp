// YASH KUMAR MITTAL
// 21105069
// ECE

//[Question.1]
// While traversing a single-circular linked list, which condition establishes that the traversing element/variable has reached the first element

//[Ans1]
// Lets Create a circular linked list to understand it
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void insert(Node *&head, int data)
{
    Node *temp = head;
    Node *newnode = new Node(data);
    if (temp == NULL)
    {
        head = newnode;
        newnode->next = head;
        return;
    }
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = head;
}
void display(Node *&head)
{
    Node *temp = head;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    display(head);
}
/*
In the above code

 while(temp->next!=head){temp=temp->next;} establishes that the traversing element has reached the first element.

We know that in circular linked list last node of linked list points to head of that linked list, hence we can check if any node points to head of linked list then that node is the end of circular linked list.
*/

/*[Question.2] 
What are the practical applications of a circular linked list? (Try to find applications in your respective fields).

Practical applications of circular linked list are :

1)Multiplayer Games: All the Players are kept in a Circular Linked List and the pointer keeps on moving forward as a player's chance ends.

2)Monopoly board:The squares on a Monopoly board can be represented in a circularly linked list, to map to their inherent structure.

3)Fionacci Heap: Circular Linked List is also used in the implementation of advanced data structures such as a Fibonacci Heap.

4) Round Robin scheduling technique:lgorithms such as Round Robin setup can effectively complete online queues without having to meet NULL suspension or reference references.

5)Implementation of Data Structure: Data structures such as stacks and queues are implemented with the help of the circular linked lists.

6)Audio/Video Streaming: Circular linked list is also used in audio and video streaming,for ex. when one copmlete audio list finishes playing in music player then it again starts playing from start.

*/

