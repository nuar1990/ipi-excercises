# Erzeuge Bibliothek
add_library(simpletests simpletests.h pali.cpp)
# Ausführbares Programm ohne Quellen für Bibliothek
add_executable(${PROJECT_NAME} "${CMAKE_CURRENT_SOURCE_DIR}/palindrom.cc")

# Programm gegen die simpletest-Bibliotek linken
target_link_libraries(${PROJECT_NAME}  simpletests)

#Kopieren der Wörter
configure_file(words.txt "${INSTALL_DIR}/words.txt" COPYONLY)
install(TARGETS ${PROJECT_NAME} DESTINATION ${INSTALL_DIR})
