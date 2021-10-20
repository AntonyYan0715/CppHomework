# 并行计算
对 homework4 中的Monte Carlo行走程序进行改造，改造后的程序应满足：
* 有多个运动目标
* 可接收命令行参数，决定运动目标的数目
* 不同目标之间并行化计算

我的[代码实现](./parallel_walk.cpp)，编译：
```
g++ parallel_walk.cpp -o walk -fopenmp
```
代码主要修改了以下内容：
* 接收命令行参数的函数 getArgs() 多加了一个case 'N'，N即为运动目标的数目：
```
./walk -h

Program Usage:
./walk
     [ -N  1 ]      number of particles run in total, default 1
     [ -n  10000 ]  number of steps per run, default 10000
     [ -s  0.1 ]    size of each step, default 0.1
     [ -T  1.0 ]    temperature kT of the system, default 1.0
     [ -h ]         display this information

./walk -N 24
```
* 将函数中读写文件的部分去掉，因为硬盘不并行(?)，不能多个线程同时读写文件。
* 在原来的主要程序外再嵌套一层for循环，循环次数即为N，代表着N个互相独立的运动目标，并将这层for循环改为并行：
```
#pragma omp parallel for
for (int n=0; n<N; ++n) {}
```
* 在每个for循环(线程)内部增加两行，通过omp_get_thread_num()函数获取当前线程ID。
* 在main()函数首尾处，通过omp_get_wtime()函数计算程序运行用时。

## 讨论
对比并行和串行下的程序运行用时:[并行](./walk) / [串行](./test)<br>
在个人电脑上(Windows)，并行比串行运行速度快三倍；<br>
但是同样的代码在服务器上，并行运行速度只有串行的1/3。