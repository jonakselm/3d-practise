#pragma once

class Object3d
{
public:
	Object3d(sf::Vector2f origin2d, sf::Vector3f axis3d);
	~Object3d();

	void update();

	void rotateAbsoluteX(double rotation);
	void rotateAbsoluteY(double rotation);
	void rotateAbsoluteZ(double rotation);

	void rotateRelativeX(double rotation);
	void rotateRelativeY(double rotation);
	void rotateRelativeZ(double rotation);

	void draw(sf::RenderTarget &target);

private:
	double degToRad(double degrees);

private:
	sf::VertexArray m_xAxis, m_yAxis, m_zAxis;
	const sf::Vector2f m_origin2d;
	sf::Vector3f m_axis3d;
	sf::Vector3f m_axisRotation;
};