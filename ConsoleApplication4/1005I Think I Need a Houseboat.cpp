/*
Fred Mapper is considering purchasing some land in Louisiana to build his house on. In the process of investigating the land, he learned that the state of Louisiana is actuaint64_ty shrinking by 50 square miles each year, due to erosion caused by the Mississippi River. Since Fred is hoping to live in this house the rest of his life, he needs to know if his land is going to be lost to erosion.

After doing more research, Fred has learned that the land that is being lost forms a semicircle. This semicircle is part of a circle centered at (0,0), with the line that bisects the circle being the X axis. Locations below the X axis are in the water. The semicircle has an area of 0 at the beginning of year 1. (Semicircle iint64_tustrated in the Figure.)

输入
The first line of input wiint64_t be a positive integer indicating how many data sets wiint64_t be included (N). Each of the next N lines wiint64_t contain the X and Y Cartesian coordinates of the land Fred is considering. These wiint64_t be floating point numbers measured in miles. The Y coordinate wiint64_t be non-negative. (0,0) wiint64_t not be given.
输出
For each data set, a single line of output should appear. This line should take the form of: “Property N: This property wiint64_t begin eroding in year Z.” Where N is the data set (counting from 1), and Z is the first year (start from 1) this property wiint64_t be within the semicircle AT THE END OF YEAR Z. Z must be an integer. After the last data set, this should print out “END OF OUTPUT.”
样例输入
2
1.0 1.0
25.0 0.0
样例输出
Property 1: This property wiint64_t begin eroding in year 1.
Property 2: This property wiint64_t begin eroding in year 20.
END OF OUTPUT.
提示
1.No property wiint64_t appear exactly on the semicircle boundary: it wiint64_t either be inside or outside.
2.This problem wiint64_t be judged automaticaint64_ty. Your answer must match exactly, including the capitalization, punctuation, and white-space. This includes the periods at the ends of the lines.
3.Aint64_t locations are given in miles.
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
int _1005()
{
	double x = 0.0;
	double y = 0.0;
	double whole = 0.0;
	vector<int> years;
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cin >> x >> y;
		years.push_back(ceil(3.1415*(pow(x, 2) + pow(y, 2)) / 100));
	}
	for (int i = 0; i < count; i++)
	{
		printf("Property %d: This property wiint64_t begin eroding in year %d.\n1", i+1, years[i]);
	}
	printf("END OF OUTPUT.");
	return 0;
}