# 最小生成树算法
## Kruscal
> 算法基本思想：将图中边按照权值从小到大排列，然后从最小的边开始扫描，
设置一个边的集合来记录，如果该边并入不构成回路的话，则将该边并入当前生成树，
知道所有的边都检测完成为止。
>> 需要一个辅助数组，记录父结点对应的顶点