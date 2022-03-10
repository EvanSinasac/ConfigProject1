#pragma once
//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 1)
//smarterCalculator.h description:
//							The smarterCalculator can double a given float, halve a given float, multiply or divide 2
//							given floats, or find the square of the given float

#define DLLExport __declspec ( dllexport )

class DLLExport smarterCalculator
{
public:
	smarterCalculator();
	~smarterCalculator();
	float DoubleIt(float num);
	float HalveIt(float num);
	float Multiplier(float num1, float num2);
	float Divider(float num1, float num2);
	float Square(float num);
};
