# MagNetC - CMakeLists.txt Raiz
# =================================

cmake_minimum_required(VERSION 3.16)

project(MagNetC VERSION 0.1.0 LANGUAGES CXX)

# --- Configurações Globais ---
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Para um executável standalone no Windows, evitamos a janela de console.
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
)

# --- Gerenciamento de Dependências ---

# Inclui o módulo FetchContent para buscar dependências em tempo de configuração.
include(FetchContent)

# Libsodium
FetchContent_Declare(
    libsodium
    GIT_REPOSITORY https://github.com/jedisct1/libsodium.git
    GIT_TAG 1.0.18-STABLE
)
FetchContent_MakeAvailable(libsodium)

# OpenDHT
FetchContent_Declare(
    opendht
    GIT_REPOSITORY https://github.com/savoirfairelinux/opendht.git
    GIT_TAG 2.4.6 # Use uma tag estável
)
FetchContent_MakeAvailable(opendht)

# Dear ImGui
FetchContent_Declare(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG v1.88 # Use uma tag estável
)
FetchContent_MakeAvailable(imgui)

# --- Subdiretórios do Projeto ---

# Adiciona o diretório do núcleo (que será compilado como uma biblioteca)
add_subdirectory(core)

# Adiciona o diretório da GUI (que será compilado como um executável)
add_subdirectory(gui)