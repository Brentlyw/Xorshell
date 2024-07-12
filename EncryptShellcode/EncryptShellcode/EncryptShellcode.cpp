#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <stdexcept>

void xorEncryptDecrypt(std::vector<unsigned char>& data, unsigned char key) {
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= key;
    }
}
std::vector<unsigned char> parseShellcode(const std::string& shellcode) {
    std::vector<unsigned char> bytes;
    size_t len = shellcode.length();
    for (size_t i = 0; i < len; ++i) {
        if (shellcode[i] == '\\' && shellcode[i + 1] == 'x') {
            std::string byteStr = shellcode.substr(i + 2, 2);
            bytes.push_back(static_cast<unsigned char>(std::stoi(byteStr, nullptr, 16)));
            i += 3; //Skip the \x and the 2 hex digi
        }
    }
    return bytes;
}

int main() {
    //replace this with your actual shellcode
    std::string shellcodeInput =
        "";

    try {
        std::vector<unsigned char> shellcode = parseShellcode(shellcodeInput);

        unsigned char key = 0xAA; //key
        xorEncryptDecrypt(shellcode, key);
        std::cout << "Encrypted shellcode: \"";
        for (size_t i = 0; i < shellcode.size(); ++i) {
            std::cout << "\\x" << std::hex << std::setw(2) << std::setfill('0') << (int)shellcode[i];
        }
        std::cout << "\"" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
