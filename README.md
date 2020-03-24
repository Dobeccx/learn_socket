## 这是一个TCP/IP网络编程的学习记录

> 参照尹圣雨《TCP/IP网络编程》及easyserverdev公众号文章整理学习

### 一. 目录

1. 常用socket函数
2. tcp通讯基本流程
3. bind函数用法
4. select函数用法
5. socket阻塞模式和非阻塞模式
6. ........

TODO

### Q&A:

​	1.string.h 和string有什么不同？

> <string.h>是旧的C 头文件，对应的是基于char*的字符串处理函数；<string>是包装了std 的C++头文件，对应的是新的string 类（看下文）；
> <cstring>是对应于旧C 头文件的std 版本。（包含std）
>
> <string>是c++ 的头文件，其内包含了一个`string`类，`string s1`就是建立一个`string`类的对象 
> <string.h> 的c语言的东西 并无类，所以不能 `string s1 `
>
> <cstring>文件实际上只是在一个命名空间std中`include`了 <string.h>

​	2.memset清空字符数组时为什么sizeof函数不起作用，会导致数组滞留上次收到的消	息？

> send函数的size 用sizeof函数计算大小别用strlen.具体原理继续深究函数。
>
> 个人觉得是memset函数被编译器优化导致其实内部数据并未被置零，导致strlen依旧返回到'\0'为止的字符串长度并被读取

