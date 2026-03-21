#pragma once
#include <corecrt_math.h>
// Matrix4 class built from Vscott OpenGL - used for building/Rendering example libraries from the book
class Matrix4
{
	Matrix4(
		float a,  float b,  float c,  float d,
		float a1, float b1, float c1, float d1,
		float a2, float b2, float c2, float d2,
		int x,	  int y,    int z,    int w
		);

	Matrix4 buildTranslate(float x, float y, float z)
	{
		Matrix4 trans = Matrix4(
			1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			x, y, z, 1.0);
		return trans;
	}


	// builds and returns a matrix that performs a rotation around the X axis
	Matrix4 buildRotateX(float rad)
	{
		Matrix4 xrot = Matrix4(
			1.0,	0.0,		0.0,		0.0,
			0.0,	cos(rad),	-sin(rad),	0.0,
			0.0,	sin(rad),	cos(rad),	0.0,
			0.0,	0.0,		0.0,		1.0);
		return xrot;
	}


	// builds and returns a matrix that performs a rotation around the Y axis
	Matrix4 buildRotateY(float rad)
	{
		Matrix4 yrot = Matrix4(cos(rad), 0.0, sin(rad), 0.0,
			0.0, 1.0, 0.0, 0.0,
			-sin(rad), 0.0, cos(rad), 0.0,
			0.0, 0.0, 0.0, 1.0);
		return yrot;
	}

	// builds and returns a matrix that performs a rotation around the Z axis
	Matrix4 buildRotateZ(float rad)
	{
		Matrix4 zrot = Matrix4(cos(rad), -sin(rad), 0.0, 0.0,
			sin(rad), cos(rad), 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
		return zrot;
	}

	// builds and returns a scale matrix
	Matrix4 buildScale(float x, float y, float z)
	{
		Matrix4 scale = Matrix4(x, 0.0, 0.0, 0.0,
			0.0, y, 0.0, 0.0,
			0.0, 0.0, z, 0.0,
			0.0, 0.0, 0.0, 1.0);
		return scale;
	}

};

