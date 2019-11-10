//
// Created by shiro on 09.11.19.
//

#ifndef PEA_BRUTEFORCE_H
#define PEA_BRUTEFORCE_H

#include "Matrix.h"
#include "Solution.h"


class BruteForce {
public:
    BruteForce(const Matrix &matrix);

    Solution bruteForceSwap();

private:
    const Matrix& matrix;

};


#endif //PEA_BRUTEFORCE_H
