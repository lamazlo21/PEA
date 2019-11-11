//
// Created by shiro on 09.11.19.
//

#ifndef PEA_SOLUTION_H
#define PEA_SOLUTION_H
#include <vector>

class Solution {
public:
    Solution();
    void addNode(int node, int value);
    void addNode(int node);
    void setValue(int value);
    int nodeValue(int i);
    int pathLength();
    int value();
    void print();
    void printReverse();
    void clear();

private:
    std::vector<int> path;
    int _value;

};


#endif //PEA_SOLUTION_H
