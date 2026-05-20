// #include <bits/stdc++.h>
// using namespace std;

// struct Student
// {
//     string name;
//     int ch, ma, en, tot;

//     Student(string A, int B, int C, int D)
//     {
//         name = A;
//         ch = B;
//         ma = C;
//         en = D;
//         tot = B + C + D; 
//     }

//     Student() = default;

//     bool operator > (const Student & x)const
//     {
//         return tot > x.tot;
//     }

// }a[1010];

// string A;
// int B, C, D;

// int main()
// {
//     int n;
//     cin>>n;

//     for (int i = 0; i < n; i++)
//     {
//         cin>>A>>B>>C>>D;
//         a[i] = Student(A, B, C, D);
//     }

//     Student ans = a[0];

//     for (int i = 1; i < n; i++)
//     {
//         if (a[i] > ans)
//         {
//             ans = a[i];
//         }
//     }

//     cout<<ans.name<<' '<<ans.ch<<' '<<ans.ma<<' '<<ans.en<<endl;

//     return 0;
// }