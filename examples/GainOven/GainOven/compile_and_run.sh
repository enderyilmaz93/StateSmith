#!/bin/bash

# exit when any command fails
set -e

#  build user code generation program
dotnet build ../CodeGen/CodeGen.csproj /property:GenerateFullPaths=true /consoleloggerparameters:NoSummary

#  run user code generation program
dotnet ../CodeGen/bin/Debug/net6.0/CodeGen.dll

# compile code and run it
gcc -g -Wall -std=c11 main.c smtest.c gainOven.c app_timer.c stateFailure.c
./a.out
