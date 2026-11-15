#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

void div(vector<int>& A, int b, vector<int>& C)
{
    ll r = 0;
    for (int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }

    reverse(C.begin(), C.end());

    while ((C.size() > 1) && (!C.back()))
    {
        C.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin>>T;

    while (T--)
    {
        string a;
        int b;
        cin>>a>>b;

        vector<int> A, C;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            A.push_back(a[i] - '0');
        }

        div(A, b, C);

        for (int i = C.size() - 1; i >= 0; i--)
        {
            cout<<C[i];
        }

        cout<<endl;
    }

    return 0;
}