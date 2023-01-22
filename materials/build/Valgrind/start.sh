#!/bin/bash

make s21_string.a
make valgrind
valgrind -q -s --trace-children=yes --track-origins=yes --leak-check=full ./test
