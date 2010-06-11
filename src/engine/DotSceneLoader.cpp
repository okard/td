/*
    Tower Defense Game
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include "DotSceneLoader.h"

//Project Includes
#include <common/Log.h>

/**
* Parse .scene file
*/
void DotSceneLoader::ParseFile(const std::string file, const Ogre::SceneManager* sceneMng)
{
    assert(sceneMng != 0);
    
    mSceneMng = const_cast<Ogre::SceneManager*>(sceneMng);
    
    TiXmlDocument   *XMLDoc = 0;
    TiXmlElement   *XMLRoot;

    try
    {
        // Strip the path
        Ogre::String basename, path;
        Ogre::StringUtil::splitFilename(file, basename, path);

        Ogre::DataStreamPtr pStream = Ogre::ResourceGroupManager::getSingleton().openResource(file);

        //DataStreamPtr pStream = ResourceGroupManager::getSingleton().
        //      openResource( SceneName, groupName );

        Ogre::String data = pStream->getAsString();
        
        // Open the .scene File
        XMLDoc = new TiXmlDocument();
        XMLDoc->Parse( data.c_str() );
        pStream->close();
        pStream.setNull();

        if( XMLDoc->Error())
        {
            //We'll just log, and continue on gracefully
            Common::LogEvent() << "DotSceneLoader: Xml Error " << XMLDoc->ErrorDesc() << Common::LogEvent::End;
            delete XMLDoc;
            return;
        }
    }
    catch(Ogre::Exception& exc)
    {
        Common::LogEvent() << "Error Loading XML:\n " << exc.getFullDescription().c_str() << Common::LogEvent::End;
        return;
    }
    
    
    XMLRoot = XMLDoc->RootElement();
    //if(XMLRoot->  == "scene"
    if(XMLRoot != 0)
        ParseScene(XMLRoot);
    
    delete XMLDoc;
}

/**
* Parse the root scene node
*/
void DotSceneLoader::ParseScene(TiXmlElement* rootNode)
{
    Common::LogEvent() << "Start parsing Scene File" << Common::LogEvent::End;
    //Terrain
    TiXmlElement* element;
    element = rootNode->FirstChildElement("terrain");
    if(element != 0)
        ParseTerrain(element);
    
    Common::LogEvent() << "End parsing Scene File" << Common::LogEvent::End;
}


/**
* Parse the terrain node
*/
void DotSceneLoader::ParseTerrain(TiXmlElement* terrainNode)
{
    Common::LogEvent() << "Parse Terrain" << Common::LogEvent::End;
    
    std::string terrain;
    //char[][] attr = {"", "", ""};
    char attr[][20] = {"WorldTexture\0", 
                       "DetailTexture\0", 
                       "DetailTile\0", 
                       "PageSource\0",
                       "Heightmap.image\0", 
                       "PageSize\0", 
                       "TileSize\0",
                       "MaxPixelError\0", 
                       "PageWorldX\0", 
                       "PageWorldZ\0", 
                       "MaxHeight\0", 
                       "MaxMipMapLevel\0",
                       "VertexProgramMorph\0", 
                       "LODMorphStart\0", 
                        0};
    
    //read attributes
    for(int i=0; i < 14; i++)
    {
        const char* value = terrainNode->Attribute(attr[i]);
        if(value != 0)
        {
            terrain.append(attr[i]).append("=").append(value).append("\n");
        }
    }
    Common::LogEvent() << "Terrain: " << terrain << Common::LogEvent::End;
    
    void *pMem = OGRE_ALLOC_T(unsigned char, terrain.length()+1, Ogre::MEMCATEGORY_GENERAL);
    memset(pMem, 0, terrain.length()+1);
    memcpy(pMem, terrain.c_str(), terrain.length() + 1);
    Ogre::DataStreamPtr pStr(new Ogre::MemoryDataStream(pMem, terrain.length() + 1, true));
    
    mSceneMng->setWorldGeometry(pStr);
}

