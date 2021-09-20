#ifndef MYNUM2SS_H_INCLUDED
#define MYNUM2SS_H_INCLUDED

#define MAX_LENGTH 1000
//���ڽ�����С����ɶ����ƴ����߽������ƴ���Ϊ����С���ĳ���
//��ͬ��matlab���˴��Ķ����ƴ�����0-1�������洢����ע��
//���洢λ���趨��1000�����ǲ����Ǵ洢�����ͷŶ��뾫���й�
//���Ƽ����ȵ���1e-6,���ܻ���Ϊdouble�ʹ��������ֵ�����
int Num2SS(double num,double Accuracy,bool *res){
    //num��С��1��������ĸ���С�������������Ա�׼���õ�
    //����ľ�������С��λ
    //�����һ����Ҫ�����ƻ���1e-6Ϊֹ����ô������Ⱦ�ֱ����1e-6
    //res�����λ��Ҫ��������Ȼ���ܻᱨ��
    //����ֵ�Ƕ����ƴ��ĳ��ȣ���������û�취������ֹ��
    int pos=0;
    while(Accuracy<1){
        num=num*2;
        Accuracy=Accuracy*2;
        if(num>1.0){res[pos++]=true;num=num-1.0;}
        else res[pos++]=false;
    }
    return pos;
}

double SS2Num(bool *num,int length){
    //num��һ�������Ͷ����ƴ�
    //�Զ����ƴ�ǰ��Ϊ���㣬ת����һ����С��
    double res=0.0;
    double buf=1.0;
    int pos=0;
    while(pos<length){
        buf=buf/2;
        res+=num[pos]*buf;
        pos++;
    }
    return res;
}

#endif // MYNUM2SS_H_INCLUDED
