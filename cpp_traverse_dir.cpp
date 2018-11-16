void traverseDirs(std::string dir_name)
{
	DIR *dir = opendir(dir_name.c_str()); // check is dir ?
	struct dirent *file;

	::std::vector<::std::string> dir_tmp;

	while ((file = readdir(dir)) != NULL)
	{ // skip "." and ".."

		if (strcmp(file->d_name, ".") == 0 || strcmp(file->d_name, "..") == 0)
		{
			ALOGD("ignore . and ..");
			continue;
		}
		if (file->d_type == DT_DIR)
		{
			std::string filePath = dir_name + "/" + file->d_name;
			traverseDirs(filePath);
		}
		else if(file->d_type == DT_REG )
		{
			std::string filePath = dir_name + "/" + file->d_name;
			std::FILE* file_ = std::fopen(filePath.c_str(), "rb");

			if(NULL != file_)
			{
			}
			else
			{
				ALOGI("open file failed! filePath: %s/%s ", dir_name.c_str(), file->d_name);
			}
		}

	}

}

