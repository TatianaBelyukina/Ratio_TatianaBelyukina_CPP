#include "../Ratio_CPP/test_Ratio.cpp"
#include "../Ratio_CPP/test_ChainFraq.cpp"
#include <iostream>

using namespace std;

int main() {
    RatioTests rt;
    rt.run_tests();

    ChainFraqTests ct;
    ct.run_tests();

    return 0;
}
