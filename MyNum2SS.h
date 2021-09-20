#ifndef MYNUM2SS_H_INCLUDED
#define MYNUM2SS_H_INCLUDED

#define MAX_LENGTH 1000
//用于将浮点小数变成二进制串或者将二进制串变为浮点小数的程序
//不同于matlab，此处的二进制串是以0-1布尔串存储，请注意
//最大存储位数设定成1000，但是不管是存储还是释放都与精度有关
//不推荐精度低于1e-6,可能会因为double型储存产生奇怪的问题
int Num2SS(double num,double Accuracy,bool *res){
    //num是小于1而大于零的浮点小数，可以用线性标准化得到
    //这里的精度是最小单位
    //比如对一个数要二进制化到1e-6为止，那么这个精度就直接填1e-6
    //res数组的位置要留够，不然可能会报错
    //返回值是二进制串的长度，布尔数组没办法设置终止符
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
    //num是一个布尔型二进制串
    //以二进制串前作为浮点，转化成一个纯小数
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
