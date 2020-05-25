#include "../Ratio_CPP/Ratio.h"
#include <assert.h>

class RatioTests
{
private:
    void test_add() {
        Ratio r1(3, 4);
        Ratio r2(1, 2);

        Ratio r = r1 + r2;
        assert(r.getNom() == 5);
        assert(r.getDen() == 4);
    }

    void test_sub() {
        Ratio r1(3, 4);
        Ratio r2(1, 2);

        Ratio r = r1 - r2;
        assert(r.getNom() == 1);
        assert(r.getDen() == 4);
    }

    void test_mul() {
        Ratio r1(3, 4);
        Ratio r2(1, 2);

        Ratio r = r1 * r2;
        assert(r.getNom() == 3);
        assert(r.getDen() == 8);

        Ratio rd = r1 * 3.0;
        assert(rd.getNom() == 9);
        assert(rd.getDen() == 4);
    }

    void test_div() {
        Ratio r1(3, 4);
        Ratio r2(1, 2);

        Ratio r = r1 / r2;
        assert(r.getNom() == 3);
        assert(r.getDen() == 2);

        Ratio rd = r1 / 3.0;
        assert(rd.getNom() == 1);
        assert(rd.getDen() == 4);
    }

    void test_eq_add() {
        Ratio r(3, 4);
        Ratio r2(1, 2);

        r += r2;
        assert(r.getNom() == 5);
        assert(r.getDen() == 4);
    }

    void test_eq_sub() {
        Ratio r(3, 4);
        Ratio r2(1, 2);

        r -= r2;
        assert(r.getNom() == 1);
        assert(r.getDen() == 4);
    }

    void test_eq_mul() {
        Ratio r(3, 4);
        Ratio r2(1, 2);

        r *= r2;
        assert(r.getNom() == 3);
        assert(r.getDen() == 8);

        r *= 5.0;
        assert(r.getNom() == 15);
        assert(r.getDen() == 8);
    }

    void test_eq_div() {
        Ratio r(3, 4);
        Ratio r2(1, 2);

        r /= r2;
        assert(r.getNom() == 3);
        assert(r.getDen() == 2);

        r /= 3.0;
        assert(r.getNom() == 1);
        assert(r.getDen() == 2);
    }

public:
    void run_tests() {
        test_add();
        test_sub();
        test_mul();
        test_div();
        test_eq_add();
        test_eq_sub();
        test_eq_mul();
        test_eq_div();

        cout << "Ratio tests completed\n";
    }
};
