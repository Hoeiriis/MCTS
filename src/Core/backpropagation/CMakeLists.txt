add_library(backpropagation BackupBase.cpp BasicBackup.cpp BackupNegamax.cpp)

target_include_directories(backpropagation
    PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(backpropagation Core Environment)
