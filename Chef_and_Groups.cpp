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
    string s;
    cin >> s;
    int n = s.length();
    int count0 = 0, count = 0;
    vector<int> v;
    f1(n)
    {
        if (s[i] == '1')
        {
            v.pb(i);
        }
    }
    // cout<<"Hello ";
    if (v.size() == 0)
    {
        count = 0;
        cout<<count<<endl;
        return;
    }

    if (v.size() == 1)
    {
        count = 1;
        cout<<count<<endl;
        return;
    }

    count = 1;

    for (int i = 0; i < v.size()-1; i++)
    {
        if (v[i + 1] - v[i] > 1)
            count++;
    }
    cout<<count<<endl;
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