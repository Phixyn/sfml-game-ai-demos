#include "../include/BaseEntityState.hpp"

GameAIDemos::BaseEntityState::BaseEntityState(std::string stateName) : m_stateName(stateName)
{
}

std::string GameAIDemos::BaseEntityState::getStateName()
{
	return m_stateName;
}
