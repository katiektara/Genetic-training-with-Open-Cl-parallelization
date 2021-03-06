// hpx 1.cpp: определяет точку входа для консольного приложения.
//
//#include "stdafx.h"


#include "C:\Users\SG\Downloads\hpx-master/hpx/hpx_init.hpp"
#include "C:\Users\SG\Downloads\hpx-master/hpx/hpx.hpp"
#include "C:\Users\SG\Downloads\hpx-master/hpx/include/parallel_algorithm.hpp"
#include "C:\Users\SG\Downloads\hpx-master/hpx/lcos/async.hpp"



#include <functional>
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <chrono>



//#include <cstddef>
//#include <cstdint>
//#include <iostream>
//#include <vector>

#include "as.h"

using namespace std;

void sleep(int ms) {
	clock_t target = clock() + ms;
	while (clock() < target) {}
}

int main()
{

	//CDiophantine dp1();
	//hpx::future<void> f = hpx::async(()[] {dp1(1, 1, 1, 1, 30); });
	//CDiophantine r = f.get();
	//auto &qqwe = hpx::dataflow([]() {});
	auto asyncDefault1 = std::async([]()
	{
		CDiophantine dp1(1, 1, 1, 1, 30);

		int ans1;
		ans1 = dp1.Solve();
		if (ans1 == -1) {
			cout << "No solution found." << endl;
		}
		else {
			gene gn1 = dp1.GetGene(ans1);

			cout << "1The solution set to a+b+c+d=30 is:\n";
			cout << "1a = " << gn1.alleles[0] << "." << endl;
			cout << "1b = " << gn1.alleles[1] << "." << endl;
			cout << "1c = " << gn1.alleles[2] << "." << endl;
			cout << "1d = " << gn1.alleles[3] << "." << endl;
		}
	});
	
	auto asyncDefault2 = std::async([]()
	{
		CDiophantine dp(-1, -1, -1, -1, -30);

		int ans;
		ans = dp.Solve();
		if (ans == -1) {
			cout << "No solution found." << endl;
		}
		else {
			gene gn = dp.GetGene(ans);

			cout << "2The solution set to a+b+c+d=30 is:\n";
			cout << "2a = " << gn.alleles[0] << "." << endl;
			cout << "2b = " << gn.alleles[1] << "." << endl;
			cout << "2c = " << gn.alleles[2] << "." << endl;
			cout << "2d = " << gn.alleles[3] << "." << endl;
		}
	});
	
	asyncDefault1.get();

	sleep(10000);

}