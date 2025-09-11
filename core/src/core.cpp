#include "magnetc/core.h"

// Inclui um header de uma dependência para testar se o include path está correto.
#include <sodium.h>

namespace magnetc {

std::string Core::getVersion() const {
    // Tenta inicializar a libsodium. É um ótimo teste para garantir que a
    // biblioteca foi vinculada corretamente ao nosso núcleo.
    if (sodium_init() < 0) {
        return "MagNetC Core (libsodium init failed!)";
    }
    
    return "MagNetC Core v0.1.0";
}

} // namespace magnetc