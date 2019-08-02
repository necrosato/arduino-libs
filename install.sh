#!/bin/bash

set -e

SCRIPTPATH="$(cd "$(dirname "$0")"; pwd -P)"
TARGETS=()

append_target() {
  TARGETS+=("$1")
}

install_target() {
  if [[ ! -e "$ARDUINO_LIBS/$1" ]]; then
    ln -s "$SCRIPTPATH/$1" "$ARDUINO_LIBS/$1"
  fi
}

uninstall_target() {
  if [[ -e "$ARDUINO_LIBS/$1" ]]; then
    rm "$ARDUINO_LIBS/$1"
  fi
}

while getopts "hd:ul:" opt; do
  case $opt in
    h )
      echo "Install or uninstall necrosato's arduino libraries."
      echo "By default all libraries are targeted but one can specify the exact libraries to target."
      echo "-h : Display this help message."
      echo "-d : The directory of the arduino 3rd party libraries."
      echo "-u : Unisntall the target libraries."
      echo "-l : Name of a library to target. This option may be passed multiple times."
      echo "     If not given then all libraries are tergeted."
      exit 0
      ;;
    d )
      ARDUINO_LIBS="$OPTARG"
      ;;
    u )
      UNINSTALL="true"
      ;;
    l )
      TARGETS+=("$(basename "$OPTARG")")
      if [[ "$(find "$SCRIPTPATH" -iname "${TARGETS[-1]}")" == "" ]]; then
        echo "${TARGETS[-1]} is not a valid library."
        exit 1
      fi
      ;;
  esac
done

if [[ "$ARDUINO_LIBS" == "" ]]; then
  echo "Must supply install directory."
  exit 1;
fi

# Append targets from the script path
if [[ "${#TARGETS[@]}" == "0" ]]; then
  while read lib; do
    append_target "$lib"
  done < <(find "$SCRIPTPATH" -maxdepth 1 ! -path "$SCRIPTPATH" ! -path "$SCRIPTPATH/.git" -type d -print0 | sort -z | xargs -0 -n1 basename)
fi

# Install/uninstall each target
for ((i = 0; i < ${#TARGETS[@]}; i++)); do
  if [[ "$UNINSTALL" == "true" ]]; then
    uninstall_target "${TARGETS[$i]}"
  else
    install_target "${TARGETS[$i]}"
  fi
done
