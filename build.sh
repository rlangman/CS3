#!/bin/bash

case `uname` in
  Linux) g++ config_parser.cc webserver.cc -std=c++0x -lboost_system -g -Wall -o webserver;;
  *) echo "Unknown operating system";;
esac
