#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

void str_replace(std::string &str, std::string old, std::string repl)
{
        std::size_t start = 0;

        if (old.length() == 0)
                return;
        while (1)
        {
                start = str.find(old, start);
                if (start > str.length())
                        break;
                str.erase(start, old.length());
                str.insert(start, repl);
                start += repl.length();
        }
}

std::string read_file(std::string filepath)
{

        std::stringstream stream;
        std::ifstream file(filepath.c_str());

        if (!file.is_open())
        {
                std::cerr << "Error: " << filepath << ": " << std::strerror(errno) << "\n";
                exit(1);
        }
        stream << file.rdbuf();
        file.close();
        return (stream.str());
}

void write_file(std::string filepath, std::string content)
{
        std::ofstream file(filepath.c_str());

        if (!file.is_open())
        {
                std::cerr << "Error: " << filepath << ": " << std::strerror(errno) << "\n";
                exit(1);
        }
        file << content;
}

/**
 * simple_sed - open file replacing every occurrence of old with repl.
 *
 * @filepath: filepath of a file to open
 * @old: string that will be replaced
 * @repl: replacement string
 */
void simple_sed(std::string filepath, std::string old, std::string repl)
{
        std::string content = read_file(filepath);
        str_replace(content, old, repl);
        write_file(filepath + ".replace", content);
}

int main(int ac, char **av)
{
        if (ac != 4)
        {
                std::cerr << "Usage: " << av[0] << " <filename> <string> <replacement>\n";
                exit(1);
        }
        simple_sed(av[1], av[2], av[3]);
        return (0);
}
