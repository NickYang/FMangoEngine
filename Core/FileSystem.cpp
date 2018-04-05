#include "Base.h"
#include "FileSystem.h"

namespace FMango{



	unsigned char* FileSystem::getFileData(const char *name, const char *mode)
	{
		FILE* pData = fopen(name, mode);
		if (!pData)
		{
			
		}
		
		return NULL;
	}

}