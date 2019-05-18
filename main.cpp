#include <iostream>
#include <cstdio>
#include <math.h>

#define PI 3.141592654

struct vector {
	double x;
	double y;
	double z;
	const char * str;

	vector operator + (const vector & v) const {
		return vector {
			x + v.x,
			y + v.y,
			z + v.z,
			NULL  // TODO
		};
	}

	vector operator - (const vector &v) const {
		return vector {
			x - v.x,
			y - v.y,
			z - v.z,
			NULL  // TODO
		};
	}

	double operator * (const vector &v) const {
		return x * v.x + y * v.y + z * v.z;
	}

	bool operator == (const vector &v) const {
		if (x == v.x && y == v.y && z == v.z)
			return true;
		else
			return false;
	}

	vector operator * (double ** &m) const {
		int i, j;
		double v[3];

		for (i = 0; i < 3; i++) {
			v[i] = 0;
			for (j = 0; j < 3; j++) {
				v[i] += m[i][j];
			}
		}
		return { v[0], v[1], v[2] };
	}
};

//const vector X = vector { 1, 0, 0, "X unit vector" };
//const vector Y = { 0, 1, 0, "Y unit vector" };
//const vector Z = { 0, 0, 1, "Z unit vector" };

vector create_vector(int x, int y, int z) {
	vector v = { (double)x, (double)y, (double)z, NULL };
	return v;
}

vector create_vector(double x, double y, double z) {
	vector v = { x, y, z, NULL };
	return v;
}

vector create_vector(double x, double y, double z, const char * str) {
	vector v = { x, y, z, str };
	return v;
}

void print_vector(vector v) {
	if (v.str == NULL)
		printf("{ %f %f %f }\n", v.x, v.y, v.z);
	else
		printf("%s: { %f %f, %f }\n", v.str, v.x, v.y, v.z);
}

vector normalise(vector v) {
	double len = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return v;
}

double ** build_rotation_matrix(vector axis, double theta) {
	axis = normalise(axis);
	
	double x = axis.x;
	double y = axis.y;
	double z = axis.z;

	double c = cos(theta);
	double s = sin(theta);
	double t = 1 - c;

	double ** m = (double **)malloc(4);
	m[0] = (double *)malloc(3);
	m[1] = (double *)malloc(3);
	m[2] = (double *)malloc(3);
	m[3] = (double *)malloc(3);

	m[0][0] = t * x*x + c;
	m[0][1] = t * x*y - s * z;
	m[0][2] = t * x*z + s * y;
	//m[0][3] = 0;

	m[1][0] = t * x*y + s * z;
	m[1][1] = t * y*y + c;
	m[1][2] = t * y*z - s * x;
	//m[1][3] = 0;

	m[2][0] = t * x*z - s * y;
	m[2][1] = t * y*z + s * x;
	m[2][2] = t * z*z + c;
	//m[2][3] = 0;

	return m;
}

void print_matrix(double ** m) {
	int i, j;
	for (i = 0; i < 3; i++) {
		printf("|");
		for (j = 0; j < 3; j++) {
			printf("%f ", m[i][j]);
		}
		printf("|\n");
	}
}

vector rotate_vector(vector v, vector axis, double theta) {
	double ** m = build_rotation_matrix(axis, theta);
	print_matrix(m);
	return v * m;
}

int main()
{
	vector axis = create_vector(1, 0, 0);
	double theta = PI/2;
	vector v = create_vector(0, 1, 0);
	v = rotate_vector(v, axis, theta);
	print_vector(v);
}
