#include<vector>
#include<queue>
using namespace std;


void traverse(int i , int j ,vector<vector<int>> matrix , vector<vector<bool>* visited> , vector<int> *sizes );
vector<vector<int>> getUnvisitedNeighbour (int i , int j , vector<vector<bool>> * visited , vector<vector<int>> matrix);

vector<int> riverSizes(vector<vector<int>> matrix) {
    vector<vector<bool>> visited (matrix.size(),vector<bool>(matrix[0].size(),false)); // intiliaze multidimesional array
    vector<int> sizes = {};
       for (int i = 0 ; i < matrix.size() ; ++i) {
           for (int j = 0 ; j < matrix[0].size() ; ++j) {
               if (visited[i][j]) {
                   continue;
               }
               else {
                   traverse(i,j,matrix,&visited,&sizes);
               }
           }
       }
    return sizes;
}

void traverse (int i , int j , vector<vector<int>> matrix , vector< vector<bool>> *visited , vector<int> *sizes) {
    int currentRiver = 0;
    queue<vector<int>> neighbours;
    vector<vector<int>> unvisitedNeighbours;
    neighbours.push({i,j});
    while (!neighbours.empty()) {
        vector<int> currentNode = neighbours.front();
        neighbours.pop();
        int row = currentNode[0];
        int col = currentNode[1];
        if (visited->at(row)[col]) {
            continue;
        }
        visited->at(row)[col] = true;
        if (!matrix[row][col]) {
            continue;
        }
        currentRiver++;
        unvisitedNeighbours = getUnvisitedNeighbour(row , col , visited);
        
        for (auto x : unvisitedNeighbours) {
            neighbours.push(x);
        }

    }
    if (currenRiver) {
        sizes->push_back(currentRiver)
    }

}

vector<vector<int>> getUnvisitedNeighbour(int i , int j , vector<vector<int>> matrix vector<vector<bool>> *visited) {

    vector<vector<int>> unvisited ;
    if (i > 0 && !visited->at(i-1)[j]) {
        unvisited.push_back({i-1,j});
    }
    if (j < matrix[0].size()-1 && !visited->at(i)[j+1]) {
        unvisited.push_back({i,j+1});
    }
    if (j > 0 && !visited->at(i)[j-1]) {
        unvisited.push_back({i,j-1});
    }
    if (i < matrix.size()-1 && !visited->at(i+1)[j]) {
        unvisited.push_back({i+1,j});
    }

    return unvisited;
}