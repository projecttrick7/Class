#include <hash_map>
#include <string>

namespace Du3Porject
{
	class IState abstract
	{
	public:
		virtual void UpdateState(float elapsedTime);

		virtual void Render();

		virtual void OnEnter(void* p_date);

		virtual void OnExit();
	};

	class EmptyState : IState
	{
	public:
		virtual void UpdateState(float elapsedTime)
		{

		}

		virtual void Render()
		{

		}

		virtual void OnEnter(void* p_data)
		{

		}

		virtual void OnExit()
		{

		}
	};

	class StateMachine
	{
	private:
		stdext::hash_map < std::string, IState> mStates;
		EmptyState mCurrentState;
	public:
		StateMachine(stdext::hash_map <std::string, IState>_mStates, EmptyState _mCurrentState) : mStates(_mStates), mCurrentState(_mCurrentState)
		{

		}

		void UpdateState(float eapsedTime)
		{
			mCurrentState.Render();
		}

		void Render()
		{
			mCurrentState.Render();
		}

		void Change(std::string stateName, void* p_data)
		{
			mCurrentState.OnExit();
			// mCurrentState = mStates[stateName];
			mCurrentState.OnEnter(p_data);
		}

		void Add(std::string name, stdext::hash_map <std::string, IState> state)
		{
			mStates[name] = state[name];
		}

	};

}