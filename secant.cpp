#include<bits/stdc++.h>

using namespace std;

const double dif = 1e-2;

class Secant{
    public:
    double f(double x){
        return x*x*x + x*x - 2;
    }

    double secant(double x1 , double x2){
        double root = (x1*f(x2) -x2*f(x1)) / (f(x2) - f(x1));
        while (abs(x2-x1) > dif) {
            cout<<root<<endl;
            x1= x2;
            x2=root;
        }
        return root;
    }
};

int main()
{
    cout << fixed << setprecision(6);
    srand(time(0));
    Secant secnt;
    double x1 , x2;
             x1 = rand();
             x2 = rand();
        secnt.secant(x1,x2);

    return 0;
}