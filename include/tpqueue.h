// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next;
    };
    Item* head;

 public:
    TPQueue() :head(nullptr) {}
    void push(const T& data);
    T pop();
};

template<typename T>
T TPQueue<T>::pop() {
    if (head == NULL) {
        throw std::string("Empty!");
    } else {
        T data = head->value;
        Item* garbage = head->next;
        delete head;
        head = garbage;
        return data;
    }
}

template<typename T>
void TPQueue<T>::push(const T& data) {
    if (head == NULL) {
        Item* temp = new Item;
        temp->value = data;
        temp->next = NULL;
        head = temp;
    } else {
        Item* current = head;
        Item* garbage = new Item;
        uint64_t flag = 0;
        while (current) {
            if (current->value.prior < data.prior) {
                break;
            } else {
                current = current->next;
                flag++;
            }
        }
        if (flag == 0) {
            garbage->next = head;
            garbage->value = data;
            head = garbage;
        } else {
            current = head;
            for (int i = 1; i < flag; i++) {
                current = current->next;
            }
            garbage->next = current->next;
            garbage->value = data;
            current->next = garbage;
        }
    }
}

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
