#include "assetManager.h"

void AssetManager::loadAll()
{
	dirt = LoadTexture(RESOURCES_PATH "dirt.png");

	block_texture_atlas = LoadTexture(RESOURCES_PATH "textures.png");

	tree_texture_atlas = LoadTexture(RESOURCES_PATH "treetextures.png");

	frame = LoadTexture(RESOURCES_PATH "frame.png");

	tree_texture_atlas = LoadTexture(RESOURCES_PATH "treetextures.png");
}