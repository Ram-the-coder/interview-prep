/*
    Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), 
    your task is to replace color of the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.
*/

/*
    My iterative Solution
*/
class Info {
public:
    int x, y, color;
    Info(int _x, int _y, int _color) : x(_x), y(_y), color(_color) {}
};

void flood_fill(vector<vector<int>> &a, int x, int y, int k) {

    if(a[x][y] == k) return;

    queue<Info> q;
    q.push(Info(x, y, a[x][y]));
    a[x][y] = k; // It is important to color it as soon as it is added to the list to ensure that it doesn't get added multiple times

    while(!q.empty()) {
        Info to_color = q.front();
        q.pop();

        // Up
        if(to_color.x > 0 && a[to_color.x-1][to_color.y] == to_color.color) {
            q.push(Info(to_color.x-1, to_color.y, to_color.color));
            a[to_color.x-1][to_color.y] = k;
        }

        // Down
        if(to_color.x < a.size()-1 && a[to_color.x+1][to_color.y] == to_color.color) {
            q.push(Info(to_color.x+1, to_color.y, to_color.color));
            a[to_color.x+1][to_color.y] = k;
        }

        // Left
        if(to_color.y > 0 && a[to_color.x][to_color.y-1] == to_color.color) {
            q.push(Info(to_color.x, to_color.y-1, to_color.color));
            a[to_color.x][to_color.y-1] = k;
        }

        // Right
        if(to_color.y < a[0].size()-1 && a[to_color.x][to_color.y+1] == to_color.color) {
            q.push(Info(to_color.x, to_color.y+1, to_color.color));
            a[to_color.x][to_color.y+1] = k;
        }
    }
}

/*
    Recursive GFG Solution
*/

// A recursive function to replace previous color 'prevC' at  '(x, y)'  
// and all surrounding pixels of (x, y) with new color 'newC' and 
void floodFillUtil(int screen[][N], int x, int y, int prevC, int newC) 
{ 
    // Base cases 
    if (x < 0 || x >= M || y < 0 || y >= N) 
        return; 
    if (screen[x][y] != prevC) 
        return; 
    if (screen[x][y] == newC)  
        return;  
  
    // Replace the color at (x, y) 
    screen[x][y] = newC; 
  
    // Recur for north, east, south and west 
    floodFillUtil(screen, x+1, y, prevC, newC); 
    floodFillUtil(screen, x-1, y, prevC, newC); 
    floodFillUtil(screen, x, y+1, prevC, newC); 
    floodFillUtil(screen, x, y-1, prevC, newC); 
} 
  
// It mainly finds the previous color on (x, y) and 
// calls floodFillUtil() 
void floodFill(int screen[][N], int x, int y, int newC) 
{ 
    int prevC = screen[x][y]; 
    floodFillUtil(screen, x, y, prevC, newC); 
} 