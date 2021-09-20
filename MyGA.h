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
��C++������һ���Ŵ��㷨������
*/
bool NewGroupGeneration(Vvector *VV,int num,int siz,double limits[][2]){//��������Ⱥ
    //VV=Ҫ���ɵ���Ⱥ����������
    //siz=����ά��
    //num=Ҫ���ɵ���Ⱥ��С
    //limits=��Ⱥ���Ͻ���½�
    //����ֵ���Ƿ�ɹ���������Ⱥ
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
    //ɱ��һ�룬����ʣ�¸���һ��ĸ������
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
