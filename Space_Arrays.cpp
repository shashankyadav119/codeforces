#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    v.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        ll temp;
        cin >> temp;
        v.pb(temp);
    }

    sort(v.begin(), v.end());
    int count = 0;

    for(int i = 0 i<=n;i++)
    {
        if(v[i]>i)
        {
            
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}