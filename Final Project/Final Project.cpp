#include <iostream>
#include "Final Project.h"
#include <string>
#include <vector>

std::string encryption(std::string plain_text){
    std::cout<<plain_text<<std::endl;

    //Initialize hash values: (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19):
    std::string h0 = "0x6a09e667";
    std::string h1 = "0xbb67ae85";
    std::string h2 = "0x3c6ef372";
    std::string h3 = "0xa54ff53a";
    std::string h4 = "0x510e527f";
    std::string h5 = "0x9b05688c";
    std::string h6 = "0x1f83d9ab";
    std::string h7 = "0x5be0cd19";

    //Initialize array of round constants: (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311):

    std::vector<std::string> array = {"0x428a2f98", "0x71374491", "0xb5c0fbcf", "0xe9b5dba5", "0x3956c25b", "0x59f111f1", "0x923f82a4", "0xab1c5ed5",
   "0xd807aa98", "0x12835b01", "0x243185be", "0x550c7dc3", "0x72be5d74", "0x80deb1fe", "0x9bdc06a7", "0xc19bf174",
   "0xe49b69c1", "0xefbe4786", "0x0fc19dc6", "0x240ca1cc", "0x2de92c6f", "0x4a7484aa", "0x5cb0a9dc", "0x76f988da",
   "0x983e5152", "0xa831c66d", "0xb00327c8", "0xbf597fc7", "0xc6e00bf3", "0xd5a79147", "0x06ca6351", "0x14292967",
   "0x27b70a85", "0x2e1b2138", "0x4d2c6dfc", "0x53380d13", "0x650a7354", "0x766a0abb", "0x81c2c92e", "0x92722c85",
   "0xa2bfe8a1", "0xa81a664b", "0xc24b8b70", "0xc76c51a3", "0xd192e819", "0xd6990624", "0xf40e3585", "0x106aa070",
   "0x19a4c116", "0x1e376c08", "0x2748774c", "0x34b0bcb5", "0x391c0cb3", "0x4ed8aa4a", "0x5b9cca4f", "0x682e6ff3",
   "0x748f82ee", "0x78a5636f", "0x84c87814", "0x8cc70208", "0x90befffa", "0xa4506ceb", "0xbef9a3f7", "0xc67178f2"};

    std::string preprocessed_text = preprocessing(plain_text);

    for (unsigned char c : preprocessed_text) {
        printf("%02x ", c);
    }
    std::cout << std::endl;

    return preprocessed_text;
}

std::string preprocessing(std::string plain_text){

    //Pre-processing (Padding):
    //begin with the original message of length L bits
    uint64_t L = plain_text.length()*8ULL;

    //append a single '1' bit
    std::string padded_message = plain_text;
    padded_message.push_back(0x80);

    //append K '0' bits, where K is the minimum number >= 0 such that (L + 1 + K + 64) is a multiple of 512
    int K = preprocessing_helper(L);
    for(int i = 0; i < K/8; i ++){
        padded_message.push_back(0x00);
    }

    //append L as a 64-bit big-endian integer
    //used chatGPT for this because I had never heard of a big-ending integer let alone how to get one
    for (int i = 7; i >= 0; i--) {
        char byte = (L >> (i * 8)) & 0xFF;
        padded_message.push_back(byte);
    }

    return padded_message;

}

int preprocessing_helper(int string_length){
    //(L + 1 + K + 64) is a multiple of 512
    //basically, L+1+k+64 needs to be % 512 = 0

    //figure out what number to start at
    int starting = string_length + 8 + 64;

    int i = 0;
    bool found = false;

    while (!found){
        if ((i + starting) % 512 == 0){
            found = true;
            return i;
        }
        i++; 
    }


    return 0;
}