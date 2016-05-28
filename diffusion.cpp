#include <iostream>
#include <cstdlib>
#include <cctype>
#include <boost/chrono/chrono_io.hpp>
#include "omp.h"
#define NUM_THREADS 2

using namespace std;

int main(int argc,char *argv[]){
	int n,*a;
	if(argc < 2){
		cout << "Array size not entered" << endl;
		exit(EXIT_FAILURE);
	}
	
	if(!isdigit(argv[1][0])){
		cout << "Invalid input" << endl;
		exit(EXIT_FAILURE);
	}else{
		n = atoi(argv[1]);
	}
	
	a = new int[n];
	for(int i=0;i<n;i++)
		a[i] = 1;
	omp_set_num_threads(NUM_THREADS);
	boost::chrono::high_resolution_clock::time_point start= boost::chrono::high_resolution_clock::now();
	#pragma omp parallel
   	{
      		for ( int i=0; i< n; i++) {
			a[i] = 0.5*a[i]+0.5*a[i+1];
      		}
   	}
	boost::chrono::high_resolution_clock::time_point end= boost::chrono::high_resolution_clock::now();
	cout << "Time taken " << end-start << endl;
/*	for(int i=0;i<n;i++)
		cout << a[i] << "\t";
	cout << endl;
*/	return 0;
}
