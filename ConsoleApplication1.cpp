
#include <iostream>
#include <stdexcept>

template <typename T>
class FixedSizeStack {
public:
    FixedSizeStack(int maxSize) {
        if (maxSize <= 0) {
            throw std::invalid_argument("Максимальный размер должен быть больше нуля.");
        }
        max_size = maxSize;
        array = new T[max_size];
        top = -1;
    }

    ~FixedSizeStack() {
        delete[] array;
    }

    void push(const T& value) {
        if (isFull()) {
            throw std::overflow_error("Стек заполнен");
        }
        array[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Стек пуст");
        }
        --top;
    }

    T topElement() {
        if (isEmpty()) {
            throw std::underflow_error("Стек заполнен");
        }
        return array[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == max_size - 1;
    }

private:
    T* array;
    int max_size;
    int top;
};


int main() {
    FixedSizeStack<int> intStack(5);
    int inputValue;

    std::cout << "Введите значения для помещения в стек целых чисел (Ctrl+D, чтобы остановить ввод):" << std::endl;
    while (std::cin >> inputValue) {
        intStack.push(inputValue);
    }

    std::cout << "Верхний элемент целочисленного стека: " << intStack.topElement() << std::endl;

    // Очищаем символ новой строки из входного буфера
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    FixedSizeStack<std::string> stringStack(3);
    std::string inputString;

    std::cout << "Введите значения для помещения в стек строк (Ctrl+D, чтобы остановить ввод):" << std::endl;
    while (std::cin >> inputString) {
        stringStack.push(inputString);
    }

    std::cout << "Верхний элемент стека строк: " << stringStack.topElement() << std::endl;

    return 0;
}