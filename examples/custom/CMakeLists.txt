set(CUSTOM_WORLD_SOURCES
main.cpp
meta.cpp
storage.cpp
config.cpp
server.cpp
)

add_executable(custom ${CUSTOM_WORLD_SOURCES})
target_link_libraries(custom fruit)