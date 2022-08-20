if(CONFIG_MY_DRIVER)
    target_include_directories(app PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/
    )

    target_sources(app PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/my_driver.c
    )
endif()
