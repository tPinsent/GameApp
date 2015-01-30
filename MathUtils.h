#pragma once
/**
 * \class MathUtils.h
 * \brief holds definitions of the Vector structs as well as the funcions toRadians and toDegrees
 * \author Justin Wilkinson
 * \date January 29, 2015
 */



// A structure to hold two floats. Similar to SDL_Point (though it contains ints).
struct Vector2
{
  float x;
  float y;
};

struct Vector3
{
  float x;
  float y;
  float z;
};

struct Vector4
{
  float x;
  float y;
  float z;
  float w;
};

struct Transform
{
  Vector3 position;
  Vector3 rotation;
  Vector3 scale;
};

class MathUtils
{
public:

/**
 * \fn float MathUtils::ToDegrees(float)
 * \brief converts radians to degrees
 * \param radians radians to be converted to degress
 */
  static float ToRadians(float degrees);

/**
 * \fn float MathUtils::ToRadians(float)
 * \brief converts degrees to radians
 * \param degrees degrees to be converted to radians
 */
  static float ToDegrees(float radians);
};