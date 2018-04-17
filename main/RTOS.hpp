//
//  RTOS.hpp
//  main
//
//  Created by Michael Emperador on 4/9/18.
//  Copyright © 2018 Michael Emperador. All rights reserved.
//

#ifndef RTOS_hpp
#define RTOS_hpp
#include <stdio.h>
#include "Task.hpp"
#include <cassert>

class RTOS : public node {
    
    public:
    RTOS(node * &taskList, node *init_link = NULL, int prior = 0): node(init_link) {
            listHead = taskList;
            priority = prior;
        }
        node* Scheduler();
        //void wait();
        void startTask();
        void task();
        void startOS();
        int getReady() {
            return ready;
        }
        int getPriority() {
            return priority;
        }
    
        ~RTOS() { }
    
    private:
        node *listHead;
        node *cursor;
        node *taskPointer = nullptr;
        int base;
        int priority;
        int ready = 1;
        
};
#endif /* RTOS_hpp */
