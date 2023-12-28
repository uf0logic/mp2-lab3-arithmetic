// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память


#include <iostream>

template <typename T>
class Stack {
private:
    static constexpr int DEFAULT_CAPACITY = 10;
    T* data;
    int capacity;
    int size;

public:
    // Конструктор
    Stack() : capacity(DEFAULT_CAPACITY), size(0) {
        data = new T[capacity];
    }

    // Деструктор
    ~Stack() {
        delete[] data;
    }

    // Вставка элемента
    void push(const T& value) {
        if (size == capacity) {
            expandCapacity();
        }
        data[size++] = value;
    }

    // Извлечение элемента
    void pop() {
        if (!isEmpty()) {
            --size;
        }
    }

    // Просмотр верхнего элемента
    T& top() const {
        if (!isEmpty()) {
            return data[size - 1];
        } else {
            throw std::out_of_range("Stack is empty");
        }
    }

    // Проверка на пустоту
    bool isEmpty() const {
        return size == 0;
    }

    // Получение количества элементов в стеке
    int getSize() const {
        return size;
    }

    // Очистка стека
    void clear() {
        size = 0;
    }

private:
    // Увеличение размера стека при необходимости
    void expandCapacity() {
        capacity *= 2;
        T* newData = new T[capacity];
        std::copy(data, data + size, newData);
        delete[] data;
        data = newData;
    }
};




