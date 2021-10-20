# Monte Carlo行走
通过Monte Carlo行走，模拟自由粒子在势场中的扩散
* 粒子每次只走一步
* 每次移动距离为固定值s
* 每次行走方向随机
* 行走概率P与行走带来的能量差ΔE有关：
    * P = exp(-ΔE / kT), ΔE>0
    * P = 1, ΔE<=0

我的[代码实现](./MC_walk.cpp)，编译：
```
g++ ./MC_walk.cpp -o MC_walk -lm
```
可以从命令行读取参数，修改模拟总次数、步长s、系统温度kT：
```
./MC_walk -h

Program Usage:
./MC_walk
     [ -n  10000 ]  number of steps per run, default 10000
     [ -s  0.1 ]    size of each step, default 0.1
     [ -T  1.0 ]    temperature kT of the system, default 1.0
     [ -h ]         display this information

```
程序会把每次模拟的数据写进[output.dat](./output.dat)，然后输出粒子处于基态的概率：
```
./MC_walk -n 100000 -s 0.1 -T 1.0

The temperature of the system: kT = 1
Probability of ground state: 0.1377
```