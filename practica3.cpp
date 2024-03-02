//práctica 3: Modelado Geométrico y Cámara Sintética.
#include <stdio.h>
#include <string.h>
#include<cmath>
#include<vector>
#include <glew.h>
#include <glfw3.h>
//glm
#include<glm.hpp>
#include<gtc\matrix_transform.hpp>
#include<gtc\type_ptr.hpp>
#include <gtc\random.hpp>
//clases para dar orden y limpieza al còdigo
#include"Mesh.h"
#include"Shader.h"
#include"Sphere.h"
#include"Window.h"
#include"Camera.h"
//tecla E: Rotar sobre el eje X
//tecla R: Rotar sobre el eje Y
//tecla T: Rotar sobre el eje Z


using std::vector;

//Dimensiones de la ventana
const float toRadians = 3.14159265f/180.0; //grados a radianes
const float PI = 3.14159265f;
GLfloat deltaTime = 0.0f;
GLfloat lastTime = 0.0f;
static double limitFPS = 1.0 / 60.0;
Camera camera;
Window mainWindow;
vector<Mesh*> meshList;
vector<Shader>shaderList;
//Vertex Shader
static const char* vShader = "shaders/shader.vert";
static const char* fShader = "shaders/shader.frag";
static const char* vShaderColor = "shaders/shadercolor.vert";
Sphere sp = Sphere(1.0, 20, 20); //recibe radio, slices, stacks




void CrearCubo()
{
	unsigned int cubo_indices[] = {
		// front
		0, 1, 2,
		2, 3, 0,
		// right
		1, 5, 6,
		6, 2, 1,
		// back
		7, 6, 5,
		5, 4, 7,
		// left
		4, 0, 3,
		3, 7, 4,
		// bottom
		4, 5, 1,
		1, 0, 4,
		// top
		3, 2, 6,
		6, 7, 3
	};

	GLfloat cubo_vertices[] = {
		// front
		-0.5f, -0.5f,  0.5f,
		0.5f, -0.5f,  0.5f,
		0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		// back
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f
	};
	Mesh* cubo = new Mesh();
	cubo->CreateMesh(cubo_vertices, cubo_indices, 24, 36);
	meshList.push_back(cubo);
}

// Pirámide triangular regular cubo rubik

void CrearPiramideTriangular()
{
	unsigned int indices_piramide_triangular[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_piramide_triangular[] = {
		-0.7f, -0.7f,0.0f,	//0
		0.7f,-0.7f,0.0f,	//1
		0.0f,0.6f, 0.0f,	//2
		0.0f,-0.2f,0.8f,	//3
	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_piramide_triangular, indices_piramide_triangular, 12, 12);
	meshList.push_back(obj1);

}

// se empieza a crear triangulos rojos 

void CrearPiramideTriangularRojos()
{
	unsigned int indices_piramide_triangular_Rojos[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_piramide_triangular_Rojos[] = {
		0.0f,	-0.24f,		0.76f,	//0		
	   -0.15f,	-0.35f,		0.56f,	//1		
		0.15f,	-0.35f,		0.56f,	//2
		0.0f,	-0.2f,		0.55f,	//3

		-0.2f,	-0.4f,		0.5f,	//0		
	   -0.38f,	-0.53f,		0.3f,	//1		
		-0.1f,	-0.53f,		0.3f,	//2
		-0.2f,	-0.3f,		0.35f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_piramide_triangular_Rojos, indices_piramide_triangular_Rojos, 24, 24);
	meshList.push_back(obj1);

}

void Creartriangulos()
{
	unsigned int indices_triangulos[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos[] = 
	{
		-0.2f,	-0.4f,		0.5f,	//0		
	   -0.38f,	-0.53f,		0.3f,	//1		
		-0.1f,	-0.53f,		0.3f,	//2
		-0.2f,	-0.3f,		0.35f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos, indices_triangulos, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos2()
{
	unsigned int indices_triangulos2[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos2[] =
	{
		0.15f,	-0.4f,		0.5f,	//0		
	   0.06f,	-0.53f,		0.3f,	//1		
		0.3f,	-0.53f,		0.3f,	//2
		0.15f,	-0.4f,		0.3f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos2, indices_triangulos2, 12, 12);
	meshList.push_back(obj1);

}


void Creartriangulos3()
{
	unsigned int indices_triangulos3[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos3[] =
	{
		0.0f,	-0.53f,		0.3f,	//0		
	    0.1f,	-0.4f,		0.5f,	//1		
		-0.1f,	-0.4f,		0.5f,	//2
		0.0f,	-0.4f,		0.35f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos3, indices_triangulos3, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos4()
{
	unsigned int indices_triangulos4[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos4[] =
	{
		-0.4f,	-0.55f,		0.25f,	//0		
		-0.6f,	-0.67f,		0.05f,	//1		
		-0.3f,	-0.67f,		0.05f,	//2
		-0.4f,	-0.45f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos4, indices_triangulos4, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos5()
{
	unsigned int indices_triangulos5[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos5[] =
	{
		-0.3f,	-0.55f,		0.25f,	//0		
		-0.17f,	-0.67f,		0.05f,	//1		
		-0.05f,	-0.55f,		0.25f,	//2
		-0.15f,	-0.45f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos5, indices_triangulos5, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos6()
{
	unsigned int indices_triangulos6[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos6[] =
	{
		 0.07f,	-0.55f,		0.25f,	//0		
		-0.07f,	-0.67f,		0.05f,	//1		
		 0.2f,	-0.67f,		0.05f,	//2
		 0.07f,	-0.45f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos6, indices_triangulos6, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos7()
{
	unsigned int indices_triangulos7[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos7[] =
	{
		 0.32f,	-0.67f,		0.05f,	//0		
		 0.15f,	-0.55f,		0.25f,	//1		
		 0.4f,	-0.55f,		0.25f,	//2
		 0.3f,	-0.45f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos7, indices_triangulos7, 12, 12);
	meshList.push_back(obj1);

}

//terminan los triangulos rojos 

//cara verde 

void Creartriangulos8()
{
	unsigned int indices_triangulos8[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos8[] =
	{
		-0.03f,	-0.19f,		0.75f,	//0		
		-0.15f,	-0.27f,		0.6f,	//1		
		-0.03f,	-0.04f,		0.6f,	//2
		 0.0f,	-0.19f,		0.65f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos8, indices_triangulos8, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos9()
{
	unsigned int indices_triangulos9[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos9[] =
	{
		-0.03f,	 0.0f,		0.54f,	//0		
		-0.04f,	 0.2f,		0.35f,	//1		
		-0.17f,	-0.07f,		0.35f,	//2
		-0.02f,	 0.0f,		0.37f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos9, indices_triangulos9, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos10()
{
	unsigned int indices_triangulos10[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos10[] =
	{
		-0.10f,	-0.06f,		0.54f,	//0		
		-0.2f,	-0.12f,		0.35f,	//1		
		-0.17f,	-0.25f,		0.54f,	//2
		-0.09f,	-0.16f,		0.45f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos10, indices_triangulos10, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos11()
{
	unsigned int indices_triangulos11[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos11[] =
	{
		-0.03f,	 0.3f,		0.25f,	//0		
		-0.22f,	 0.15f,		0.05f,	//1		
		-0.04f,	 0.48f,		0.05f,	//2
		-0.03f,	 0.3f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos11, indices_triangulos11, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos12()
{
	unsigned int indices_triangulos12[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos12[] =
	{
		-0.19f,	-0.26f,		0.54f,	//0		
		-0.24f,	-0.18f,		0.35f,	//1		
		-0.35f,	-0.4f,		0.35f,	//2
		-0.19f,	-0.29f,		0.4f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos12, indices_triangulos12, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos13()
{
	unsigned int indices_triangulos13[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos13[] =
	{
		-0.07f,	 0.22f,		0.25f,	//0		
		-0.24f,	 0.13f,		0.05f,	//1		
		-0.21f,	-0.02f,		0.25f,	//2
		-0.04f,	 0.02f,		0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos13, indices_triangulos13, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos14()
{
	unsigned int indices_triangulos14[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos14[] =
	{
		-0.26f,	-0.15f,		0.28f,	//0		
		-0.29f,	 0.03f,		0.05f,	//1		
		-0.43f,	-0.25f,		0.05f,	//2
		-0.26f,	-0.15f,		0.1f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos14, indices_triangulos14, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos15()
{
	unsigned int indices_triangulos15[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos15[] =
	{
		-0.48f,	-0.37f,		0.08f,	//0		
		-0.32f,	-0.24f,		0.25f,	//1		
		-0.45f,	-0.48f,		0.25f,	//2
		-0.3f,	-0.37f,		0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos15, indices_triangulos15, 12, 12);
	meshList.push_back(obj1);

}

//termina cara verde

//cara azul empieza

void Creartriangulos16()
{
	unsigned int indices_triangulos16[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos16[] =
	{   //x      y           z
		 0.0f,	 0.5f,		-0.02f,	//0		
		 0.14f,	 0.2f,		-0.02f,	//1		
		-0.14f,	 0.2f,		-0.02f,	//2
		 0.0f,	 0.25f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos16, indices_triangulos16, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos17()
{
	unsigned int indices_triangulos17[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos17[] =
	{   //x      y           z
		 0.19f,	 0.1f,		-0.02f,	//0		
		 0.35f,	-0.2f,		-0.02f,	//1		
	     0.09f, - 0.2f,		-0.02f,	//2
		 0.2f,	-0.1f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos17, indices_triangulos17, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos18()
{
	unsigned int indices_triangulos18[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos18[] =
	{   //x      y           z
		 0.1f,	 0.1f,		-0.02f,	//0		
		 0.0f,	-0.2f,		-0.02f,	//1		
		-0.1f,   0.1f,		-0.02f,	//2
		 0.0f,	 0.0f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos18, indices_triangulos18, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos19()
{
	unsigned int indices_triangulos19[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos19[] =
	{   //x      y           z
		-0.2f,	 0.1f,		-0.02f,	//0		
		-0.1f,	-0.2f,		-0.02f,	//1		
		-0.35f, -0.2f,		-0.02f,	//2
		-0.2f,	-0.1f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos19, indices_triangulos19, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos20()
{
	unsigned int indices_triangulos20[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos20[] =
	{   //x      y           z
		 0.4f,	-0.3f,		-0.02f,	//0		
		 0.6f,	-0.65f,		-0.02f,	//1		
		 0.2f,  -0.65f,		-0.02f,	//2
		 0.4f,	-0.5f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos20, indices_triangulos20, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos21()
{
	unsigned int indices_triangulos21[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos21[] =
	{   //x      y           z
		 0.3f,	-0.3f,		-0.02f,	//0		
		 0.12f,	-0.65f,		-0.02f,	//1		
		 0.0f,  -0.3f,		-0.02f,	//2
		 0.1f,	-0.45f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos21, indices_triangulos21, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos22()
{
	unsigned int indices_triangulos21[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos21[] =
	{   //x      y           z
		-0.15f,	-0.3f,		-0.02f,	//0		
		 0.0f,	-0.65f,		-0.02f,	//1		
		-0.3f,  -0.65f,		-0.02f,	//2
		-0.15f,	-0.5f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos21, indices_triangulos21, 12, 12);
	meshList.push_back(obj1);

}

void Creartriangulos23()
{
	unsigned int indices_triangulos21[] = {
			0,1,2,
			1,3,2,
			3,0,2,
			1,0,3

	};
	GLfloat vertices_triangulos21[] =
	{   //x      y           z
		-0.25f,	-0.3f,		-0.02f,	//0		
		-0.4f,	-0.65f,		-0.02f,	//1		
		-0.45f, -0.3f, 	-0.02f,	//2
		-0.4f,	-0.45f,		 0.15f,	//3

	};
	Mesh* obj1 = new Mesh();
	obj1->CreateMesh(vertices_triangulos21, indices_triangulos21, 12, 12);
	meshList.push_back(obj1);

}







/*
Crear cilindro, cono y esferas con arreglos dinámicos vector creados en el Semestre 2023 - 1 : por Sánchez Pérez Omar Alejandro
*/
void CrearCilindro(int res, float R) {

	//constantes utilizadas en los ciclos for
	int n, i;
	//cálculo del paso interno en la circunferencia y variables que almacenarán cada coordenada de cada vértice
	GLfloat dt = 2 * PI / res, x, z, y = -0.5f;

	vector<GLfloat> vertices;
	vector<unsigned int> indices;

	//ciclo for para crear los vértices de las paredes del cilindro
	for (n = 0; n <= (res); n++) {
		if (n != res) {
			x = R * cos((n)*dt);
			z = R * sin((n)*dt);
		}
		//caso para terminar el círculo
		else {
			x = R * cos((0)*dt);
			z = R * sin((0)*dt);
		}
		for (i = 0; i < 6; i++) {
			switch (i) {
			case 0:
				vertices.push_back(x);
				break;
			case 1:
				vertices.push_back(y);
				break;
			case 2:
				vertices.push_back(z);
				break;
			case 3:
				vertices.push_back(x);
				break;
			case 4:
				vertices.push_back(0.5);
				break;
			case 5:
				vertices.push_back(z);
				break;
			}
		}
	}

	//ciclo for para crear la circunferencia inferior
	for (n = 0; n <= (res); n++) {
		x = R * cos((n)*dt);
		z = R * sin((n)*dt);
		for (i = 0; i < 3; i++) {
			switch (i) {
			case 0:
				vertices.push_back(x);
				break;
			case 1:
				vertices.push_back(-0.5f);
				break;
			case 2:
				vertices.push_back(z);
				break;
			}
		}
	}

	//ciclo for para crear la circunferencia superior
	for (n = 0; n <= (res); n++) {
		x = R * cos((n)*dt);
		z = R * sin((n)*dt);
		for (i = 0; i < 3; i++) {
			switch (i) {
			case 0:
				vertices.push_back(x);
				break;
			case 1:
				vertices.push_back(0.5);
				break;
			case 2:
				vertices.push_back(z);
				break;
			}
		}
	}

	//Se generan los indices de los vértices
	for (i = 0; i < vertices.size(); i++) indices.push_back(i);

	//se genera el mesh del cilindro
	Mesh *cilindro = new Mesh();
	cilindro->CreateMeshGeometry(vertices, indices, vertices.size(), indices.size());
	meshList.push_back(cilindro);
}

//función para crear un cono
void CrearCono(int res,float R) {

	//constantes utilizadas en los ciclos for
	int n, i;
	//cálculo del paso interno en la circunferencia y variables que almacenarán cada coordenada de cada vértice
	GLfloat dt = 2 * PI / res, x, z, y = -0.5f;
	
	vector<GLfloat> vertices;
	vector<unsigned int> indices;

	//caso inicial para crear el cono
	vertices.push_back(0.0);
	vertices.push_back(0.5);
	vertices.push_back(0.0);
	
	//ciclo for para crear los vértices de la circunferencia del cono
	for (n = 0; n <= (res); n++) {
		x = R * cos((n)*dt);
		z = R * sin((n)*dt);
		for (i = 0; i < 3; i++) {
			switch (i) {
			case 0:
				vertices.push_back(x);
				break;
			case 1:
				vertices.push_back(y);
				break;
			case 2:
				vertices.push_back(z);
				break;
			}
		}
	}
	vertices.push_back(R * cos(0) * dt);
	vertices.push_back(-0.5);
	vertices.push_back(R * sin(0) * dt);


	for (i = 0; i < res+2; i++) indices.push_back(i);

	//se genera el mesh del cono
	Mesh *cono = new Mesh();
	cono->CreateMeshGeometry(vertices, indices, vertices.size(), res + 2);
	meshList.push_back(cono);
}

//función para crear pirámide cuadrangular unitaria
void CrearPiramideCuadrangular()
{
	vector<unsigned int> piramidecuadrangular_indices = {
		0,3,4,
		3,2,4,
		2,1,4,
		1,0,4,
		0,1,2,
		0,2,4

	};
	vector<GLfloat> piramidecuadrangular_vertices = {
		0.5f,-0.5f,0.5f,
		0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,-0.5f,
		-0.5f,-0.5f,0.5f,
		0.0f,0.5f,0.0f,
	};
	Mesh *piramide = new Mesh();
	piramide->CreateMeshGeometry(piramidecuadrangular_vertices, piramidecuadrangular_indices, 15, 18);
	meshList.push_back(piramide);
}







void CreateShaders()
{
	Shader *shader1 = new Shader();
	shader1->CreateFromFiles(vShader, fShader);
	shaderList.push_back(*shader1);

	Shader* shader2 = new Shader();
	shader2->CreateFromFiles(vShaderColor, fShader);
	shaderList.push_back(*shader2);
}


int main()
{
	mainWindow = Window(800, 600);
	mainWindow.Initialise();
	//Cilindro y cono reciben resolución (slices, rebanadas) y Radio de circunferencia de la base y tapa

	CrearCubo();//índice 0 en MeshList
	CrearPiramideTriangular();//índice 1 en MeshList
	CrearCilindro(5, 1.0f);//índice 2 en MeshList
	CrearCono(25, 2.0f);//índice 3 en MeshList
	CrearPiramideCuadrangular();//índice 4 en MeshList
	CrearPiramideTriangularRojos();//índice 5 en MeshList
	Creartriangulos(); //indice mesh 6
	Creartriangulos2(); //indice mesh 7
	Creartriangulos3(); //indice mesh 8
	Creartriangulos4(); //indice mesh 9
	Creartriangulos5(); //indice mesh 10
	Creartriangulos6(); //indice mesh 11
	Creartriangulos7(); //indice mesh 12
	Creartriangulos8(); //indice mesh 13
	Creartriangulos9(); //indice mesh 14
	Creartriangulos10(); //indice mesh 15
	Creartriangulos11(); //indice mesh 16
	Creartriangulos12(); //indice mesh 17
	Creartriangulos13(); //indice mesh 18
	Creartriangulos14(); //indice mesh 19
	Creartriangulos15(); //indice mesh 20
	Creartriangulos16(); //indice mesh 21
	Creartriangulos17(); //indice mesh 22
	Creartriangulos18(); //indice mesh 23
	Creartriangulos19(); //indice mesh 24
	Creartriangulos20(); //indice mesh 25
	Creartriangulos21(); //indice mesh 26
	Creartriangulos22(); //indice mesh 27
	Creartriangulos23(); //indice mesh 28
	CreateShaders();
	
	

	/*Cámara se usa el comando: glm::lookAt(vector de posición, vector de orientación, vector up));
	En la clase Camera se reciben 5 datos:
	glm::vec3 vector de posición,
	glm::vec3 vector up,
	GlFloat yaw rotación para girar hacia la derecha e izquierda
	GlFloat pitch rotación para inclinar hacia arriba y abajo
	GlFloat velocidad de desplazamiento,
	GlFloat velocidad de vuelta o de giro
	Se usa el Mouse y las teclas WASD y su posición inicial está en 0,0,1 y ve hacia 0,0,-1.
	*/

	camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), -60.0f, 0.0f, 0.3f, 0.3f);

	
	GLuint uniformProjection = 0;
	GLuint uniformModel = 0;
	GLuint uniformView = 0;
	GLuint uniformColor = 0;
	glm::mat4 projection = glm::perspective(glm::radians(60.0f)	,mainWindow.getBufferWidth() / mainWindow.getBufferHeight(), 0.1f, 100.0f);
	//glm::mat4 projection = glm::ortho(-1, 1, -1, 1, 1, 10);
	
	//Loop mientras no se cierra la ventana
	sp.init(); //inicializar esfera
	sp.load();//enviar la esfera al shader

	glm::mat4 model(1.0);//Inicializar matriz de Modelo 4x4

	glm::vec3 color = glm::vec3(0.0f,0.0f,0.0f); //inicializar Color para enviar a variable Uniform;

	while (!mainWindow.getShouldClose())
	{
		
		GLfloat now = glfwGetTime();
		deltaTime = now - lastTime;
		deltaTime += (now - lastTime) / limitFPS;
		lastTime = now;
		//Recibir eventos del usuario
		glfwPollEvents();
		//Cámara
		camera.keyControl(mainWindow.getsKeys(), deltaTime);
		camera.mouseControl(mainWindow.getXChange(), mainWindow.getYChange());

		//Limpiar la ventana
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se agrega limpiar el buffer de profundidad
		shaderList[0].useShader();
		uniformModel = shaderList[0].getModelLocation();
		uniformProjection = shaderList[0].getProjectLocation();
		uniformView = shaderList[0].getViewLocation();
		uniformColor = shaderList[0].getColorLocation();
		
		model = glm::mat4(1.0);
		//Traslación inicial para posicionar en -Z a los objetos
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, -4.0f));
		//otras transformaciones para el objeto
		//model = glm::scale(model, glm::vec3(0.5f,0.5f,0.5f));
		model = glm::rotate(model, glm::radians(mainWindow.getrotax()), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(mainWindow.getrotay()), glm::vec3(0.0f, 1.0f, 0.0f));  //al presionar la tecla Y se rota sobre el eje y
		model = glm::rotate(model, glm::radians(mainWindow.getrotaz()), glm::vec3(0.0f, 0.0f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));		
		//la línea de proyección solo se manda una vez a menos que en tiempo de ejecución
		//se programe cambio entre proyección ortogonal y perspectiva


		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 1.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[1]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[5]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[6]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[7]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[8]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[9]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[10]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[11]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(1.0f, 0.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[12]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[13]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[14]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[15]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[16]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[17]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[18]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[19]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 1.0f, 0.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[20]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[21]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[22]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[23]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[24]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[25]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[26]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[27]->RenderMesh(); //dibuja cubo y pirámide triangular

		glUniformMatrix4fv(uniformProjection, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(uniformView, 1, GL_FALSE, glm::value_ptr(camera.calculateViewMatrix()));
		color = glm::vec3(0.0f, 0.0f, 1.0f);
		glUniform3fv(uniformColor, 1, glm::value_ptr(color)); //para cambiar el color del objetos
		meshList[28]->RenderMesh(); //dibuja cubo y pirámide triangular

		//meshList[3]->RenderMeshGeometry(); //dibuja las figuras geométricas cilindro, cono, pirámide base cuadrangular
		//sp.render(); //dibuja esfera
		
		
		/*
		//ejercicio: Instanciar primitivas geométricas para recrear el dibujo de la práctica pasada en 3D,
		//se requiere que exista piso y la casa tiene una ventana azul circular justo en medio de la pared trasera y solo 1 puerta frontal.
		model = glm::mat4(1.0f);
		color=glm::vec3(0.0f,1.0f,0.0f);
		//Opcional duplicar esta traslación inicial para posicionar en -Z a los objetos en el mismo punto
		//model = glm::translate(model, glm::vec3(0.0f, 0.0f, -3.0f));
		model = glm::translate(model, glm::vec3(0.0f, 0.75f, -2.5f));
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 1.0f));
		glUniformMatrix4fv(uniformModel, 1, GL_FALSE, glm::value_ptr(model));//FALSE ES PARA QUE NO SEA TRANSPUESTA
		meshList[1]->RenderMeshGeometry();
		*/

		glUseProgram(0);
		mainWindow.swapBuffers();
	}
	return 0;
}

	
		