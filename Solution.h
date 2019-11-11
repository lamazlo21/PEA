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
    int value();
    void print();
    void clear();

private:
    std::vector<int> path;
    int _value;

};


#endif //PEA_SOLUTION_H
