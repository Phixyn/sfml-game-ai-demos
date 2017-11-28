#ifndef DEAD_ENTITY_STATE_H
#define DEAD_ENTITY_STATE_H

#include "BaseEntityState.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="BaseEntityState">BaseEntityState</see> used for
	/// the dead state of entities.
	/// </summary>
	class DeadEntityState : public BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state.
			/// </summary>
			DeadEntityState();
			/// <summary>
			/// Default destructor.
			/// </summary>
			~DeadEntityState() { }

			/// <summary>
			/// Implementation of the enter() virtual method for the dead
			/// state. Performs any initialization actions necessary upon
			/// entering this state.
			/// </summary>
			void enter();
			/// <summary>
			/// Implementation of the update() virtual method for the dead
			/// state. Carries out the dead state actions.
			/// </summary>
			void update();
			/// <summary>
			/// Implementation of the enter() virtual method for the dead
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
