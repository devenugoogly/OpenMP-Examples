#include <iostream>
#include <boost/chrono/chrono_io.hpp>
#include "omp.h"
#define NUM_THREADS 2

using namespace std;

int main(){
	int a[1000][1000],n=1000;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			a[i][j] = 1;
		}
	}
	omp_set_num_threads(NUM_THREADS);
	boost::chrono::high_resolution_clock::time_point start= boost::chrono::high_resolution_clock::now();
	#pragma omp critical
   	{
      		for ( int i=1; i<n-1; i++) {
			for(int j=1;j<n-1;j++){
				a[i][j] = 0.5*a[i][j-1] + 0.5*a[i][j+1] + 0.5*a[i+1][j] + 0.5*a[i+1][j];
			}
      		}
   	}
	boost::chrono::high_resolution_clock::time_point end= boost::chrono::high_resolution_clock::now();
	cout << "Time taken " << end-start << endl;
/*	for(int i=0;i<n;i++)
		cout << a[i] << "\t";
	cout << endl;
*/	return 0;
}
