# 字符串与Trie

**核心：前后缀状态与按位分支。**

KMP O(n+m)；Trie 处理前缀；01-Trie 贪心选择异或分支；Manacher 处理回文半径。

常见检查点：next/pi 定义差异、匹配后的回退、字符集和值域、总节点数。

## 知识文章

- [字符串六题：next 数组的花式玩法](../%E7%BD%91%E7%AB%99%E7%AE%97%E6%B3%95%E4%B8%93%E9%A2%98/2026-08-16-string-kmp-roundup.md)

## 对应代码

专题标签来自题号、原目录、网站题解或代码结构；标为“候选”的行需进一步人工确认。全注释文件保留原貌，并不代表可直接执行。

| 文件 | 题目 | 分类依据 | 源码形态 |
|---|---|---|---|
| [02_模板/字符串与Trie/洛谷/String/P_1470_IOI_1996_USACO_2_3_最长前缀_Longest_Prefix.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_1470_IOI_1996_USACO_2_3_%E6%9C%80%E9%95%BF%E5%89%8D%E7%BC%80_Longest_Prefix.cpp) | [P1470 [IOI 1996 / USACO2.3] 最长前缀 Longest Prefix](https://www.luogu.com.cn/problem/P1470) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_2375_NOI_2014_动物园.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_2375_NOI_2014_%E5%8A%A8%E7%89%A9%E5%9B%AD.cpp) | [P2375 [NOI2014] 动物园](https://www.luogu.com.cn/problem/P2375) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_3375_模板_KMP.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_3375_%E6%A8%A1%E6%9D%BF_KMP.cpp) | [P3375 【模板】KMP](https://www.luogu.com.cn/problem/P3375) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_3435_POI_2006_OKR_Periods_of_Words.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_3435_POI_2006_OKR_Periods_of_Words.cpp) | [P3435 [POI 2006] OKR-Periods of Words](https://www.luogu.com.cn/problem/P3435) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_4391_BalticOI_2009_Radio_Transmission_无线传输.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_4391_BalticOI_2009_Radio_Transmission_%E6%97%A0%E7%BA%BF%E4%BC%A0%E8%BE%93.cpp) | [P4391 [BalticOI 2009] Radio Transmission 无线传输](https://www.luogu.com.cn/problem/P4391) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_4551_最长异或路径.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_4551_%E6%9C%80%E9%95%BF%E5%BC%82%E6%88%96%E8%B7%AF%E5%BE%84.cpp) | [P4551 最长异或路径](https://www.luogu.com.cn/problem/P4551) | 题号/模板目录 | 全注释/空文件 |
| [02_模板/字符串与Trie/洛谷/String/P_4824_USACO_15_FEB_Censoring_S.cpp](../../02_%E6%A8%A1%E6%9D%BF/%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%8ETrie/%E6%B4%9B%E8%B0%B7/String/P_4824_USACO_15_FEB_Censoring_S.cpp) | [P4824 [USACO15FEB] Censoring S](https://www.luogu.com.cn/problem/P4824) | 题号/模板目录 | 全注释/空文件 |
| [03_题目/蓝桥杯/国赛/P_12213_蓝桥杯_2023_国_Python_B_最长回文前后缀.cpp](../../03_%E9%A2%98%E7%9B%AE/%E8%93%9D%E6%A1%A5%E6%9D%AF/%E5%9B%BD%E8%B5%9B/P_12213_%E8%93%9D%E6%A1%A5%E6%9D%AF_2023_%E5%9B%BD_Python_B_%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%89%8D%E5%90%8E%E7%BC%80.cpp) | [P12213 [蓝桥杯 2023 国 Python B] 最长回文前后缀](https://www.luogu.com.cn/problem/P12213) | 题号/模板目录 | 全注释/空文件 |
| [03_题目/蓝桥杯/国赛/P_3805_模板_Manacher.cpp](../../03_%E9%A2%98%E7%9B%AE/%E8%93%9D%E6%A1%A5%E6%9D%AF/%E5%9B%BD%E8%B5%9B/P_3805_%E6%A8%A1%E6%9D%BF_Manacher.cpp) | [P3805 【模板】Manacher](https://www.luogu.com.cn/problem/P3805) | 题号/模板目录 | 全注释/空文件 |
