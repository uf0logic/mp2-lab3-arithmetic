// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"




// Функция для разбиения выражения на лексемы
void tokenizeExpression(const std::string& expression, Stack<char>& operators, Stack<std::string>& operands) {
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (isspace(ch)) {
            // Пропускаем пробелы
            continue;
        } else if (isdigit(ch) || isalpha(ch) || ch == '.') {
            // Собираем операнды (числа и переменные)
            std::string operand;
            operand += ch;

            while (i + 1 < expression.size() &&
                   (isdigit(expression[i + 1]) || isalpha(expression[i + 1]) || expression[i + 1] == '.')) {
                operand += expression[i + 1];
                ++i;
                   }

            operands.push(operand);
        } else {
            // Собираем операторы и скобки
            operators.push(ch);
        }
    }
}

double evaluatePostfix(const std::string& postfix) {
    Stack<double> operands;

    for (char ch : postfix) {
        if (isspace(ch)) {
            // Пропускаем пробелы
            continue;
        } else if (isdigit(ch) || (ch == '.' && isdigit(postfix[postfix.find(ch) + 1]))) {
            // Собираем операнды (числа)
            std::string operand;
            operand += ch;

            size_t nextPos = postfix.find_first_not_of("0123456789.", postfix.find(ch) + 1);
            if (nextPos != std::string::npos) {
                operand += postfix.substr(postfix.find(ch) + 1, nextPos - postfix.find(ch) - 1);
            } else {
                operand += postfix.substr(postfix.find(ch) + 1);
            }

            operands.push(std::stod(operand));
        } else {
            // Выполняем операции
            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 != 0) {
                        operands.push(operand1 / operand2);
                    } else {
                        throw std::invalid_argument("Division by zero");
                    }
                    break;
                case '^':
                    operands.push(std::pow(operand1, operand2));
                    break;
                default:
                    throw std::invalid_argument("Invalid operator");
            }
        }
    }

    if (!operands.isEmpty()) {
        return operands.top();
    } else {
        throw std::invalid_argument("Invalid expression");
    }
}
