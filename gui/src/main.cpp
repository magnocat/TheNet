// Para uma aplicação sem console no Windows, conforme definido no CMakeLists.txt
#if defined(_WIN32)
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include <magnetc/core.h> // API da nossa biblioteca de núcleo
#include <string>

// Ponto de entrada para aplicações de janela no Windows
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
    magnetc::Core core;
    std::string version_message = core.getVersion();

    // Mostra a versão em uma caixa de diálogo para confirmar que tudo funcionou.
    MessageBoxA(
        NULL,
        version_message.c_str(),
        "MagNetC Build Test",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;
}