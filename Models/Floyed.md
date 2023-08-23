### 题目描述

**有向图**中存在$n$个节点，每个节点之间有道路相连，共有$m$条道路，给出$Q$此询问，包含起点和终点,请输出两点间最短距离$L\min$.

### 输入描述
第一行$3$个整数$n,m,Q$.  
第$2$到$(m+1)$行，输入每条路的起点$u_i$，终点$v_i$，权值$w_i$.  
第$(m+2)$到$(m+Q+2)$行，输入起点$U_i$，终点$V_i$. 

### 输出描述
$m$行，每行一个整数，表示$U_i$到$V_i$的最短路径$L_i\min$,如果到不了，输出`No way.`.