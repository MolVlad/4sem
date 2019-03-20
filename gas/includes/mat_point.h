#ifndef __MAT_POINT_H__
#define __MAT_POINT_H__

#include <string>
#include <vector>
#include "vector2.h"

class MaterialPoint
{
  public:
  MaterialPoint();

  virtual ~MaterialPoint();

  virtual void updatePosition(const float dt);

  my_math::Vector2 getImpulse() const;

  my_math::Vector2 position;
  my_math::Vector2 velocity;
  my_math::Vector2 acceleration;

  float mass;
};

#endif /* __MAT_POINT_H__ */
