#ifndef ATTACK_ENTITY_STATE_H
#define ATTACK_ENTITY_STATE_H

#include "BaseEntityState.hpp"
#include "LiveEntity.hpp"

namespace GameAIDemos
{
	/// <summary>
	/// Subclass of <see cref="BaseEntityState">BaseEntityState</see> used for
	/// the attacking state of entities.
	/// </summary>
	class AttackEntityState : public BaseEntityState
	{
		public:
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state.
			/// </summary>
			AttackEntityState();
			/// <summary>
			/// Default constructor. Calls the super class constructor, passing
			/// in the name of this state.
			/// </summary>
			///
			/// <param> TODO </param>
			AttackEntityState(LiveEntity* target);
			/// <summary>
			/// Default destructor.
			/// </summary>
			~AttackEntityState() { }

			/// <summary>
			/// Implementation of the enter() virtual method for the attacking
			/// state. Performs any initialization actions necessary upon
			/// entering this state.
			/// </summary>
			///
			/// <param> TODO </param>
			void enter();
			/// <summary>
			/// Implementation of the update() virtual method for the attacking
			/// state. Carries out the attacking state actions.
			/// </summary>
			void update();
			/// <summary>
			/// Implementation of the enter() virtual method for the attacking
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

			/// <summary>
			/// TODO (+ make private)
			/// </summary>
			LiveEntity* m_target;
	};
}

#endif
