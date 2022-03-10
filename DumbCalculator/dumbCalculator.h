#pragma once
//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 1)
//dumbCalculato.h description:
//						The dumbCalculator can add or subtract 2 from an integer, and add or subtract 2 given floats

#define DLLExport __declspec ( dllexport )

class DLLExport dumbCalculator
{
public:
	dumbCalculator();
	~dumbCalculator();
	int AddTwo(int num);
	int SubTwo(int num);
	float FloatAdder(float num1, float num2);
	float FloatSubtraction(float num1, float num2);
};