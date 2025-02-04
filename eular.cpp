#include<bits/stdc++.h>
using namespace std;

class EularMethod{
    private:
    double fc(double x , double y){
        return x*x + y;
    }
    public:
    void eular(double x0 , double y0, double h, double x){
        double y=y0;
        while(x0 < x){
            y = y + h * fc(x0 , y);
            x0 = x0 + h;
        }
        cout<<"the value of y is : "<<y<<endl;
    }
};
int main(){
    EularMethod eularMethod;
    double x0,y0,h,x;
    cout<<"enter the value of  x0,y0,x and h"<<endl;
    cin>>x0>>y0>>h>>x;
    eularMethod.eular(x0,y0,h,x);


}