#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
#include <regex>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

const string TESTSTRING = "4.5x^8+ 3.4x^3-6.4x^1+3.1x^0";

class Polynomial {
    string inputString;
public:
    Polynomial(string);
    Polynomial(const Polynomial&);
    Polynomial& operator= (const Polynomial &);
    const Polynomial operator+ (const Polynomial&);
    const Polynomial operator- (const Polynomial&);
    const Polynomial operator* (double z);
    std::istream& operator>> (std::istream&);
    std::ostream& operator<< (std::ostream&);
    double& operator[] (int n);
    double operator[] (int n) const;
    double operator() (double x) const;
private:
    void parseExpression(string expression);
    vector<double> coef;
    vector<double> expo;
};
