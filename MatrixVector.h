#ifndef MATRIXVECTOR_H_INCLUDED
#define MATRIXVECTOR_H_INCLUDED
#include <cstring>
#include <iostream>
/*
�Լ�����һ������������
û�ҵ��ֳɵĺܺ��õľ������Ǿ������������
�������ѧ�������ҵ��ֳɵĺ����Ӿ��滻һ��
*/
struct Vvector
{
    double val[100];
    int siz;
    void init(){//������ʼ��
        for(int i=0;i<100;i++)
            val[i]=0.0;
        siz=0;
    }
    void print(){//�������
        for(int i=0;i<siz;i++)
            std::cout<<val[i]<<' ';
        std::cout<<"\n";
    }
    Vvector operator =(const Vvector &VV)//����һ���Ⱥ��Լ򻯲���
    {
        this->siz=VV.siz;
        memcpy(this->val,VV.val,this->siz*sizeof(int));
        return *this;
    }
};
int sqdist(Vvector V1,Vvector V2){//������������
        if(V1.siz!=V2.siz)return -1;//����ά�Ȳ�һ�²��ܼ������
        int buf=0;
        for(int i=0;i<V1.siz;i++)
            buf+=(V1.val[i]-V2.val[i])*(V1.val[i]-V2.val[i]);
        return buf;
}
#endif // MATRIXVECTOR_H_INCLUDED
