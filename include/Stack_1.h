#ifndef LAB_05_STACK_STACK_1_H
#define LAB_05_STACK_STACK_1_H

#include <stdexcept>
#include "Stack_object.h"

template <typename T>
class Stack_1
{
public:
    Stack_1(){
        Entry = nullptr;
    }
    Stack_1<T>(Stack_1<T>& tmp) = delete;
    Stack_1<T>(Stack_1<T>&& tmp) noexcept {
        Entry = tmp.Entry;
        tmp.Entry = nullptr;
    }
    ~Stack_1(){
        while (Entry != nullptr)
            pop();
    }
public:
    void push(T&& value){
        if(Entry == nullptr) {
            Entry = new Stack_object<T>(std::forward<T>(value));
        }
        else{
            auto* tmp = new Stack_object<T>(std::forward<T>(value));
            tmp -> SetPrevious(Entry);
            Entry = tmp;
        }
    }
    void push(T& value){
        if(Entry == nullptr) {
            Entry = new Stack_object<T>(value);
        }
        else{
            auto* tmp = new Stack_object<T>(value);
            tmp -> SetPrevious(Entry);
            Entry = tmp;
        }
    }
    void pop(){
        if(Entry != nullptr) {
            Stack_object<T>* tmp = Entry->GetPrevious();
            delete Entry;
            Entry = tmp;
        }else{
            throw std::runtime_error("Stack is empty");
        }
    }
    const T& head() const{
      if(Entry != nullptr) {
        const T& ret = Entry->GetValue();
        return ret;
      } else{
        throw std::runtime_error("Stack is empty");
      }
    };

private:
    Stack_object<T>* Entry;
};
#endif //LAB_05_STACK_STACK_1_H
