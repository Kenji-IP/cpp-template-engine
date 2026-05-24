project(EngineName)

file(GLOB_RECURSE EngineName_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME} SHARED ${EngineName_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_DLL_EXPORT)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_PLATFORM_WINDOWS)
endif()

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        $<$<CONFIG:Debug>:ENGINE_BUILD_DEBUG>
        $<$<CONFIG:Release>:ENGINE_BUILD_RELEASE>
        $<$<CONFIG:Dist>:ENGINE_BUILD_DIST>
)

if (MSVC)
    target_compile_options(${PROJECT_NAME} PUBLIC /Zc:preprocessor) # for __VA_OPT__() MSVC only
endif()

message(STATUS "C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "C Compiler ID: ${CMAKE_C_COMPILER_ID}")
message(STATUS "C Compiler Version: ${CMAKE_C_COMPILER_VERSION}")

message(STATUS "CXX Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CXX Compiler ID: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CXX Compiler Version: ${CMAKE_CXX_COMPILER_VERSION}")