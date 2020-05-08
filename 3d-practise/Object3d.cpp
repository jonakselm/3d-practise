#include "stdafx.h"
#include "Object3d.hpp"

Object3d::Object3d(sf::Vector2f origin2d, sf::Vector3f axis3d)
	:
	m_origin2d(origin2d),
	m_axis3d(axis3d),
	m_xAxis(sf::Lines, 2),
	m_yAxis(sf::Lines, 2),
	m_zAxis(sf::Lines, 2),
	m_axisRotation(0, 0, 0)
{
	m_xAxis[0] = m_origin2d;
	m_xAxis[1] = sf::Vector2f(m_origin2d.x + m_axis3d.x, m_origin2d.y);
	m_xAxis[0].color = sf::Color::Red;
	m_xAxis[1].color = sf::Color::Red;

	m_yAxis[0] = m_origin2d;
	m_yAxis[1] = sf::Vector2f(m_origin2d.x, m_origin2d.y + m_axis3d.y);
	m_yAxis[0].color = sf::Color::Green;
	m_yAxis[1].color = sf::Color::Green;

	m_zAxis[0] = m_origin2d;
	m_zAxis[1] = m_origin2d;
	m_zAxis[0].color = sf::Color::Blue;
	m_zAxis[1].color = sf::Color::Blue;
}

Object3d::~Object3d()
{
}

void Object3d::update()
{
	double cosXAxis = cos(degToRad(m_axisRotation.x));
	double sinXAxis = sin(degToRad(m_axisRotation.x));

	double cosYAxis = cos(degToRad(m_axisRotation.y));
	double sinYAxis = sin(degToRad(m_axisRotation.y));

	double cosZAxis = cos(degToRad(m_axisRotation.z));
	double sinZAxis = sin(degToRad(m_axisRotation.z));


	m_xAxis[1].position.x = m_origin2d.x + (m_axis3d.x * cosYAxis * cosZAxis);
	m_xAxis[1].position.y = m_origin2d.y + (m_axis3d.y * sinZAxis);

	m_yAxis[1].position.y = m_origin2d.y + (m_axis3d.y * cosXAxis * cosZAxis);
	m_yAxis[1].position.x = m_origin2d.x - (m_axis3d.z * sinZAxis);

	m_zAxis[1].position.x = m_origin2d.x - (m_axis3d.z * sinYAxis);
	m_zAxis[1].position.y = m_origin2d.y - (m_axis3d.z * sinXAxis);

	//m_xAxis[1].position.x = m_origin2d.x + (m_axis3d.z * cosZAxis);
	//m_xAxis[1].position.y = m_origin2d.y + (m_axis3d.y * sinZAxis);

	//m_yAxis[1].position.x = m_origin2d.x - (m_axis3d.z * sinZAxis);
	//m_yAxis[1].position.y = m_origin2d.y + (m_axis3d.y * cosZAxis);
}

void Object3d::rotateAbsoluteX(double rotation)
{
	m_axisRotation.x = rotation;
	update();
}

void Object3d::rotateAbsoluteY(double rotation)
{
	m_axisRotation.y = rotation;
	update();
}

void Object3d::rotateAbsoluteZ(double rotation)
{
	m_axisRotation.z = rotation;
	update();
}

void Object3d::rotateRelativeX(double rotation)
{
	m_axisRotation.x += rotation;
	update();
}

void Object3d::rotateRelativeY(double rotation)
{
	m_axisRotation.y += rotation;
	update();
}

void Object3d::rotateRelativeZ(double rotation)
{
	m_axisRotation.z += rotation;
	update();
}

void Object3d::draw(sf::RenderTarget &target)
{
	target.draw(m_xAxis);
	target.draw(m_yAxis);
	target.draw(m_zAxis);
}

double Object3d::degToRad(double degrees)
{
	return degrees * 3.141592653589 / 180;
}
