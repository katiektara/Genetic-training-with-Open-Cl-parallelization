#include "mainwindow.h"
#include "gen_algo.h"

#include <QApplication>

#include <functional>
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <chrono>

using namespace std;

void sleep(int ms) {
    clock_t target = clock() + ms;
    while (clock() < target) {}
}

int main(int argc, char *argv[])
{
    //CDiophantine dp1();
    //hpx::future<void> f = hpx::async(()[] {dp1(1, 1, 1, 1, 30); });
    //CDiophantine r = f.get();
    //auto &qqwe = hpx::dataflow([]() {});
    auto asyncDefault1 = std::async([]()
    {
        CDiophantine dp1(2, 1, -1, 1, 100);

        int ans1;
        ans1 = dp1.Solve();
        if (ans1 == -1) {
            cout << "No solution found." << endl;
        }
        else {
            gene gn1 = dp1.GetGene(ans1);

            cout << "The solution set to 2a+b-c+d = 100 is:\n";
            cout << "a = " << gn1.alleles[0] << endl;
            cout << "b = " << gn1.alleles[1] << endl;
            cout << "c = " << gn1.alleles[2] << endl;
            cout << "d = " << gn1.alleles[3] << endl;
        }
    });
    /*
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
    */
    asyncDefault1.get();

    sleep(10000);

    return 0;
}
