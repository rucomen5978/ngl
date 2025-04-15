install:
git clone https://github.com/rucomen5978/ngl
cd ngl

compile:
gcc main.c -o ngl -lm
clang main.c -o ngl -lm

run:
./ngl
