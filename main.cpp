#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <getopt.h>
#include <fstream>
#include <set>

template<typename T, typename Key>
bool key_exists(const T &container, const Key &key);

void countRepeatedValue(std::vector<std::string> &vector);

void printVector(const std::vector<std::string>& vector);

void printOnlyRepeatedValue(std::vector<std::string>& vector);

void printHelp();

int main(int argc, char **argv) {
    std::vector<std::string> stringVector;
    std::map<std::string, std::string> mapOption{};
    int options, optionIndex = 0;
    static struct option $longOptions[] = {
            {"unique",      no_argument,       nullptr, 'u'},
            {"repeated",    no_argument,       nullptr, 'd'},
            {"count",       no_argument,       nullptr, 'c'},
            {"help",        no_argument,       nullptr, 'h'},
    };

    while ((options = getopt_long(argc, argv, "udch",
                                  $longOptions, &optionIndex)) != -1) {
        switch (options) {
            case 'u':
                mapOption.insert(std::make_pair("u", "unique"));
                break;
            case 'd':
                mapOption.insert(std::make_pair("d", "repeated"));
                break;
            case 'c':
                mapOption.insert(std::make_pair("c", "count"));
                break;
            case 'h':
                mapOption.insert(std::make_pair("h", "help"));
                break;
            default: /* For invalid option e.g '?' */
                exit(EXIT_FAILURE);
        }
    }

    if (key_exists(mapOption, "h")) {
        printHelp();
    }

    if (argv[optind] != nullptr) {
        std::fstream file{argv[optind]};
        for (std::string line; getline(file, line);) {
            stringVector.emplace_back(line);
        }

        file.close();
    } else {
        for (std::string line; getline(std::cin, line);) {
            stringVector.emplace_back(line);
        }
    }

    if (key_exists(mapOption, "u")) {
        std::set<std::string> s(stringVector.begin(), stringVector.end());
        stringVector.assign(s.begin(), s.end());
    }

    if (key_exists(mapOption, "d")) {
        printOnlyRepeatedValue(stringVector);
    } else if (key_exists(mapOption, "c")) {
        countRepeatedValue(stringVector);
    } else {
        printVector(stringVector);
    }

    return EXIT_SUCCESS;
}

template<typename T, typename Key>
bool key_exists(const T &container, const Key &key) {
    return container.find(key) != end(container);
}

void printVector(const std::vector<std::string>& vector) {
    std::string string;
    for (const auto &value: vector) {
        if (value != string) {
            std::cout << value << std::endl;
        }

        string = value;
    }
}

void printOnlyRepeatedValue(std::vector<std::string>& vector) {
    std::string string;
    for (const auto &value : vector) {
        if (value == string) {
            std::cout << value << std::endl;
        }
    }
}

void countRepeatedValue(std::vector<std::string> &vector) {
    std::string string;
    std::map<std::string, int> secondMap;
    for (auto &vec : vector) {
        if (vec == string) {
            auto result = secondMap.insert(std::make_pair(vec, 2));
            if (!result.second) {
                result.first->second++;
            }
        }

        string = vec;
    }

    for (auto &item : secondMap) {
        std::cout << "\t" << item.second << " " << item.first << std::endl;
    }

    std::set<std::string> unique(vector.begin(), vector.end());
    for (const auto &item : unique) {
        std::cout << "\t" << 1 << " " << item << std::endl;
    }
}

void printHelp() {
    std::cout << "Usage: Program PATH [OPTION] < [FILE] ...\n"
            " or: Program PATH [OPTION] file name\n"
            "If you execute the uniq commands without "
            "the o parameter and a new text file,\n"
            "it simply uses the standard output.\n\n";

    std::cout << "Arguments required for long options "
            "are also required for short ones.\n"
            "Parameters:\n\n";
    std::cout <<"-c, --count                den Zeilen die Anzahl des Vorkommens voranstellen\n"
                "-d, --repeated             nur die doppelten Zeilen ausgeben\n"
                "-u, --unique               ausschließlich nur einmal vorkommende Zeilen ausgeben\n"
                "-h, --help                 Display this help and the program will be exited\n";

    std::cout << "\n\nif you have any problem executing "
            "commands you can open an issue \n"
            "in github or you can fix it yourself "
            "by opening a pull request \n\n"
            "Thanks for using my sort program :)\n";

    exit(EXIT_SUCCESS);
}
