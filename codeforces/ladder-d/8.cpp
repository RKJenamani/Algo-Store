#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
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
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define mod 1000000007
#define inf 9999999999999999ll
#define modulo 100000000ll
//ll dp[101][101][11][2];
//dp[i][j][k][l]=number of beautiful permutations in which i footmen are used, j horsemen are used,
//k:represents how many of the last soldiers are of type as represented by l.
ll fun(ll n1,ll n2,ll k1,ll k2,ll flag,ll cont,map <pair<ii,ii>,ll > &m)
{
    //tr2(n1,n2);
    if(m.find(mp(mp(n1,n2),mp(flag,cont)))!=m.end())
        return m[mp(mp(n1,n2),mp(flag,cont))];
    if(flag==0)
    {
        if(cont>k1)
        {
             m[mp(mp(n1,n2),mp(flag,cont))]=0;
            return 0;
        }
    }
    else
    {
        if(cont>k2)
        {
            m[mp(mp(n1,n2),mp(flag,cont))]=0;
            return 0;
        }
    }
    if(n1==0 && n2==0)
    {
        m[mp(mp(n1,n2),mp(flag,cont))]=1;
        return 1;
    }
    if(n1>0 && n2>0)
    {
        if(flag==0)
        {
            ll x=fun(n1-1,n2,k1,k2,0,cont+1,m);
            ll y=fun(n1,n2-1,k1,k2,1,1,m);
            m[mp(mp(n1,n2),mp(flag,cont))]=(x+y)%modulo;
            //tr2(x,y);
            return (x+y)%modulo;
        }
        else
        {
            ll x=fun(n1-1,n2,k1,k2,0,1,m);
            ll y=fun(n1,n2-1,k1,k2,1,cont+1,m);
            m[mp(mp(n1,n2),mp(flag,cont))]=(x+y)%modulo;
            //tr2(x,y);
            return (x+y)%modulo;
        }
    }
    else if(n1==0)
    {
        if(flag==0)
        {
            return (m[mp(mp(n1,n2),mp(flag,cont))]=fun(n1,n2-1,k1,k2,1,1,m));
        }
        else
        {
            return (m[mp(mp(n1,n2),mp(flag,cont))]=fun(n1,n2-1,k1,k2,1,cont+1,m));
        }

    }
    else//n2==0
    {
        if(flag==0)
        {
            return (m[mp(mp(n1,n2),mp(flag,cont))]=fun(n1-1,n2,k1,k2,0,cont+1,m));
        }
        else
        {
            return (m[mp(mp(n1,n2),mp(flag,cont))]=fun(n1-1,n2,k1,k2,0,1,m));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n1,n2,k1,k2;
    cin>>n1>>n2>>k1>>k2;
    map <pair<ii,ii>,ll > m;
    ll ans=fun(n1,n2,k1,k2,0,0,m);
    cout<<ans<<endl;
}
//dp[n1][n2][k][0]=dp[n1-1][n2][k-1][0]+if(k==1)dp[n1-1][n2][all possible last ele][1];
//dp[n1][n2][k][1]=dp[n1][n2-1][k-1][0]+similar as above;
