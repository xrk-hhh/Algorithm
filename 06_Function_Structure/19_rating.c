// #include <stdio.h>

// typedef struct
// {
//     int a, b, c;
// } STU;

// STU stu[1010];

// int score(int b, int c)
// {
//     return b * 7 + c * 3; 
// }

// int main()
// {
//     int N;
//     scanf("%d", &N);

//     for (int i = 0; i < N; i++)
//     {
//         scanf("%d %d %d", &stu[i].a, &stu[i].b, &stu[i].c);
//     }

//     for (int i = 0; i < N; i++)
//     {
//         int b = stu[i].b;
//         int c = stu[i].c;
//         int bc = b + c;
//         int sc = score(b, c);
//         if (bc > 140 && sc >= 800)
//         {
//             printf("Excellent\n");
//         }
//         else
//         {
//             printf("Not excellent\n");
//         }
//     }

//     return 0;
// }