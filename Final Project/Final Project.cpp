#include <iostream>
#include "Final Project.h"
#include <string>
#include <vector>

std::string encryption(std::string plain_text){
    std::cout<<plain_text<<std::endl;

    std::string preprocessed_text = preprocessing(plain_text);

    std::string encrypted_string = processing(preprocessed_text);

    std::cout<<encrypted_string<<std::endl;

    return encrypted_string;
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

//helping function to get K
int preprocessing_helper(int string_length){
    //(L + 1 + K + 64) is a multiple of 512
    //basically, L+1+k+64 needs to be % 512 = 0

    //figure out what number to start at
    int starting = string_length + 8 + 64;

    int i = 0;
    bool found = false;

    //while haven't found it yet
    while (!found){
        //check if its a multiple
        if ((i + starting) % 512 == 0){
            found = true;
            return i;
        }
        i++; 
    }

    return 0;
}

//actual processing
std::string processing(std::string preprocessed_string){

    //Initialize hash values: (first 32 bits of the fractional parts of the square roots of the first 8 primes 2..19):
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    //Initialize array of round constants: (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311):
    uint32_t k[64] = {0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,
        0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
        0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,
        0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
        0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,
        0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
        0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,
        0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
        0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,
        0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
        0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,
        0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
        0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
        0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
        0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,
        0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};

    //break message into 512-bit chunks
    
    //for each chunk create a 64-entry message schedule array w[0..63] of 32-bit words
    for (int start = 0; start<preprocessed_string.size(); start+=64){
        //(The initial values in w[0..63] don't matter, so many implementations zero them here)
        uint32_t w[64] = {0};

        //copy chunk into first 16 words w[0..15] of the message schedule array
        for(int i = 0; i < 16; i++){
            w[i] = ((unsigned char)preprocessed_string[start + i*4] << 24) |
                   ((unsigned char)preprocessed_string[start + i*4 + 1] << 16) |
                   ((unsigned char)preprocessed_string[start + i*4 + 2] << 8) |
                   ((unsigned char)preprocessed_string[start + i*4 + 3]);
        }

        //Extend the first 16 words into the remaining 48 words w[16..63] of the message schedule array:
        for(int i = 16; i < 64; i++){
            uint32_t s0 = ((w[i-15] >> 7) | (w[i-15] << (32-7))) ^
                          ((w[i-15] >> 18) | (w[i-15] << (32-18))) ^
                          (w[i-15] >> 3);
            uint32_t s1 = ((w[i-2] >> 17) | (w[i-2] << (32-17))) ^
                          ((w[i-2] >> 19) | (w[i-2] << (32-19))) ^
                          (w[i-2] >> 10);
            w[i] = w[i-16] + s0 + w[i-7] + s1;
        }

        //Initialize working variables to current hash value:
        uint32_t a = h0;
        uint32_t b = h1;
        uint32_t c = h2;
        uint32_t d = h3;
        uint32_t e = h4;
        uint32_t f = h5;
        uint32_t g = h6;
        uint32_t h = h7;

        // Compression function main loop
        for(int i = 0; i < 64; i++){
            //rotate e
            uint32_t S1 = ((e >> 6) | (e << (32-6))) ^
                          ((e >> 11) | (e << (32-11))) ^
                          ((e >> 25) | (e << (32-25)));

            //mix e, f, and g
            uint32_t ch = (e & f) ^ ((~e) & g);

            //create temp variable
            uint32_t temp1 = h + S1 + ch + k[i] + w[i];

            //rotate a
            uint32_t S0 = ((a >> 2) | (a << (32-2))) ^
                          ((a >> 13) | (a << (32-13))) ^
                          ((a >> 22) | (a << (32-22)));

            //choose between a, b, and c
            uint32_t maj = (a & b) ^ (a & c) ^ (b & c);

            //get other temp variable used to modify a and e
            uint32_t temp2 = S0 + maj;

            //rotate and mutate
            h = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }
        
        // Add compressed chunk to current hash value
        h0 += a; 
        h1 += b; 
        h2 += c; 
        h3 += d;
        h4 += e; 
        h5 += f; 
        h6 += g; 
        h7 += h;
    }

    // Produce final digest in hex
    std::string digest = "";
    //make array to loop through
    uint32_t hs[8] = {h0,h1,h2,h3,h4,h5,h6,h7};
    //go through each hash value
    for(int i = 0; i < 8; i++){
        //get each set of hex digits
        for(int shift = 28; shift >= 0; shift -= 4){
            //used chat gpt again to help with this again because more big endian
            uint8_t chunk = (hs[i] >> shift) & 0xF;
            //convert to hex
            digest += (chunk < 10) ? ('0'+chunk) : ('a'+chunk-10);
        }
    }

    return digest;
}