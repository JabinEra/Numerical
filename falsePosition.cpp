#include<bits/stdc++.h>
using namespace std;
const int up=1000;
const int lb=-1000;
const int MAX=1000;

class False{
    private:
    double a,b,c,root;
    double fc(double x){
        return x+x*x - x*x +2;
    }
    void random(){
        srand(time(0));
        do{
            a=rand()%101 - 50;
            b = rand()%101 -50;
        }
        while(fc(a)*fc(b)>0);
    }
    public:
    False(){
        random();
    }
    void falseposition(){
        for(int i=0;i<MAX; i++){
            c =( b*fc(a)-a*fc(b)) / (fc(b) - fc(a)); 
            if(fc(c) == 0){
                root=c;
                cout<<"Root found: "<<root<<endl;
                return;
            }
            else if(fc(a)*fc(c)<0){
                b=c;
            }
            else{
                a=c;
            }
        }
        root=c;
        cout<<"Max iteration reached. the root is: "<<root<<endl;
    }
};
int main(){
    False falsi;
    falsi.falseposition();
}
// #include<bits/stdc++.h>

// using namespace std;

// const int lb = -1000;
// const int ub = 1000;
// const int mx = 2e6;
// const double dif = 0.0001;

// class False{
//     public :
//     double func(double x){
//         return x*x*x + x*x + 7;
//     }

//     double regulaFalsi(double a, double b){
//         if (func(a) * func(b) >= 0){
//             cout << "You have not assumed right a and b\n";
//             return 0;
//         }
//         double root = a;
//         for (int i=0; i < mx; i++)
        
//         {
//             root = (a*func(b) - b*func(a))/ (func(b) - func(a));
//             if (func(root)==0)
//                 break;
//             else if (func(root)*func(a) > 0)
//                 a = root;
//             else
//                 b = root;
//         }
//         return root;
//     }
// };

// int main()
// {
//     cout << fixed << setprecision(10);
//     False falsi;
//     srand(time(0));
//     double a, b;
   
//     double roots[10];

//     for (int i = 0; i < 10; i++) {
//         do {
//             a = (rand() % (ub - lb + 1)) + lb;
//         } while (falsi.func(a) > 0);
//         do {
//             b = (rand() % (ub - lb + 1)) + lb;
//         } while (falsi.func(b) < 0);
        
//         cout << "in range [" << a << ", " << b << "] : " <<  falsi.regulaFalsi(a, b) << endl;
//     }

    

//     return 0;
// }
