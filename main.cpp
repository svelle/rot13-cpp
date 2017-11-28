#include "main.h"

//TODO: implement checks for valid file names

int main(int argc, char *argv[]) {
    std::string InputFileName;
    std::string OutputFileName;

    if (argc == 1) {
        std::cout << "file to decipher with rot13: " << std::endl;
        getline(std::cin, InputFileName);

        std::cout << "file to write decrypted text in: " << std::endl;
        getline(std::cin, OutputFileName);

        DecryptRot13(InputFileName, OutputFileName);
    } else if (argc == 2) {
        std::cout << "file to write decrypted text in: " << std::endl;
        getline(std::cin, OutputFileName);

        DecryptRot13(argv[0], OutputFileName);
    } else if (argc == 3) {
        DecryptRot13(argv[0], argv[1]);
    } else {
        std::cout << "Error! Too many Arguments!" << std::endl;
    }
	return 0;
}

int DecryptRot13(const std::string &InputFileName, const std::string &OutputFileName) {
    std::ifstream FileToDecrypt;
    std::ofstream FileToWrite;
    std::string line;
    FileToDecrypt.open(InputFileName);
    FileToWrite.open(OutputFileName);
    if (FileToDecrypt.is_open()) {
        while (getline(FileToDecrypt, line)) {
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
            FileToWrite << line << std::endl;
        }
        FileToDecrypt.close();
        FileToWrite.close();
    }
}
