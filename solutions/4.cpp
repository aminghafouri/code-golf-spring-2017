#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include<math.h>
using namespace std;


double GetMean(vector<double> daArray) {
    double dSum = daArray[0];
    for (int i = 1; i < daArray.size(); ++i) {
        dSum += daArray[i];
    }
    return dSum/daArray.size();
}


int main(int argc, const char * argv[]) {
    
    
    std::fstream myfile("/Users/HAM/Desktop/inputs/4.txt", std::ios_base::in);
    
    vector<double> vx;
    vector<double> vy;
    double x, y;
    while (myfile >> x)
    {
        myfile >> y;
        vx.push_back(x);
        vy.push_back(y);
    }
    double xm = GetMean(vx);
    double ym = GetMean(vy);
    double ssxx = 0;
    double ssxy = 0;
    for (auto i = 0; i < vx.size(); ++i) {
        ssxx += pow(vx[i]-xm, 2.0);
        ssxy += (vx[i] - xm) * (vy[i] - ym);
    }
    
    double m = ssxy / ssxx;
    double b = ym - m*xm;
    cout << std::fixed << std::setprecision(3);
    if (b/m > 0)
        cout << b/m << endl;
    else
        cout << -b/m <<'-' << endl;
    
    return 0;
}
