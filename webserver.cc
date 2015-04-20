/*
 * webserver.cc
 *
 *  Created on: Apr 18, 2015
 *      Author: rlangman
 */

#include <string>
#include <iostream>
#include <boost/asio.hpp>

#include "config_parser.h"

using namespace std;
using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./webserver <path to config file>\n");
        return 1;
    }

    NginxConfigParser config_parser;
    NginxConfig config;
    config_parser.Parse(argv[1], &config);

    int port_number = config.getPortNumber();

    if (port_number == -1) {
        cout << "Config file should only contain a port number" <<
                " (server->listen)" << endl;
        return 1;
    }



    return 0;
}



