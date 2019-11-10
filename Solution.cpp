//
// Created by shiro on 09.11.19.
//

#include <iostream>
#include "Solution.h"


Solution::Solution() {}

void Solution::addNode(int node, int value) {
    path.push_back(node);
    _value+=value;
}

int Solution::value() {
    return _value;
}

void Solution::print() {
    for(auto e : path)
        std::cout<<e<<" ";

}
