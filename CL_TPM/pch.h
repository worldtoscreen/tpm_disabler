#pragma once

#include <iostream>
#include <random>
#include <Windows.h>
#include <filesystem>

static volatile std::string watermark = "https://shop.cheatloverz.store";

std::string _xor( std::string toEncrypt ) {
    char key = '\'';
    std::string output = toEncrypt;

    for ( int i = 0; i < toEncrypt.size( ); i++ )
        output[i] = toEncrypt[i] ^ key;

    return output;
}