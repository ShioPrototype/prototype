#include <iostream>
#include "MyGA.h"
#include "MatrixVector.h"
using namespace std;
double func(Vvector V1){
    Vvector VV;
    VV.siz=5;
    for(int i=0;i<5;i++)VV.val[i]=5;
    return sqdist(V1,VV);
}
int main(){
    cout<<RAND_MAX<<endl;
    Vvector Group[100];
    double limits[5][2]={10,0,10,0,10,0,10,0,10,0};
    if(NewGroupGeneration(Group,100,5,limits))
    for(int i=0;i<100;i++){
        for(int j=0;j<5;j++)
            cout<<Group[i].val[j]<<' ';
        cout<<endl;
    }
    Tierra(Group,50,func);
    return 0;
}
