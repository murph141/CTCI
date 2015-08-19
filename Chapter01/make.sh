#!/bin/bash

if [[ $# < 2 ]]
then
  echo "Usage $0 <command> <directory> [params]"
  exit
fi

if [[ ! -d "$2" ]]
then
  echo "Directory doesn't exist"
  exit
fi

make $1 DIRECTORY=$2 PARAMS=$3
