// Implementation of sliding window
#include <iostream>
#include <sstream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <opencv2/opencv.hpp>

#define RED Scalar(0, 0, 255)
#define BLUE Scalar(255, 0, 0)

using namespace std;
using namespace cv;

Mat main_image;
Mat output_image;

vector<Mat> regions;

void syntax()
{
  printf("sliding_window [image] [w] [h] [step]\n");
}

int main(int argc, char **argv)
{
  if(argc != 5)
  {
    syntax();
    return false;
  }

  cout << "Using OpenCV Version: " << CV_VERSION << endl;

  main_image = imread(argv[1], 1);
  main_image.copyTo(output_image);
  int width = main_image.cols;
  int height = main_image.rows;

  int w = atoi(argv[2]);
  int h = atoi(argv[3]);
  int step = atoi(argv[4]);

  // slide
  for(int c = 0; c < width - (width % step); c += step)
  {
    for(int r = 0; r < height - (height % step); r += step)
    {
      Rect rect_region(c, r, step, step);

      // Extract region as a Mat
      Mat region = main_image(rect_region);
      regions.push_back(region);

      // draw
      Point p_start(c, r);
      Point p_end(c + w, r + h);
      rectangle(output_image, p_start, p_end, RED);
    }
  }

  return 0;
}
