#include<bits/stdc++.h>
using namespace std;

class NewtonForward{

    private:
    vector<double> x,y;
    vector<vector<double>> table;
    int n;

    double find_p(double p , int k){
        double temp = 1;
        for(int i=0; i<k; i++){
            temp = temp*(p-i);
        }
        return temp;
    }
    int factorial(int n){
        int fact=1;
        for(int i=2; i<=n; i++){
            fact *= i;
        } 
        return fact;
    }
    public:
    void input(){
       // int n;
        cout<<"Enter the number of data points: "<<endl;
        cin>>n;
        x.resize(n);
        y.resize(n);
        table.resize(n,vector<double>(n));
        cout<<"Enter the value of x and its correspoinding value of y: "<<endl;
        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
            table[i][0]=y[i];
        }   
    }
    void diff_table(){
        for(int i=1; i<n; i++){
            for(int j=0; j<n-i; j++){
                table[i][j] = table[j+1][i-1] - table[j][i-1];
            }
        }
        for(int i=0; i<n; i++){
            cout<<setw(4)<<x[i]<<"\t";
            for(int j=0; j<n-i; j++){
                cout<<setw(4)<<table[i][j]<<"\t";
            } 
            cout<<endl;
        }
    }
    void newtonRoot(double value){
        double sum = table[0][0];
        double p = (value - x[0])/(x[1] - x[0]);
        for(int i=1; i<n; i++){
            sum = sum + (find_p(p,i)*table[0][i]) / factorial(i);
        }
        cout<<"interpolated value x = "<<value<<" is: "<<sum<<endl;
    }



};
int main(){
    NewtonForward newton;
    newton.input();
    newton.diff_table();
    double value;
    cout<<"enter the value ; "<<endl;
    cin>>value;
    newton.newtonRoot(value);

}