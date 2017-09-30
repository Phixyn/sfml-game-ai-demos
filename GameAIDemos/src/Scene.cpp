#include "../include/Scene.hpp"

/// <summary>
/// Sets <see cref="m_game_ptr">m_game_ptr</see> to the reference of Game in
/// the parameter.
/// </summary>
GameAIDemos::Scene::Scene(Game &game) :
	m_game_ptr(&game)
{

}
