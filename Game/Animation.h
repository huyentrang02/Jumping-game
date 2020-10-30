#pragma once
#include <SFML/Graphics.hpp>

class Animation
	:public sf::Sprite
{

public:
	Animation(sf::Vector2i numFrames, float frameTime);
	void ApplyRect();
	void CalculateSize();
	void Update(float deltaTime);

private:
	sf::IntRect m_Rect;
	sf::Vector2i m_RectUV;
	sf::Vector2i m_Size;
	sf::Vector2i m_NumFrames;
	sf::Vector2i m_CurrentFrame;

	float m_CurrentTime;
	float m_FrameTime;
};