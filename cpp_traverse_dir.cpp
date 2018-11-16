void traverseDirs(std::string dir_name)
{
	DIR *dir = opendir(dir_name.c_str()); // check is dir ?
	struct dirent *entry = (struct dirent *)malloc(sizeof(struct dirent));
        struct dirent *file = (struct dirent *)malloc(sizeof(struct dirent));


        if((dir = opendir(dir_name.c_str())) == NULL)
        {
                ALOGD("open dir %s error", dir_name.c_str());
                free(entry);
                free(file);
                return;
        }


	while (1)
	{ // skip "." and ".."

		if(readdir_r(dir, entry, &file) != 0)
                {
                        ALOGD("read dir %s error", dir_name.c_str());
                }

                if(file == NULL)
                        break;

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

