cmake_minimum_required (VERSION 3.6.1)

project (staticLib)

if (APPLE)
  # Do something for Mac
endif ()

if (WIN32)
  # Do something for Windows
endif()

# Use a list, so you can conditionally add stuff later...
# (Otherwise, you can just include the files directly)
set (STATICLIB_SOURCES
  "stat1.cpp"
  "stat2.cpp"
)
# Same thing here
# There are some useful macros that can be found on cmake's website
set (STATICLIB_INCLUDES "${PROJECT_SOURCE_DIR}/include")
set (STATICLIB_DEFINES "VERSION=\"1.3.1\"")

include_directories(${STATICLIB_INCLUDES} "${PROJECT_SOURCE_DIR}/impl-include")
add_library(staticLib STATIC ${STATICLIB_SOURCES})
# Any of the "PUBLIC" link libraries will be used by any
# dependent projects when they link...
# target_link_libraries(staticLib PUBLIC ${OTHER_LIBS})
set_target_properties(staticLib PROPERTIES
  COMPILE_DEFINITIONS "${STATICLIB_DEFINES}"
  OUTPUT_NAME demoStat
)
# You only need to install it if it's part of the final bits (SDK or something)
# install(TARGETS staticLib ARCHIVE DESTINATION lib)
