#include "../Ratio_CPP/ChainFraq.h"
#include <assert.h>

class ChainFraqTests
{
private:
    void test() {
        ChainFraq rc(7.56, 0.00001);
        assert(rc.getNum() == 6);
        Ratio r = rc.getRatio();
        assert(r.getNom() == 189);
        assert(r.getDen() == 25);

        ChainFraq rc2(-7.568, 0.00001);
        assert(rc2.getNum() == 7);
        r = rc2.getRatio();
        assert(r.getNom() == -946);
        assert(r.getDen() == 125);
    }

public:
    void run_tests() {
        test();

        cout << "ChainFraq tests complete\n";
    }
};
