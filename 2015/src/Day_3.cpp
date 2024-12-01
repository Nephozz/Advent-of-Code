#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

pair<int,int> newPos(char dir, pair<int,int> pos_init) {
    pair<int,int> pos = pos_init;

    switch (dir) {
        case '^':
            pos.first++;
            break;
        case 'v':
            pos.first--;
            break;
        case '<':
            pos.second--;
            break;
        case '>':
            pos.second++;
            break;
    }

    return pos;
}

int main() {
    ifstream inputFile ("inputs/input_Day3");

    if (!inputFile.is_open()) {
        cout << "Error: File not found" << endl;
        return 1;
    }

    string line;

    getline(inputFile, line);
    pair<int,int> pos_santa = {0,0};
    pair<int,int> pos_robot = {0,0};

    set<pair<int,int>> santa;
    set<pair<int,int>> robot;

    santa.insert(pos_santa);

    for (int i = 0; i < line.length(); i += 2) {
        char dir_santa = line[i], dir_robot = line[i+1];

        pos_santa = newPos(dir_santa, pos_santa);
        pos_robot = newPos(dir_robot, pos_robot);

        santa.insert(pos_santa);
        robot.insert(pos_robot);
    }

    santa.insert(robot.begin(), robot.end());

    cout << santa.size() << endl;
}
