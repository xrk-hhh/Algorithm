# 01_minesweeper_game：多方法对照

原稿：[03_题目/洛谷/Algorithm/01_Simulation_and_High_Precision/01_minesweeper_game.c](../../../../../../03_%E9%A2%98%E7%9B%AE/%E6%B4%9B%E8%B0%B7/Algorithm/01_Simulation_and_High_Precision/01_minesweeper_game.c)。按原文顺序拆分独立程序或接口，保留内部注释；原文行号可用于追溯。

| 方法 | 主要做法 | 原文行号 | 类型 | 检查 |
|---|---|---:|---|---|
| [方法01](%E6%96%B9%E6%B3%9501.c) | 邻格分支模拟 | 1–85 | 独立程序 | C11 语法通过 |
| [方法02](%E6%96%B9%E6%B3%9502.c) | 方向数组遍历八邻格 | 86–144 | 独立程序 | C11 语法通过 |

方法名称描述代码做法，不表示在线评测通过。复杂度与题目边界请结合原文注释和原题核对。
