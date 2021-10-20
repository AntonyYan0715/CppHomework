# Brown Dynamics 布朗运动
单原子的布朗运动<br>
* 矢量类Vec有关代码写在头文件[vec.h](./vec.h)中
* Atom类以及关于原子的运动Motion类写在头文件[atom.h](./atom.h)中
* 从命令行接收参数的函数写在头文件[use.h](./use.h)中
* 测试代码写在[main.cpp](./main.cpp)中

编译并运行
```
g++ main.cpp -o brown
./brown
```
生成一个[输出文件](./output.dat)，里面存放的是原子运动的位置数据和速度数据