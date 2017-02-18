#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); ++i) {
        if(x % i==0) {
           // cout << x << " " << i << " " ;
            return false;
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    
    std::fstream myfile("/Users/HAM/Desktop/inputs/1.txt", std::ios_base::in);
    int x;
    while (myfile >> x) {
        int count=0;
        for (int i = x; i > 1; --i) {
            if (isPrime(i)) {
                count++;
            }
        }
        cout << count << endl;
    }
    
    return 0;
}
