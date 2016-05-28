#include <iostream>
#include <boost/chrono/chrono_io.hpp>

using namespace std;

int main(){
	int a[10000],n=10000;
	for(int i=0;i<n;i++)
		a[i] = 1;
	boost::chrono::high_resolution_clock::time_point start= boost::chrono::high_resolution_clock::now();
      	for ( int i=0; i< n-1; i++ ) {
		a[i] = 0.5*a[i]+0.5*a[i+1];
      	}
	boost::chrono::high_resolution_clock::time_point end= boost::chrono::high_resolution_clock::now();
	cout << "Time taken " << end-start << endl;
	for(int i=0;i<n;i++)
		cout << a[i] << "\t";
	cout << endl;
	return 0;
}
