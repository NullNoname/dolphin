#!/bin/bash

# Written by Anti-Ultimate for creating an AppImage of the latest dolphin master
# Feel free to change this in any way

# Original codes:
# https://forums.dolphin-emu.org/Thread-dolphin-as-appimage-on-linux
# "build_new.sh" in https://drive.google.com/drive/folders/0B-tFnZC4LvDuXzBuM0Q2V2hSdTA

# Modified by NullNoname for 3.0
# This script assumes you're running Ubuntu 16.04 or its variants
# and all dependencies already installed (see Readme.txt)

# Get AppImage functions
wget -q https://github.com/probonopd/AppImages/raw/master/functions.sh -O ./functions.sh
. ./functions.sh

# Create the build directory
mkdir Build
cd Build

# Build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr -DCMAKE_BUILD_TYPE=Release
make -j5
make DESTDIR=dolphin-emu-3.0.AppDir install

cd dolphin-emu-3.0.AppDir

# Download the AppRun tool
get_apprun

# Copy and move dependencies
copy_deps
move_lib

# Do not bundle the blacklisted system libraries
delete_blacklisted

# We can't bundle the PulseAudio, otherwise the system fails to load libpulsecommon-8.0.so in Ubuntu 18.04
rm -v ./usr/lib/x86_64-linux-gnu/libpulse.so.0
rm -v ./usr/lib/x86_64-linux-gnu/libpulse-simple.so.0
rm -v ./usr/lib/x86_64-linux-gnu/pulseaudio/libpulsecommon-8.0.so

# Copy desktop file
cp ../../dolphin-emu-3.0.desktop dolphin-emu-3.0.desktop

# Copy icon
cp ../../Source/Core/DolphinWX/resources/Dolphin.xpm dolphin-emu-3.0.xpm

# Patch the binary so it won't look for the hardcoded /usr/share
patch_usr

# Generate the AppImage
cd ..
ARCH="x86_64"
APP="dolphin-emu-3.0"
VERSION="3.0"
generate_appimage
