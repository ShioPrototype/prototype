#ifndef MATRIXVECTOR_H_INCLUDED
#define MATRIXVECTOR_H_INCLUDED
#include <cstring>
#include <iostream>
/*
自己搓了一个向量的轮子
没找到现成的很好用的矩阵，于是就用这个东西了
如果后面学到或者找到现成的好轮子就替换一下
*/
struct Vvector
{
    double val[100];
    int siz;
    void init(){//向量初始化
        for(int i=0;i<100;i++)
            val[i]=0.0;
        siz=0;
    }
    void print(){//输出向量
        for(int i=0;i<siz;i++)
            std::cout<<val[i]<<' ';
        std::cout<<"\n";
    }
    Vvector operator =(const Vvector &VV)//重载一个等号以简化步骤
    {
        this->siz=VV.siz;
        memcpy(this->val,VV.val,this->siz*sizeof(int));
        return *this;
    }
};
int sqdist(Vvector V1,Vvector V2){//向量间距离计算
        if(V1.siz!=V2.siz)return -1;//向量维度不一致不能计算距离
        int buf=0;
        for(int i=0;i<V1.siz;i++)
            buf+=(V1.val[i]-V2.val[i])*(V1.val[i]-V2.val[i]);
        return buf;
}
#endif // MATRIXVECTOR_H_INCLUDED
