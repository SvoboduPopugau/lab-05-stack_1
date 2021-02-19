#ifndef LAB_05_STACK_STACK_OBJECT_H
#define LAB_05_STACK_STACK_OBJECT_H

#include <algorithm>
template <typename T>
struct Stack_object{
    explicit Stack_object(const T& tmp){
        value = tmp;
        previous = nullptr;
    }
    explicit Stack_object(T&& tmp){
        value = std::move(tmp);
        previous = nullptr;
    }
    void SetPrevious(Stack_object* tmp){
        previous = tmp;
    }
    T& GetValue(){
        return value;
    }
    Stack_object* GetPrevious(){
        return previous;
    }
private:
    T value;
    Stack_object* previous;
};

#endif //LAB_05_STACK_STACK_OBJECT_H
