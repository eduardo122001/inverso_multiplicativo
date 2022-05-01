#include <iostream>
using namespace std;

int euclides(int num1,int num2){
    if(num2==0){
        return num1;
    }else{
        return euclides(num2,num1%num2);
    }
}

int ext_euclides(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }else{
        int x1,y1;
        int d=ext_euclides(b,a%b,x1,y1);
        x=y1;
        y = x1-y1*(a/b);
        return d;
    }
}

int inverso(int a,int n){
    if(euclides(a,n)==1){
       int x,y;
       int d=ext_euclides(a,n,x,y);
       return (x%n+n)%n;
    }else{
        cout<<"no existe inverso"<<endl;
        return 0;
    }
}

int main()
{
        int a,n,ai;
        cout<<"ingrese el numero del cual desea el inverso:";cin>>a;
        cout<<"ingrese el numero del modulo:";cin>>n;
        ai=inverso(a,n);
        if(ai!=0){cout<<"el inverso de "<<a<<" en la congruencia mod "<<n<<" es: "<<ai<<endl;}

    return 0;
}
