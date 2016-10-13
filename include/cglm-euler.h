/*
 * Copyright (c), Recep Aslantas.
 *
 * MIT License (MIT), http://opensource.org/licenses/MIT
 * Full license can be found in the LICENSE file
 */

#ifndef cglm_euler_h
#define cglm_euler_h

#include "cglm.h"

/*!
 * @brief build rotation matrix from euler angles (zxy)
 */
CGLM_INLINE
void
glm_euler_angle(float yaw,
                float pitch,
                float roll,
                mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(pitch); cx = cosf(pitch);
  sy = sinf(yaw);   cy = cosf(yaw);
  sz = sinf(roll);  cz = cosf(roll);

  dest[0][0] = cy * cz - sx * sy * sz;
  dest[0][1] = cy * sz + cz * sx * sy;
  dest[0][2] =-cx * sy;
  dest[1][0] =-cx * sz;
  dest[1][1] = cx * cz;
  dest[1][2] = sx;
  dest[2][0] = cz * sy + cy * sx * sz;
  dest[2][1] = sy * sz - cy * cz * sx;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][3] = 1.0f;
}

/*!
 * @brief build rotation matrix from euler angles/yaw-pitch-roll (xyz)
 */
CGLM_INLINE
void
glm_yaw_pitch_roll(float yaw,
                   float pitch,
                   float roll,
                   mat4 dest) {
  float cx, cy, cz,
        sx, sy, sz;

  sx = sinf(pitch); cx = cosf(pitch);
  sy = sinf(yaw);   cy = cosf(yaw);
  sz = sinf(roll);  cz = cosf(roll);

  dest[0][0] = cy * cz;
  dest[0][1] = cz * sx * sy - cx * sz;
  dest[0][2] = cx * cz * sy + sx * sz;
  dest[1][0] = cy * sz;
  dest[1][1] = cx* cz + sx * sy * sz;
  dest[1][2] =-cz * sx + cx * sy * sz;
  dest[2][0] =-sy;
  dest[2][1] = cy * sx;
  dest[2][2] = cx * cy;
  dest[0][3] = 0.0f;
  dest[1][3] = 0.0f;
  dest[2][3] = 0.0f;
  dest[3][3] = 1.0f;
}

#endif /* cglm_euler_h */