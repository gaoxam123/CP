#include "Bomb.h"

Bomb::Bomb (std::pair <int, int> pl_coords) {
    //setTex("../") -> import png
    index_map = pl_coords;
    srcRect.x = 0;
    srcRect.y = 0;
	srcRect.w = 32 * transformObject_b.scale;
	srcRect.h = 32 * transformObject_b.scale;

	destRect.x = index_map.first * 64;
	destRect.y = index_map.second * 64;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
	isPlaced = true;
}

void Bomb::setTex(const char *p_filename) {
    texture = TextureManager::loadTexture(p_filename);
}

void Bomb::update() {
    if(timeToExplode <= 0) isAlive = false;
    else timeToExplode --;
}

void Bomb::draw() {
    if(isPlaced) {
        TextureManager::draw(texture, srcRect, destRect);
        cout << "nigga" << endl;
    }
}

void Bomb::init () {}

bool Bomb::checkCollision(const SDL_Rect &a, const SDL_Rect &b) {}

Bomb::~Bomb() {}