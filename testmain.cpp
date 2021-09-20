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

int main(){
    int LOOPTIME=100000;//迭代次数
    const int MAX_SPC=10000;//种群规模
    Vvector Group[MAX_SPC+10];
    for(int i=0;i<MAX_SPC;i++)Group[i].init();
    double limits[2][2]={10,-10,10,-10};
    Vvector ans;
    ans.init();
    if(NewGroupGeneration(Group,MAX_SPC,2,limits))
        while(LOOPTIME--){
        cout<<100000-LOOPTIME<<endl;
        Tierra(Group,MAX_SPC,Rosenbrock);
        for(int i=0;i<MAX_SPC;i++)
            if(ans.siz==0||Rosenbrock(Group[i])<Rosenbrock(ans))
                ans=Group[i];
        //cout<<Rosenbrock(ans)<<'\n';
        //ans.print();
        ShuffleVvector(Group,MAX_SPC);
        for(int i=0;i<MAX_SPC;i++)
            Variation(Group[i],0.005,limits);
    }
    cout<<Rosenbrock(ans)<<'\n';
    ans.print();
    return 0;
}
