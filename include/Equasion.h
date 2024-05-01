#ifndef EQUASION_H
#define EQUASION_H

#include <stdlib.h>
#include <string.h>
#include <stack>
#include <map>

using namespace std;

class Equasion
{
    public:
        Equasion();

        Equasion(string expression);

        string toPolishNotation();

        double evaluate();

        void setExpression(string expression);

        int getOperatorPriority(char oper);

        string getExpression();

        string getPolish();

        bool isOperator(char oper);

        bool isNumber(char number);

        bool isLetter(char letter);

        string collectNumber(int& position);

        string collectIdent(int& position);
    private:
        string expression;
        string polish;
        map<char, int> priorities;
        map<string, char> functions;
};

#endif // EQUASION_H
