#include "huffman_decoding.h"
#include <memory>

int main() {
    std::string path = "../texts/exemple_freq.txt";
    mainDecode(path);
    return 0;
}
