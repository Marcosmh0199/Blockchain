//***************************************************************************************/
//*    Title: BUILD A BLOCKCHAIN WITH C++
//*    Author: Nash, D
//*    Date: 2017
//*    Code version: 1.0
//*    Availability: https://davenash.com/2017/10/build-a-blockchain-with-c/
//***************************************************************************************/

#include "Blockchain.h"

using namespace std;
int main() {
	//Se recomienda no aumentar el nivel a mas de 4 para evitar prolongados tiempos de espera
	uint32_t nivelDificultad = 1;
	Blockchain bChain = Blockchain(nivelDificultad);
	
	cout << "Minando bloque 1...\n";
	bChain.addBlock(Bloque(1, "Informacion bloque 1"));
	
	cout << "Minando bloque 2...\n";
	bChain.addBlock(Bloque(2, "Informacion bloque 2"));
	
	cout << "Minando bloque 3...\n";
	bChain.addBlock(Bloque(3, "Informacion bloque 3"));
	
	return 0;
}
