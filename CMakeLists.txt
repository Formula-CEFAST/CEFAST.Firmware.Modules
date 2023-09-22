add_library(modules INTERFACE)

list(APPEND MODULE_SOURCES
${CMAKE_CURRENT_SOURCE_DIR}/Src/Modules/Inc/Models/ReturnType.c
${CMAKE_CURRENT_SOURCE_DIR}/Src/Services/RingBufferService.c
${CMAKE_CURRENT_SOURCE_DIR}/Src/Services/TimerService.c
        )

target_sources(modules INTERFACE
   ${MODULE_SOURCES}
        )

target_include_directories(modules INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/Inc
        )

