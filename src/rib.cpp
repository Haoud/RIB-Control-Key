#include <rib.h>
#include <string>
#include <iostream>
#include <exception>

/**
 * @brief Permet de vérifier si le RIB est valide c,'est à dire s'il contient
 * 21 lettres et/ou chiffres.
 * Dans ce programme, la clé de contrôle du RIB n'est pas prise en compte car
 * on doit la calculer.
 *
 * @param rib La chaîne de caractère représentant le RIB
 * @return true Si le RIB est valide
 * @return false  Les RIB est invalide
 */
bool IsValidRIB(const std::string &rib)
{
	if(rib.length() != 21)
		return false;

	for(char c : rib)
		if(!isalnum(c) && !isalnum(c))
			return false;

	return true;
}

/**
 * @brief Permet de remplacer toutes les lettres dans le RIB par des
 * chiffres pour pouvoir calculer la clé de contrôle.
 * La fonction s'attend à ce que le RIB soit valide et qui ne contient
 * que des lettres et/ou des chiffres.
 *
 * @param rib Le RIB qui va être modifié (c'est une référence)
 */
void SubsituteRIBLetterByNumber(std::string &rib)
{
	char c = 0;
	size_t index = 0;
	unsigned int alphabetIndex = 0;

	for(index = 0; index < rib.length; index++)
	{
		c = rib[index];

		if(!isalpha(c))
			continue;

		if(islower(c))
			c = toupper(c);

		if(c == 'A' || c == 'J')
			rib[index] = '1';
		else if(c == 'B' || c == 'K' || c == 'S')
			rib[index] = '2';
		else if(c == 'C' || c == 'L' || c == 'T')
			rib[index] = '3';
		else if(c == 'D' || c == 'M' || c == 'U')
			rib[index] = '4';
		else if(c == 'E' || c == 'N' || c == 'V')
			rib[index] = '5';
		else if(c == 'F' || c == 'O' || c == 'W')
			rib[index] = '6';
		else if(c == 'G' || c == 'P' || c == 'X')
			rib[index] = '7';
		else if(c == 'H' || c == 'Q' || c == 'Y')
			rib[index] = '8';
		else if(c == 'I' || c == 'R' || c == 'Z')
			rib[index] = '9';
	}
}

/**
 * @brief Permet le lire le RIB sur l'entrée standart et d'en extraire
 * les informations utiles.
 *
 * @note Peut lancer des exceptions si le RIB entré par l'utilisateur
 * est invalide
 *
 * @param b Les 5er chiffres du RIB
 * @param g Les 5 chiffres suivant
 * @param c Les 11 derniers chiffres (sans la clé de controle)
 */
void ReadRIBOnStandartInput(uint32_t &b, uint32_t &g, uint64_t &c)
{
	std::string rib = "";
	std::string bstring = "";
	std::string gstring = "";
	std::string cstring = "";

	std::cin >> rib;							// Lit le RIB

	if(!IsValidRIB(rib))						// Si le RIB n'est pas valide
		throw std::exception();

	SubsituteRIBLetterByNumber(rib);			// Remplace les lettres du RIB par des chiffres
	std::cout << rib << std::endl;

	// Remplace les lettres par des nombres

	bstring = rib.substr(0, 5);
	gstring = rib.substr(5, 5);
	cstring = rib.substr(10, 11);

	b = std::stoul(bstring);
	g = std::stoul(gstring);
	c = std::stoul(cstring);
}