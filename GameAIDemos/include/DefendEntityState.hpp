#ifndef DEFEND_ENTITY_STATE_H
#define DEFEND_ENTITY_STATE_H

#include "BaseEntityState.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="BaseEntityState">BaseEntityState</see> used for
	/// the defending state of entities.
	/// </summary>
	class DefendEntityState : public BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state.
			/// </summary>
			DefendEntityState();
			/// <summary>
			/// Default destructor.
			/// </summary>
			~DefendEntityState() { }

			/// <summary>
			/// Implementation of the enter() virtual method for the defending
			/// state. Performs any initialization actions necessary upon
			/// entering this state.
			/// </summary>
			void enter();
			/// <summary>
			/// Implementation of the update() virtual method for the defending
			/// state. Carries out the defending state actions.
			/// </summary>
			void update();
			/// <summary>
			/// Implementation of the enter() virtual method for the defending
			/// state. Performs any clean up actions necessary upon exiting
			/// this state.
			/// </summary>
			void exit();

			/// <summary>
			/// Returns a pointer to a new state.
			/// </summary>
			///
			/// <returns>
			/// A pointer to a new state.
			/// </returns>
			BaseEntityState* getNewState();
	};
}

#endif
