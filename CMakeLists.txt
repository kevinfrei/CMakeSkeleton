cmake_minimum_required (VERSION 3.6.1)
#Name the project, because...
project (DemoProject)

# The order of subdirectories only matters for dependencies
add_subdirectory (staticLib)
# For fun, the dynamicLib uses staticLib
add_subdirectory (dynamicLib)

#The remaining contents of this file could be put in another
#CMakeLists.txt file in a directory added using add_subdirectory if you want
#The only requirement is that is occurs *after* all the things it depends on

set (DEMO_SOURCES
  "demo1.cpp"
  "demo2.cpp"
)
# Same thing here
# There are some useful macros that can be found on cmake's website
set (DEMO_INCLUDES
  "${PROJECT_SOURCE_DIR}/include"
  "${dynamicLib_SOURCE_DIR}/include"
  "${staticLib_SOURCE_DIR}/include"
)
set (DEMO_DEFINES "VERSION=\"2.2.2\"")

include_directories(${DEMO_INCLUDES})
add_executable(demoProject ${DEMO_SOURCES})
# Any of the "PUBLIC" link libraries will be used by any
# dependent projects when they link...
target_link_libraries(demoProject dynamicLib staticLib)
set_target_properties(demoProject PROPERTIES
  COMPILE_DEFINITIONS "${DEMO_DEFINES}"
  OUTPUT_NAME demoBinary
)
# You only need to install it if it's part of the final bits (SDK or something)
install(TARGETS demoProject RUNTIME DESTINATION bin)
