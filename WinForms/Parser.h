#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <iterator>

//������ ����������
typedef std::map<std::string, double> Variables;
//������ "��������"
typedef std::map<std::string, std::vector<double> > Massives;

//������� ��������� ��������� � ������ "expr" � ���� ���������� ��� �������
void ReadExpressionFromStream(std::string expr, std::string utoch, Variables& var, Massives& mas) {

    std::string temp;
    int pos;
    //���� ��������� '=', �� ��� ����������, ������� �� ��� � �������� � ������
    temp = utoch;
    pos = temp.find('=');
    if (pos > 0) {
        std::string name = temp.substr(0, pos);
        double value = atof(temp.substr(pos + 1).c_str());
        var[name] = value;
    }
    //���� ����� '{', ��� ������, ������� ��� ������� � �������� � ��������������� �������
    pos = temp.find('{');
    if (pos > 0) {
        std::string name = temp.substr(0, pos);
        //���� �������� ������� � ���������� ��
        int pos1 = pos, pos2;
        do {
            pos2 = temp.find(',');
            double value = atof(temp.substr(pos1 + 1, pos2).c_str());
            mas[name].push_back(value);
            if (pos2 == -1)
                break;
            temp[pos2] = ' ';
            pos1 = pos2;
        } while (pos2 > 0);
    }
}


// ���� �������
enum tokentype {
    //����������, ���������, (, ), �������, ��������, ������, {, }
    var, num, op_br, cl_br, func, op, mas, op_sbr, cl_sbr
};
// ��������� ������
struct token {
    std::string name;
    tokentype type;

    //������������
    token(std::string str, tokentype typ) {
        name = str;
        type = typ;
    }
    token() {}
};
//������ �������
typedef std::vector<token> tokens;
//��������� ������������
std::set<char> DelimSet;
//�����������
const std::string delimiters = " ()+/*-^&|!%[]";
//�������������� ��������� ������������
void CreateSetOfDelimiters() {
    for (int i = 0; i < delimiters.size(); i++)
        DelimSet.insert(delimiters[i]);
    return;
}

//��������, �������� �� ������ ������������
bool IsDelimiter(char sym) {
    return DelimSet.count(sym) > 0;
}

//��������� ��������� �� ������
void CreateTokensFromExpression(std::string& expr, tokens& texpr) {
    CreateSetOfDelimiters();
    std::string ex = expr + " ";
    std::string name;

    //�������� ��� ������
    int i = 0;
    while (i < ex.size() - 1) {
        name = "";
        //���� ������� ������ �����������
        if (IsDelimiter(ex[i])) {
            if (ex[i] == ' ') { //������ ������ �������������
                i++;
                continue;
            }
            name = ex[i]; //����� ������ ��������� � ��� ������
            i++;
        }

        else {
            while (!IsDelimiter(ex[i])) {
                /*���� �� ����������� ��������, ���������� ��� ��� �������,
                ��������� ��� ��������� */
                name += ex[i];
                i++;
            }
        }
        //������� ������������ ����� � ������ �������
        texpr.push_back(token(name, var));
    }

    //������� ������������ ������� ����
    for (int j = 0; j < texpr.size(); j++) {
        if (texpr[j].name[0] == '[') {
            texpr[j].type = op_sbr;
            continue;
        }
        if (texpr[j].name[0] == ']') {
            texpr[j].type = cl_sbr;
            continue;
        }
        if (texpr[j].name[0] == '(') {
            texpr[j].type = op_br;
            continue;
        }
        if (texpr[j].name[0] == ')') {
            texpr[j].type = cl_br;
            continue;
        }
        if (isdigit(texpr[j].name[0])) {
            texpr[j].type = num;
            continue;
        }

        //mas
        if (isalpha(texpr[j].name[0])) {
            if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '[')
                texpr[j].type = mas;
            //continue;
        }

        if (isalpha(texpr[j].name[0])) {
            if (j < texpr.size() - 1 && texpr[j + 1].name[0] == '(')
                texpr[j].type = func;
            continue;
        }

        texpr[j].type = op;
    }

    //��������� ����� � !, ��� ��� ���������� ��������
    for (int j = 0; j < texpr.size(); j++) {
        if (texpr[j].name == "-" && (j == 0 || texpr[j - 1].type == op_br))
            texpr[j].name = "opposite";
        if (texpr[j].name == "!" && (j == texpr.size() - 1 || texpr[j + 1].type == cl_br || texpr[j + 1].type == op))
            texpr[j].name = "factorial";
    }

    return;
}

//���������� ��������
std::map <std::string, int> prior;
//������� ���������� ���������� ��������
void CreatePrior() {
    prior["+"] = 10;
    prior["-"] = 10;
    prior["*"] = 20;
    prior["/"] = 20;
    prior["^"] = 30;
    prior["opposite"] = 10;
    prior["factorial"] = 30;
    prior["%"] = 20;
    prior["&"] = 5;
    prior["|"] = 5;
    prior["!"] = 40;
}

//��������� ��������� � ����������� ������
void CreatePostfixFromTokens(tokens& texpr, tokens& pexpr) {
    //������ ���������� ��������
    CreatePrior();
    std::stack <token> TStack;

    //����� ������ � �������� �� ���������
    for (int i = 0; i < texpr.size(); i++) {
        switch (texpr[i].type) {
        case var:
        case num:
            pexpr.push_back(texpr[i]);
            break;

        case op_br:
            TStack.push(texpr[i]);
            break;

        case cl_br:
            while (TStack.top().type != op_br) {
                pexpr.push_back(TStack.top());
                TStack.pop();
            }
            TStack.pop();
            break;

        case op_sbr:
            TStack.push(texpr[i]);
            break;

        case cl_sbr:
            while (TStack.top().type != op_sbr) {
                pexpr.push_back(TStack.top());
                TStack.pop();
            }
            TStack.pop();
            break;

        case op:
            if (TStack.size()) {
                while (TStack.size() && ((TStack.top().type == op && prior[texpr[i].name] <= prior[TStack.top().name]) ||
                    TStack.top().type == func ||
                    TStack.top().type == mas)) {
                    pexpr.push_back(TStack.top());
                    TStack.pop();
                }
            }
            TStack.push(texpr[i]);
            break;

        case mas:
            while (TStack.size() && TStack.top().type == mas) {
                pexpr.push_back(TStack.top());
                TStack.pop();
            }
            TStack.push(texpr[i]);
            break;

        case func:
            while (TStack.size() && TStack.top().type == func) {
                pexpr.push_back(TStack.top());
                TStack.pop();
            }
            TStack.push(texpr[i]);
            break;
        }
    }

    while (TStack.size()) {
        pexpr.push_back(TStack.top());
        TStack.pop();
    }
    return;
}

//���������� ��������� ��������
double fact(double n) {
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
double op_plus(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a + b;
}
double op_minus(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b - a;
}
double op_mul(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a * b;
}
double op_div(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b / a;
}
double op_deg(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    //b^a!!
    return pow(b, a);
}
double op_opposite(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return -a;
}
double op_factorial(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return fact(a);
}
double op_odiv(std::stack <double>& s) {
    long long a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return b % a;
}
double op_and(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a && b;
}
double op_or(std::stack <double>& s) {
    double a, b;
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    return a || b;
}
double op_not(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return !a;
}
double op_sin(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return sin(a);
}
double op_cos(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return cos(a);
}
double op_tan(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return tan(a);
}
double op_asin(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return asin(a);
}
double op_acos(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return acos(a);
}
double op_atan(std::stack <double>& s) {
    double a;
    a = s.top();
    s.pop();
    return atan(a);
}

//��������� �� �������(��� ��������)
typedef double(*func_type)(std::stack<double>&);

//������ ��������
typedef std::map<std::string, func_type> Ops;
Ops ops;

//������������� ������� ��������
void CreateOps() {
    ops["+"] = op_plus;
    ops["-"] = op_minus;
    ops["*"] = op_mul;
    ops["/"] = op_div;
    ops["^"] = op_deg;
    ops["opposite"] = op_opposite;
    ops["factorial"] = op_factorial;
    ops["%"] = op_odiv;
    ops["&"] = op_and;
    ops["|"] = op_or;
    ops["!"] = op_not;
    ops["sin"] = op_sin;
    ops["cos"] = op_cos;
    ops["tan"] = op_tan;
    ops["asin"] = op_asin;
    ops["acos"] = op_acos;
    ops["atan"] = op_atan;
    return;
}

//������� ��������� ���������
double ResultExpr(tokens& pexpr, Variables& expvars, Massives& varmas) {
    CreateOps();
    std::stack <double> s;

    for (int i = 0; i < pexpr.size(); i++) {
        switch (pexpr[i].type) {
        case num: {
            s.push(atoi(pexpr[i].name.c_str()));
        }
                break;

        case var: {
            Variables::iterator Vit;
            for (Vit = expvars.begin(); Vit != expvars.end(); Vit++) {
                if (Vit->first == pexpr[i].name) {
                    s.push(Vit->second);
                    break;
                }
            }
        }
                break;

        case func:
        case op: {
            Ops::iterator Oit;
            for (Oit = ops.begin(); Oit != ops.end(); Oit++) {
                if (Oit->first == pexpr[i].name) {
                    s.push(Oit->second(s));
                    break;
                }
            }
        }
               break;

        case mas: {
            int index = s.top();
            s.pop();

            Massives::iterator it;
            for (it = varmas.begin(); it != varmas.end(); it++) {
                if (it->first == pexpr[i].name)
                    s.push(it->second[index]);
            }
        }
        }
    }
    return s.top();
}

using namespace System;

void clear_el(Variables& expvars, Massives& expmasvars, tokens& texpr, tokens& pexpr) // ������� ��� ������, ��� ��� ����� �������� ��������
{
    expvars.clear();
    expmasvars.clear();
    texpr.clear();
    pexpr.clear();
};