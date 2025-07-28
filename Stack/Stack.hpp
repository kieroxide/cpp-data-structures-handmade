#pragma once
#include "../Vector/Vector.hpp"

template<typename Type>

class Stack{
    private:
        Vector<Type> data;
        
    public:
        // Push item to top of the stack
        void push(Type item){
            data.append(item);
        }

        //Pop item from top of the stack
        Type pop(){
            Type item = data.remove(data.length()-1);
            return item;
        }
};