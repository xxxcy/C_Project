function(source_sub_directories_recursively ROOT_DIR)
    if (IS_DIRECTORY ${ROOT_DIR})
        #message("include dir: " ${ROOT_DIR})
        aux_source_directory(${ROOT_DIR} DIR_SOURCES)
        #message("DIR_SOURCES:" ${DIR_SOURCES})
        set(SOURCES_LIST ${DIR_SOURCES} CACHE INTERNAL "")
        include_directories(${ROOT_DIR})
    endif ()

    file(GLOB ALL_SUB RELATIVE ${ROOT_DIR} ${ROOT_DIR}/*)
    foreach (SUB ${ALL_SUB})
        if (IS_DIRECTORY ${ROOT_DIR}/${SUB})
            source_sub_directories_recursively(${ROOT_DIR}/${SUB})
        endif ()
    endforeach ()
endfunction()

function(include_sub_directories_recursively ROOT_DIR)
    if (IS_DIRECTORY ${ROOT_DIR})
        #message("include dir: " ${ROOT_DIR})
        #aux_source_directory(${ROOT_DIR} DIR_SOURCES)
        #message("DIR_SOURCES:" ${DIR_SOURCES})
        include_directories(${ROOT_DIR})
    endif ()

    file(GLOB ALL_SUB RELATIVE ${ROOT_DIR} ${ROOT_DIR}/*)
    foreach (SUB ${ALL_SUB})
        if (IS_DIRECTORY ${ROOT_DIR}/${SUB})
            include_sub_directories_recursively(${ROOT_DIR}/${SUB})
        endif ()
    endforeach ()

    #set(SOURCES_LIST ${DIR_SOURCES} CACHE STRING "")
endfunction()

### source files
SET(SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
#source_sub_directories_recursively(${PROJECT_SOURCE_DIR}/src)

aux_source_directory(${SOURCE_DIR} DIR_SOURCES)

file(GLOB ALL_SUB RELATIVE ${SOURCE_DIR} ${SOURCE_DIR}/*)
    foreach (SUB ${ALL_SUB})
        if (IS_DIRECTORY ${SOURCE_DIR}/${SUB})
            aux_source_directory(${SUB} DIR_SOURCES)
        endif ()
    endforeach ()


### head files
include_sub_directories_recursively(${PROJECT_SOURCE_DIR}/src)
include_sub_directories_recursively(${PROJECT_SOURCE_DIR}/include)


### debug message
#message("PROJECT_SOURCE_DIR:" ${PROJECT_SOURCE_DIR})
#message("PROJECT_BINARY_DIR:" ${PROJECT_BINARY_DIR})
#aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SOURCES)
#aux_source_directory(${PROJECT_SOURCE_DIR}/src/print_test DIR_SOURCES)
#message("DIR_SOURCES:" ${DIR_SOURCES})
#message("SOURCES_LIST:" ${SOURCES_LIST})

link_directories("${PROJECT_BINARY_DIR}/lib")
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")

#add_compile_options(-g -no-pie)

add_executable(main ${DIR_SOURCES})
target_link_libraries(main libcjson.a)