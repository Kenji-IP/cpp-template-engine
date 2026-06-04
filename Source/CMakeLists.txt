project(EngineName)

file(GLOB_RECURSE EngineName_SRC CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(${PROJECT_NAME} SHARED ${EngineName_SRC})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/)

target_compile_definitions(${PROJECT_NAME} PRIVATE ENGINE_DLL_EXPORT)

if (WIN32)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ENGINE_PLATFORM_WINDOWS)
endif()

if (LINUX)
    target_compile_definitions(${PROJECT_NAME} PUBLIC ENGINE_PLATFORM_LINUX)
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