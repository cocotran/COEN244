#include "Polynomial.hpp"

Polynomial::Polynomial(string expression)
{
    inputString = expression;
    parseExpression(inputString);
}

void Polynomial::parseExpression(string expression)
{
    expression.erase(std::remove_if(expression.begin(), expression.end(), [](char c) {
        return std::isspace(static_cast<unsigned char>(c)); }), expression.end());
    cout << "Input with spaces removed: " << expression << endl;
    std::regex polynomial_regex("([+-]?[^-+]+)");
    vector<string> matched_elements;
    try
    {
        std::sregex_iterator next(expression.begin(), expression.end(), polynomial_regex);
        std::sregex_iterator end;
        while (next != end)
        {
            std::smatch match = *next;
            std::cout << "Matched element: " << match.str() << endl;
            matched_elements.push_back(match.str());
            next++;
        }
    }
    catch (std::regex_error &e)
    {
        throw "Malformed input string!";
    }
    for (auto i = matched_elements.begin(); i != matched_elements.end(); i++)
    {
        string el = *i;
        uint exponent = std::stoi(el.substr(el.find("^") + 1, el.back()));
        double coefficient = std::stod(el.substr(0, el.find('x')));
        cout << "For " << el << ", coefficient is " << coefficient << ", exponent is " << exponent << endl;
        this->coef.push_back(coefficient);
        this->expo.push_back(exponent);
        size++;
    }
}
Polynomial::Polynomial(const Polynomial& poly) {
    this->inputString = poly.inputString;
    this->parseExpression(this->inputString);
}
Polynomial & Polynomial::operator= (const Polynomial& poly) {
    return (Polynomial x = new Polynomial(poly));
}
