cmake_minimum_required(VERSION 3.13.1)

set(BOARD nrf5340dk_nrf5340_cpuapp)

set(DTC_OVERLAY_FILE
	my_driver.overlay
)

# the following line actually sets up the zephyr build system
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# set the project name and version
project(my_test_firmware LANGUAGES C VERSION 1.0.0)

include(${CMAKE_CURRENT_LIST_DIR}/drivers/my_driver/CMakeLists.txt)

# include directories
target_include_directories(app PRIVATE
    src/rpc_api_server
    src
)

# source files
target_sources(app PRIVATE
	src/main.c
)

