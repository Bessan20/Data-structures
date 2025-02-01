#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int x = 5;  //value of x
    int* ptr = &x; //assign the address value of x to the pointer ptr
    cout<<x<<" "<<*ptr<<" "<<ptr<<"\n";
    //the output : 5  5  address of x 
    *ptr = 10;//the value of x changes
    cout<<x<<"\n";//10

    //program to add two numbers using pointers
    int num1 = 5, num2 = 10;
    int* pnum1 = &num1, *pnum2 = &num2;
    int sum = *pnum1 + *pnum2;
    cout<<"Sum : "<<sum<<"\n";//15

    //program to swap two numbers using pointers
    cout<<"Before swapping : "<<*pnum1<<" "<<*pnum2<<"\n";
    swap(*pnum1,*pnum2);
    cout<<"After swapping : "<<*pnum1<<" "<<*pnum2<<"\n";

    swap(*pnum1,*pnum2);

  //program to find the maximum number between three number using pointers
  
  cout<<max(4,7);
  cout<<max({7,8,9});
 cout<<7;   
    
    return 0;
}