//
// Created by shiro on 10.11.19.
//

#ifndef PEA_BRANCHANDBOUND_H
#define PEA_BRANCHANDBOUND_H


#include <climits>
#include "Matrix.h"
#include "Solution.h"
#include <memory>

class BranchAndBound {
public:
    BranchAndBound(const Matrix &matrix);

    void find();

    Solution solution{};


private:
    const Matrix& matrix;

    // Stores the final minimum weight of shortest tour.
    int final_res = INT_MAX;
    // visited[] keeps track of the already visited nodes
    // in a particular path
    std::unique_ptr<bool> visited;


    void copyToFinal(int *curr_path);
    int firstMin(int i);
    int secondMin(int i);
    void TSPRec(int curr_bound, int curr_weight,
                int level, int curr_path[]);

};


#endif //PEA_BRANCHANDBOUND_H
