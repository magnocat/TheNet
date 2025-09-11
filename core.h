#pragma once

#include <string>

namespace magnetc {

/**
 * @class Core
 * @brief A classe principal que encapsula a lógica de negócio do MagNetC.
 */
class Core {
public:
    // Retorna a versão da biblioteca do núcleo.
    std::string getVersion() const;
};

} // namespace magnetc