# CMake para o executável magnetc_gui
# ===================================

add_executable(magnetc_gui
    src/main.cpp
)

# Adiciona os backends do ImGui (ex: para GLFW, OpenGL3, etc.)
# Você precisará adicionar os arquivos de backend do ImGui ao seu projeto
# Ex: src/imgui_impl_glfw.cpp, src/imgui_impl_opengl3.cpp
# target_sources(magnetc_gui PRIVATE
#     src/imgui_impl_glfw.cpp 
#     src/imgui_impl_opengl3.cpp
# )

# Vincula as bibliotecas necessárias.
# PRIVATE: Apenas o executável precisa delas, não são exportadas.
target_link_libraries(magnetc_gui
    PRIVATE
        magnetc_core # Nossa biblioteca de núcleo!
        imgui        # Biblioteca Dear ImGui
)