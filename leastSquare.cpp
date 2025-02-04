#include<bits/stdc++.h>
using namespace std;
 class LeastSquare{
    private:
    vector<double> x,y;
    int n;
    public:
    void input(){
        cout<<"Enter the number of data points: "<<endl;
        cin>>n;
        x.resize(n);
        y.resize(n);
        cout<<" enter the coordinate points : "<<endl;
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }
    }
    void fitCurve(){
        double sum_x=0, sum_y=0, sum_xy=0, sum_x2=0;
        for(int i=0; i<n; i++){
            sum_x += x[i];
            sum_y += y[i];
            sum_xy += x[i]*y[i];
            sum_x2 += x[i]*x[i];
        }
        double a = (n*sum_xy - sum_x*sum_y)/(n*sum_x2 - sum_x*sum_x);
        double b = (sum_y - a*sum_x)/n;
        cout<<"best fit line is y = "<<a<<"x";
        if (b >= 0) {
            cout << "+ " << b << endl;
        } else {
            cout << " - " << -b << endl;
        }
    }
 };

int main(){
    LeastSquare leastSquare;
    leastSquare.input();
    leastSquare.fitCurve();
}