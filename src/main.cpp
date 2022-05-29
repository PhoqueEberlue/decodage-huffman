#include "huffman_decoding.h"

int main(int argc, char** argv) {
    if (argc == 3) {
        mainDecode(argv[1], argv[2]);
    }
    return 0;
}
