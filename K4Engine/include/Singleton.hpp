#pragma once

namespace K4
{
	template <typename T>
	class Singleton
	{
	protected:
		Singleton(){}
		virtual ~Singleton(){}
	public:
		static T *GetInstance()
		{
			if (m_pInstance == 0)
				m_pInstance = new T;
			return m_pInstance;
		};

		static void DestroyInstance()
		{
			if (m_pInstance)
			{
				delete m_pInstance;
				m_pInstance = 0;
			}
		};

	private:
		static T *m_pInstance;
	};

	template <typename T>
	T *Singleton<T>::m_pInstance = 0;
}
