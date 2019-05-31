#include "JavaToken.h"

JavaToken::JavaToken()
{
	// Cria o aut�mato de tokens
	this->tokenDFA = new DFA();

	// Adiciona os estados b�sicos
	this->tokenDFA->addState("error", false);
	this->tokenDFA->addState("<q0>", false);
	this->tokenDFA->addState("<xS>", true);

	// Adiciona as transi��es para os caracteres de 'escape'
	this->tokenDFA->addTransition("<q0>", ' ', "<xS>");
	this->tokenDFA->addTransition("<q0>", '\t', "<xS>");
	this->tokenDFA->addTransition("<q0>", '\r', "<xS>");
	this->tokenDFA->addTransition("<q0>", '\n', "<xS>");
	this->tokenDFA->addTransition("<q0>", '\f', "<xS>");

	// Adiciona todas as transi��es do aut�mato
	this->tokenDFA->addTransition("<q0>", 'o', "<x15>");
	this->tokenDFA->addTransition("<q4>", 'o', "<q5>");
	this->tokenDFA->addTransition("<x15>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'o', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'o', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'u', "<x15>");
	this->tokenDFA->addTransition("<q5>", 'u', "<q6>");
	this->tokenDFA->addTransition("<x15>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'u', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'u', "<x15>");
	this->tokenDFA->addTransition("<q0>", 't', "<x15>");
	this->tokenDFA->addTransition("<q6>", 't', "<q7>");
	this->tokenDFA->addTransition("<x12>", 't', "<x13>");
	this->tokenDFA->addTransition("<x15>", 't', "<x15>");
	this->tokenDFA->addTransition("<x17>", 't', "<x15>");
	this->tokenDFA->addTransition("<x23>", 't', "<x15>");
	this->tokenDFA->addTransition("<x24>", 't', "<x25>");
	this->tokenDFA->addTransition("<x25>", 't', "<x15>");
	this->tokenDFA->addTransition("<x26>", 't', "<x15>");
	this->tokenDFA->addTransition("<x27>", 't', "<x15>");
	this->tokenDFA->addTransition("<q0>", '.', "<x1>");
	this->tokenDFA->addTransition("<q7>", '.', "<q8>");
	this->tokenDFA->addTransition("<x27>", '.', "<q4>");
	this->tokenDFA->addTransition("<q0>", 'p', "<x15>");
	this->tokenDFA->addTransition("<q8>", 'p', "<q9>");
	this->tokenDFA->addTransition("<x15>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'p', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'p', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'r', "<x15>");
	this->tokenDFA->addTransition("<q9>", 'r', "<x10>");
	this->tokenDFA->addTransition("<x15>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'r', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'r', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x10>", 'i', "<x11>");
	this->tokenDFA->addTransition("<x15>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'i', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'i', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x11>", 'n', "<x12>");
	this->tokenDFA->addTransition("<x14>", 'n', "<x1>");
	this->tokenDFA->addTransition("<x15>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'n', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'n', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x13>", 'l', "<x14>");
	this->tokenDFA->addTransition("<x15>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'l', "<x15>");
	this->tokenDFA->addTransition("<x15>", '_', "<x15>");
	this->tokenDFA->addTransition("<x17>", '_', "<x15>");
	this->tokenDFA->addTransition("<x23>", '_', "<x15>");
	this->tokenDFA->addTransition("<x24>", '_', "<x15>");
	this->tokenDFA->addTransition("<x25>", '_', "<x15>");
	this->tokenDFA->addTransition("<x26>", '_', "<x15>");
	this->tokenDFA->addTransition("<x27>", '_', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'a', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'a', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'b', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'b', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'c', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'c', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'd', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'd', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'e', "<x26>");
	this->tokenDFA->addTransition("<x26>", 'e', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'e', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'f', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'f', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'g', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'g', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'h', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'h', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'j', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'j', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'k', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'k', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'm', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'm', "<x27>");
	this->tokenDFA->addTransition("<x27>", 'm', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'q', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'q', "<x15>");
	this->tokenDFA->addTransition("<q0>", 's', "<x15>");
	this->tokenDFA->addTransition("<x15>", 's', "<x15>");
	this->tokenDFA->addTransition("<x17>", 's', "<x15>");
	this->tokenDFA->addTransition("<x23>", 's', "<x24>");
	this->tokenDFA->addTransition("<x24>", 's', "<x15>");
	this->tokenDFA->addTransition("<x25>", 's', "<x15>");
	this->tokenDFA->addTransition("<x26>", 's', "<x15>");
	this->tokenDFA->addTransition("<x27>", 's', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'v', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'v', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'w', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'w', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'x', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'x', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'y', "<x23>");
	this->tokenDFA->addTransition("<x23>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'y', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'y', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'z', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'z', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'A', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'A', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'B', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'B', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'C', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'C', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'D', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'D', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'E', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'E', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'F', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'F', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'G', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'G', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'H', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'H', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'I', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'I', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'J', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'J', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'K', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'K', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'L', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'L', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'M', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'M', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'N', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'N', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'O', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'O', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'P', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'P', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'Q', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'R', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'R', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'S', "<x17>");
	this->tokenDFA->addTransition("<x15>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'S', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'S', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'T', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'T', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'U', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'U', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'V', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'V', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'W', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'W', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'X', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'X', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'Y', "<x15>");
	this->tokenDFA->addTransition("<q0>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x15>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x17>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x23>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x24>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x25>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x26>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<x27>", 'Z', "<x15>");
	this->tokenDFA->addTransition("<q0>", '0', "<x16>");
	this->tokenDFA->addTransition("<x15>", '0', "<x15>");
	this->tokenDFA->addTransition("<x16>", '0', "<x16>");
	this->tokenDFA->addTransition("<x17>", '0', "<x15>");
	this->tokenDFA->addTransition("<x23>", '0', "<x15>");
	this->tokenDFA->addTransition("<x24>", '0', "<x15>");
	this->tokenDFA->addTransition("<x25>", '0', "<x15>");
	this->tokenDFA->addTransition("<x26>", '0', "<x15>");
	this->tokenDFA->addTransition("<x27>", '0', "<x15>");
	this->tokenDFA->addTransition("<q0>", '1', "<x16>");
	this->tokenDFA->addTransition("<x15>", '1', "<x15>");
	this->tokenDFA->addTransition("<x16>", '1', "<x16>");
	this->tokenDFA->addTransition("<x17>", '1', "<x15>");
	this->tokenDFA->addTransition("<x23>", '1', "<x15>");
	this->tokenDFA->addTransition("<x24>", '1', "<x15>");
	this->tokenDFA->addTransition("<x25>", '1', "<x15>");
	this->tokenDFA->addTransition("<x26>", '1', "<x15>");
	this->tokenDFA->addTransition("<x27>", '1', "<x15>");
	this->tokenDFA->addTransition("<q0>", '2', "<x16>");
	this->tokenDFA->addTransition("<x15>", '2', "<x15>");
	this->tokenDFA->addTransition("<x16>", '2', "<x16>");
	this->tokenDFA->addTransition("<x17>", '2', "<x15>");
	this->tokenDFA->addTransition("<x23>", '2', "<x15>");
	this->tokenDFA->addTransition("<x24>", '2', "<x15>");
	this->tokenDFA->addTransition("<x25>", '2', "<x15>");
	this->tokenDFA->addTransition("<x26>", '2', "<x15>");
	this->tokenDFA->addTransition("<x27>", '2', "<x15>");
	this->tokenDFA->addTransition("<q0>", '3', "<x16>");
	this->tokenDFA->addTransition("<x15>", '3', "<x15>");
	this->tokenDFA->addTransition("<x16>", '3', "<x16>");
	this->tokenDFA->addTransition("<x17>", '3', "<x15>");
	this->tokenDFA->addTransition("<x23>", '3', "<x15>");
	this->tokenDFA->addTransition("<x24>", '3', "<x15>");
	this->tokenDFA->addTransition("<x25>", '3', "<x15>");
	this->tokenDFA->addTransition("<x26>", '3', "<x15>");
	this->tokenDFA->addTransition("<x27>", '3', "<x15>");
	this->tokenDFA->addTransition("<q0>", '4', "<x16>");
	this->tokenDFA->addTransition("<x15>", '4', "<x15>");
	this->tokenDFA->addTransition("<x16>", '4', "<x16>");
	this->tokenDFA->addTransition("<x17>", '4', "<x15>");
	this->tokenDFA->addTransition("<x23>", '4', "<x15>");
	this->tokenDFA->addTransition("<x24>", '4', "<x15>");
	this->tokenDFA->addTransition("<x25>", '4', "<x15>");
	this->tokenDFA->addTransition("<x26>", '4', "<x15>");
	this->tokenDFA->addTransition("<x27>", '4', "<x15>");
	this->tokenDFA->addTransition("<q0>", '5', "<x16>");
	this->tokenDFA->addTransition("<x15>", '5', "<x15>");
	this->tokenDFA->addTransition("<x16>", '5', "<x16>");
	this->tokenDFA->addTransition("<x17>", '5', "<x15>");
	this->tokenDFA->addTransition("<x23>", '5', "<x15>");
	this->tokenDFA->addTransition("<x24>", '5', "<x15>");
	this->tokenDFA->addTransition("<x25>", '5', "<x15>");
	this->tokenDFA->addTransition("<x26>", '5', "<x15>");
	this->tokenDFA->addTransition("<x27>", '5', "<x15>");
	this->tokenDFA->addTransition("<q0>", '6', "<x16>");
	this->tokenDFA->addTransition("<x15>", '6', "<x15>");
	this->tokenDFA->addTransition("<x16>", '6', "<x16>");
	this->tokenDFA->addTransition("<x17>", '6', "<x15>");
	this->tokenDFA->addTransition("<x23>", '6', "<x15>");
	this->tokenDFA->addTransition("<x24>", '6', "<x15>");
	this->tokenDFA->addTransition("<x25>", '6', "<x15>");
	this->tokenDFA->addTransition("<x26>", '6', "<x15>");
	this->tokenDFA->addTransition("<x27>", '6', "<x15>");
	this->tokenDFA->addTransition("<q0>", '7', "<x16>");
	this->tokenDFA->addTransition("<x15>", '7', "<x15>");
	this->tokenDFA->addTransition("<x16>", '7', "<x16>");
	this->tokenDFA->addTransition("<x17>", '7', "<x15>");
	this->tokenDFA->addTransition("<x23>", '7', "<x15>");
	this->tokenDFA->addTransition("<x24>", '7', "<x15>");
	this->tokenDFA->addTransition("<x25>", '7', "<x15>");
	this->tokenDFA->addTransition("<x26>", '7', "<x15>");
	this->tokenDFA->addTransition("<x27>", '7', "<x15>");
	this->tokenDFA->addTransition("<q0>", '8', "<x16>");
	this->tokenDFA->addTransition("<x15>", '8', "<x15>");
	this->tokenDFA->addTransition("<x16>", '8', "<x16>");
	this->tokenDFA->addTransition("<x17>", '8', "<x15>");
	this->tokenDFA->addTransition("<x23>", '8', "<x15>");
	this->tokenDFA->addTransition("<x24>", '8', "<x15>");
	this->tokenDFA->addTransition("<x25>", '8', "<x15>");
	this->tokenDFA->addTransition("<x26>", '8', "<x15>");
	this->tokenDFA->addTransition("<x27>", '8', "<x15>");
	this->tokenDFA->addTransition("<q0>", '9', "<x16>");
	this->tokenDFA->addTransition("<x15>", '9', "<x15>");
	this->tokenDFA->addTransition("<x16>", '9', "<x16>");
	this->tokenDFA->addTransition("<x17>", '9', "<x15>");
	this->tokenDFA->addTransition("<x23>", '9', "<x15>");
	this->tokenDFA->addTransition("<x24>", '9', "<x15>");
	this->tokenDFA->addTransition("<x25>", '9', "<x15>");
	this->tokenDFA->addTransition("<x26>", '9', "<x15>");
	this->tokenDFA->addTransition("<x27>", '9', "<x15>");
	this->tokenDFA->addTransition("<q0>", '|', "<q3>");
	this->tokenDFA->addTransition("<q3>", '|', "<x1>");
	this->tokenDFA->addTransition("<q0>", '&', "<q2>");
	this->tokenDFA->addTransition("<q2>", '&', "<x1>");
	this->tokenDFA->addTransition("<q0>", '*', "<x1>");
	this->tokenDFA->addTransition("<q0>", '>', "<x18>");
	this->tokenDFA->addTransition("<x18>", '>', "<x1>");
	this->tokenDFA->addTransition("<q0>", '<', "<x19>");
	this->tokenDFA->addTransition("<x19>", '<', "<x1>");
	this->tokenDFA->addTransition("<q0>", '-', "<x20>");
	this->tokenDFA->addTransition("<x20>", '-', "<x1>");
	this->tokenDFA->addTransition("<q0>", '+', "<x21>");
	this->tokenDFA->addTransition("<x21>", '+', "<x1>");
	this->tokenDFA->addTransition("<q0>", '!', "<x22>");
	this->tokenDFA->addTransition("<q0>", '/', "<x1>");
	this->tokenDFA->addTransition("<q0>", '%', "<x1>");
	this->tokenDFA->addTransition("<q0>", '=', "<x22>");
	this->tokenDFA->addTransition("<x18>", '=', "<x1>");
	this->tokenDFA->addTransition("<x19>", '=', "<x1>");
	this->tokenDFA->addTransition("<x22>", '=', "<x1>");
	this->tokenDFA->addTransition("<q0>", '^', "<x1>");
	this->tokenDFA->addTransition("<q0>", '?', "<x1>");
	this->tokenDFA->addTransition("<q0>", ':', "<x1>");
	this->tokenDFA->addTransition("<q0>", ',', "<x1>");
	this->tokenDFA->addTransition("<q0>", ';', "<x1>");
	this->tokenDFA->addTransition("<q0>", '{', "<x1>");
	this->tokenDFA->addTransition("<q0>", '}', "<x1>");
	this->tokenDFA->addTransition("<q0>", '(', "<x1>");
	this->tokenDFA->addTransition("<q0>", ')', "<x1>");
	this->tokenDFA->addTransition("<q0>", '[', "<x1>");
	this->tokenDFA->addTransition("<q0>", ']', "<x1>");
}

JavaToken::~JavaToken()
{
	delete this->tokenDFA;
}

string JavaToken::getTokenType(string stateId, string lexeme)
{
	// Verifica se o estado � o terminal "<x1>"
	if (stateId == "<x1>")
	{
		// Faz a desambigua��o entre os tokens
		if ((lexeme == "*") || (lexeme == "/") || (lexeme == "%"))
			return "MATH_OP";
		else if ((lexeme == "<=") || (lexeme == ">=") || (lexeme == "==") || (lexeme == "!="))
			return "COMP_OP";
		else if ((lexeme == "&&") || (lexeme == "||"))
			return "LOGICAL_OP";
		else if (lexeme == "++")
			return "INC_OP";
		else if (lexeme == "--")
			return "DEC_OP";
		else if ((lexeme == "<<") || (lexeme == ">>"))
			return "BITWISE_OP";
		else if (lexeme == "^")
			return "MATH_OP";
		else if ((lexeme == "?") || (lexeme == ":"))
			return "COND_OP";
		else if (lexeme == ",")
			return "COMMA";
		else if (lexeme == ".")
			return "DOT";
		else if (lexeme == ";")
			return "SC";
		else if (lexeme == "{")
			return "LCB";
		else if (lexeme == "}")
			return "RCB";
		else if (lexeme == "(")
			return "LP";
		else if (lexeme == ")")
			return "RP";
		else if (lexeme == "[")
			return "LSB";
		else if (lexeme == "]")
			return "RSB";
		else
			return "SOUT";
	}
	else if (stateId == "<x15>") // Verifica se o estado � o terminal "<x15>"
	{
		// Faz a desambigua��o entre os tokens
		if (lexeme == "package")
			return "PACKAGE";
		else if (lexeme == "import")
			return "IMPORT";
		else if (lexeme == "class")
			return "CLASS";
		else if (lexeme == "interface")
			return "INTERFACE";
		else if (lexeme == "extends")
			return "EXTENDS";
		else if (lexeme == "implements")
			return "IMPLEMENTS";
		else if (lexeme == "this")
			return "THIS";
		else if (lexeme == "super")
			return "SUPER";
		else if (lexeme == "new")
			return "NEW";
		else if (lexeme == "null")
			return "NULL";
		else if (lexeme == "return")
			return "RETURN";
		else if ((lexeme == "public") || (lexeme == "private") || (lexeme == "protected")
			|| (lexeme == "static") || (lexeme == "final") || (lexeme == "abstract") 
			|| (lexeme == "const") || (lexeme == "synchronized") || (lexeme == "volatile") 
			|| (lexeme == "transient"))
			return "ACCESS_MODIFIER";
		else if ((lexeme == "int") || (lexeme == "long") || (lexeme == "short")
			|| (lexeme == "float") || (lexeme == "double") || (lexeme == "char")
			|| (lexeme == "String") || (lexeme == "boolean") || (lexeme == "byte")
			|| (lexeme == "enum") || (lexeme == "void"))
			return "TYPE";
		else if (lexeme == "instanceof")
			return "INSTANCEOF";
		else if (lexeme == "if")
			return "IF";
		else if (lexeme == "else")
			return "ELSE";
		else if (lexeme == "switch")
			return "SWITCH";
		else if (lexeme == "case")
			return "CASE";
		else if (lexeme == "default")
			return "DEFAULT";
		else if (lexeme == "assert")
			return "ASSERT";
		else if (lexeme == "for")
			return "FOR";
		else if (lexeme == "while")
			return "WHILE";
		else if (lexeme == "do")
			return "DO";
		else if (lexeme == "goto")
			return "GOTO";
		else if (lexeme == "continue")
			return "CONTINUE";
		else if (lexeme == "break")
			return "BREAK";
		else if (lexeme == "try")
			return "TRY";
		else if (lexeme == "catch")
			return "CATCH";
		else if (lexeme == "finally")
			return "FINALLY";
		else if (lexeme == "throws")
			return "THROWS";
		else if (lexeme == "throw")
			return "THROW";
		else if (lexeme == "native")
			return "NATIVE";
		else if (lexeme == "strictfp")
			return "STRICTFP";
		else if (lexeme == "main")
			return "MAIN";
		else if (lexeme == "length")
			return "LENGTH";
		else if ((lexeme == "true") || (lexeme == "false"))
			return "BOOLEAN";
		else
			return "ID";
	}
	else if (stateId == "<x16>") // Verifica se o estado � o terminal "<x16>"
	{
		// Retorna o token "INTEGER"
		return "INTEGER";
	}
	else if ((stateId == "<x18>") || (stateId == "<x19>")) // Verifica se o estado � o terminal "<x18>" ou "<x19"
	{
		// Retorna o token "COMP_OP"
		return "COMP_OP";
	}
	else if ((stateId == "<x20>") || (stateId == "<x21>")) // Verifica se o estado � o terminal "<x20>" ou "<x21>"
	{
		// Retorna o token "MATH_OP"
		return "MATH_OP";
	}
	else if (stateId == "<x22>") // Verifica se o estado � o terminal "<x22>"
	{
		// Faz a desambigua��o e retorna o token "ASSIGN" ou "LOGICAL_OP"
		if (lexeme == "=")
			return "ASSIGN";
		else
			return "LOGICAL_OP";
	}
	else
	{
		// Se n�o for nenhum dos casos, retorna token "INVALID"
		return "INVALID";
	}
}

string JavaToken::getNextState(string stateId, char transition)
{
	return tokenDFA->nextState(stateId, transition);
}

bool JavaToken::isTerminalState(string stateId)
{
	return tokenDFA->isTerminalState(stateId);
}