#ifndef FLEE_ENTITY_STATE_H
#define FLEE_ENTITY_STATE_H

#include "BaseEntityState.hpp"
#include "PlayerEntity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="BaseEntityState">BaseEntityState</see> used for
	/// the fleeing state of an entity. In this state, an entity is moving away
	/// from a target entity.
	/// </summary>
	class FleeEntityState : public BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state. Initializes member variables for the
			/// source and target entity pointers.
			/// </summary>
			///
			/// <param name="source">
			/// A pointer to the source entity of this state. This is the
			/// entity that is currently in this state. We need to be able to
			/// access and modify the entity's position and velocity, according
			/// to the target's position.
			/// </param>
			/// <param name="target">
			/// A reference to the target entity to flee from. We need access
			/// to the target's position, so we can move away from it.
			/// </param>
			///
			/// <seealso cref="LiveEntity" />
			/// <seealso cref="PlayerEntity" />
			FleeEntityState(LiveEntity* source, PlayerEntity& target);
			// TODO LiveEntity has to be a pointer because 'this' returns a pointer
			// FleeEntityState(SeekEntity& source, PlayerEntity& target);

			/// <summary>
			/// Default destructor.
			/// </summary>
			~FleeEntityState() { }

			/// <summary>
			/// Implementation of the enter() virtual method for the flee
			/// state. Performs any initialization actions necessary upon
			/// entering this state.
			/// </summary>
			void enter();
			/// <summary>
			/// Implementation of the update() virtual method for the flee
			/// state. Carries out the seek state actions.
			/// </summary>
			void update();
			/// <summary>
			/// Implementation of the enter() virtual method for the flee
			/// state. Performs any clean up actions necessary upon exiting
			/// this state.
			/// </summary>
			void exit();

			/// <summary>
			/// Implementation of the getNewState() virtual method for the
			/// flee state. Returns a pointer to a new state.
			/// </summary>
			///
			/// <returns>
			/// A pointer to a new state.
			/// </returns>
			BaseEntityState* getNewState();
		private:
			/// <summary>
			/// A pointer to a LiveEntity object, necessary to access and
			/// modify the current entity's position and velocity in order to
			/// flee from the target entity.
			/// </summary>
			///
			/// <seealso cref="LiveEntity" />
			LiveEntity* m_sourcePtr;
			/// <summary>
			/// A pointer to a PlayerEntity object, necessary to access the
			/// player's position in order to calculate the required velocity
			/// for the target to flee from them.
			/// </summary>
			///
			/// <seealso cref="PlayerEntity" />
			PlayerEntity* m_playerPtr;
	};
}

#endif
