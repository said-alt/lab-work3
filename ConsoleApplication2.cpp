#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class Stack {
public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (!top) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
    }

    void pop() {
        if (isEmpty()) {
            throw std::underflow_error("Стек пуст");
        }
        Node<T>* temp = top;
        top = top->next;
        delete temp;
    }

    T topElement() {
        if (isEmpty()) {
            throw std::underflow_error("Стек пуст");
        }
        return top->data;
    }

    bool isEmpty() const {
        return !top;
    }

    void display() {
        Node<T>* current = top;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    Node<T>* top;
};

int main() {
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << "Верхний элемент: " << intStack.topElement() << std::endl;

    intStack.pop();
    std::cout << "Верхний элемент после удаления: " << intStack.topElement() << std::endl;

    intStack.push(4);
    intStack.push(5);

    std::cout << "Элементы стека: ";
    intStack.display();

    return 0;
}
