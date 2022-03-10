INFO6025 Configuration & Deployment (Project 1)
Evan Sinasac - 1081418

I built and compiled using Visual Studios 2019 in Debug and 64 bit.  Will also work in Release and 64 bit, will not run in 32 bit.

There is an executable in the x64 folder on the solution level.

I have difficulties when it comes to making creative decisions when there's a time constraint, and the only idea I could come up with to show myself using the GTest library was to make two small calculator like classes that could pass their results to each other.

So there are 15 tests, the first 5 use a test fixture for the "DumbCalculator" to test the results of the functions.  The next 3 use a test fixture to test the results of the functions of the "SmarterCalculator", followed by 2 IntegrationTests with purposeful wrong results to test 'bad' cases.  The next 4 tests use a test fixture with both parts of the calculator included and test passing results from one to the other, vice versa, and with both passing results back and forth.  One final Integration Test passing the results from the FloatAdder function in the "DumbCalculator" to the square function in the "SmarterCalculator".

I use std::system("pause") so that running the executable keeps the command prompt open.  Otherwise, just close the command prompt/press two buttons to close it when running through Visual Studio.