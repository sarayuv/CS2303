#include "Rational.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
    // The output file is the last argument from the command line
    std::string outputFile = argv[argc - 1];
    std::ofstream of(outputFile);

    // For each input file, read each line and assign values to the numerators and denominators
    for (int i = 1; i < argc - 1; i++)
    {
        std::ifstream inputFile(argv[i]);
        std::string ln;

        while (std::getline(inputFile, ln))
        {
            std::string operation;

            // Initializing Rationals
            Rational a;
            Rational b;
            Rational answer;

            // Create the stream that input will go through
            std::istringstream stream(ln);
            stream >> a >> operation >> b;

            // Identify the operation and perform the calculation
            if (operation == "+")
            {
                answer = a + b;
            }
            else if (operation == "-")
            {
                answer = a - b;
            }
            else if (operation == "*")
            {
                answer = a * b;
            }
            else if (operation == "/")
            {
                answer = a / b;
            }
            else if (operation == ">")
            {
                answer = a > b;
            }
            else if (operation == "<")
            {
                answer = a < b;
            }
            else if (operation == ">=")
            {
                answer = (a >= b);
            }
            else if (operation == "<=")
            {
                answer = (a <= b);
            }
            else if (operation == "==")
            {
                answer = (a == b);
            }
            else if (operation == "!=")
            {
                answer = (a != b);
            }
            else
            {
                std::cout << "Error" << std::endl;
            }

            // if the operation is one of the below, print true or false according to the int 1 or 0
            if (operation == ">" || operation == ">=" || operation == "<" || operation == "<=" || operation == "==" || operation == "!=")
            {
                if (answer == 1)
                {
                    of << a << " " << operation << " " << b << "\t:\t"
                       << "true" << std::endl;
                }
                else
                {
                    of << a << " " << operation << " " << b << "\t:\t"
                       << "false" << std::endl;
                }
            }
            else
            {
                of << a << " " << operation << " " << b << "\t:\t" << answer << std::endl;
            }
        }

        inputFile.close();
    }

    of.close();

    return 0;
}
