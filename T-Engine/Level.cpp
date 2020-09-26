#include "Level.hpp"
#include <string>
#include <iostream>

Level::Level(std::string roomsDirectory, std::string textureDirectory, int tileRowLength, int roomRowLength): roomsDirectory(roomsDirectory),
	textureDirectory(textureDirectory),
	tileRowLength(tileRowLength),
	roomRowLength(roomRowLength)
	{ }

Level::~Level() {
}

void Level::Render() {
	int rectHeight = 32;
	int rectWidth = 64;

	int roomRows = 0;

	for (int i = 0; i < rooms.size(); i++) {
		std::vector<Layer> layers = rooms[i].layers;

		for (int l = 0; l < layers.size(); l++) {
			int tileRows = 0;

			for (int j = 0; j < layers[l].tiles.size(); j++) {
				std::string line = layers[l].tiles[j];

				for (int k = 0; k < line.length(); k++) {

					std::map<char, Texture>::iterator it = textureMap.textures.find(line[k]);
					
					if (it == textureMap.textures.end()) {
						continue;
					}

					Texture texture = it->second;

					SDL_Rect destination = texture.destination;
					destination.x = 550;
					destination.x += (rectWidth / 2) * ((i - (roomRows * roomRowLength)) * tileRowLength);
					destination.x -= (rectWidth / 2) * tileRows;
					destination.x += (rectWidth / 2) * k;
					destination.x -= (rectWidth / 2) * (roomRows * tileRowLength);

					destination.y = 150;
					destination.y += (rectHeight / 2) * tileRows;
					destination.y += (rectHeight / 2) * k;
					destination.y += (rectHeight / 2) * ((i - (roomRows * roomRowLength)) * tileRowLength);
					destination.y += (rectHeight / 2) * (roomRows * tileRowLength);

					SDL_RenderCopy(renderer, texture.texture, NULL, &destination);
				}

				tileRows++;
			}
		}

		if (i - (roomRows * roomRowLength) >= roomRowLength - 1) {
			roomRows++;
		}
	}
}