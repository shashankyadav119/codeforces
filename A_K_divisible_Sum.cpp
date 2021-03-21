#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for(int i = 0;i<n;i++)
#define f2(n) for(int j = 0;j<n;j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

void rev(int arr[],int n)
{
    for(int i = 0 ; i<n/2;i++)
    {
        swap(arr[i],arr[n-1-i]);
    }

    f1(n)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    f1(n)
    {
        cin>>arr[i];
    }

    rev(arr,n);
    
    return 0;
}