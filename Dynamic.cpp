//
// Created by dawid on 11.11.2019.
//

#include "Dynamic.h"

Dynamic::Dynamic(const Matrix &matrix) : matrix(matrix){

}

using namespace std;

Solution Dynamic::dynamic(int k, vector<int> s) {

    int min = INT_MAX;
    Solution solution{};
    if (s.empty()) {
        solution.addNode(k, matrix[k][0]);
        return solution;
    }

    for(int i=0;i<s.size();i++){
        int first = s[i];
        s.erase(s.begin() + i);
        Solution solutionCandidate = dynamic(first, s);
        int minCandidate = matrix[k][first] + solutionCandidate.value();
        solution.addNode(k);
        if(minCandidate<min) {
            min=minCandidate;

        }
        s.insert(s.begin(), first);
    }
    return move(solution);
}