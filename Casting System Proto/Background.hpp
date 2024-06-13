#include <SFML/Graphics.hpp>
#include <vector>
#include "Textures.hpp"

class Background {
public:
    Background(Textures& textures);

    void drawTiles(sf::RenderWindow& window) {
        for (auto& tile : tiles) {
            window.draw(tile);
        }
    }

private:
    const int gridWidth = 15;
    const int gridHeight = 10;
    const sf::Vector2f originalTileSize = { 32.f, 32.f };
    const sf::Vector2f scaledTileSize = { 128.f, 128.f };
    sf::Sprite tile;
    std::vector<sf::Sprite> tiles; // Using RectangleShape for simplicity

    void initTiles(Textures& textures) {
        for (int y = 0; y < gridHeight; ++y) {
            for (int x = 0; x < gridWidth; ++x) {
                tile.setTexture(textures.loadRandomBackgroundTexture());
                tile.setScale(scaledTileSize.x / originalTileSize.x, scaledTileSize.y / originalTileSize.y);
                tile.setPosition(x * scaledTileSize.x, y * scaledTileSize.y);
                tiles.push_back(tile);
            }
        }
    }


};

