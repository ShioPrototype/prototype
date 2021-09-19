#ifndef MYGA_H_INCLUDED
#define MYGA_H_INCLUDED
#include "MatrixVector.h"
#include <ctime>
#include <cstdlib>

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

void Tierra(Vvector *VV,int num,double (*func)(Vvector)){
    //VV����Ҫɱ�����Ⱥ
    //num�����µĸ�������ʹ��num����Ⱥ��һ��
    //func������ȺΪ�Ա���������ֵ����������ֵԽ��˵����Ӧ��Խ��
    for(int i=0;i<num;i++){
        Vvector V1=VV[i];
        Vvector V2=VV[2*num-i-1];
        if(func(V1)>func(V2))
            VV[i]=VV[2*num-i-1]=V1;
        else VV[i]=VV[2*num-i-1]=V2;
    }
}
#endif // MYGA_H_INCLUDED
