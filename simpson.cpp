#include<bits/stdc++.h>
using namespace std;
class Simpsonroot{
    private:
    double n,h;
    double f(double x){
        return 1.0/(1+x*x);
    }
    public:
    void simp(double l, double r, double n){
        double h=(r-l)/n;
        double sum=(f(l)+f(r));
        for(int i=1; i<n; i++){
            double x = l + h*i;
            if(i%2==0){
                sum += 2 * f(x);
            }
            if(i%2!=0){
                sum += 4 * f(x);
            }

            
        }
        cout<<"the result "<<(h*sum)/3.0 <<endl;;
    }
};
int main(){
    Simpsonroot simpsonroot;
    double a,b,n;
    cout<<"enter the value of a, b and n: "<<endl;
    cin>>a>>b>>n;
    simpsonroot.simp(a,b,n);
}