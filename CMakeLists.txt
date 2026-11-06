cmake_minimum_required(VERSION 3.5)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
endif()

project(NoomiVita C)
include("$ENV{VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-q -O2 -std=gnu99")

add_executable(NoomiVita main.c)

target_link_libraries(NoomiVita
  vita2d
  SceDisplay_stub SceGxm_stub SceSysmodule_stub SceCtrl_stub
  SceCommonDialog_stub ScePgf_stub ScePvf_stub
  freetype png jpeg z m c
)

vita_create_self(NoomiVita.self NoomiVita)
vita_create_vpk(NoomiVita.vpk NOOM00001 NoomiVita.self NAME NoomiVita)
