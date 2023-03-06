# compile requires:
> linux  
>   GL X11 pthread  
> windows  
>   d2d1 gl  

> cmake version:  
    3.24 and above  
> cpp version:  
    20 and above  
> glfw version:  
    3.3.8 and above  
> glad version:  
    opengl 4.6 generated with no extensions  

moob 的基础框架是:  
    a. 一个2d页面  
    b. 一定数量的管道  
    c. 同时处理n个像素逻辑的演化器  
其中: 
    a. 需要一个线程支持，该线程不断从管道中取像素的坐标和颜色数据，并打在2d页面上  
    b. 需要一个中间模块支持，管道的设计有待考究  
    c. 演化器由gpu 或 cpu 计算，在gpu中计算会更合理一些，毕竟像素的演化应该是并行处理的  
由于一定会有背景的需求，因此该基础组合结构必须是可以多次构建的  

启动:
./moob -m[mode]
-m 指定启动模式:
    // 0.(client combo) + (server combo) + (pixel logic commbo)
    // 1.(client combo)
    // 2.(root server combo)
    // 3.(pixel logic commbo)
    // 4.(root server combo) + (pixel logic commbo)
    