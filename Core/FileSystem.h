#pragma once

namespace FMango{

	class FileSystem
	{
	public:
		FileSystem()
		{
		}

		~FileSystem()
		{
		}

		unsigned char* getFileData(const char *name, const char *mode);
	private:

	};


}