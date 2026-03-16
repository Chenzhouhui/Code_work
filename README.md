# Git Demo: C 练习项目

这是一个用于复习和练习 C 语言的小项目，包含若干示例文件与练习代码。本 README 汇总了工作区内示例的关键知识点（指针、结构体、动态分配等），并给出每个示例的简短说明与运行方法。

**知识点总结**
- **指针基础**: 指针保存变量地址，可通过解引用访问或修改所指向的值。参见示例: [note/1.c](note/1.c#L1-L120) 中 `pointer_basics()`。
- **指针与数组**: 数组名可退化为指针，指针算术用于遍历数组。参见: [note/1.c](note/1.c#L1-L200) 的 `pointer_and_array()`。
- **指针的指针（二级指针）**: 指向指针的指针可用于在函数中修改调用者的指针（例如动态分配）。参见: [git_demo/5.c](git_demo/5.c#L1-L120) 与 [note/1.c](note/1.c#L1-L200)。
- **通过指针修改外部变量（传地址）**: 函数接收指针参数以修改调用处变量（swap 示例）。参见: [git_demo/1.c](git_demo/1.c#L1-L50) 与 [note/1.c](note/1.c#L1-L200)。
- **结构体定义与 typedef**: 用 `struct` 定义复合数据类型，`typedef` 可简化类型名。参见: [git_demo/2.c](git_demo/2.c#L1-L120)、[note/1.c](note/1.c#L1-L200)。
- **结构体指针与 -> 运算符**: 通过结构体指针访问成员使用 `->`，或通过 `(*p).member`。参见: [git_demo/3.c](git_demo/3.c#L1-L120)、[git_demo/4.c](git_demo/4.c#L1-L200)、[note/1.c](note/1.c#L1-L200)。
- **动态分配（malloc/free）与结构体**: 在堆上分配结构体并记得释放以避免内存泄漏。参见: [git_demo/4.c](git_demo/4.c#L1-L200)、[note/1.c](note/1.c#L1-L200)。

**工作区示例文件说明**
- [note/1.c](note/1.c#L1-L200): 综合示例，演示指针基础、数组与指针、指针的指针、`swap`、结构体用法、结构体的动态分配与嵌套结构体。
- [git_demo/1.c](git_demo/1.c#L1-L50): 使用指针实现 `swap` 函数的简单示例。
- [git_demo/2.c](git_demo/2.c#L1-L120): 使用 `typedef struct` 定义 `Student`，并演示结构体数组的初始化与遍历。
- [git_demo/3.c](git_demo/3.c#L1-L120): 结构体指针作为函数参数，演示通过指针初始化结构体成员。
- [git_demo/4.c](git_demo/4.c#L1-L200): 在堆上分配结构体并通过指针初始化与访问。
- [git_demo/5.c](git_demo/5.c#L1-L120): 二级指针示例，演示在函数中为调用者分配内存并修改调用者的指针。

**编译与运行（Windows, MinGW/gcc）**
在工作区根目录运行示例（示例命令）：

```bash
gcc -g git_demo/1.c -o git_demo/1.exe
./git_demo/1.exe

gcc -g note/1.c -o note/1.exe
./note/1.exe
```

或者在 VS Code 中打开目标文件并运行工作区任务 “C/C++: gcc.exe 生成活动文件”。

**建议与下一步**
- 我可以为每个 `git_demo` 示例添加更详细中文注释并验证它们能否在你的环境中顺利编译运行；要我继续吗？
