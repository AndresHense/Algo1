project(cmake_generated)
cmake_minimum_required(VERSION 3.10)
set(INCROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
set(SRCROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
set(DIRROOT ${CMAKE_CURRENT_SOURCE_DIR}/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(OUT_NAME main)
set(CMAKE_CXX_FLAGS"${CMAKE_CXX_FLAGS} -Wall -g")
set(LIBS )
set(FILES_HEADER
	${INCROOT}/ejercicios.h
	${INCROOT}/cases.h
)
set(FILES_SRC
	${SRCROOT}/main.cpp
	${SRCROOT}/cases.cpp
	${SRCROOT}/ejercicios.cpp
)
set(FILES_DIR
	${DIRROOT}/
)
include_directories(${FILES_DIR})
add_executable(${OUT_NAME} ${FILES_SRC})
target_link_libraries(${OUT_NAME} ${LIBS})
