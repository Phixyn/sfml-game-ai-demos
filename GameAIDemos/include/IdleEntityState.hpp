#ifndef IDLE_ENTITY_STATE_H
#define IDLE_ENTITY_STATE_H

#include "BaseEntityState.hpp"
#include "LiveEntity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="BaseEntityState">BaseEntityState</see> used for
	/// the idling state. In this state, an entity is not performing any
	/// specific action (but may still be moving in a specified direction).
	/// </summary>
	class IdleEntityState : public BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state.
			/// Initializes the <see cref="LiveEntity">LiveEntity</see>
			/// source pointer to nullptr.
			///
			/// TODO: We only need this for the Entity class. Maybe we can fix
			/// this by refactoring Entity a bit.
			/// </summary>
			IdleEntityState();
			/// <summary>
			/// Overloaded constructor taking a parameter containing a pointer
			/// to a <see cref="LiveEntity">LiveEntity</see> object.
			/// Initializes the member variable for the source entity pointer.
			/// </summary>
			///
			/// <param name="source">
			/// A pointer to the source entity of this state. This is the
			/// entity that is currently in this state. We need to be able to
			/// modify its sprite color in the enter() method.
			/// </param>
			///
			/// <seealso cref="LiveEntity" />
			IdleEntityState(LiveEntity* source);
			/// <summary>
			/// Default destructor.
			/// </summary>
			~IdleEntityState() { }

			/// <summary>
			/// Implementation of the enter() virtual method for the idling
			/// state. Performs any initialization actions necessary upon
			/// entering this state.
			/// </summary>
			void enter();
			/// <summary>
			/// Implementation of the update() virtual method for the idling
			/// state. Carries out the idling state actions.
			/// </summary>
			void update();
			/// <summary>
			/// Implementation of the enter() virtual method for the idling
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
		private:
			/// <summary>
			/// A pointer to a LiveEntity object. We use this to modify the
			/// entity's sprite color when it enters the Idle state.
			/// </summary>
			///
			/// <seealso cref="LiveEntity" />
			LiveEntity* m_sourcePtr;
	};
}

#endif
