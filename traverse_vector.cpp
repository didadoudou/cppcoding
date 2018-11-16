for(auto iter = dir_tmp.cbegin();iter != dir_tmp.cend();iter++)
{
	std::string dir = *iter;
	ALOGI("entering dir: Path %s", dir.c_str());
	getDirMd5(dir, fileMD5s);
}

