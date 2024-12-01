#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
    vector<string> res;
    stringstream ss (str);
    string token;

    while (getline(ss, token, delimiter)) {
        res.push_back(token);
    }

    return res;
}

int calculateWrappingPaper(int h, int l, int w) {
    int a1, a2, a3;

    a1 = h*l;
    a2 = l*w;
    a3 = h*w;

    return 2*a1 + 2*a2 + 2*a3 + min(a1,min(a2,a3));
}

int calculateRibbon(int h, int l, int w) {
    int bow, perimeter;

    bow = h*l*w;

    int dim[3] = {h, l, w};

    sort(dim, dim + 3);

    perimeter = 2*dim[0] + 2*dim[1];

    return bow + perimeter;
}

int main() {
    std::ifstream inputFile ("inputs/input_Day2");


    if (!inputFile.is_open()) {
        cout << "Error: File not found" << endl;
        return 1;
    }

    vector<int> sizes;
    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            break;
        }

        vector<string> res = split(line, 'x');

        int h = stoi(res[0]);
        int l = stoi(res[1]);
        int w = stoi(res[2]);

        sizes.push_back(calculateRibbon(h, l, w));
    }


    int total = 0;
    for (int size : sizes) {
        total += size;
    }

    cout << "Total: " << total << endl;

    inputFile.close();

    return 0;
}
