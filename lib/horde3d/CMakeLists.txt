#########################################
# CMake File for Horde3D
#########################################
cmake_minimum_required(VERSION 2.8)
project(horde3d)

include_directories(shared)



set ( HORDE3D_SRC
    source/egAnimatables.cpp
    source/egAnimation.cpp
    source/egCamera.cpp
    source/egCom.cpp
    source/egExtensions.cpp
    source/egGeometry.cpp
    source/egLight.cpp
    source/egMain.cpp
    source/egMaterial.cpp
    source/egModel.cpp
    source/egModules.cpp
    source/egParticle.cpp
    source/egPipeline.cpp
    source/egPrimitives.cpp
    source/egRendererBase.cpp
    source/egRenderer.cpp
    source/egResource.cpp
    source/egScene.cpp
    source/egSceneGraphRes.cpp
    source/egShader.cpp
    source/egTexture.cpp
    source/utImage.cpp
    source/utOpenGL.cpp
)

add_library(horde3d ${HORDE3D_SRC})


