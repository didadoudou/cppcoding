std::map<std::string, std::string> checkMap;

checkMap.insert(std::pair<std::string, std::string>(path, md));

 auto iterc = checkMap.find(dir_name);
if(iterc == checkMap.end())
{
	ALOGD("the directory record is null, return");
	return;
}
std::string origin_md5 = iterc->second;
