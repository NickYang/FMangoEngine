#pragma once
#include "Mesh.h"
namespace FMango
{
	class Bundle
	{
	public:
		static Bundle* Create(const char *path);
		Mesh* LoadMesh();
	protected:


		
	private:
		Bundle();
		~Bundle();
	};

	class Reference
    {
    public:
        std::string id;
        unsigned int type;
        unsigned int offset;

        /**
         * Constructor.
         */
        Reference();

        /**
         * Destructor.
         */
        ~Reference();
    };

}