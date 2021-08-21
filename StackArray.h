#include <memory>

template<class t_Data>
class StackArray {
    t_Data *stack = nullptr;
    int numOfItems = 0;
    int capacity = 0;

public:

    StackArray() {
        stack = new t_Data[1];
        capacity = 1;
    }

    ~StackArray() {
        delete[] stack;
    }

    void push(const t_Data &item) {
        if (numOfItems == capacity) {
            resize(capacity * 2);
        }

        stack[++numOfItems] = item;
    }

    t_Data pop() {
        if (isEmpty()) {
            throw std::out_of_range("StackArray is empty!");
        }

        t_Data itemToPop = stack[--numOfItems];

        if (numOfItems > 0 && numOfItems == capacity / 4) {
            resize(capacity / 2);
        }

        return itemToPop;
    }

    [[nodiscard]] bool isEmpty() const {
        return numOfItems == 0;
    }

    [[nodiscard]] int size() const {
        return numOfItems;
    }

    void resize(int _capacity) {
        auto *stackCopy = new t_Data[_capacity];

        for (int i = 0; i < numOfItems; ++i) {
            stackCopy[i] = stack[i];
        }

        delete[] stack;
        stack = stackCopy;
        capacity = _capacity;
    }
};