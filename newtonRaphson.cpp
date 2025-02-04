#include<bits/stdc++.h>
using namespace std;
const double dif=1e-2;
class NewtonRaphson{
    public:
    double fc(double x){
        return x*x*x*x -x*x -2;
    }
    double ddx(double x){
        return 4*x*x*x -2*x;
    }
    double newtonRaphson(double x){
        double h = fc(x)/ddx(x);
        while(abs(h)>dif){
            x=x-h;
            h = fc(x)/ddx(x);
        }
        return x;
    }

};
int main(){
    cout<<fixed<<setprecision(6);
    srand(time(0));
    NewtonRaphson raphson;
    for(int i=0; i<10; i++){
        double root=rand();
        cout<<"assumption root : "<<root<<endl;
        root = raphson.newtonRaphson(root);
        cout<<"final root : "<<root<<endl;
    }
}