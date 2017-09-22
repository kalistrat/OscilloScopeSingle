cmake_minimum_required(VERSION 3.8)
project(OscilloScopeSingle)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.8.0\\5.8\\mingw53_32\\lib\\cmake")
set(CMAKE_AUTOMOC ON)

set(SOURCE_FILES main.cpp mainwindow.cpp mainwindow.h crc16_ccitt.cpp crc16_ccitt.h devcmd.cpp devcmd.h hdlc.cpp hdlc.h MySerialPort.cpp MySerialPort.h)
add_executable(OscilloScopeSingle ${SOURCE_FILES})

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.8.0\\5.8\\mingw53_32\\lib\\cmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)
qt5_use_modules(OscilloScopeSingle Core Widgets Gui SerialPort)