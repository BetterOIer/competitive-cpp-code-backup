#include<iostream>
#define 使用 using
#define 命名空间 namespace
#define 标准库 std
#define 分号 ;
#define 逗号 ,
#define 钦定 const
#define 加 +
#define 减 -
#define 乘 *
#define 除以 /
#define 取模 %
#define 亦或 ^
#define 等于 = 
#define 判断等于 == 
#define 小于等于 <=
#define 大于等于 >=
#define 小于 <
#define 大于 >
#define 不是 !
#define 加上一 ++
#define 长整型 long long
#define 长整型标识 1LL
#define 整型 int
#define 字符型 char
#define 循环 for
#define 左小括号 (
#define 右小括号 )
#define 左中括号 [
#define 右中括号 ]
#define 左大括号 {
#define 右大括号 } 
#define 返回 return
#define 输出 <<
#define 左移 <<
#define 输出流 cout
#define 如果 if
使用 命名空间 标准库 分号
钦定 长整型 模数 等于 1e9 加 7 分号
长整型 快读 左小括号 右小括号 左大括号
长整型 x 等于 0 逗号 f 等于 1 分号
字符型 c 等于 getchar 左小括号 右小括号 分号 循环 左小括号 分号 不是 isdigit 左小括号 c 右小括号
分号 c 等于 getchar 左小括号 右小括号 右小括号 如果 左小括号 c 判断等于 '-' 右小括号 f 等于  减 1 分号
循环 左小括号 分号 isdigit 左小括号 c 右小括号 分号 c 等于 getchar 左小括号 右小括号 右小括号 x 等于 左小括号 x 左移 3 右小括号  加  左小括号 x 左移 1 右小括号  加  左小括号 c 亦或 48 右小括号 分号
返回 x 乘 f 分号
右大括号
长整型 n 逗号 m 逗号 答案1 等于 1 逗号 答案2 等于 1 逗号 答案 分号 
整型 main 左小括号 右小括号 左大括号
    n 等于 快读 左小括号 右小括号 逗号 m 等于 快读 左小括号 右小括号 分号 
    循环 左小括号 长整型 i 等于 1 分号 i 小于等于 m 分号 i 加上一 右小括号 答案1 等于 左小括号 答案1 乘 2 乘 长整型标识 右小括号 取模 模数 分号 
    循环 左小括号 长整型 i 等于 1 分号 i 小于 m 分号 i 加上一 右小括号 答案2 等于 左小括号 答案2 乘 左小括号 n 加 长整型标识 右小括号 右小括号 取模 模数 分号 
    答案 等于 长整型标识 乘 左小括号 n 加 长整型标识 减 m 右小括号 乘 答案1 取模 模数 乘 答案2 取模 模数 分号 
    输出流 输出 答案 分号 
    返回 0 分号 
右大括号