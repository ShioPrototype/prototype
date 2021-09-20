#ifndef MYGA_H_INCLUDED
#define MYGA_H_INCLUDED
#include "MatrixVector.h"
#include "MyNum2SS.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>

#define SHUFFLE_TIMES 100000
#define DEFAULT_ACCURACY 1e-6
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

void Tierra(Vvector *VV,int num,double(*func)(Vvector)){
    //杀灭一半，并用剩下更好一半的复制填充
    for(int i=0;i<num/2;i++){
        Vvector V1=VV[i];
        Vvector V2=VV[num-i-1];
        if(func(V1)<func(V2))
            VV[i]=VV[num-1-i]=V1;
        else VV[i]=VV[num-1-i]=V2;
    }
}

void ShuffleVvector(Vvector *VV,int num){
    srand(time(NULL));
    for(int i=0;i<SHUFFLE_TIMES;i++){
        int pos1=rand()%num;
        int pos2=rand()%num;
        if(pos1!=pos2) {
            Vvector buf=VV[pos1];
            VV[pos1]=VV[pos2];
            VV[pos2]=buf;
        }
    }
}

void Variation(Vvector VV,double prob,double limits[][2]){
    for(int i=0;i<VV.siz;i++){
        VV.val[i]=(VV.val[i]-limits[i][1])/(limits[i][0]-limits[i][1]);
        bool buf[100];
        int len=Num2SS(VV.val[i],DEFAULT_ACCURACY,buf);
        for(int j=0;j<len;j++)
            if((double)rand()/RAND_MAX<prob)buf[j]=~buf[j];
        VV.val[i]=SS2Num(buf,len)*(limits[i][0]-limits[i][1])+limits[i][1];
    }
}
#endif // MYGA_H_INCLUDED
