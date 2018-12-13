#include <rib.h>
#include <cstdint>
#include <iomanip>
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
	uint32_t b = 0;			// Les 5 premiers chiffres du RIB
	uint32_t g = 0;			// Les 5 chiffres suivants du RIB
	uint64_t c = 0;			// Les 11 derniers chiffres du RIB
	uint32_t r = 0;			// Le reste de la division euclidienne de la clé RIB par 97
	uint32_t k = 0;			// La clé RIB

	std::cout << "Entrer le RIB (sans espaces ni tiret): ";

	try
	{
		ReadRIBOnStandartInput(b, g, c);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	/**
	 * @brief Calcul le reste de la division euclidienne de la clé RIB facteur 100 par 97:
	 * r = 100A % 97 où est est la clé RIB, qui est décomposé ici en 3 nombres b, g et c.
	 */
	r = (89 * b) % 97;
	r = (r + (15 * g)) % 97;
	r = (r + (3 * c)) % 97;

	k = 97 - r;						// Calcul la clé de contrôle du RIB

	std::cout << "La clé de contrôle de votre RIB est " << k << std::endl;
	std::cout << "Le RIB complet est donc ";
	std::cout << std::setfill('0') << std::setw(5) << b << "-";
	std::cout << std::setfill('0') << std::setw(5) << g << "-";
	std::cout << std::setfill('0') << std::setw(11) << c << " ";
	std::cout << std::setfill('0') << std::setw(2) << k << std::endl;
}
