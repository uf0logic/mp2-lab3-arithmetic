// реализация пользовательского приложения

#include <iostream>

#include "arithmetic.h"
#include "stack.h"

int main() {
  // // Пример использования
  // Stack<int> myStack;
  // myStack.push(1);
  // myStack.push(2);
  // myStack.push(3);
  //
  // std::cout << "Top element: " << myStack.top() << std::endl;
  // std::cout << "Stack size: " << myStack.getSize() << std::endl;
  //
  // myStack.pop();
  // std::cout << "After pop, top element: " << myStack.top() << std::endl;
  //
  // myStack.clear();
  // std::cout << "After clear, stack size: " << myStack.getSize() << std::endl;
  //
  // return 0;

  // std::string expression;
  // std::cout << "Введите арифметическое выражение: ";
  // std::getline(std::cin, expression);
  //
  // tokenizeExpression(expression);
  //
  // return 0;

  // std::string expression;
  // std::cout << "Введите арифметическое выражение: ";
  // std::getline(std::cin, expression);
  //
  // tokenizeExpression(expression);
  //
  // return 0;

  std::string expression;
  std::cout << "Введите арифметическое выражение: ";
  std::getline(std::cin, expression);

  Stack<char> operators;
  Stack<std::string> operands;

  tokenizeExpression(expression, operators, operands);

  // Создаем строку для постфиксной записи, объединяя операторы и операнды
  std::string postfixExpression;
  while (!operands.isEmpty()) {
    postfixExpression += operands.top() + ' ';
    operands.pop();
  }

  while (!operators.isEmpty()) {
    postfixExpression += operators.top();
    operators.pop();
  }

  try {
    double result = evaluatePostfix(postfixExpression);
    std::cout << "Результат вычисления: " << result << std::endl;
  } catch (const std::exception& e) {
    std::cerr << "Ошибка: " << e.what() << std::endl;
  }

  return 0;
}
