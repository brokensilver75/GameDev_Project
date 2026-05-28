#pragma once
#include <raylib.h>

struct AssetManager
{
	Texture2D dirt = {};
	Texture2D block_texture_atlas = {};
	Texture2D frame = {};

	Texture2D tree_texture_atlas = {};

	void loadAll();
};