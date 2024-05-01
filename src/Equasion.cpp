#include "Equasion.h"

Equasion::Equasion()
{
    priorities['~'] = 4;
    priorities['('] = 0;
    priorities['+'] = 1;
    priorities['-'] = 1;
    priorities['*'] = 2;
    priorities['/'] = 2;
    priorities['^'] = 3;
    priorities['s'] = 5;
    priorities['c'] = 5;
    priorities['t'] = 5;
    priorities['a'] = 5;
    priorities['q'] = 5;

    functions["sin"] = 's';
    functions["cos"] = 'c';
    functions["tg"] = 't';
    functions["abs"] = 'a';
    functions["sqrt"] = 'q';
}

Equasion::Equasion(string expression)
{
    Equasion();
    setExpression(expression);
}

void Equasion::setExpression(string expression)
{
    this->expression = expression;
    toPolishNotation();
}

string Equasion::getExpression() { return expression; }

string Equasion::getPolish() { return polish; }

int Equasion::getOperatorPriority(char oper) { return priorities[oper]; }

bool Equasion::isOperator(char oper)
{
    return (oper == '+' ||
            oper == '-' ||
            oper == '*' ||
            oper == '/' ||
            oper == '^');
}

bool Equasion::isNumber(char number)
{
    return (number >= '0' && number <= '9');
}

bool Equasion::isLetter(char letter)
{
    return (((letter >= 'a') && (letter <= 'z')) ||
            ((letter >= 'A') && (letter <= 'A')));
}

string Equasion::collectNumber(int& position)
{
    string number = "";
    while (isNumber(expression[position])) number += expression[position++];
    position--;
    //number.reverse();
    return number;
}

string Equasion::collectIdent(int& position)
{
    string ident = "";
    while (isLetter(expression[position])) ident += expression[position++];
    position--;
    //letter.reverse();
    return ident;
}

string Equasion::toPolishNotation()
{
    stack<char> operators;

    assert(!expression.empty());
    polish = "";
    bool is_unary = true;
    for(int i = 0; i < expression.length(); i++)
    {
        if (isNumber(expression[i]))
        {
            is_unary = false;
            string number = collectNumber(i);
            polish += (number + " ");
        }
        else if (isOperator(expression[i]))
        {
            if (!is_unary)
            {
                while ((getOperatorPriority(expression[i]) <
                       getOperatorPriority(operators.top())) &&
                       !operators.empty())
                {
                    polish += operators.top();
                    polish += ' ';
                    operators.pop();
                }
                operators.push(expression[i]);
            }
            else if (is_unary &&
                    expression[i] == '-')
            {


            }
        }
        else if (isLetter(expression[i]))
        {
            string identifier = collectIdent(i);
            if (expression[i + 1] == "(")
        }
    }
}

double Equasion::evaluate()
{

}
