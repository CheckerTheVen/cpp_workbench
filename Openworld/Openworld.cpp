#include <fstream>
#include <iostream>

void buildWorld(char world[16][8]);

int main() {

	char world[16][8];

	try
	{
		buildWorld(world);
	}
	catch (const std::exception& e)
	{
		return -1;
		std::cout << e.what();
	}
	
	while (true) {

		for (int y = 0; y < 10; y++) {
			for (int x = 0; x < 18; x++) {
				if ((x == 0 || x == 17) && (y != 0 || y != 9)) { std::cout << '|'; }
				else if ((y == 0 || y == 9)) {}
			}
		}
	}

	return 0;
}

void buildWorld(char world[16][8]) {

	using namespace std;

	ifstream level_input;
	level_input.open("Level.txt");

	if (level_input.good()) {

		char input;
		for (int tile = 0; !level_input.eof(); tile++) {

			level_input >> input;
			world[tile % 16][tile / 16] = input == 0 ? ' ' : input;
		}
	}
	else {

		throw new exception("Unable to read \"Level.txt\"", 1);
	}

	return;
}

class world {

	char world_field[16][8];

public:
	world() {

		
	}

};