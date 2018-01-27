#ifndef BASE_ENTITY_STATE_H
#define BASE_ENTITY_STATE_H

#include <string>

namespace GameAIDemos
{
	/// <summary>
	/// Base state class for entities in the game. A state defines an entity's
	/// current actions in the game. For example, an entity can be fleeing from
	/// another entity, or seeking an entity.
	/// </summary>
	class BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor.
			/// </summary>
			BaseEntityState() { }
			/// <summary>
			/// Overloaded constructor which takes a string parameter for the
			/// name of the state.
			/// </summary>
			///
			/// <param name="stateName">
			/// The name of this state.
			/// </param>
			BaseEntityState(std::string stateName);
			/// <summary>
			/// Default destructor.
			/// </summary>
			~BaseEntityState() { }

			/// <summary>
			/// Pure virtual method to perform setup actions to enter a state.
			/// </summary>
			virtual void enter() = 0;
			/// <summary>
			/// Pure virtual method to execute actions in a state.
			/// </summary>
			virtual void update() = 0;
			/// <summary>
			/// Pure virtual method to perform cleanup actions and exit a
			/// state.
			/// </summary>
			virtual void exit() = 0;
			/// <summary>
			/// Pure virtual method to return a pointer to a new state.
			/// </summary>
			///
			/// <returns>
			/// A pointer to a new state.
			/// </returns>
			virtual BaseEntityState* getNewState() = 0;

			/// <summary>
			/// Returns the state's name.
			/// </summary>
			///
			/// <returns>
			/// A string containing the state's name.
			/// </returns>
			std::string getStateName();
		private:
			/// <summary>
			/// The name of the state.
			/// </summary>
			std::string m_stateName;
	};
}

#endif
