#include "KeyEventListener.h"

namespace cae
{
	template<typename T>
	void KeyEventArgs<T>::setValue(const T iVal)
	{
		mValue = iVal;
	}

	template<typename T>
	const T& KeyEventArgs<T>::getValue()
	{
		return mValue;
	}

	template<typename T>
	const Event& KeyEventArgs<T>::getEvent()
	{
		return mSrcEvent;
	}

	KeyEventListener::KeyEventListener(Event& iEventNum, Event& iEventStr)
		:mEventNum(iEventNum),mEventStr(iEventStr)
	{
		iEventNum += ([&](const EventArgs& eventArgs) { this->onNumber(eventArgs); });
		iEventStr += ([&](const EventArgs& eventArgs) { this->onString(eventArgs); });
	}

	void KeyEventListener::onNumber(const EventArgs& iArgs)
	{
		EventArgs* tmpArgs = const_cast<EventArgs*>(&iArgs);
		KeyEventArgs<std::string>* strEventArgs = dynamic_cast<KeyEventArgs<std::string>*>(tmpArgs);
		
		std::cout << "N: " << strEventArgs->getValue() << std::endl;
	}

	void KeyEventListener::onString(const EventArgs& iArgs)
	{
		EventArgs* tmpArgs = const_cast<EventArgs*>(&iArgs);
		KeyEventArgs<std::string>* strEventArgs = dynamic_cast<KeyEventArgs<std::string>*>(tmpArgs);

		std::cout << "S: " << strEventArgs->getValue() << std::endl;
	}

}
