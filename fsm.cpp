#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

std::vector<int32_t> move_bits(const std::string &input_seq);

int main(int argc, char const *argv[])
{
    auto out_seq = move_bits(argv[1]);
    
    std::copy(out_seq.begin(), out_seq.end(), std::ostream_iterator<int32_t>(std::cout, ""));
    
    std::cout << std::endl;

    return 0;
}

std::vector<int32_t> 
move_bits(const std::string &input_seq)
{
    int32_t CS = 0;         // curr state
    std::vector<int32_t> out;

    for (auto &inp : input_seq)
    {
        switch (CS)
        {
            case 0:
                if (inp == '0')   
                {
                    CS = 0;
                    out.push_back(0);
                }
                else   
                {
                    CS = 1;
                    out.push_back(0);
                }      
                break;
            case 1:
                if (inp == '0') 
                {
                    CS = 7;
                    out.push_back(0);
                }
                else 
                {
                    CS = 2;
                    out.push_back(0);
                }
                break;
            case 2:
                if (inp == '0') 
                {
                    CS = 4;
                    out.push_back(0);
                }
                else 
                {
                    CS = 3;
                    out.push_back(0);
                }
                break;
            case 3:
                if (inp == '0') 
                {
                    CS = 4;
                    out.push_back(1);
                }
                else 
                {
                    CS = 3;
                    out.push_back(1);
                }
                break;
            case 4:
                if (inp == '0') 
                {
                    CS = 5;
                    out.push_back(1);
                }
                else 
                {
                    CS = 6;
                    out.push_back(1);
                }
                break;
            case 5:
                if (inp == '0') 
                {
                    CS = 0;
                    out.push_back(1);
                }
                else 
                {
                    CS = 1;
                    out.push_back(1);
                }
                break;
            case 6:
                if (inp == '0') 
                {
                    CS = 7;
                    out.push_back(1);
                }
                else 
                {
                    CS = 2;
                    out.push_back(1);
                }
                break;
            case 7:
                if (inp == '0') 
                {
                    CS = 5;
                    out.push_back(0);
                }
                else 
                {
                    CS = 6;
                    out.push_back(0);
                }
                break;
        }
    }

    return out;
}