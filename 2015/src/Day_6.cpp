#include <iostream>
#include <fstream>

using namespace std;

void turnOn(int grid[1000][1000], int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            grid[i][j]++;
        }
    }
}

void turnOff(int grid[1000][1000], int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            grid[i][j] = max(0, grid[i][j] - 1);
        }
    }
}

void toggle(int grid[1000][1000], int x1, int y1, int x2, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            grid[i][j] += 2;
        }
    }
}

int main() {
    ifstream file("inputs/day6");

    int grid[1000][1000] = {0};
    string line;
    int lights = 0;

    while (getline(file, line)) {
        int x1, y1, x2, y2;
        if (line.find("turn on") != string::npos) {
            sscanf(line.c_str(), "turn on %d,%d through %d,%d", &x1, &y1, &x2, &y2);
            turnOn(grid, x1, y1, x2, y2);
        } else if (line.find("turn off") != string::npos) {
            sscanf(line.c_str(), "turn off %d,%d through %d,%d", &x1, &y1, &x2, &y2);
            turnOff(grid, x1, y1, x2, y2);
        } else {
            sscanf(line.c_str(), "toggle %d,%d through %d,%d", &x1, &y1, &x2, &y2);
            toggle(grid, x1, y1, x2, y2);
        }
    }

    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            lights += grid[i][j];
        }
    }

    cout << "Answer: " << lights << endl;

    return 0;
}