cmake_minimum_required(VERSION 3.6)
project(veri_yapilari_ikinci_odev_auto)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp dugum.cpp dugum.h
        gezici.cpp gezici.h
        bagilliste.cpp bagilliste.h
        sayi.cpp sayi.h
        islem.cpp islem.h
        konsol.cpp konsol.h)
add_executable(veri_yapilari_ikinci_odev_auto ${SOURCE_FILES} dugum.cpp dugum.h
        gezici.cpp gezici.h
        bagilliste.cpp bagilliste.h
        sayi.cpp sayi.h
        islem.cpp islem.h
        konsol.cpp konsol.h)
