std::string String16ToString(String16 dir)
{
	String8 tmp = String8(dir);
	const char* tmp_name = tmp.string();
	std::string dir_name(tmp_name);
	return dir_name;
}

