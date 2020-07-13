/*
    Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
    0 : Empty cell
    1 : Cells have fresh oranges
    2 : Cells have rotten oranges

    So, we have to determine what is the minimum time required to rot all oranges. 
    A rotten orange at index [i,j] can rot other fresh orange 
    at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
    If it is impossible to rot every orange then simply return -1.
*/

bool are_all_oranges_rotten(vector<vector<int>> &a) {
    for(int i=0; i<a.size(); ++i) 
        for(int j=0; j<a[i].size(); ++j)
            if(a[i][j] == 1) return false;

    return true;
}

/* 
    Solution 1
    TC: O(MAX(r, c)*r*c)
    SC: O(r*c)
*/
int min_time_to_rot(vector<vector<int>> &a) {
    int time =  0;
    while(true) {
        if(are_all_oranges_rotten(a)) return time;

        queue<pair<int, int>> to_rot;

        for(int i=0; i<a.size(); ++i) {
            for(int j=0; j<a[i].size(); ++j) {
                if(a[i][j] == 2) {
                    if(i > 0 && a[i-1][j] == 1) to_rot.push({i-1, j});
                    if(i < a.size()-1 && a[i+1][j] == 1) to_rot.push({i+1, j});
                    if(j > 0 && a[i][j-1] == 1) to_rot.push({i, j-1});
                    if(j < a[i].size()-1 && a[i][j+1] == 1) to_rot.push({i, j+1});
                }
            }
        }

        if(to_rot.size() == 0) return -1;

        while(!to_rot.empty()) {
            pair<int, int> orange = to_rot.front();
            to_rot.pop();
            if(a[orange.first][orange.second] == 1) a[orange.first][orange.second] = 2;
        }

        ++time;
    }

    return -1;
}

/* 
    Solution 2
    TC: O(r*c)
    SC: O(r*c)
*/
int min_time_to_rot(vector<vector<int>> &a) {
    queue<pair<int, int>> to_rot;

    for(int i=0; i<a.size(); ++i)
        for(int j=0; j<a[i].size(); ++j) {
            if(a[i][j] == 2) {
                if(i > 0 && a[i-1][j] == 1) to_rot.push({i-1, j});
                if(i < a.size()-1 && a[i+1][j] == 1) to_rot.push({i+1, j});
                if(j > 0 && a[i][j-1] == 1) to_rot.push({i, j-1});
                if(j < a[i].size()-1 && a[i][j+1] == 1) to_rot.push({i, j+1});
            }
        }
        
    if(to_rot.size() == 0) return 0;

    to_rot.push({-1, -1});

    int time = 1;

    while(!to_rot.empty()) {
        int i = to_rot.front().first;
        int j = to_rot.front().second;
        to_rot.pop();

        if(i == -1) {
            if(!to_rot.empty()) {
                to_rot.push({-1, -1});
                ++time;
            }
            continue;
        }
        
        a[i][j] = 2;

        if(i > 0 && a[i-1][j] == 1) to_rot.push({i-1, j});
        if(i < a.size()-1 && a[i+1][j] == 1) to_rot.push({i+1, j});
        if(j > 0 && a[i][j-1] == 1) to_rot.push({i, j-1});
        if(j < a[i].size()-1 && a[i][j+1] == 1) to_rot.push({i, j+1});
    }

    return are_all_oranges_rotten(a) ? time : -1;
}