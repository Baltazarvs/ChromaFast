// Created by Baltazarus (Nitrocell). Used for ChromaFast

#ifndef HEX_DEC_H
#define HEX_DEC_H

#include <string>
#include <cmath>
#include <deque>
#include <algorithm>

namespace Baltazarus
{
    class HexDec
    {
    private:
        std::string input_value;
        int value_dec;
        int value_hex;
        bool bValueValid;

    public:
        HexDec(std::string hex_num) : input_value(hex_num), bValueValid(true)
        {
            std::transform(input_value.begin(), input_value.end(), input_value.begin(), ::tolower);
            for(std::string::iterator itr = input_value.begin(); itr != input_value.end(); ++itr)
            {
                if(!std::isalpha(*itr) && !std::isdigit(*itr))
                {
                    this->bValueValid = false;
                    return;
                }
                if(std::isalpha(*itr))
                {
                    int alph = (int)*itr;
                    if(alph != (int)'a' && alph != (int)'b' && alph != (int)'c' && alph != (int)'d' && alph != (int)'e' && alph != (int)'f')
                        this->bValueValid = false;
                }
            }
        }
        int ToDecimal()
        {
            int result = 0ll;
            std::deque<int> res16_vec;
            unsigned int exps = this->input_value.length();
            for(unsigned int i = 0u; i < exps; ++i)
                res16_vec.push_front(std::pow(16, i));  
            for(unsigned int i = 0u; i < exps; ++i)
            {
                int to_int = 0;
                if(std::isdigit(input_value[i]))
                    to_int = input_value[i] - '0';
                else if(std::isalpha(input_value[i]))
                {
                    switch(input_value[i])
                    {
                        case 'a':
                            to_int = 10;
                            break;
                        case 'b':
                            to_int = 11;
                            break;
                        case 'c':
                            to_int = 12;
                            break;
                        case 'd':
                            to_int = 13;
                            break;
                        case 'e':
                            to_int = 14;
                            break;
                        case 'f':
                            to_int = 15;
                            break;
                    }
                }
                result += to_int * res16_vec[i];
            }
            return result;
        }

        bool IsValid() const 
        {
            return this->bValueValid;
        }
    };
}

#endif