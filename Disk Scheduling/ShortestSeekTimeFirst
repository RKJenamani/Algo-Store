#include<iostream>
#include<math.h>
using namespace std;

int nProc, proc[10],head,visited[10],previous;

int findShortest( int point)
{
    int dis=999,distance,process,flag=0;
    for(int i=0;i<nProc;i++)
    {
        if(visited[proc[i]]==0)
        {
            distance=abs(point-proc[i]);
            if(distance<dis)
            {
              dis=distance;
              process=proc[i];
              flag=1;
            }

        }

    }
    if(flag==1)
        return process;
    else return -1;
}

void input()
{
    cout<<"\n Enter head";
    cin>>head;
    cout<<"\n Enter no. of proc excluding head count";
    cin>>nProc;
    for(int i=0;i<nProc;i++)
        cin>>proc[i];
    for(int i=0;i<nProc;i++)
        visited[i]=0;
    previous=head;

}

void SSTF()
{
    int cur=head;
    cout<<cur;
    int totalDis=0;

    for(int i=0;i<nProc;i++)
    {
        previous=cur;
        visited[previous]=1;
        cur=findShortest(cur);
        cout<<" --> "<<cur;
        if(cur>0)
        {
            totalDis+=abs(previous-head);
        }
        else
            break;
    }
    cout<<"\n Distance : "<<totalDis;
}

int main()
{
    input();
    SSTF();
}
