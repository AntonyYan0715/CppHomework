# 随机行走

GitHub上有老师的[源代码](https://github.com/ghzuo/CppTeach/tree/master/src/demo/04/walk.c)，代码有几处bug：
* 不能修改输出的文件名output.dat
* 每次随机的结果都一样
* 每次都往同个方向跑

还需要对代码做一些改进：
* 单位时间移动概率为80%
* 若移动，50%概率走半步，50%概率走一步
* 每次行走方向随机

我的[代码实现](./random_walk.c)，编译：
```
gcc random_walk.c -o random_walk -lm
```
从命令行读取参数的函数只是将老师的源代码稍作修改，修改后可以改变输出的文件名：
```
./random_walk -n 100000 -o output1.dat
```
随机三次的结果：[结果1](./output1.dat), [结果2](./output2.dat), [结果3](./output3.dat)

可以看到，每次**结果不同**且行走**方向随机**
