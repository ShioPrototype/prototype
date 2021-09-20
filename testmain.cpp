#include <iostream>
#include <algorithm>
#include "MyGA.h"
#include "MatrixVector.h"
#include "MyNum2SS.h"
using namespace std;
double Rosenbrock(Vvector VV){//测试函数
    double x1=VV.val[0];
    double x2=VV.val[1];
    return 100*(x2-x1*x1)*(x2-x1*x1)+(1-x1)*(1-x1);
}
bool cmp(Vvector V1,Vvector V2){
    return Rosenbrock(V1)<Rosenbrock(V2);
}

int main(){
    int LOOPTIME=100;//迭代次数
    const int MAX_SPC=1000;//种群规模
    Vvector Group[MAX_SPC+10];
    for(int i=0;i<MAX_SPC;i++)Group[i].init();
    double limits[2][2]={10,-10,10,-10};
    Vvector ans;
    ans.init();
    if(NewGroupGeneration(Group,MAX_SPC,2,limits))
        while(LOOPTIME--){
        //部分杀灭
        int res=MAX_SPC/2;//留存数
        sort(Group,&Group[MAX_SPC],cmp);
        for(int i=0;i<MAX_SPC;i++)
            Group[i]=Group[i%res];

        cout<<Rosenbrock(Group[0])<<'\n';
        Group[0].print();
        ShuffleVvector(Group,MAX_SPC);
        for(int i=0;i<MAX_SPC;i++)
            Variation(Group[i],0.05,limits);
    }
    return 0;
}
