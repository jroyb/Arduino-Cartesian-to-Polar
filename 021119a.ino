#include <math.h>
#define PI 3.141592654

bool convertDegrees = false; // Set to true if theta is wanted in degrees instead of radians.

void setup() {
  // Your code here.
}

void loop() {
  // Your code here.
}

// RETURNS: the maginuted of a 2D cartesian point
double returnMagnitude (double x, double y) {
  return sqrt(x * x + y * y);
}

// RETURNS: the theta of a 2D cartesian point from 0 to 2 PI rather than
//          0 to PI / 4 like a basic atan(double) math function.
double returnTheta(double x, double y) {
  double theta = 0;

  if (x > 0) {
    if (y > 0) { // (X > 0, Y > 0) First quadrant
      theta = atan(abs(y) / abs(x));
    } else if (y < 0) { // (X > 0, Y < 0) Fourth quadrant
      theta = (double) 2 * PI - atan(abs(y) / abs(x));
    } else { // (X > 0, Y = 0) theta is equal to 0 (0)
      theta = 0;
    }
  } else if (x < 0) {
    if (y > 0) { // (X < 0, Y > 0) Second quadrant
      theta = PI - atan(abs(y) / abs(x));
    } else if (y < 0) { // (X < 0, Y < 0) Third quadrant
      theta = PI + atan(abs(y) / abs(x));
    } else {  // (X < 0, Y = 0) theta is equal to PI (180)
      theta = PI;
    }
  } else {
    if (y > 0) { // (X = 0, Y > 0) theta is equal to PI / 2 (90)
      theta = PI / (double) 2;
    } else if (y < 0) { // (X = 0, Y < 0) theta is equal to 3 * PI / 2 (270)
      theta = (double) 3 * PI / (double) 2;
    }
    else {
      // (X = 0, Y = 0) Technically no direction, therefore set to null.
      // Can be changed to something else depending on programmers need.
      theta = NULL;
    }
  }

  // Converts theta from radians to degrees
  if (theta != NULL and convertDegrees) {
    theta = theta * ((double) 180 / PI);
  }

  return theta;
}
