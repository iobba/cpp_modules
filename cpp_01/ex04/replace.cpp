#include "replace.hpp"

void replace(std::string infile_name, std::string s1, std::string s2)
{
    // open infile
    std::string line;
    int pos;
    std::string outfile_name = infile_name + ".replace";
    std::ifstream infile(infile_name);
    if (!infile)
    {
        std::cerr << "Error opening infile" << std::endl;
        exit(1);
    }

    // open outfile
    std::ofstream outfile(outfile_name);
    if (!outfile)
    {
        std::cerr << "Error in creating the output file" << std::endl;
        infile.close();
        exit(1);
    }

    while (std::getline(infile, line))
    {
        pos = 0;
        while ((pos = line.find(s1, pos)) >= 0)
        {
            line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
            pos += s2.length();
        }
        outfile << line << std::endl;
    }

    infile.close();
    outfile.close();
}
