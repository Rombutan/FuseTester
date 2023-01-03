# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/rombutan/pico-sdk/tools/pioasm"
  "/home/rombutan/Documents/FuseTester/build/pioasm"
  "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm"
  "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/tmp"
  "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
  "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src"
  "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/rombutan/Documents/FuseTester/build/pico-sdk/src/rp2_common/cyw43_driver/pioasm/src/PioasmBuild-stamp${cfgdir}") # cfgdir has leading slash
endif()
