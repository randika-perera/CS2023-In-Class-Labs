/*
Carry out the same set of stack operations on the 2 implementations of stack. 
First using array implementation of stack.
Then using linked list implementation of stack.
Then compare the time taken by the 2 implementations.
*/

#include <bits/stdc++.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

/*-------------------------------------------------------------------*/

/*Functions and variables needed to implement stack using array.     */
int stack_using_array_A[100]; 
int stacksize_A=100;
int top_A=-1;
void Push_A(int val) 
{
    if(top_A>=stacksize_A-1)
    cout<<"Stack Overflow"<<endl;
    else 
    {
        top_A++;
        stack_using_array_A[top_A]=val;
    }
}
void Pop_A() 
{
    if(top_A<=-1) 
    cout<<"Stack Underflow"<<endl;
    else 
    {
        cout<<"The popped element is "<< stack_using_array_A[top_A] <<endl;
        top_A--;
    }
}

void Display_A() 
{
    if(top_A>=0) 
    {
        cout<<"Stack elements are : ";
        for (int i=top_A;i>=0;i--)
        {
            cout<<stack_using_array_A[i]<<" ";
        }
        cout<<endl;
    } 
    else
    {
        cout<<"Stack is empty";
    }
}

/*-------------------------------------------------------------------*/

/*Functions and variables needed to implement stack using linkedlist.*/
struct Node 
{
    int data;
    struct Node *next;
};
struct Node* top = NULL;
void Push_LL(int val) 
{
    struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = val;
    newnode->next = top;
    top = newnode;
}
void Pop_LL() 
{
    if(top==NULL)
    cout<<"Stack Underflow"<<endl;
    else 
    {
        cout<<"The popped element is "<< top->data <<endl;
        top = top->next;
    }
}
void Display_LL() 
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

/*-------------------------------------------------------------------*/

/*
This is the list of operations that we will perform.
Push(8)
Push(10)
Push(5)
Push(11)
Push(15)
Push(23)
Push(6)
Push(18)
Push(20)
Push(17)
Display()
Pop() × 5 times
Display()
Push(4)
Push(30)
Push(3)
Push(1)
Display()
*/

/*-------------------------------------------------------------------*/

int main()
{

    cout<<endl;

    //First find time taken for stack using array.
    cout<<"Doing operations for Stack Implementation using Array"<<endl;
    auto t_start_A = chrono::high_resolution_clock::now();
    Push_A(8);
    Push_A(10);
    Push_A(5);
    Push_A(11);
    Push_A(15);
    Push_A(23);
    Push_A(6);
    Push_A(18);
    Push_A(20);
    Push_A(17);
    Display_A();
    Pop_A();
    Pop_A();
    Pop_A();
    Pop_A();
    Pop_A();
    Display_A();
    Push_A(4);
    Push_A(30);
    Push_A(3);
    Push_A(1);
    Display_A();
    auto t_stop_A = high_resolution_clock::now();
    auto t_duration_A = duration_cast<microseconds>(t_stop_A - t_start_A);

    cout<<endl;

    //Now find time taken for stack using linked list.
    cout<<"Doing operations for Stack Implementation using LinkedList"<<endl;
    auto t_start_LL = chrono::high_resolution_clock::now();
    Push_LL(8);
    Push_LL(10);
    Push_LL(5);
    Push_LL(11);
    Push_LL(15);
    Push_LL(23);
    Push_LL(6);
    Push_LL(18);
    Push_LL(20);
    Push_LL(17);
    Display_LL();
    Pop_LL();
    Pop_LL();
    Pop_LL();
    Pop_LL();
    Pop_LL();
    Display_LL();
    Push_LL(4);
    Push_LL(30);
    Push_LL(3);
    Push_LL(1);
    Display_LL();
    auto t_stop_LL = high_resolution_clock::now();
    auto t_duration_LL = duration_cast<microseconds>(t_stop_LL - t_start_LL);

    cout<<endl;

    cout<<"Time taken,"<<endl;
    cout<<"Total time taken for Stack Implementation using Array : "<<t_duration_A.count()<<" Microseconds"<<endl;
    cout<<"Total time taken for Stack Implementation using LinkedList : "<<t_duration_LL.count()<<" Microseconds"<<endl;

    cout<<endl;

    return 0;
}