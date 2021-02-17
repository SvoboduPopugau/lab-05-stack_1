#ifndef LAB_05_STACK_STACK_2_H
#define LAB_05_STACK_STACK_2_H

#include <stdexcept>
#include "Stack_object.h"
template <typename T>
class Stack_2{
    static_assert(std::is_move_constructible<T>::value);
    static_assert(!std::is_copy_constructible<T>::value);
public:
    //TODO: Написать конструкторы и дестркутор
public:
    template <typename ... Args>
    void push_emplace(Args&&... value){
        auto* tmp = new Stack_object(T(std::forward<Args>(value)...));
        if (Entry == nullptr){
            Entry = tmp;
        } else {
            tmp -> SetPrevious(Entry);
            Entry = tmp;
        }
    }
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
    const T& head() const{
        return Entry -> GetValue();
    }
    T pop(){
        if(Entry != nullptr) {
            Stack_object<T>* tmp = Entry->GetPrevious();
            auto ret = Entry -> GetValue();
            delete Entry;
            Entry = tmp;
            return ret;
        }else{
            throw std::runtime_error("Stack is empty");
        }
    }

private:
    Stack_object<T>* Entry;
};

#endif //LAB_05_STACK_STACK_2_H
