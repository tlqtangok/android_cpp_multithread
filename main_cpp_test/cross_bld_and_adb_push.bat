rm -rf  a.out && clang++ -std=c++11 -pthread -pie main.cpp && adb push a.out /data/t 
