#ifndef _TEXTURED_POLYGON_IMPORTER_H_
#define _TEXTURED_POLYGON_IMPORTER_H_

#include <Core/Visualization/Importer/ImporterBase.h>
#include "TexturedPolygonObject.h"

namespace kvs{
namespace jaea{

#ifdef CGFORMATEXT4KVS_SUPPORT_FBXSDK
class FBX;
#endif //CGFORMATEXT4KVS_SUPPORT_ASSIMP

#ifdef CGFORMATEXT4KVS_SUPPORT_ASSIMP
class ThreeDS;
#endif // CGFORMATEXT4KVS_SUPPORT_ASSIMP

class TexturedPolygonImporter : public kvs::ImporterBase, public TexturedPolygonObject {
    kvsModule( kvs::jaea::TexturedPolygonImporter, Importer );
    kvsModuleBaseClass( kvs::ImporterBase );
    kvsModuleSuperClass( kvs::jaea::TexturedPolygonImporter );

public:
    TexturedPolygonImporter(){};
    virtual ~TexturedPolygonImporter(){};
    
    SuperClass* exec( const kvs::FileFormatBase* file_format ) override;

private:
#ifdef CGFORMATEXT4KVS_SUPPORT_ASSIMP
    void import3DS(const kvs::jaea::ThreeDS* threeDS);
#endif // CGFORMATEXT4KVS_SUPPORT_ASSIMP

#ifdef CGFORMATEXT4KVS_SUPPORT_FBXSDK
    void importFBX( const kvs::jaea::FBX* fbx);  
#endif // CGFORMATEXT4KVS_SUPPORT_FBXSDK
};

} // namespace jaea
} // kvs 

#endif // _THREE_DS_H_
