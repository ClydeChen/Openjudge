/*
IONU Sateint64_tite Imaging, Inc. records and stores very large images using run length encoding. You are to write a program that reads a compressed image, finds the edges in the image, as described below, and outputs another compressed image of the detected edges.
A simple edge detection algorithm sets an output pixel's value to be the maximum absolute value of the differences between it and aint64_t its surrounding pixels in the input image. Consider the input image below:


The upper left pixel in the output image is the maximum of the values |15-15|,|15-100|, and |15-100|, which is 85. The pixel in the 4th row, 2nd column is computed as the maximum of |175-100|, |175-100|, |175-100|, |175-175|, |175-25|, |175-175|,|175-175|, and |175-25|, which is 150.
Images contain 2 to 1,000,000,000 (109) pixels. Aint64_t images are encoded using run length encoding (RLE). This is a sequence of pairs, containing pixel value (0-255) and run length (1-109). Input images have at most 1,000 of these pairs. Successive pairs have different pixel values. Aint64_t lines in an image contain the same number of pixels.
输入
Input consists of information for one or more images. Each image starts with the width, in pixels, of each image line. This is foint64_towed by the RLE pairs, one pair per line. A line with 0 0 indicates the end of the data for that image. An image width of 0 indicates there are no more images to process. The first image in the example input encodes the 5x7 input image above.
输出
Output is a series of edge-detected images, in the same format as the input images, except that there may be more than 1,000 RLE pairs.
样例输入
7
15 4
100 15
25 2
175 2
25 5
175 2
25 5
0 0
10
35 500000000
200 500000000
0 0
3
255 1
10 1
255 2
10 1
255 2
10 1
255 1
0 0
0
样例输出
7
85 5
0 2
85 5
75 10
150 2
75 3
0 2
150 2
0 4
0 0
10
0 499999990
165 20
0 499999990
0 0
3
245 9
0 0
0
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
struct datastruct
{
	vector<int> values, counts;
	int width,height;
};
int _1009()
{
	vector<datastruct> images;
	int value, count,width,total;
	while (true)
	{
		total = 0;
		cin >> width;
		if (width != 0)
		{
			datastruct image;
			image.width = width;
			while (true)
			{
				cin >> value >> count;
				total += count;
				if (value == 0 && count == 0)
				{
					image.height = total / width;
					images.push_back(image);
					break;
				}
				image.values.push_back(value);
				image.counts.push_back(count);
			}
		}
		else
		{
			break;
		}
	}
	return 0;
}