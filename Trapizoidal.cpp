#include<bits/stdc++.h>
using namespace std;
class Trapezoidal{
    private:
    double n,h ; 
    double f(double x){
        return 1.0/(1+x*x);
    }
    public:
    void trape(double l, double r, double n){
        double h=(r-l)/n;
        double sum= 0.5 * (f(l)+f(r));
        for(int i=1;i<n;i++){
            sum += f(i*h+l);
        }
        cout<<"the result "<<h*sum<<endl;;
    }
};
int main(){
    Trapezoidal trapezoidal;
    double a,b,n;
    cout<<"enter the value of a, b and n: "<<endl;
    cin>>a>>b>>n;
    trapezoidal.trape(a,b,n);
}