#!/bin/bash

while getopts "hd:" opt; do
  case $opt in
    h )
      echo "Install necrosato's arduino libraries."
      echo "-h : Display this help message."
      echo "-d : The directory of the arduino 3rd party libraries."
      exit 0
      ;;
    d )
      ARDUINO_LIBS="$OPTARG"
      ;;
  esac
done

if [[ "$ARDUINO_LIBS" == "" ]]; then
  echo "Must supply install directory."
  exit 1;
fi
