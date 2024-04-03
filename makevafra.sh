#!/bin/bash
# makevafra.sh

# install packages if not already installed
unzip -v &> /dev/null || pacman -S --noconfirm unzip
make -v &> /dev/null || pacman -S --noconfirm make
g++ -v &> /dev/null || pacman -S --noconfirm mingw-w64-x86_64-gcc

cd src

# build Vafra executable
make clean
make build ARCH=x86-64-vnni512
mv vafra.exe vafra_v14.12.2_x86-64_vnni512_windows.exe
cp vafra.bmp vafra_v14.12.2_x86-64_vnni512_windows.bmp
make clean
make build ARCH=x86-64-avx512
mv vafra.exe vafra_v14.12.2_x86-64_avx512_windows.exe
cp vafra.bmp vafra_v14.12.2_x86-64_avx512_windows.bmp
make clean
make build ARCH=x86-64-avx2
mv vafra.exe vafra_v14.12.2_x86-64_avx2_windows.exe
cp vafra.bmp vafra_v14.12.2_x86-64_avx2_windows.bmp
make clean
make build ARCH=x86-64-sse41-popcnt
mv vafra.exe vafra_v14.12.2_x86-64_sse41popcnt_windows.exe
cp vafra.bmp vafra_v14.12.2_x86-64_sse41popcnt_windows.bmp
make clean
cd ..

