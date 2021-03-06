#include <iostream>
#include <cmath>
using namespace std;
/// Computes n-th root of x
double sqrtn(int n, double x){
	return exp( log(x) / n); 
}
double power(double  x, double y){
	return exp( log(x) * y);
}
template <typename F, typename G>
double function(int n, double y, double z, F f, G g){
	return (f(n,y) > z) ? g(z, y) : g(y, z);
}
int main(){
	//auto fp1 = sqrtn;
    double (*fp1)(int, double ) = sqrtn;
    //auto fp2 = power;
    double (*fp2)(double, double ) = power;
	//auto fp3 = function<decltype(fp1), decltype(fp2)>;
    double (*fp3)(int, double, double, double (*)(int, double),double (*)(double, double)) = function<double(*)(int, double ), double(*)(double, double )>;
	cout << fp3(2, 10, 3, fp1, fp2) << endl;
	cout << fp3(3, 10, 3, fp1, fp2) << endl;
	return 0;
}

//59049
//1000
