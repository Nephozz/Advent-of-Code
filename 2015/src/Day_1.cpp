#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inputFile ("inputs/input_Day1");
    
    std::string input;

    if (inputFile.is_open()) {
        int floor = 0;
        int iter = 1;
        int i;
        bool basement = false;
        char currentChar;
        while (inputFile.good()) {
            currentChar = inputFile.get();
            if (currentChar == '(') { 
                floor++;
            }
            else if (currentChar == ')') { 
                floor--;
                if (!basement && floor == -1) { 
                    basement = true;
                    i = iter;
                }
            }
            iter++;
            if (!basement && floor == -1) { 
                basement = true;
                i = iter;
            }
        }
        inputFile.close();

        std::cout << "Floor : " << floor << std::endl;
        std::cout << "First time in basement : " << i << std::endl;
    } else {
        std::cout << "Failed to open the file !" << std::endl;
    }

    return 0;
}