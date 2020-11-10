#pragma once

#include <iostream>
#include <Event.h>
#include <EventArgs.h>

namespace cae
{
    template <typename T>
    class KeyEventArgs : public EventArgs
    {
        public:
            KeyEventArgs(const Event& iSrcEvent, const T iVal)
                : mSrcEvent(iSrcEvent), mValue(iVal) { };
            void setValue(const T iVal);
            const T& getValue();
            const Event& getEvent();

        private:
            const Event& mSrcEvent;
            const T mValue;
    };

  class KeyEventListener
  {
  public:
    KeyEventListener(Event& iEventNum, Event& iEventStr);

    ~KeyEventListener() = default;

  private:
    void onNumber(const EventArgs& iArgs);

    void onString(const EventArgs& iArgs);

    Event& mEventNum;
    Event& mEventStr;
  };

}
