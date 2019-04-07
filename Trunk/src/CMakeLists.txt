set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/../lib)

set_option(BUILD_SHARED_LIBS TRUE BOOL "TRUE to build runtime as shared libraries, FALSE to build static libraries")

include_directories(${PROJECT_SOURCE_DIR}/Trunk/inc)
include_directories(${PROJECT_SOURCE_DIR}/IDCP/IDCP/inc)
include_directories(${PROJECT_SOURCE_DIR}/SFML/SFML/include)

link_libraries(IDCP sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

set(INC ${PROJECT_SOURCE_DIR}/Trunk/inc/IDC)
set(SRC ${PROJECT_SOURCE_DIR}/Trunk/src)

set(PROJECT_FILES
	${INC}/IDC.hpp
	${INC}/Game.hpp
	${INC}/Stream.hpp
	${SRC}/IDC.cpp
	${SRC}/Game.cpp
	${SRC}/Stream.cpp
	${SRC}/main.cpp
)

add_executable(IDC ${PROJECT_FILES})

set_property(TARGET IDC PROPERTY CXX_STANDARD 11)
set_property(TARGET IDC PROPERTY CXX_STANDARD_REQUIRED ON)