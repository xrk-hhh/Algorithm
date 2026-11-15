// 原始稿：03_题目/洛谷/Answer Questions/06_revise_demo6.c
// 原文行号：1-31；恢复外层注释 1 层；保留方法内部注释。
#include <stdio.h>

int main()
{
    /*
        需求：
            假设x=5、y=7，产生如下输出:
            #####
            $$$$$
            &&&&&
    */
    int x, y;
    printf("请输入x和y\n");
    scanf("%d %d",&x,&y);

    if (y == 8)
    {
        if (x == 5)
        {
            puts("@@@@@");
        }
    }
    else
    {
        puts("#####");
        puts("$$$$$");
        puts("&&&&&");
    }
    
    return 0;
}
