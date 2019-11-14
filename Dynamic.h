//
// Created by dawid on 11.11.2019.
//

#ifndef PEA_DYNAMIC_H
#define PEA_DYNAMIC_H

#include "Matrix.h"
#include "Solution.h"
#include <climits>
#include <vector>

class Dynamic{
public:
    Dynamic(const Matrix &matrix);

    Solution dynamic(int, vector<int>);

private:
    const Matrix& matrix;
};

#endif //PEA_DYNAMIC_H
