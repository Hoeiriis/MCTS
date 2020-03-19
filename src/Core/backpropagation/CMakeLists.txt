
add_library(backpropagation_objLib OBJECT)

target_include_directories(backpropagation_objLib
      PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)


target_sources(backpropagation_objLib
      PRIVATE
        BackupBase.cpp
        BasicBackup.cpp
        BackupNegamax.cpp)

Set_Multiple_PUBLIC_HEADER(backpropagation_objLib
        ${CMAKE_CURRENT_SOURCE_DIR}/include/BackupBase.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/BasicBackup.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/BackupNegamax.h)

target_link_libraries(backpropagation_objLib
        PRIVATE
          environments_objLib
          common_objLib)