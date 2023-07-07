#!/usr/bin/env bash


SCRIPT_PATH=$(readlink -f "$BASH_SOURCE")
SCRIPT_DIR=$(dirname "$SCRIPT_PATH")

cd ../..

git log -n 1 --pretty=format:"Current Used Branch/Commit: - %d - %H"

cd Build/VS

build_command="make -f $SCRIPT_DIR/Make/make_000.gmk TYP_OS=unix $1"

echo Executing Command: $build_command

$build_command

exit
