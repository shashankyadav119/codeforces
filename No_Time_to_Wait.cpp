#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, h, x;
    cin >> n >> h >> x;
    int maxo = INT_MIN;
    vector<int> t;
    f1(n)
    {
        int temp;
        cin>>temp;
        t.pb(temp);
        if (temp >= maxo)
        {
            maxo = temp;
        }
    }
    if (x + maxo >= h)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}