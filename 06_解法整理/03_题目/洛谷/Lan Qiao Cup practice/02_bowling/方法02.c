// 原始稿：03_题目/洛谷/Lan Qiao Cup practice/02_bowling.c
// 原文行号：87-230；恢复外层注释 2 层；保留方法内部注释。
#include <stdio.h>
#include <stdlib.h>

#define MAX_HASH 200003 // 桶的总数（选质数减少冲突）

typedef struct {
    int val;   // 存储瓶子数（键）
    int pos;   // 存储对应的位置（值）
    int next;  // 链表指针：指向下一个节点在hash_table中的下标
} HashNode;

HashNode hash_table[MAX_HASH]; // 存储所有链表节点（最多MAX_HASH个）
int head[MAX_HASH];            // 每个桶的头节点下标（-1表示空桶）
int idx = 0;                   // 记录hash_table的下一个可用位置

/*
    hash_table：是一个数组，每个元素是一个链表节点，保存 “瓶子数 - 位置” 对，以及指向下一个节点的 “指针”（这里用数组下标模拟指针）；
    head：是一个数组，head[h]表示哈希值为h的桶对应的链表头节点在hash_table中的下标；
    idx：相当于 “节点计数器”，每插入一个新节点，就把它存在hash_table[idx]，然后idx++。
*/

// 哈希函数
int hash(int x) 
{
    return (x % MAX_HASH + MAX_HASH) % MAX_HASH; // 处理负数（本题x为正，可简化）
}

/*
    作用：将任意整数x（瓶子数）映射到0~MAX_HASH-1范围内的一个 “桶编号”h；
    取模MAX_HASH是为了让桶编号不超出head数组的范围；
    +MAX_HASH再取模是为了处理x为负数的情况（本题x是正整数，可简化为x%MAX_HASH）。
*/

// 插入哈希表
void insert(int val, int pos) 
{
    int h = hash(val); // 第一步：计算桶编号h
    // 第二步：创建新节点，存在hash_table[idx]
    hash_table[idx].val = val;
    hash_table[idx].pos = pos;
    hash_table[idx].next = head[h]; // 新节点的next指向当前桶的头节点
    // 第三步：更新桶的头节点为新节点的下标
    head[h] = idx;
    // 第四步：idx自增，准备存储下一个新节点
    idx++;
}

/*
    插入逻辑拆解（结合例子）：
    假设插入第一个元素：val=5，pos=1

    1.计算哈希值h=5%200003=5；
    2.初始时head[5]=-1（桶 5 是空的）；
    3.新节点存在hash_table[0]：
    hash_table[0].val=5，hash_table[0].pos=1，hash_table[0].next=-1（没有下一个节点）；
    4.更新head[5]=0（桶 5 的头节点是hash_table[0]）；
    5.idx变为1。

    再插入第二个元素：val=200008，pos=2（哈希值h=200008%200003=5，冲突）
    1.哈希值h=5（和val=5冲突）；
    2.新节点存在hash_table[1]：
    3.hash_table[1].val=200008，hash_table[1].pos=2，hash_table[1].next=head[5]=0（指向之前的头节点）；
    更新head[5]=1（桶 5 的头节点变为新节点）；
    4.idx变为2。

    此时桶 5 的链表结构：head[5]=1 → hash_table[1].next=0 → hash_table[0].next=-1（新节点插在链表头部）。
*/

// 查询哈希表
int find(int val) 
{
    int h = hash(val); // 第一步：计算桶编号h
    // 第二步：遍历桶h对应的链表
    for (int i = head[h]; i != -1; i = hash_table[i].next) 
    {
        if (hash_table[i].val == val) 
        { // 找到目标值
            return hash_table[i].pos;   // 返回对应的位置
        }
    }
    return 0; // 遍历完链表没找到，返回0
}

/*
    查询逻辑拆解（结合上面的例子）：

    查询val=200008：
    1.哈希值h=5；
    2.从head[5]=1开始遍历：
    i=1：hash_table[1].val=200008（匹配），返回pos=2；

    查询val=5：
    1.哈希值h=5；
    2.从head[5]=1开始遍历：
    i=1：hash_table[1].val=200008（不匹配），继续；
    i=hash_table[1].next=0：hash_table[0].val=5（匹配），返回pos=1；

    查询val=10（不存在）：
    1.哈希值h=10；
    2.head[10]=-1（桶 10 是空的），直接返回0。
*/

int main() 
{
    // 初始化哈希表头
    for (int i = 0; i < MAX_HASH; i++) 
    {
        head[i] = -1;
    }

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        int a;
        scanf("%d", &a);
        insert(a, i); // 存储值和位置
    }

    int Q;
    scanf("%d", &Q);
    while (Q--) 
    {
        int m;
        scanf("%d", &m);
        printf("%d\n", find(m)); // 直接查询
    }

    /*
        主函数逻辑：串联所有步骤

        1.初始化head数组：所有桶的头节点设为-1（表示空桶）；
        2.读取位置数n：循环n次，读取每个位置的瓶子数a[i]，调用insert(a[i], i)存入哈希表；
        3.读取查询次数Q：循环Q次，读取每次的目标m，调用find(m)查询位置并输出（没找到则输出0）。
    
        整个逻辑的核心是 “哈希分组 + 链表串冲突”，通过head数组记录每个桶的链表入口，实现高效的插入和查询。
    */
    return 0;
}

// /*

// */
