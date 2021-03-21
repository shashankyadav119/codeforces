#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

bool sortBySec(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return b.second > a.second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> vp, dp;

    f1(n)
    {
        ll a, b;
        cin >> a >> b;
        vp.pb(make_pair(a, b));
        // dp.pb(make_pair(a, b));
    }

    ll day = 0;

    sort(vp.begin(), vp.end());
    f1(n)
    {
        if (min(vp[i].first, vp[i].second) >= day)
        {
            day = min(vp[i].first, vp[i].second);
        }
        else
        {
            day = max(vp[i].first, vp[i].second);
        }
    }
    cout << day << endl;

    return 0;
}