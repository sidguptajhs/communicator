#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "config/server.h"

using namespace std;

class Communicator {
public:
    int clientMode(char **configFile) {
        std::cout << "Running in Client Mode" << std::endl;
        return 0;
    }

    int serverMode(char **configFile) {
        std::cout << "Running in Server Mode" << std::endl;
        return 0;
    }
};


int main(int argc, char **argv) {
    vector<string> args(argv + 1, argv + argc);
    size_t n = std::find(args.begin(), args.end(), "--config") - args.begin();
    if (n < args.size()) {
        char *path = argv[n + 2];
        std::cout << "Welcome to Communicator!" << std::endl;
        std::cout << "Reading config from "<< path << std::endl;

        Communicator communicator;
        #ifdef COMMUNICATOR_CLIENT_MODE
        return communicator.clientMode(&path);
        #else //COMMUNICATOR_CLIENT_MODE
        return communicator.serverMode(&path);
        #endif //COMMUNICATOR_CLIENT_MODE
    } else {
        std::cout << "You need to specify a config file with --config !" << std::endl;
        return 1;
    }
}


