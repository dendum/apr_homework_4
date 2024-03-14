#include <iostream>
#include <initializer_list>

template<typename T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T data) : data(data), next(nullptr) {}
};

template<typename T>
class ForwardList {
private:
    Node<T> *head;
    std::size_t size;
public:
    ForwardList() : head(nullptr), size(0) {}

    ForwardList(std::initializer_list<T> init_list) : head(nullptr), size(0) {
        for (const auto &item: init_list) { push_front(item); }
    }

    ~ForwardList() {
        while (head != nullptr) {
            Node<T> *next = head->next;
            delete head;
            head = next;
        }
    }

    ForwardList(const ForwardList &) = delete;
    ForwardList &operator=(const ForwardList &) = delete;

    ForwardList(ForwardList &&source) noexcept: head(source.head), size(source.size) {
        source.head = nullptr;
        source.size = 0;
    }

    ForwardList &operator=(ForwardList &&source) noexcept {
        if (this != &source) {
            delete head;
            head = source.head;
            size = source.size;
            source.head = nullptr;
            source.size = 0;
        }
        return *this;
    }

    void push_front(const T &data) {
        Node<T> *new_node = new Node<T>(data);
        new_node->next = head;
        head = new_node;
        size++;
    }

    void push_front(T &&data) {
        Node<T> *new_node = new Node<T>(std::move(data));
        new_node->next = head;
        head = new_node;
        size++;
    }

    void pop_front() {
        if (head) {
            Node<T> *to_delete = head;
            head = head->next;
            delete to_delete;
            size--;
        }
    }

    size_t getSize() const {
        return size;
    }

    void iterate() const {
        Node<T> *temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }
};
