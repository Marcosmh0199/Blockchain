#include "Bloque.h"
#include "sha256.h"

Bloque::Bloque(std::uint32_t pNumeroIndice, const std::string &pInformacion){
	numeroIndice = pNumeroIndice;
	informacion = pInformacion;
	numeroTemporal = 0;
	tiempo = time(nullptr);
}

void Bloque::minarBloque(std::uint32_t pNivelDificultad){
	char charString[pNivelDificultad + 1];
	for(std::uint32_t i = 0; i < pNivelDificultad; ++i){
		charString[i] = '0';
	}
	charString[pNivelDificultad] = '\0'; //caracter de terminacion
	
	std::string str(charString);
	
	//valida si la cantidad de ceros iniciales es igual o mayor a pNivelDificultad
	//sino, se vuelve a crear el hash y se incrementa numeroTemporal hasta que el
	//bloque sea valido
	do 
	{
		numeroTemporal++;
		hash = calcularHash();	
	} while(hash.substr(0, pNivelDificultad) != str);
	
	std::cout << "Bloque minado: " << hash + "\n";
}

std::string Bloque::obtenerHash(){
	return hashAnterior;
}

inline std::string Bloque::calcularHash() const {
	std::stringstream ss;
	ss << numeroIndice << tiempo << informacion << numeroTemporal << hashAnterior; //
	
	return sha256(ss.str());
}
