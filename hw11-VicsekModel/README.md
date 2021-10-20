# Vicsek Model
活性物质的Vicsek模型

我的[代码实现](./Vicsek.c)，以及我对Vicsek模型的[拓展](./new_Vicsek.c)<br>
编译：
```
gcc Vicsek.c -o Vicsek -lm
gcc new_Vicsek.c -o new_Vicsek -lm
```
得到[Vicsek](./Vicsek)和[new_Vicsek](./new_Vicsek)，运行程序，会在当前目录下生成一个data目录，里面存放了300个.csv文件。<br>
每一个.csv文件存储的是某一时刻下，所有粒子（共300个）的位置坐标和速度方向。<br>
data1 - data5是我已经生成好的数据，分别代表了不同状态下的Vicsek模型模拟的结果：<br>
[data1](./data1): 高密度，高噪声（𝐿 = 7, 𝜂 = 2.0）<br>
[data2](./data2): 低密度，低噪声（𝐿 = 25, 𝜂 = 0.1）<br>
[data3](./data3): 高密度，低噪声（𝐿 = 5, 𝜂 = 0.1）<br>
[data4](./data4): 拓展后的Vicsek模型，migration现象<br>
[data5](./data5): 拓展后的Vicsek模型，clustering现象<br>

我还写了一个Python程序，用以将数据可视化：[paint](./paint.py)<br>
只要修改其中的路径名dir_data_input，运行后就可以看到与data1 - data5对应的动态Vicsek模型。

