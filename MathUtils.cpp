#include "MathUtils.h"

/**
 * \fn float MathUtils::ToDegrees(float)
 * \brief converts radians to degrees
 * \param radians radians to be converted to degress
 */
float MathUtils::ToDegrees(float radians)
{
  float radiansToDegrees = 180.0f / 3.1415926535f;
  return radians * radiansToDegrees;
}

/**
 * \fn float MathUtils::ToRadians(float)
 * \brief converts degrees to radians
 * \param degrees degrees to be converted to radians
 */
float MathUtils::ToRadians(float degrees)
{
  float degreesToRadians = 3.1415926535f / 180.0f;
  return degrees * degreesToRadians;
}