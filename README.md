# Git Demo: C 练习项目

这是一个用于复习和练习 C 语言的小项目，包含若干示例文件和简单的构建说明。

## 目录结构

- `git_demo/`：示例 C 源文件。
	- `1.c`
	- `2.c`
	- `3.c`

## 前提条件

- 已安装 MinGW 或其他可用的 `gcc` 编译器（Windows 下可使用 `C:\mingw64\bin\gcc.exe`）。
- 推荐在 VS Code 中使用提供的构建任务来编译单个源文件。

## 构建与运行

使用命令行编译单个文件（示例：编译 `git_demo/1.c`）：

```bash
gcc -g git_demo/1.c -o git_demo/1.exe
./git_demo/1.exe
```

在 VS Code 中，你可以运行工作区提供的任务 “C/C++: gcc.exe 生成活动文件”。该任务会用 `gcc` 编译当前打开的文件并将可执行文件输出到相同目录。

示例：在 VS Code 中打开 `git_demo/2.c`，运行构建任务，将生成 `git_demo/2.exe`。

## 说明与建议

- 如果要一次性构建多个文件或建立更复杂的项目，建议添加 `Makefile` 或使用 CMake。
- 可选：为每个示例文件在 README 中添加简短描述，说明该示例演示的知识点。

## 下一步

- 需要我为每个 `git_demo` 下的 C 文件添加注释说明并确保它们都能编译运行吗？

