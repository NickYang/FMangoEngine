#include "Base.h"
#include "SampleScene.h"

FMango::Scene *scene;
void initializeGL() {

	//////////////// PLUG IN SCENE HERE /////////////////
	scene = new FMango::SampleScene();
	////////////////////////////////////////////////////

	//GLUtils::dumpGLInfo();

	glClearColor(1.0f, 1.0f, 0.0f, 1.0f);

	scene->init();
}

void paintGL() {
	//GLUtils::checkForOpenGLError(__FILE__, __LINE__);
	scene->render();
	glutSwapBuffers();
}

void resizeGL(int w, int h) {
	scene->resize(w, h);
}

void updateGL() {
	scene->update(1);
	glutPostRedisplay();
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitContextVersion(4, 0);
	glutInitContextProfile(GLUT_CORE_PROFILE);

	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 200);
	glutCreateWindow(argv[0]);

	glload::LoadFunctions();

	initializeGL();
	glutDisplayFunc(paintGL);
	glutReshapeFunc(resizeGL);
	glutIdleFunc(updateGL);
	glutMainLoop();
}