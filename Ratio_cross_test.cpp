namespace RatioCPP {
    #include "../Ratio_CPP/Ratio.h"
    #include "../Ratio_CPP/ChainFraq.h"
}
namespace RatioC {
    #include "../Ratio_C/Ratio.h"
    #include "../Ratio_C/ChainFraq.h"
}

#include <iostream>
using namespace std;

void run_cross_test() {
    RatioC::Ratio r_c = RatioC::fromDType(7.56);
    RatioCPP::Ratio r_cpp = RatioCPP::Ratio::fromDouble(7.56);

    assert(r_c.nom == r_cpp.getNom());
    assert(r_c.den == r_cpp.getDen());

    RatioC::ChainFraq cf_c = RatioC::create_ChainFraq(7.56, 0.00001);
    RatioCPP::ChainFraq cf_cpp = RatioCPP::ChainFraq(7.56, 0.00001);

    RatioC::Ratio cf_c_r = RatioC::getRatio(cf_c);
    RatioCPP::Ratio cf_cpp_r = cf_cpp.getRatio();

    assert(cf_c_r.nom == cf_cpp_r.getNom());
    assert(cf_c_r.den == cf_cpp_r.getDen());
}
