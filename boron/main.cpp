#define STB_IMAGE_IMPLEMENTATION

#include <iostream>
#include <stb_image.h>
#include <fstream>
#include <vector>

struct Pixel {
	unsigned char red;
	unsigned char grn;
	unsigned char blu;
	float gry;
};

int main(int argc, char *argv[])
{
	if (argv[1] == nullptr)
	{
		std::cerr << "usage: boron [file path]\n";
		return -1;
	}

	int width;
	int height;
	int channels;
	const char* PATH = argv[1];

	unsigned char* data = stbi_load(PATH, &width, &height, &channels, 0);
	if (data == nullptr)
	{
		std::cerr << "Error loading image.\n";
		return -1;
	}

	std::vector<Pixel> vec;

	std::ofstream file("output.txt");

	for (int index = 0; index < width * height * channels; index += channels)
	{
		unsigned char red = data[index + 0];
		unsigned char grn = data[index + 1];
		unsigned char blu = data[index + 2];
		float gry = ((0.299 * red + 0.587 * grn + 0.114 * blu) - 0) / (255 - 0);

		Pixel pixelData = { red, grn, blu, gry };
		vec.push_back(pixelData);
	}

	int x = 0;
	int index = 0;
	for (int y = 0; y < height; y++)
	{
		x = 0;
		while (x < width)
		{
			if (vec[index].gry == 0.0)
			{
				file << "*";
			}
			if (vec[index].gry > 0.0 && vec[index].gry < 0.2)
			{
				file << "-";
			}
			if (vec[index].gry > 0.2 && vec[index].gry < 0.4)
			{
				file << "+";
			}
			if (vec[index].gry > 0.4 && vec[index].gry < 0.6)
			{
				file << "=";
			}
			if (vec[index].gry > 0.6 && vec[index].gry < 0.8)
			{
				file << "#";
			}
			if (vec[index].gry > 0.8 && vec[index].gry < 1.0)
			{
				file << "@";
			}
			x++;
			index++;
		}

		file << "\n";
	}

	file.close();
	stbi_image_free(data);
	return 0;
}