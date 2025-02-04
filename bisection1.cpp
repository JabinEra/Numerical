#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
const double diff=0.00001;
const int lb=-100;
const int up=100;
class Bisection{
    public:
    double fc(double x){
        return x*x*x -x*x + 2;
    }
    void Bisec(double a,double b){
        if(fc(a) * fc(b) > 0){
            cout<<"wrong assumption."<<endl;
            return;
        }   
         double root = a;
     
        while((b-a)>=diff){
            root=(a+b)/2;
           // cout<<"In range"<<a<<" to "<<b;
           // cout<<"let the root be: "<<root;
            if(fc(root)== 0.0){
                break;
            }
            else if(fc(a) * fc(root)>0){
                a=root;
            }else{
                b=root;
            }

        }
        cout<<"the root is: "<<root<<endl;;
    }
};

int main(){
    cout<<fixed<<setprecision(10);
    srand(time(0));
    Bisection bisec;
    double a,b;
    do{
        a= (rand()%(up-lb+1))+lb;
    } while(bisec.fc(a)>0);
    do{
        b= (rand()%(up-lb+1))+lb;
    }  while(bisec.fc(b)<0);
    cout<<"In rang ["<<a<<" , "<<b<<"] :";
    bisec.Bisec(a,b);
    cout<<endl;

}
