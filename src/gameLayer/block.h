#pragma once
#include <cstdint>

struct Block
{
	enum
	{
		air = 0,
		dirt,
		grassBlock,
		stone,
		grass,
		sand,
		sandRuby,
		sandStone,
		woodPlank,
		stoneBricks,
		clay,
		woodLog,
		leaves,
		copper,
		iron,
		gold,
		copperBlock,
		ironBlock,
		goldBlock,
		bricks,
		snow,
		ice,
		rubyBlock,
		platform,
		workBench,
		glass,
		furnace,
		painting,
		sappling,
		snowBlueRuby,
		blueRubyBlock,
		door,
		jar,
		table,
		wordrobe,
		bookShelf,
		snowBricks,
		iceTable,
		iceWordrobe,
		iceBookShelf,
		icePlatform,
		sandTable,
		sandWordrobe,
		sandBookShelf,
		sandPlatform,
		woodenChest,
		iceChest,
		sandChest,
		boneChest,
		boneBricks,
		boneBench,
		boneWordrobe,
		boneBookShelf,
		bonePlatform,

		BLOCKS_COUNT,

	};

	std::uint16_t type = 0;

	static constexpr const char* names[] = {
		"Air", "Dirt", "Grass Block", "Stone", "Grass", "Sand", "Sand Ruby", "Sand Stone",
		"Wood Plank", "Stone Bricks", "Clay", "Wood Log", "Leaves", "Copper", "Iron", "Gold",
		"Copper Block", "Iron Block", "Gold Block", "Bricks", "Snow", "Ice", "Ruby Block",
		"Platform", "Work Bench", "Glass", "Furnace", "Painting", "Sappling", "Snow Blue Ruby",
		"Blue Ruby Block", "Door", "Jar", "Table", "Wordrobe", "Book Shelf", "Snow Bricks",
		"Ice Table", "Ice Wordrobe", "Ice Book Shelf", "Ice Platform", "Sand Table",
		"Sand Wordrobe", "Sand Book Shelf", "Sand Platform", "Wooden Chest", "Ice Chest",
		"Sand Chest", "Bone Chest", "Bone Bricks", "Bone Bench", "Bone Wordrobe",
		"Bone Book Shelf", "Bone Platform"
	};
};