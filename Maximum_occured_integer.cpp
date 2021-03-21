// #include <bits/stdc++.h>
// using namespace std;

// #define pb push_back
// #define f1(n) for (int i = 0; i < n; i++)
// #define f2(n) for (int j = 0; j < n; j++)
// #define mmax 100005
// #define all(v) v.begin(), v.end()
// #define ll long long

// typedef pair<int, int> pi;
// map<int, int> mp;
// int ar[100000];
// int br[100000];

// void num(int a, int b, int n)
// {

//     int maxo = -1,mino = -74;
//     for (int i = a; i <= b; i++)
//     {
//         mp[i]++;
//     }

//     map<int, int>::iterator itr;

//     for (itr = mp.begin(); itr != mp.end(); itr++)
//     {
//         cout << itr->first << " " << itr->second << endl;

//         int r = itr->first;
//         int t = itr->second;

//         if(t > maxo)
//         {
//             maxo = t;
//             mino = r;
//         }

//     }
//     cout << maxo <<" "<<mino<< endl;
// }

// void maxo(int l[], int r[], int n)
// {
//     int res = 0;
//     f1(n)
//     {
//         num(l[i], r[i], n);
//     }
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0), cout.tie(0);
//     int n;
//     cin >> n;
//     int l[n], r[n];
//     f1(n)
//     {
//         cin >> l[i];
//     }
//     f1(n)
//     {
//         cin >> r[i];
//     }

//     maxo(l, r, n);
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for(int i = 0;i<n;i++)
#define f2(n) for(int j = 0;j<n;j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

int arr[1000000];
int prefixSum[1000000];
int max = 1000000;

int maxo(int l[],int r[],int n)
{
    for(int i = 0;i<n+2;i++)
    {
        arr[l[i]]+=1;
        arr[r[i]+1]+=-1;
    }

    prefixSum[0] = arr[0];

    f1(n+3)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int l[n], r[n];
    f1(n)
    {
        cin >> l[i];
    }
    f1(n)
    {
        cin >> r[i];
    }

    maxo(l, r, n);
    return 0;
}

