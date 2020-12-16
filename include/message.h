#include "socket.h"

// Estructura de los mensajes
struct Message {
	std::array<char, 1024> text;	// Igual que "char text[1024]"
};
