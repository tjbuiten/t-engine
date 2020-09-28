#include "Level.hpp"
#include <string>
#include <iostream>

Level::Level(std::string roomsDirectory, std::string textureDirectory, int tileRowLength, int roomRowLength) : roomsDirectory(roomsDirectory),
textureDirectory(textureDirectory),
tileRowLength(tileRowLength),
roomRowLength(roomRowLength)
{ }

Level::~Level() {
}

void Level::Render() {
	player.Update();

	int rectHeight = 32;
	int rectWidth = 64;

	bool layerExists = true;
	int currentLayer = 0;

	bool playerRendered = false;

	while (layerExists) {
		layerExists = false;

		int roomRows = 0;

		for (int i = 0; i < rooms.size(); i++) {
			std::vector<Layer> layers = rooms[i].layers;

			if (layers.size() - 1 < currentLayer) {
				continue;
			}

			layerExists = true;

			int tileRows = 0;

			for (int j = 0; j < layers[currentLayer].tiles.size(); j++) {
				std::string line = layers[currentLayer].tiles[j];

				for (int k = 0; k < line.length(); k++) {
					SDL_Rect destination;
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

					if (((player.destination.y < destination.y + (rectHeight / 1.9) &&
						player.destination.y > destination.y - rectHeight) ||
						player.destination.y < 180) &&
						player.destination.x > destination.x - (rectWidth / 2) &&
						player.destination.x < destination.x + (rectWidth) &&
						currentLayer == 1 && !playerRendered) {
						player.Render();
						playerRendered = true;
					}

					std::map<char, Texture>::iterator it = textureMap.textures.find(line[k]);

					if (it == textureMap.textures.end()) {
						continue;
					}

					Texture texture = it->second;

					SDL_Rect textureDestination = texture.destination;
					textureDestination.x = destination.x;
					textureDestination.y = destination.y;

					SDL_RenderCopy(renderer, texture.texture, NULL, &textureDestination);
				}

				tileRows++;
			}

			if (i - (roomRows * roomRowLength) >= roomRowLength - 1) {
				roomRows++;
			}
		}

		currentLayer++;
	}
}