std::string filePath = "somefile.txt";
std::ifstream inFile(filePath);
if (inFile)
{
	std::string line;
	while(getline(inFile, line))
	{
	}
	inFile.close();
}

