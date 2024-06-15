#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> tail(const std::string& filename, size_t numLines) {
    std::vector<std::string> result;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return result;
    }

    // Find the end of the file
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();

    // Start reading the file from the end, line by line
    for (long long pos = fileSize - 1; pos >= 0 && numLines > 0; pos--) {
        file.seekg(static_cast<std::streampos>(pos), std::ios::beg); // Set the position relative to the beginning of the file
        char c;
        file.get(c);

        if (c == '\n') {
            numLines--;
        }
    }

    // Read the last few lines and store them in the result vector
    std::string line;
    while (std::getline(file, line)) {
        result.push_back(line);
    }

    // Close the file
    file.close();

    // Reverse the vector to get the lines in the correct order (last to first)
    std::reverse(result.begin(), result.end());

    return result;
}


int main() {
    std::string filename = "/Users/rajat/Downloads/ShareChat Candidate Prep Doc - Technical Guide MLE.docx";
    size_t numLines = 10; // You can change this to the number of lines you want to read

    std::vector<std::string> lastLines = tail(filename, numLines);

    // Print the last lines
    for (const auto& line : lastLines) {
        std::cout << line << std::endl;
    }

    return 0;
}
