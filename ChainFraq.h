#include "Ratio.h"
#include <vector>

using namespace std;

class ChainFraq
{
private:
    int num;
    vector<int> a;
    double eps;

public:
    ChainFraq(double x, double eps);
    ChainFraq(double x, int num);

    string toString();
    void output();

    double getPrecision();
    Ratio getRatio();
    double getNum();
};
