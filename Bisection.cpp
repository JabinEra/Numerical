#include<bits/stdc++.h>
using namespace std;
const int lb=-1000;
const int ub=1000;
const double toll=0.0001;
class Bisection{
    public:
     double func(double x){
        return x*x - 2*x -5;
    }
    void bisection(double a, double b){
        if (func(a) * func(b) >=0){
               cout<<"enter right assumption"<<endl;
               return;
        }
        double root=a;
        while(b-a>=toll){
            root=(b+a)/2;
            if(func(root)==0){
                break;
            }
            else if(func(root)* func(a)>0){
                a=root;
            }
            else{
                b=root;
            }
        }
    }
};
int main(){
    cout<<fixed<<setprecision(10);
    srand(time(0));
    Bisection bisec;
    double a,b;
    do{
        a = (rand() % (ub - lb + 1)) + lb;
    }while(bisec.func(a)>0);
    do{
        a=(rand() % (ub-lb)+1) +lb;
    }while(bisec.func(a)>0);
    bisec.bisection(a,b);

}
