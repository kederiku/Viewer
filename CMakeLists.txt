CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)

PROJECT(id_sviewer)

SET(EXECUTABLE_OUTPUT_PATH .)

SET(CMAKE_CXX_FLAGS_DEBUG "-g3 -DD_ERRORS_ON")

SET(srcs src/main.cpp
	 src/FBXloader.cpp
	 src/window.cpp
	 src/func_event.cpp
	 src/render.cpp
	 src/node.cpp
	 src/mesh.cpp
	 src/debug.cpp
	 src/matrix.cpp)

FIND_PACKAGE(Threads REQUIRED)
INCLUDE_DIRECTORIES(include)
ADD_DEFINITIONS(-W -Wall -Werror -I/usr/include/GL -I/usr/include/GLTools)
ADD_EXECUTABLE(${CMAKE_PROJECT_NAME} ${srcs})
TARGET_LINK_LIBRARIES(${CMAKE_PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT} GL GLU glut gltools GLEW fbxsdk-2012.2d uuid dl rt)

IF (UNIX)
	ADD_CUSTOM_TARGET(distclean COMMENT "Distcleaning lib2D")
	ADD_CUSTOM_COMMAND(COMMAND rm ARGS -rf ${objs} ${EXECUTABLE_OUTPUT_PATH}/${CMAKE_PROJECT_NAME} TARGET distclean)

	ADD_CUSTOM_TARGET(rebuild COMMENT "Rebuilding lib2D")
	ADD_CUSTOM_COMMAND(COMMAND make ARGS distclean TARGET rebuild)
	ADD_CUSTOM_COMMAND(COMMAND make TARGET rebuild)

	ADD_CUSTOM_TARGET(release COMMENT "Releasing lib2D")
	ADD_CUSTOM_COMMAND(COMMAND cmake ARGS . -DCMAKE_BUILD_TYPE:STRING=Release TARGET release)
	ADD_CUSTOM_COMMAND(COMMAND make ARGS distclean TARGET release)
	ADD_CUSTOM_COMMAND(COMMAND make TARGET release)

	ADD_CUSTOM_TARGET(debug COMMENT "Debugging lib2D")
	ADD_CUSTOM_COMMAND(COMMAND cmake ARGS . -DCMAKE_BUILD_TYPE:STRING=Debug TARGET debug)
	ADD_CUSTOM_COMMAND(COMMAND make ARGS distclean TARGET debug)
	ADD_CUSTOM_COMMAND(COMMAND make TARGET debug)
ENDIF(UNIX)
