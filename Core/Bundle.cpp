#include "Base.h"
#include "Bundle.h"
#include "FileSystem.h"
#include "Mesh.h"


namespace FMango{


	Bundle::Bundle()
	{

	}

	Bundle::~Bundle()
	{

	}

	Bundle* Bundle::Create( const char *path )
	{
		//Stream* stream = FileSystem::open(path);
		//if (!stream)
		//{
		//	FM_WARN("Fail to open file '%s'", path);
		//	return NULL;
		//}
		//// Read the GPB header info.
		//char sig[9];
		//if (stream->read(sig, 1, 9) != 9 || memcmp(sig, "\xABGPB\xBB\r\n\x1A\n", 9) != 0)
		//{
		//	SAFE_DELETE(stream);
		//	FM_WARN("Invalid GPB header for bundle '%s'.", path);
		//	return NULL;
		//}
		//// Read version.
		//unsigned char version[2];
		//if (stream->read(version, 1, 2) != 2)
		//{
		//	SAFE_DELETE(stream);
		//	FM_WARN("Failed to read GPB version for bundle '%s'.", path);
		//	return NULL;
		//}
		//// Read ref table.
		//unsigned int refCount;
		//if (stream->read(&refCount, 4, 1) != 1)
		//{
		//	SAFE_DELETE(stream);
		//	FM_WARN("Failed to read ref table for bundle '%s'.", path);
		//	return NULL;
		//}
		//// Read all refs.
		//Reference* refs = new Reference[refCount];
		//for (unsigned int i = 0; i < refCount; ++i)
		//{
		//	if ((refs[i].id = readString(stream)).empty() ||
		//		stream->read(&refs[i].type, 4, 1) != 1 ||
		//		stream->read(&refs[i].offset, 4, 1) != 1)
		//	{
		//		SAFE_DELETE(stream);
		//		FM_WARN("Failed to read ref number %d for bundle '%s'.", i, path);
		//		SAFE_DELETE_ARRAY(refs);
		//		return NULL;
		//	}
		//}
		//// Keep file open for faster reading later.
		Bundle* bundle = new Bundle(/*path*/);
		//bundle->_version[0] = version[0];
		//bundle->_version[1] = version[1];
		//bundle->_referenceCount = refCount;
		//bundle->_references = refs;
		//bundle->_stream = stream;

		return bundle;

	}

	Mesh* Bundle::LoadMesh()
	{
		return NULL;
	}

}