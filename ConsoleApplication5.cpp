#include <iostream>
#include <stack>
#include <stdexcept>

template <typename T>
class QueueWithStacks {
public:
    QueueWithStacks() {}

    // Вставка элемента в очередь
    void push(T value) {
        while (!outputStack.empty()) {
            inputStack.push(outputStack.top());
            outputStack.pop();
        }
        inputStack.push(value);
    }

    // Удаление элемента из очереди
    void pop() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
        if (outputStack.empty()) {
            throw std::underflow_error("Очередь пуста");
        }
        outputStack.pop();
    }

    // Получение верхнего элемента очереди
    T top() {
        while (!inputStack.empty()) {
            outputStack.push(inputStack.top());
            inputStack.pop();
        }
        if (outputStack.empty()) {
            throw std::underflow_error("Очередь пуста");
        }
        return outputStack.top();
    }

    // Проверка на пустоту
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }

private:
    std::stack<T> inputStack;
    std::stack<T> outputStack;
};

int main() {
    QueueWithStacks<int> queue;

    char choice;
    int value;

    while (true) {
        std::cout << "Выберите действие:\n"
            "1. Вставить элемент (push)\n"
            "2. Удалить элемент (pop)\n"
            "3. Верхний элемент (top)\n"
            "4. Проверить пустоту (empty)\n"
            "5. Выход\n"
            "Ваш выбор: ";

        std::cin >> choice;

        if (choice == '1') {
            std::cout << "Введите значение для вставки: ";
            std::cin >> value;
            queue.push(value);
        }
        else if (choice == '2') {
            if (!queue.empty()) {
                queue.pop();
                std::cout << "Удален верхний элемент" << std::endl;
            }
            else {
                std::cout << "Очередь пуста" << std::endl;
            }
        }
        else if (choice == '3') {
            if (!queue.empty()) {
                std::cout << "Верхний элемент: " << queue.top() << std::endl;
            }
            else {
                std::cout << "Очередь пуста" << std::endl;
            }
        }
        else if (choice == '4') {
            if (queue.empty()) {
                std::cout << "Очередь пуста" << std::endl;
            }
            else {
                std::cout << "Очередь не пуста" << std::endl;
            }
        }
        else if (choice == '5') {
            break;
        }
        else {
            std::cout << "Неверный выбор. Попробуйте ещё раз." << std::endl;
        }
    }

    return 0;
}
