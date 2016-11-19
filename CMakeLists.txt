cmake_minimum_required(VERSION 3.6)
project(veri_yapilari_ikinci_odev_auto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
set(SOURCE_FILES src/main.cpp src/dugum.cpp include/dugum.h
        src/gezici.cpp include/gezici.h
        src/bagilliste.cpp include/bagilliste.h
        src/sayi.cpp include/sayi.h
        src/islem.cpp include/islem.h
        src/konsol.cpp include/konsol.h include/secim.h src/secim.cpp)
add_executable(veri_yapilari_ikinci_odev_auto ${SOURCE_FILES} src/dugum.cpp include/dugum.h
        src/gezici.cpp include/gezici.h
        src/bagilliste.cpp include/bagilliste.h
        src/sayi.cpp include/sayi.h
        src/islem.cpp include/islem.h
        src/konsol.cpp include/konsol.h)
