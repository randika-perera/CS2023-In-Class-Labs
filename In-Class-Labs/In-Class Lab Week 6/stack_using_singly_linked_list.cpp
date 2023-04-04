#include <iostream>
using namespace std;

/* We will use structure-Node to create the linked list that is used to implement the stack */
struct Node 
{
    int data;
    struct Node *next;
};

struct Node* top = NULL;

/* Define Push function.
We will make a new node and insert val into the data part. 
This node is added to the front of the linked list and top points to it. */
void Push(int val) 
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}

/* Define Pop function.
We will pop the topmost value of the stack, if there is a value. 
If the stack is empty, underflow is printed. */
void Pop() 
{
    if(top==NULL)
    cout<<"Stack Underflow"<<endl;
    else 
    {
        cout<<"The popped element is "<< top->data <<endl;
        top = top->next;
    }
}

/* Define Display function 
Ptr initially points to top and goes until the end of the stack. 
All the values corresponding to ptr will be printed. */
void Display() 
{
    struct Node* ptr;
    if(top==NULL)
    cout<<"stack is empty";
    else 
    {
        ptr = top;
        cout<<"Stack elements are: ";
        while (ptr != NULL) 
        {
            cout<< ptr->data <<" ";
            ptr = ptr->next;
        }
    }
    cout<<endl;
}


/* Main function. */
int main() 
{
    /* Perform operations onto the stack using a menu-driven 
    interface that the user can interact with */
    int ch, val;
    cout<<"1) Push in stack"<<endl;
    cout<<"2) Pop from stack"<<endl;
    cout<<"3) Display stack"<<endl;
    cout<<"4) Exit"<<endl<<endl;

    do 
    {
        cout<<endl<<"Enter choice: ";
        cin>>ch;
        switch(ch) 
        {
            case 1: 
            {
                cout<<"Enter value to be pushed: ";
                cin>>val;
                Push(val);
                break;
            }
            case 2: 
            {
                Pop();
                break;
            }
            case 3: 
            {
                Display();
                break;
            }
            case 4: 
            {
                cout<<"Exit"<<endl<<endl;
                break;
            }
            default: 
            {
                cout<<"Invalid Choice"<<endl;
            }
        }
    }
    while(ch!=4);

    return 0;

}

