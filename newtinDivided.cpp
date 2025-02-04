#include<bits/stdc++.h>
using namespace std;
class NewtonDivided{
   public:
    vector<double> x,y;
    vector<vector<double>> table;
    int n;
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
    void newtonDivided(double xp){
       int  p=1;
       double ans;
       for(int i=0; i<n; i++){
            p = p*(xp -x[i-1]);
             ans= ans+p*table[0][i];
       }
       cout<<"the ans is : "<<ans<<endl;
    } 
};
int main(){
    NewtonDivided newton;
    newton.input();
    newton.diff_table();
    cout<<"enter the value for interpolation : "<<endl;
    double xp;
    cin>>xp;
    newton.newtonDivided(xp);

}