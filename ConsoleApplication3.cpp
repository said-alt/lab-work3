#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
public:
    Stack() {
        capacity = 8;  // Начальный размер массива
        size = 0;
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(T value) {
        if (size == capacity) {
            resize(2 * capacity);  // Увеличиваем размер массива вдвое
        }
        data[size++] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Стек пуст");
        }
        size--;
    }

    T topElement() {
        if (isEmpty()) {
            throw std::underflow_error("Стек пуст");
        }
        return data[size - 1];
    }

    bool isEmpty() const {
        return size == 0;
    }

private:
    T* data;
    int capacity;
    int size;

    void resize(int newCapacity) {
        T* newData = new T[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
};

int main() {
    Stack<int> intStack;
    for (int i = 1; i <= 15; i++) {
        intStack.push(i);
    }

    std::cout << "Верхний элемент: " << intStack.topElement() << std::endl;

    intStack.pop();
    std::cout << "Верхний элемент после удаления: " << intStack.topElement() << std::endl;

    intStack.push(16);

    while (!intStack.isEmpty()) {
        std::cout << "Извлечение: " << intStack.topElement() << std::endl;
        intStack.pop();
    }

    return 0;
}
