#include <iostream>
using namespace std;
int stack[10], n = 10, top = -1;
void push(int val)
{
    if (top >= n - 1)
        cout << "Stack Is Full" << endl;
    else
    {
        top++;
        stack[top] = val;
    }
}
void pop()
{
    if (top <= -1)
        cout << "Stack is empty" << endl;
    else
    {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void isempty()
{
    if (top == -1)
    {
        cout << "Stack is currently empty" << endl;
    }
    else
    {
        cout << "Stack is not empty" << endl;
    }
}
int kth_ele_top(int pos)
{
   
    int s = top;
    int cnt = 0;
    if (s > top)
    {
        return -1;
    }
    while (cnt < pos)
    {
        cnt++;
        s--;
    }
    return stack[s];
}
void replace(int val, int pos)
{
  
    int s = top;
    int cnt = 0;
    // if (s > top)
    // {
    //     return -1;
    // }
    while (cnt < pos)
    {
        cnt++;
        s--;
    }
    stack[s] = val;
}
void print()
{
    for (int x = 0; x <= top; x++)
    {
        cout << stack[x] << " ";
    }
    cout << endl;
}
void is_full(){
    if(top == n-1){
        cout<<"Full"<<endl;
    }
    else{
        cout<<"Not full"<<endl;
    }
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    print();
    pop();
    print();
    pop();
    print();
    cout <<"Kth element from top is:-" <<kth_ele_top(2) << endl;
    // cout<<stack[top]<<endl;
    // pop();
    // pop();
    // cout<<stack[top]<<endl;
     isempty();
     replace(23,2);
     print();
     replace(353,1);
     print();
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    print();
    is_full();
     pop();
     is_full();
    // pop();
    // cout << kth_ele_top(1) << endl;
}