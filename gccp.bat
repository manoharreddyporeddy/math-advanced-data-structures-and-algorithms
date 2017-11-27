@echo off
echo compiling C++ using -ansi -pedantic-errors -Wall
g++ -ansi -pedantic-errors -Wall %1 %2 %3
