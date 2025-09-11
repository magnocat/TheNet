# CMake para a biblioteca magnetc_core
# =====================================

# Cria uma biblioteca estática chamada "magnetc_core".
# Usar uma biblioteca estática simplifica a criação de um executável standalone.
add_library(magnetc_core STATIC)

# Adiciona os arquivos-fonte à biblioteca.
target_sources(magnetc_core
    PRIVATE
        src/core.cpp
    PUBLIC
        # Headers públicos que a GUI precisará incluir
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/magnetc/core.h>
        $<INSTALL_INTERFACE:include/magnetc/core.h>
)

# Define os diretórios de include.
# PUBLIC: Diretórios que tanto o núcleo quanto os alvos que o consomem (a GUI) precisam.
target_include_directories(magnetc_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Vincula as dependências.
# PUBLIC: A GUI pode precisar de acesso transitivo aos headers dessas libs.
target_link_libraries(magnetc_core
    PUBLIC
        libsodium::libsodium
        opendht::dht
        # WebRTC será adicionado aqui quando configurado
        # webrtc::webrtc 
)