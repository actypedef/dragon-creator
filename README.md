# Dragon-creator
> a program that reads a program and outputs some 🐉-like code. 😍

Xiwon 的 `shit-creator` 的 🐉 ver

简单的替换所有的标识符为 '🐉', '🐲', '🐍' 组成的字符串

原理：提取所有 `[A-Za-z0-9_]+` 匹配的串，然后依次判断是否需要替换

naive 且暴力的实现（

由于完全没有语法 / 语义分析 (词法分析都算不上)，所以需要直接打保留字表。

如果你发现 create 出来的 dragon.cpp 没办法编译过，可以试着找找源代码里哪些不该替换的字符被替换成了 '🐉🐉🐉🐲🐍...'，然后把他们逐一添加到保留字表中（

### 项目意义！

没有意义 😀
