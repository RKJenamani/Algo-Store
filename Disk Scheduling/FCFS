#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int nProc,head,prev,dis=0;
    cout<<"\nEnter head";
    cin>>head;
    cout<<"\nEnter no. of processes excluding head process : ";
    cin>>nProc;
    int proc[nProc];
    for(int i=0;i<nProc;i++)
        cin>>proc[i];
    prev=head;
    cout<<head;
    for(int i=0;i<nProc;i++)
    {
      cout<<" --> "<<proc[i];
      dis+=abs(prev-proc[i]);
    }
    cout<<"\n Distance : "<<dis;
}
