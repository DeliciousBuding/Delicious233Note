> 本文由 [简悦 SimpRead](http://ksria.com/simpread/) 转码， 原文地址 [blog.csdn.net](https://blog.csdn.net/qq_44431690/article/details/108175827)

#### 文章目录

- [【 1. Dijkstra 算法简介 】](#1-dijkstra-算法简介)
- [【 2. 算法实现范例 】](#2-算法实现范例)
- [【 3. 邻接矩阵 】](#3-邻接矩阵)
- [【 4. Dijkstra 算法的 C++ 描述 】](#4-dijkstra-算法的-c-描述)
- [【 5. Dijkstra 算法的 Matlab 描述 】](#5-dijkstra-算法的-matlab-描述)
- [【 6. 温故知新！ 】](#6-温故知新)

---

### 【 1. Dijkstra 算法简介 】

- **背景**  
  迪杰斯特拉算法 (Dijkstra) 是由荷兰计算机科学家狄杰斯特拉于 1959 年提出的，因此又叫狄克斯特拉算法。
- **用途**  
  该算法可以算出从一个顶点到其余各顶点的最短路径，解决的是有权图中最短路径问题。
- **复杂度**  
  该算法复杂度 = $n^2$
- **核心思想**  
  迪杰斯特拉算法主要特点是从起始点开始，采用贪心算法的策略，_每次遍历到始点距离最近且未访问过的顶点的邻接节点，直到扩展到终点为止_。
- **Dijkstra 算法理解**  
  Dijkstra 算法是一种标号法：给赋权图的每一个顶点记一个数，称为顶点的标号：_**临时标号 T**_ 表示从始顶点到该标点的最短路长的上界、_**固定标号 P**_ 表示从始顶点到该顶点的最短路长。

  ![[071227ec3cde473dc01c99e824dc1569_MD5.jpg]]

---

### 【 2. 算法实现范例 】

> **求始点 $V_1$ 到其余顶点的最短路径**  
> ![[01351d8f5391e2d6238efe9014457e46_MD5.jpg]]

- **令不可直接到达 $V_1$ 的点（需经过第三个点）到 $V_1$ 的距离为 ∞。  
  此时，距 $V_1$ 最近的点： $V_1$，最短路径： $V_1 → V_1$，最短距离：0。**  
  ![[4537a7526a2cf8503c0a66c60d93a89d_MD5.jpg]]  
  ![[e7fbfb55d6140bcc50f546aefbd76f70_MD5.jpg]]

- **除自身外，距离 $V_1$ 最近的点： $V_4$。可知，最短路径： $V_1 → V_4$，最短距离：1。**  
  ![[b416030680342812bc56ef1fb86d8bb5_MD5.jpg]]  
  ![[a47eb68f0443abddad61337ce806ddba_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_4$ 的最短路径，则：  
  $V_1 → V_4 → V_3$ 距离为 8 = $V_1 → V_3$ 的距离 8，不更新表格；  
  $V_1 → V_4 → V_7$ 距离为 10 < ∞，更新表格。**

  ![[87fb0775404886125d9f58deed556937_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_2$。可知，最短路径： $V_1 → V_2$，最短距离：2。  
  ![[7f1ea2e0d3fa047914bcd2a8743f3ef2_MD5.jpg]]

  ![[d35654f2d00376a99eec74985e9a34db_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_2$ 的最短路径，则：  
  $V_1 → V_2 → V_3$ 距离为 8 = 8，不更新表格。  
  $V_1 → V_2 → V_5$ 距离为 3 < ∞，更新表格。**  
  ![[cd5d1d329a5781a2c096f6de46819356_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_5$。可知，最短路径： $V_1 → V_2 → V_5$，最短距离：3。  
  ![[e3bcf4109332fb2e217cd41f2fcc977c_MD5.jpg]]

  ![[b534a01d9d80c5d1fca9f4841d18209d_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_5$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_3$ 距离为 8 = 8，不更新表格。  
  $V_1 → V_2 → V_5 → V_6$ 距离为 6 < ∞，更新表格。  
  $V_1 → V_2 → V_5 → V_9$ 距离为 12 < ∞，更新表格。  
  $V_1 → V_2 → V_5 → V_8$ 距离为 5 < ∞，更新表格。**  
  ![[9f2bf55ba9f6e563d3b6242304519053_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_8$。可知，最短路径： $V_1 → V_2 → V_5 → V_8$，最短距离：5。  
  ![[495e62c1d24b7af884df84f30927bad2_MD5.jpg]]  
  ![[9c76e52acb68f9879250f9f978dd4455_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_8$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_8 → V_9$ 距离为 12 = 12，不更新表格。  
  $V_1 → V_2 → V_5 → V_8 → V_{11}$ 距离为 14 < ∞，更新表格。**  
  ![[a7a0074f7615740154291336ff9c3167_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_6$。可知，最短路径： $V_1 → V_2 → V_5 → V_6$，最短距离：6。  
  ![[cc06e87ec84a5049c33cf4a509351ae0_MD5.jpg]]

  ![[a2380c291839cedb81c0c4fcef57e7a5_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_6$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_6 → V_7$ 距离为 10 = 10，不更新表格。  
  $V_1 → V_2 → V_5 → V_6 → V_9$ 距离为 12 = 12，不更新表格。  
  $V_1 → V_2 → V_5 → V_6 → V_3$ 距离为 7 < 8，更新表格。**  
  ![[a67ab022456c066aabb350f215c91506_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_3$。可知，最短路径： $V_1 → V_2 → V_5 → V_6 → V_3$，最短距离：7。  
  ![[541d3f100a97613f098006e7c798f282_MD5.jpg]]  
  ![[dade22ded0b81e0f3e6969956c70a532_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_3$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7$ 距离为 9 < 10，更新表格。**  
  ![[d4e01a16e1f9321ede7f7432952c1d75_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_7$。可知，最短路径： $V_1 → V_2 → V_5 → V_6 → V_3 → V_7$，最短距离：9。  
  ![[9a21e26c5ad7dc95e28aabd357e73197_MD5.jpg]]  
  ![[92c69cf611c7b21df5bd29401ced935a_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_7$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_9$ 距离为 12 = 12，不更新表格。  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10}$ 距离为 10 < ∞，更新表格。**  
  ![[1ede372e89ab93e62a9bcaac8034613b_MD5.jpg]]  
  更新表格后，距离 $V_1$ 最近的点： $V_{10}$。可知，最短路径： $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10}$，最短距离：10。  
  ![[b4c79bb02073b62e6b3a3b12d8e78941_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_{10}$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10} → V_{11}$ 距离为 14 < 11，不更新表格。  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10} → V_9$ 距离为 11 < 12，更新表格。**  
  ![[3b6949971a66f216d1ec6bf3428915d9_MD5.jpg]]  
  此时，距离 $V_1$ 最近的点： $V_9$。可知，最短路径： $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10} → V_9$，最短距离：11。  
  ![[3dda17d4b5ba8d2acf4d1f5ff4ec5276_MD5.jpg]]

- **由上步已获知 $V_1$ 到 $V_9$ 的最短路径，则：  
  $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10} → V_9 → V_{11}$ 距离为 13 < 14，更新表格。**  
  ![[be952357675b8d9eccc3f53f3518f120_MD5.jpg]]  
  此时，距离 $V_1$ 最近的点： $V_{11}$。可知，最短路径： $V_1 → V_2 → V_5 → V_6 → V_3 → V_7 → V_{10} → V_9 → V_{11}$，最短距离：13。  
  ![[92c1c2a2ae8aa9fee3e6000f247843c1_MD5.jpg]]  
  ![[d1ca3edf15a7f1c73b4a9d3a3d1e4c3f_MD5.jpg]]

---

### 【 3. 邻接矩阵 】

邻接矩阵用于描述图上顶点间的关系。例如临接矩阵 $D[i][j]$ 表示顶点 $i$ 到顶点 $j$ 的直达距离，可将其赋值为无穷大 $\text{Inf}$ 来表示顶点 $i$ 无法直达到顶点 $j$。

> ![[74eb487e5bad4a99a05e1c9df4efefcc_MD5.jpg]]  
> ![[c5b1865b995c9fc66afa12e2cc51d853_MD5.jpg]]

---

### 【 4. Dijkstra 算法的 C++ 描述 】

```cpp
/*
函数名：dijkstra()  迪科斯彻最短路径算法 
参数：vs：源点的索引;f：终点的索引;
      pre[]：前驱数组,即pre[i]为从vs到i最短路径时,i前面那个顶点的索引 
	  dist[]：距离数组，即dist[i]是vs到i的最短路径的长度 
全局变量q：点的数量 
功能：算出从源点下标vs到其余点最短路径,轨迹记录在pre[],距离记录在dist[]。 
*/
void dijkstra(  int vs, int prev[], int dist[],int f )
{   
    
    int i,j,k;
    int min;
    int tmp;
    int flag[q];  // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
/* 1.  初始化*/
    for (i = 0; i < q; i++)
    {
        flag[i] = 0;  // 顶点i的最短路径还没获取到。
        prev[i] = vs;  // 顶点i的前驱顶点为0。
        dist[i] = martix[vs][i];// 顶点i的最短路径为vs到i的权。
    }
 					 
    flag[vs] = 1; // 对顶点vs自身进行初始化
    dist[vs] = 0; 
 
/* 2.  遍历q-1次，每次找出vs到另一个顶点的最短路径 */
    for (i = 1; i < q ; i++)
    {
        
        /* 2.1 在未获取最短路径的顶点中，找到离vs最近的顶点k */
        min = INF;
        for ( j = 0; j < q ; j++)
        {
            if (flag[j]==0 && dist[j]<min)
			//若从vs到顶点j距离小于min,而且从vs到j的最短路径还未获取。 
            {
                min = dist[j];//改变最近距离 
                k = j;//记录j 
            }
        }
        
       /* 2.2  对刚刚已找到最短距离的顶点k进行标记判断     */
        flag[k] = 1; // 标记顶点k,dist[k]已确定。 
        if(k==f)   //判断k是否是终点索引,若是则退出 
			break;
	
        /*  2.3   已知顶点k的最短路径后,更新未获取最短路径的顶点的最短路径和前驱顶点   */
        for (j = 0; j < q ; j++)
        {
            tmp = (martix[k][j]==INF ? INF : (min + martix[k][j])); // 防止溢出
            if (flag[j] == 0 && (tmp  < dist[j]) ) //若j还不是最短距离且从k到j距离比记录的距离短 
            {
                //更新k的前驱和最短距离 
			    prev[j] = k; 
                dist[j] = tmp;
            }
        }
        
    }
 
}
```

---

### 【 5. Dijkstra 算法的 Matlab 描述 】

两个文件在同一[文件夹](https://so.csdn.net/so/search?q=%E6%96%87%E4%BB%B6%E5%A4%B9&spm=1001.2101.3001.7020)下，运行 tulun1.m 即可。

```matlab
% 文件命名为：tulun1.m
weight=    [0     2     8     1   Inf   Inf   Inf   Inf   Inf   Inf   Inf;
            2     0     6   Inf     1   Inf   Inf   Inf   Inf   Inf   Inf;
            8     6     0     7     5     1     2   Inf   Inf   Inf   Inf;
            1   Inf     7     0   Inf   Inf     9   Inf   Inf   Inf   Inf;
          Inf     1     5   Inf     0     3   Inf     2     9   Inf   Inf;
          Inf   Inf     1   Inf     3     0     4   Inf     6   Inf   Inf;
          Inf   Inf     2     9   Inf     4     0   Inf     3     1   Inf;
          Inf   Inf   Inf   Inf     2   Inf   Inf     0     7   Inf     9;
          Inf   Inf   Inf   Inf     9     6     3     7     0     1     2;
          Inf   Inf   Inf   Inf   Inf   Inf     1   Inf     1     0     4;
          Inf   Inf   Inf   Inf   Inf   Inf   Inf     9     2     4     0;];
[dis, path]=dijkstra(weight,1, 11)
```

```matlab
function [min,path]=dijkstra(w,start,terminal)
n=size(w,1); label(start)=0; f(start)=start;
for i=1:n
    if i~=start
        label(i)=inf;
    end
end
s(1)=start; u=start;
while length(s)<n
    for i=1:n
        ins=0;
        for j=1:length(s)
            if i==s(j)
                ins=1;
            end
        end
        if ins==0
            v=i;
            if label(v)>(label(u)+w(u,v))
                label(v)=(label(u)+w(u,v));
                f(v)=u;
            end
        end
    end
    v1=0;
    k=inf;
    for i=1:n
        ins=0;
        for j=1:length(s)
            if i==s(j)
                ins=1;
            end
        end
        if ins==0
            v=i;
            if k>label(v)
                k=label(v);  v1=v;
            end
        end
    end
    s(length(s)+1)=v1;
    u=v1;
end
min=label(terminal); path(1)=terminal;
i=1;
while path(i)~=start
    path(i+1)=f(path(i));
    i=i+1 ;
end
path(i)=start;
L=length(path);
path=path(L:-1:1);
```

![[ed1b55c2bf4ce5fa95bb4595d500794e_MD5.jpg]]

---

### 【 6. 温故知新！ 】

1. **第一步，定义个邻接矩阵 $\text{Martix}[][]$**  
   $\text{Martix}[i][j]$ 代表点 $i$ 到 点 $j$ 的初始距离，若点 $i$ 能直达到点 $j$ （不经过第三个点），则 $\text{Martix}[i][j]$ = 对应距离，否则 = 无穷大。
2. **第二步，定义 3 个数组存信息**  
   距离数组 $\text{dist}[]$，$\text{dist}[i]$ 代表源点 $\text{vs}$ 到点 $i$ 的最短路径的长度；  
   再定义个前驱数组 $\text{pre}[]$，$\text{pre}[i]$ 代表源点 $\text{vs}$ 到点 $i$ 的最短路径的前驱点（即上一个点）。  
   最后再定义个标记数组 $\text{flag}[]$，$\text{flag}[i]=1$ 代表源点 $\text{vs}$ 到点 $i$ 的最短距离已经确定。
3. **好了，前戏准备完毕，进入正题，让我们开始初始化第二步定义的三个数组。**  
   显而易见，$\text{dist}[\text{vs}]=0$，自己到自己距离为 0，那么其他的点嘛比如点 $i$ ，就让点 $\text{vs}$ 到点 $i$ 的距离等于 $\text{Martix}[\text{vs}][i]$，即第一步的初始距离。  
   那么前驱数组 $\text{pre}[]$ ，就让他们的前驱点都是点 $\text{vs}$ 好了；  
   最后这个标记位数组 $\text{flag}[]$ ，$\text{flag}[\text{vs}]=1$（自己到自己距离为 0 肯定最小了），其他的都不确定，就 $\text{flag}[$除点 $\text{vs}$ 外的点$]=0$。
4. **初始化完毕。准备开炮。**  
   我们决定每遍历一次就确定 $\text{vs}$ 到一个点的最短路径，那么需要遍历 $n-1$ 次（算上点 $\text{vs}$ 共有 $n$ 个点嘛）。  
   也就是每次遍历我们都需要找到距离点 $\text{vs}$ 最近的点（怎么找？同样遍历个 $n-1$ 次来比较没确定最短路径的点的 $\text{dist}[]$ 哪个最小 ），此时肯定是最短路径啊（你经过别的点再绕向它距离肯定大了），那么这个点的 $\text{flag}[i] =1$，$\text{dist}[i]$ 确定不变了，$\text{pre}[i]$ 也不变了。
5. **OK，我们已经确定了一个最短路径。那么开始刷新吧。**  
   刷新的是什么呢？确定一个最短路径后，可能这个点 $i$ 到其他点的距离 < 原来点 $\text{vs}$ 到点 $i$ 的距离，所以我们要刷新，$\text{dist}[]$ 和 $\text{pre}[]$。
6. **好的，第 5 步刷新完了，就继续回到第四步不断遍历，直到所有的点都遍历完**，那么最终的 $\text{flag}[]$ 都等于 1 了，$\text{dist}[]$、$\text{pre}[]$ 也存着你想要的信息。
7. **最重要的，完结，撒花✿✿ヽ (°▽°) ノ✿。**