//
// Created by dawid on 11.11.2019.
//

#include "Dynamic.h"

Dynamic::Dynamic(const Matrix &matrix) : matrix(matrix){

}

using namespace std;

/*Solution Dynamic::dynamic(int k, vector<int> s) {

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
}*/

pair<vector<int>, int>  Dynamic::dynamic(int k, vector<int> s) {

    vector<int> path;

    if (s.empty()) {
        path.push_back(k);
        return make_pair(path, matrix[k][0]);
    }

    int min = INT_MAX;

    for(int i=0;i<s.size();i++){
        int first = s[i];
        s.erase(s.begin() + i);
        pair<vector<int>, int> pairCandidate = dynamic(first, s);
        int minCandidate = matrix[k][first] + pairCandidate.second;
        vector<int> pathCandidate;
        for(int e : pairCandidate.first)
            pathCandidate.push_back(e);
        pathCandidate.push_back(k);
        if(minCandidate<min) {
            min = minCandidate;
            path.clear();
            for(int j=0;j<pathCandidate.size();j++)
                path.push_back(pathCandidate[j]);
        }
        s.insert(s.begin(), first);
    }
    return make_pair(path, min);
}