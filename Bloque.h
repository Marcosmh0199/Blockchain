
#ifndef BLOCK_H
#define BLOCK_H

#include <cstdint>
#include <iostream>
#include <time.h>
#include <sstream>

class Bloque {
	public:
		std::string hashAnterior; //hash del bloque anterior
		
		Bloque(std::uint32_t pNumeroIndice, const std::string &pInformacion);
		
		std::string obtenerHash();
		
		void minarBloque(std::uint32_t pNivelDificultad);
		
	private:
		std::uint32_t numeroIndice;
		std::int64_t numeroTemporal;
		std::string informacion;
		std::string hash;
		time_t tiempo;
		
		/*
		* se utilzia const para que el metodo no pueda alterar las variables
		* dentro del bloque, replicando asi la inmutabilidad de la blockchain
		*/
		std::string calcularHash() const; 
		
};

#endif //BLOCK_H
