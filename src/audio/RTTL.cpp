#pragma once

#include "picosystem.hpp"
#include <cstring>
#include "../globals/Basic.cpp"

using namespace picosystem;

void play_rtttl(std::string song)
{
    char char_array[song.length() + 1];
    strcpy(char_array, song.c_str());
    char *p = char_array;
    unsigned char default_dur = 4;
    unsigned char default_oct = 6;
    int bpm = 63;
    int num;
    long wholenote, duration;
    unsigned char note, scale;

    while (*p != ':')
    {
        p++;
    }
    p++;
    if (*p == 'd')
    {
        p++;
        p++;
        num = 0;
        while (isdigit(*p))
        {
            num = (num * 10) + (*p++ - '0');
        }
        if (num > 0)
            default_dur = num;
        p++;
    }
    if (*p == 'o')
    {
        p++;
        p++;
        num = *p++ - '0';
        if (num >= 3 && num <= 7)
        {
            default_oct = num;
        }
        p++;
    }

    if (*p == 'b')
    {
        p++;
        p++;
        num = 0;
        while (isdigit(*p))
        {
            num = (num * 10) + (*p++ - '0');
        }
        bpm = num;
        p++;
    }

    wholenote = (60 * 1000L / bpm) * 4;

    while (*p)
    {
        num = 0;
        while (isdigit(*p))
        {
            num = (num * 10) + (*p++ - '0');
        }

        if (num)
            duration = wholenote / num;
        else
            duration = wholenote / default_dur;

        note = 0;

        switch (*p)
        {
        case 'c':
            note = 1;
            break;
        case 'd':
            note = 3;
            break;
        case 'e':
            note = 5;
            break;
        case 'f':
            note = 6;
            break;
        case 'g':
            note = 8;
            break;
        case 'a':
            note = 10;
            break;
        case 'b':
            note = 12;
            break;
        case 'p':
        default:
            note = 0;
        }

        p++;

        if (*p == '#')
        {
            note++;
            p++;
        }
        if (*p == '.')
        {
            duration += duration / 2;
            p++;
        }
        if (isdigit(*p))
        {
            scale = *p - '0';
            p++;
        }
        else
        {
            scale = default_oct;
        }
        if (*p == ',')
        {
            p++;
        }

        if (note)
        {
            play(piano, notes[(scale - 4) * 12 + note], duration * 0.9, volume);
            for (int8_t i = 0; i < 25; i++) {
                if (stopMusic) {
                    stopMusic = false;
                    return;
                }
                sleep(duration/25);
            }
        }
        else
        {
            for (int8_t i = 0; i < 25; i++) {
                if (stopMusic) {
                    stopMusic = false;
                    return;
                }
                sleep(duration/25);
            }
        }
    }
}