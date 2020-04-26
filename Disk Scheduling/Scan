#include<iostream>
#include<algorithm>
using namespace std;

int nProc, proc[10],head,visited[10],previous,flagFirst=0,flagLast=0;

int findMinMax(int boolCheck)
{
    int temp[nProc];
    for(int i=0;i<nProc+2;i++)
        temp[i]=proc[i];
    sort(temp,temp+nProc);
    if(boolCheck==0) //to return minimum
        return temp[0];
    else if(boolCheck==1)//to return maximum valued process
        return temp[nProc-1];

}

int findShortest( int point)
{

    int dis=999,distance,process,flag=0;
    for(int i=0;i<nProc+2;i++)
    {
        if(visited[proc[i]]==0)
        {
            distance=point-proc[i];
            if(flagFirst==1 || flagLast==1)
            {
                distance=abs(point-proc[i]);
            }
            if(distance>0)
            {

                if(distance<dis)
                {
                    dis=distance;
                    process=proc[i];
                    if(process ==findMinMax(0)) flagLast=1;
                    if(process==findMinMax(1)) flagFirst=1;
                    flag=1;
                }

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
    proc[nProc]=0;
    proc[nProc+1]=99;
    for(int i=0;i<nProc;i++)
        visited[i]=0;
    previous=head;

}

void Scan()
{
    previous=head;
    int cur=proc[0];
    int totalDis=abs(head-cur);
    visited[cur]=0;

    cout<<"\n "<<previous<<" --> "<<cur;

    for(int i=1;i<nProc+2;i++)
    {
        previous=cur;
        visited[previous]=1;
        cur=findShortest(cur);
        cout<<" --> "<<cur;
        if(cur>=0)
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
    Scan();
}

