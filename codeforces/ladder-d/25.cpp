#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define mod 1000000007
#define inf 999999999999999ll
 
int main()
{
    ll r,c;
    cin>>r>>c;
    vs a(r,"");
    ll exitr,exitc;
    ll startr,startc;
    for(ll i=0;i<r;i++)
    {
        cin>>a[i];
        for(ll j=0;j<a[i].size();j++)
        {
            if(a[i][j]=='E')
            {
                exitr = i;
                exitc = j;
            }
            if(a[i][j]=='S')
            {
                startr=i;
                startc=j;
            }
        }
    }

    // BFS with exit as source
    vv distance(r,vi(c,inf));
    vv visited(r,vi(c,0)); 
  
    queue <ii> q; 

    // cout<<startr<<" "<<startc<<endl;
    // cout<<exitr<<" "<<exitc<<endl;

    visited[exitr][exitc] = 1; 
    distance[exitr][exitc] = 0; 
    q.push(mp(exitr,exitc)); 
  
    while(!q.empty()) 
    {  
        ii temp = q.front(); 
        q.pop(); 
        if(temp.F-1>=0 && a[temp.F-1][temp.S] != 'T' && visited[temp.F-1][temp.S] == 0 )
        {
            visited[temp.F-1][temp.S] = 1;
            distance[temp.F-1][temp.S] = distance[temp.F][temp.S]+1;
            q.push(mp(temp.F-1,temp.S));
        }
        if(temp.S-1>=0 && a[temp.F][temp.S-1] != 'T' && visited[temp.F][temp.S-1] == 0 )
        {
            visited[temp.F][temp.S-1] = 1;
            distance[temp.F][temp.S-1] = distance[temp.F][temp.S]+1;
            q.push(mp(temp.F,temp.S-1));
        }
        if(temp.S+1<c && a[temp.F][temp.S+1] != 'T' && visited[temp.F][temp.S+1] == 0 )
        {
            visited[temp.F][temp.S+1] = 1;
            distance[temp.F][temp.S+1] = distance[temp.F][temp.S]+1;
            q.push(mp(temp.F,temp.S+1));
        }
        if(temp.F+1<r && a[temp.F+1][temp.S] != 'T' && visited[temp.F+1][temp.S] == 0 )
        {
            visited[temp.F+1][temp.S] = 1;
            distance[temp.F+1][temp.S] = distance[temp.F][temp.S]+1;
            q.push(mp(temp.F+1,temp.S));
        }
    } 

    // for(ll i=0;i<r;i++)
    // {
    //     for(ll j=0;j<c;j++)
    //         cout<<distance[i][j]<<" ";
    //     cout<<endl;
    // }

    ll mindistance = distance[startr][startc];

    ll ans=0;
    for(ll i=0;i<r;i++)
        for(ll j=0;j<c;j++)
            if(a[i][j] !='S' && a[i][j]!='E' && a[i][j]!='T' && distance[i][j]<=mindistance)
                ans+= a[i][j] - '0';

    cout<<ans<<endl;


    return 0;
}