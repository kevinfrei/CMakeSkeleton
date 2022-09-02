# This is a "configuration only" library:
# the point of the stuff is to set a number of toolchain configuration bits
# for use by 'clients'. So basically, everything it does is exported as INTERFACE stuff

cmake_minimum_required(VERSION 3.12)

# Name the project, because...
project(ConfigInfo VERSION 1.0.0)

add_library(configNoRTTI INTERFACE)

# Any #define's go in here:
target_compile_definitions(
  configNoRTTI
  INTERFACE
  CONFIG_DATA=123
)
# If we need any compilation features, put them here
# target_compile_features(configInfo INTERFACE )
# And additional compilation flags go in here:
if (WIN32) 
  target_compile_options(configNoRTTI INTERFACE $<$<COMPILE_LANGUAGE:CXX>:/GR->)
else()
  target_compile_options(configNoRTTI INTERFACE $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>)
endif()