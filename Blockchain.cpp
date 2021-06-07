#include "Blockchain.h"

Blockchain::Blockchain(std::uint32_t pNivelDificultad){
	bloques.emplace_back(Bloque(0, "Primer Bloque"));
	nivelDificultad = pNivelDificultad;
}

void Blockchain::addBlock(Bloque pBloque){
	pBloque.hashAnterior = obtenerUltimoBloque().obtenerHash();
	pBloque.minarBloque(nivelDificultad);
	bloques.push_back(pBloque);
}

Bloque Blockchain::obtenerUltimoBloque() const {
	return bloques.back();
}
