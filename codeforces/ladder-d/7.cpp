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
    ll n,m;
    cin>>n>>m;
    vv adjm(n,vi(n,0));
    vv adjl(n,vi());
    for(ll i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        adjm[a-1][b-1]=1;
        adjl[a-1].pb(b-1);
    }
    ll count=0;
    for(ll i=0;i<n;i++) // all a
    {
        for(ll j=0;j<n;j++) // all c
        {
            if(i!=j)
            {
                ll num=0;
                for(ll k=0;k<adjl[i].size();k++)
                    if(adjm[ adjl[i][k] ][j] == 1)
                        num++;
                count += (num*(num-1))/2;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}