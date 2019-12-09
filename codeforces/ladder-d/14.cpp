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
vi fun(string &s)//returns length of longest prefix which is also a suffix
{
    ll len=0;
    ll m=s.size();
    vi lps(m,0);
    ll i=1;
    while(i<m)
    {
        if(s[i]==s[len])
        {
           len++;
           lps[i]=len;
           i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin>>s;
    vi a=fun(s);
    ll n=s.size();
    vb exist(n+2,false);
    for(ll i=1;i<(ll)a.size()-1;i++)
    {
        exist[a[i]]=true;
    }
    ll len=a.back();
    while(len>0)
    {
        if(exist[len])
        {
            for(ll i=0;i<len;i++)
            {
                cout<<s[i];
            }
            cout<<"\n";
            return 0;
        }
        len=a[len-1];
    }
    cout<<"Just a legend\n";
}
