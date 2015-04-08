#pragma once

#include <cstdint>
#include <map>
#include <array>
#include <string>


#define SWAP_R_AND_B(COLOR) ( ( COLOR & 0xFF ) << 16 ) | ( COLOR & 0xFF00 ) | ( ( COLOR & 0xFF0000 ) >> 16 )


class PaletteManager
{
    std::map<uint32_t, std::map<uint32_t, uint32_t>> palettes;

    std::array<std::array<uint32_t, 256>, 36> originals;

public:

    static uint32_t computeHighlightColor ( uint32_t color );

    void init ( uint32_t **originalPalettes );

    uint32_t get ( uint32_t paletteNumber, uint32_t colorNumber ) const;
    void set ( uint32_t paletteNumber, uint32_t colorNumber, uint32_t color );

    void clear ( uint32_t paletteNumber, uint32_t colorNumber );
    void clear ( uint32_t paletteNumber );
    void clear();

    bool save ( const std::string& file ) const;
    bool load ( const std::string& file );
};