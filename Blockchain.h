#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <cstdint>
#include <vector>
#include "Bloque.h"

class Blockchain {
	public:
		Blockchain(std::uint32_t pNivelDificultad);
	
		void addBlock(Bloque pBloque);
	
	private:
		std::uint32_t nivelDificultad;
		std::vector<Bloque> bloques;
		
		Bloque obtenerUltimoBloque() const;
	
};

#endif //BLOCKCHAIN_H
