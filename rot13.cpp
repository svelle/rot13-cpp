#include <iostream>
#include <fstream>

int main() {
    std::string InputText;
    std::string line;
    std::ifstream InputFile;

    std::cout << "file to decipher with rot13: " << std::endl;
    getline(std::cin, InputText);
    InputFile.open(InputText);

    if (InputFile.is_open()) {
        while (getline(InputFile, line)) {
            for (char &i : line) {
                if (isalpha(i)) {
                    if (i >= 'a' && i <= 'm') {
                        i = i + 13;
                    } else if (i >= 'A' && i <= 'M') {
                        i = i + 13;
                    } else if (i > 'm' && i <= 'z') {
                        i = i - 13;
                    } else if (i > 'M' && i <= 'Z') {
                        i = i - 13;
                    }
                }
            }
            std::cout << line << std::endl;
        }
        InputFile.close();
    }
	return 0;
}
