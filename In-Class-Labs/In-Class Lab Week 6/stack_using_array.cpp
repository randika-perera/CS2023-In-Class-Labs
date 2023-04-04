#include <iostream>
using namespace std;

/* Create an integer array of size 100. */
int stack_using_array[100]; 
int stacksize=100;

/* Set the variable top to -1. Top represents the index of the element that was
inserted last into the stack. Since at the start, there are no elements in the 
stack, top is set to -1. */
int top=-1;

/* Define push function. Function type is void since it just 
modifies the array without returning anything. */
void Push(int val) 
{
    if(top>=stacksize-1) //Checking if the stack is full
    cout<<"Stack Overflow"<<endl;
    else 
    {
        top++;
        stack_using_array[top]=val;
    }
}

/* Define pop function. Function type is void since it just 
modifies the array without returning anything. */
void Pop() 
{
    if(top<=-1) //Checking if the stack is empty
    cout<<"Stack Underflow"<<endl;
    else 
    {
        cout<<"The popped element is "<< stack_using_array[top] <<endl;
        top--;
    }
}

/* Define display function to print all the elements of the stack. 
Topmost element of the stack will be printed first. 
Function type is void since it just modifies the array without returning anything. */
void Display() 
{
    if(top>=0) //First check if there are elements inside the stack to print
    {
        cout<<"Stack elements are : ";
        for (int i=top;i>=0;i--)
        {
            cout<<stack_using_array[i]<<" ";
        }
        cout<<endl;
    } 
    else
    {
        cout<<"Stack is empty";
    }
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

