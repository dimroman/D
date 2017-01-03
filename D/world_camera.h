#ifndef WORLD_CAMERA_H_INCLUDED
#define WORLD_CAMERA_H_INCLUDED

#include "math.h"

class world_camera {
public:
	math::float4x4 look_at_right_handed();
	math::float4x4 perspective_projection_right_handed() const;

	void set_position(math::float3 const position) { m_position = position; }
	void set_target_position(math::float3 const target_position) { m_target_position = target_position; }
	void set_up_direction(math::float3 const up_direction) { m_up_direction = up_direction; }

	void move_x(float const value);
	void move_y(float const value);

private:
	math::float4x4 view_right_handed() const;
	void recalculate_axis();
private:
	math::float3 m_position{ 0.0f, 15.0f, -30.0f };
	math::float3 m_target_position{ 0.0f, 8.0f, 0.0f };
	math::float3 m_up_direction{ 0.0f, 1.0f, 0.0f };

	math::float3 m_axis_x;
	math::float3 m_axis_y;
	math::float3 m_axis_z;
};

#endif // #ifndef WORLD_CAMERA_H_INCLUDED