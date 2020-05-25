#include "ChainFraq.h"
#include <math.h>

using namespace std;

ChainFraq::ChainFraq(double x, double eps) {
    this->eps = eps;

    Ratio r = Ratio::fromDouble(x);
    while(true) {
        int a0 = (int) floor(r.getNom() / abs((int)r.getDen()));
        this->a.push_back(a0);

        if (r.getDen() == 1) {
            this->num = this->a.size();
            break;
        } else if (abs(r.getNom()/(int)r.getDen()) < eps) {
            this->num = this->a.size();
            break;
        }

        unsigned int tmp_den = r.getDen();
        int sign = (r.getNom() > 0) - (r.getNom() < 0);
        r.setDen( abs(r.getNom()) - abs(a0)*tmp_den );
        r.setNom( tmp_den * sign );
    }

    r = this->getRatio();
    this->eps = (double) r.getNom() / abs((int)r.getDen()) - x;
}

ChainFraq::ChainFraq(double x, int num) {
    this->num = num;

    Ratio r = Ratio::fromDouble(x);

    for (int i=0; i<num; i++) {
        int a0 = (int) floor(r.getNom() / abs((int)r.getDen()));
        this->a.push_back(a0);

        if (r.getDen() == 1) {
            this->eps = abs(r.getNom()/abs((int)r.getDen()) - x);
            this->num = this->a.size();
            break;
        }

        unsigned int tmp_den = r.getDen();
        int sign = (r.getNom() > 0) - (r.getNom() < 0);
        r.setDen( abs(r.getNom()) - abs(a0)*tmp_den );
        r.setNom( tmp_den * sign );
    }

    r = this->getRatio();
    this->eps = r.getNom() / abs((int)r.getDen()) - x;
}

string ChainFraq::toString() {
    string r = "";

    for (vector<int>::iterator it = this->a.begin(); it != this->a.end(); ++it) {
        r += *it + " 1 + 1/(";
    }
    r += "1/" + this->a[this->a.size()-1];
    for (vector<int>::iterator it = this->a.begin(); it != this->a.end(); ++it) {
        r += ")";
    }

    return r;
}

void ChainFraq::output() {
    for (vector<int>::iterator it = this->a.begin(); it != this->a.end(); ++it) {
        cout << *it << " + 1/(";
    }
    cout << "1/" << this->a[this->a.size()-1];
    for (vector<int>::iterator it = this->a.begin(); it != this->a.end(); ++it) {
        cout << ")";
    }
}

double ChainFraq::getPrecision() {
    return eps;
}

Ratio ChainFraq::getRatio() {
    Ratio r(this->a[this->num-1], 1);

    for (vector<int>::reverse_iterator it = this->a.rbegin()+1; it != this->a.rend(); ++it) {
        int tmp_nom = r.getNom();
        int sign = (r.getNom() > 0) - (r.getNom() < 0);
        r.setNom( (*it * r.getNom() + r.getDen())*sign );
        r.setDen( tmp_nom*sign );
    }

    return r;
}

double ChainFraq::getNum() {
    return num;
}
