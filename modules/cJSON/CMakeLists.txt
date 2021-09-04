aux_source_directory(./ SOURCES)
include_directories(./)

#set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

add_library(cjson ${SOURCES})
set_target_properties(cjson PROPERTIES PUBLIC_HEADER "cJSON.h")
INSTALL(TARGETS cjson
        LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/lib
        PUBLIC_HEADER DESTINATION ${PROJECT_SOURCE_DIR}/include
)