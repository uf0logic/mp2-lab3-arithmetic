// объявление функций и классов для вычисления арифметических выражений
#include <iostream>
#include <string>
#include "stack.h"

void tokenizeExpression(const std::string& expression, Stack<char>& operators, Stack<std::string>& operands);

double evaluatePostfix(const std::string& postfix);


