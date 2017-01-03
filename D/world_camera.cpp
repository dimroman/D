#include "world_camera.h"
#include "options.h"

extern options g_options;

math::float4x4 world_camera::look_at_right_handed()
{
	recalculate_axis();
	return view_right_handed();
}

void world_camera::recalculate_axis()
{
	m_axis_z = math::normalize(m_position - m_target_position);
	m_axis_x = math::normalize(cross(m_up_direction, m_axis_z));
	m_axis_y = math::cross(m_axis_z, m_axis_x);
}

math::float4x4 world_camera::view_right_handed() const
{
	math::float4x4 orientation{
		{ m_axis_x.x, m_axis_y.x, m_axis_z.x, 0.0f },
		{ m_axis_x.y, m_axis_y.y, m_axis_z.y, 0.0f },
		{ m_axis_x.z, m_axis_y.z, m_axis_z.z, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	math::float4x4 translation{
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ -m_position.x, -m_position.y, -m_position.z, 1.0f }
	};

	return orientation*translation;
}

math::float4x4 world_camera::perspective_projection_right_handed() const
{
	math::float4x4 result;

	result.m[1][1] = 1 / (float)tan(0.5f * math::to_radians( g_options.field_of_view ));
	result.m[0][0] = result.m[1][1] / g_options.aspect_ratio();
	result.m[2][2] = -g_options.far_plane / (g_options.far_plane - g_options.near_plane);
	result.m[2][3] = -g_options.far_plane * g_options.near_plane / (g_options.far_plane - g_options.near_plane);
	result.m[3][2] = -1.0f;

	return result;
}

void world_camera::move_x(float const value)
{
	m_position = m_position + m_axis_x*value*10;
}

void world_camera::move_y(float const value)
{
	m_position = m_position + m_axis_y*value*10;
}