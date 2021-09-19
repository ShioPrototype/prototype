#ifndef MYGA_H_INCLUDED
#define MYGA_H_INCLUDED
#include "MatrixVector.h"
#include <ctime>
#include <cstdlib>

/*
用C++重新造一编遗传算法的轮子
*/
bool NewGroupGeneration(Vvector *VV,int num,int siz,double limits[][2]){//产生新种群
    //VV=要生成的种群的向量数组
    //siz=向量维数
    //num=要生成的种群大小
    //limits=种群的上界和下界
    //返回值是是否成功生成了种群
    for(int i=0;i<siz;i++)
        if(limits[i][0]<limits[i][1])return false;
    srand(time(NULL));
    for(int i=0;i<num;i++){
        VV[i].init();
        VV[i].siz=siz;
        for(int j=0;j<siz;j++)
            VV[i].val[j]=((double)rand()/RAND_MAX)*(limits[j][0]-limits[j][1])+limits[j][1];
    }
    return true;
}

void Tierra(Vvector *VV,int num,double (*func)(Vvector)){
    //VV是需要杀灭的种群
    //num是留下的个体数，使得num是种群的一半
    //func是以种群为自变量的评价值函数，评价值越大说明适应性越好
    for(int i=0;i<num;i++){
        Vvector V1=VV[i];
        Vvector V2=VV[2*num-i-1];
        if(func(V1)>func(V2))
            VV[i]=VV[2*num-i-1]=V1;
        else VV[i]=VV[2*num-i-1]=V2;
    }
}
#endif // MYGA_H_INCLUDED
