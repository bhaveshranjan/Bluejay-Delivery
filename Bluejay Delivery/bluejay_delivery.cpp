#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

// Function to split a string based on a delimiter
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }

    return result;
}

int main() {
    // Open the input file
    std::ifstream inputFile("employee_data.txt");

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream outputFile("output.txt");

    // Check if the file is opened successfully
    if (!outputFile.is_open()) {
        std::cerr << "Error opening the output file." << std::endl;
        return 1;
    }

    // Variables to store employee information
    std::string line;
    std::string name, position;
    int daysWorked;
    double hoursWorked;

    // Read each line from the file
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        // Read values from the current line
        iss >> name >> position >> daysWorked >> hoursWorked;

        // Condition a) Check for employees who worked for 7 consecutive days
        if (daysWorked == 7) {
            std::cout << "Employee: " << name << ", Position: " << position
                      << " worked for 7 consecutive days." << std::endl;
            outputFile << "Employee: " << name << ", Position: " << position
                       << " worked for 7 consecutive days." << std::endl;
        }

        // Condition b) Check for employees with less than 10 hours between shifts but greater than 1 hour
        if (hoursWorked < 10 && hoursWorked > 1) {
            std::cout << "Employee: " << name << ", Position: " << position
                      << " has less than 10 hours between shifts but greater than 1 hour." << std::endl;
            outputFile << "Employee: " << name << ", Position: " << position
                       << " has less than 10 hours between shifts but greater than 1 hour." << std::endl;
        }

        // Condition c) Check for employees who worked for more than 14 hours in a single shift
        if (hoursWorked > 14) {
            std::cout << "Employee: " << name << ", Position: " << position
                      << " worked for more than 14 hours in a single shift." << std::endl;
            outputFile << "Employee: " << name << ", Position: " << position
                       << " worked for more than 14 hours in a single shift." << std::endl;
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
