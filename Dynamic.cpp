#include "Dynamic.h"

Dynamic::Dynamic(const Matrix &matrix) : matrix(matrix){

}

using namespace std;

// Złożoność pamięciowa = O(N)

Solution Dynamic::dynamic(int k, vector<int> s) {

    Solution solution{};

    if (s.empty()) {
        solution.setValue(matrix[k][0]);
        solution.addNode(k);
        return solution;
    }

    int min = INT_MAX;

    for(int i=0;i<s.size();i++){
        int first = s[i];
        s.erase(s.begin() + i);
        Solution solutionCandidate = dynamic(first, s);
        solutionCandidate.setValue(matrix[k][first] + solutionCandidate.value());
        solutionCandidate.addNode(k);
        if(solutionCandidate.value()<min) {
            min = solutionCandidate.value();
            solution.clear();
            solution.setValue(min);
            for(int j=0;j<solutionCandidate.pathLength();j++)
                solution.addNode(solutionCandidate.nodeValue(j));
        }
        s.insert(s.begin(), first);
    }
    return move(solution);
}
