//Evan Sinasac - 1081418
//INFO6025 Configuration and Deployment (Project 1)
//smarterCalculator.cpp description:
//							Functions for the smartCalculator as defined by their names and in the header file

#include "smarterCalculator.h"

smarterCalculator::smarterCalculator()
{

}

smarterCalculator::~smarterCalculator()
{

}

float smarterCalculator::DoubleIt(float num)
{
	return num * 2;
}

float smarterCalculator::HalveIt(float num)
{
	return num / 2;
}

float smarterCalculator::Multiplier(float num1, float num2)
{
	return num1 * num2;
}

float smarterCalculator::Divider(float num1, float num2)
{
	return num1 / num2;
}

float smarterCalculator::Square(float num)
{
	return num * num;
}