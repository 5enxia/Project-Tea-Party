#include <GL/glut.h>
#include "MyTexture.h"
#include "OBJ_Loader.h"

void drawModel(objl::Loader& model, MyTexture* textures, vec3d pos, vec3d rotate, float scale) {
	glPushMatrix();
	glRotatef(rotate.x, 1, 0, 0); 	glRotatef(rotate.y, 0, 1, 0); glRotatef(rotate.z, 0, 0, 1);
	glTranslated(pos.x, pos.y, pos.z);
	glScaled(scale, scale, scale);
	for (int i = 0; i < model.LoadedMeshes.size(); i++)
	{
		textures[i].beginTexture();
		glBegin(GL_TRIANGLES);
		for (int j = 0; j < model.LoadedMeshes[i].Vertices.size(); j++)
		{
			glTexCoord2d(
				model.LoadedMeshes[i].Vertices[j].TextureCoordinate.X,
				-model.LoadedMeshes[i].Vertices[j].TextureCoordinate.Y
			);
			glVertex3d(
				model.LoadedMeshes[i].Vertices[j].Position.X,
				model.LoadedMeshes[i].Vertices[j].Position.Y,
				model.LoadedMeshes[i].Vertices[j].Position.Z
			);
		}
		glEnd();
		textures[i].endTexture();
	}
	glPopMatrix();
}