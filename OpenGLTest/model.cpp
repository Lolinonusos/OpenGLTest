//#include "model.h"


//
//void Model::draw(Shader& shader) {
//	for (unsigned int i = 0; i < meshes.size(); i++) {
//		meshes[i].draw(shader);
//	}
//}
//
//void Model::loadModel(std::string const& path) {
//	// Importer object from assimp
//	Assimp::Importer importer;
//	// Triangulate tells assimp to make a mopdel only consist of triangles
//	// FlipUVs tells assimp that it should flip texture coordinates on the y-axis
//	const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenSmoothNormals | aiProcess_FlipUVs | aiProcess_CalcTangentSpace);
//
//	// Print error and stop import
//	if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
//	{
//		std::cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << std::endl;
//		return;
//	}
//	directory = path.substr(0, path.find_last_of('/'));
//
//
//	processNode(scene->mRootNode, scene);
//}
//
//void Model::processNode(aiNode* node, const aiScene* scene) {
//	// Process all of the node's meshes if there are any
//	for (unsigned int i = 0; i < node->mNumMeshes; i++) {
//		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
//		meshes.push_back(processMesh(mesh, scene));
//	}
//	// Then process all of its children
//	for (unsigned int i = 0; i < node->mNumChildren; i++) {
//		processNode(node->mChildren[i], scene);
//	}
//}
//
//// Translates the assimp object to a mesh object readable by opengl
//Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene) {
//	std::vector<Vertex> vertices;
//	std::vector<unsigned int>indices;
//	std::vector<Texture> textures;
//
//	// process vertex positions, normals and texture coordinates
//	for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
//		Vertex vertex;
//		
//		// Assimp calls their vertex position array mVertices
//		glm::vec3 vector;
//		vector.x = mesh->mVertices[i].x;
//		vector.y = mesh->mVertices[i].y;
//		vector.z = mesh->mVertices[i].z;
//		vertex.position = vector;
//
//		vector.x = mesh->mNormals[i].x;
//		vector.y = mesh->mNormals[i].y;
//		vector.z = mesh->mNormals[i].z;
//		vertex.normal = vector;
//
//		if (mesh->mTextureCoords[0]) {
//			glm::vec2 vec;
//			vec.x = mesh->mTextureCoords[0][i].x;
//			vec.y = mesh->mTextureCoords[0][i].y;
//			vertex.texCoord = vec;
//		}
//		else {
//			vertex.texCoord = glm::vec2(0.0f, 0.0f);
//		}
//
//		vertices.push_back(vertex);
//	}
//	// process indices
//	for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
//		aiFace face = mesh->mFaces[i];
//		for (unsigned int j = 0; j < face.mNumIndices; j++) {
//			indices.push_back(face.mIndices[j]);
//		}
//	}
//	// process material
//	if (mesh->mMaterialIndex >= 0) {
//		aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
//		
//		std::vector<Texture> diffuseMaps = loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
//		textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
//		
//		std::vector<Texture> specularMaps = loadMaterialTextures(material, aiTextureType_SPECULAR, "texure_specular");
//		textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
//	}
//
//	return Mesh(vertices, indices, textures);
//}
//
//std::vector<Texture> Model::loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName) {
//    std::vector<Texture> textures;
//    for (unsigned int i = 0; i < mat->GetTextureCount(type); i++)
//    {
//        aiString str;
//        mat->GetTexture(type, i, &str);
//        // check if texture was loaded before and if so, continue to next iteration: skip loading a new texture
//        bool skip = false;
//        for (unsigned int j = 0; j < texturesLoaded.size(); j++)
//        {
//            if (std::strcmp(texturesLoaded[j].path.data(), str.C_Str()) == 0)
//            {
//                textures.push_back(texturesLoaded[j]);
//                skip = true; // a texture with the same filepath has already been loaded, continue to next one. (optimization)
//                break;
//            }
//        }
//        if (!skip)
//        {   // if texture hasn't been loaded already, load it
//            Texture texture;
//            texture.ID = TextureFromFile(str.C_Str(), this->directory);
//            texture.type = typeName;
//            texture.path = str.C_Str();
//            textures.push_back(texture);
//            texturesLoaded.push_back(texture);  // store it as texture loaded for entire model, to ensure we won't unnecesery load duplicate textures.
//        }
//    }
//    return textures;
//}
//
//unsigned int TextureFromFile(const char* path, const std::string& directory, bool gamma)
//{
//    std::string filename = std::string(path);
//    filename = directory + '/' + filename;
//
//    unsigned int textureID;
//    glGenTextures(1, &textureID);
//
//    int width, height, nrComponents;
//    unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
//    if (data)
//    {
//        GLenum format;
//        if (nrComponents == 1)
//            format = GL_RED;
//        else if (nrComponents == 3)
//            format = GL_RGB;
//        else if (nrComponents == 4)
//            format = GL_RGBA;
//
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
//        glGenerateMipmap(GL_TEXTURE_2D);
//
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//        stbi_image_free(data);
//    }
//    else
//    {
//        std::cout << "Texture failed to load at path: " << path << std::endl;
//        stbi_image_free(data);
//    }
//
//    return textureID;
//}