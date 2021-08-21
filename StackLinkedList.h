#include <memory>

template<class t_Data>
class Stack {
    struct Node {
        t_Data data;
        std::unique_ptr<Node> nextNode;

        Node (const t_Data &_data) : data(_data) {}
    };

    int count = 0;

public:

    void push(const t_Data &newData) {
        if (!head) {
            head = std::unique_ptr<Node>(newData);
        } else {
            std::unique_ptr<Node> oldHead = std::move(head);
            head = std::make_unique<Node>(newData);
            head->nextNode = std::move(oldHead);
        }

        ++count;
    }

    t_Data pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty!");
        }

        t_Data itemToPop = head->data;
        std::unique_ptr<Node> temp = std::move(head->nextNode);
        head = std::move(temp);

        --count;

        return itemToPop;
    }

    bool isEmpty() const {
        return !head;
    }

    int size() const {
        return count;
    }
};