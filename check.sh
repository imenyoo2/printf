#!/bin/bash
./betty-style.pl *.c
echo "----- betty style check done -----"
./betty-doc.pl *.c
echo "----- betty style check done -----"
