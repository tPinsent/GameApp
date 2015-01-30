#include "Timer.h"
#include <SDL.h>


Timer::Timer() : _duration(0.0f) 
{
  Stop();
}
/**
 * \fn coid Timer::Update()
 * \brief used to update the timmer
 */
void Timer::Update()
{
  if (_state == RUNNING)
  {
    _oldTime = _currentTime;
    _currentTime = SDL_GetTicks();
    _deltaTime = (_currentTime - _oldTime) / 1000;

    _elapsedTime += _deltaTime;

    if (_duration > 0.0f && _elapsedTime >= _duration)
    {
      Stop();
    }
  }
}

/**
 * \fn void Timer::Start()
 * \brief used to start the timer
 */
void Timer::Start()
{
  if (_state != PAUSED)
  {
    _oldTime = _currentTime = SDL_GetTicks();
  }

  _state = RUNNING;
}

/**
 * \fn void Timer::Pause()
 * \brief used to pause the timer
 */
void Timer::Pause()
{
  _state = PAUSED;
  _deltaTime = 0;
}

/**
 * \fn void Timer::Stop()
 * \brief used to stop the timer
 */
void Timer::Stop()
{
  _state = STOPPED;
  Reset();
}

/**
 * \fn void Timer::Reset()
 * \brief used to reset the timer
 */
void Timer::Reset()
{
  _deltaTime = 0;
  _elapsedTime = 0;
  _currentTime = 0;
}

/**
 * \fn float Timer::GetElapsedTime()
 * \brief returns elapsed time
 */
float Timer::GetElapsedTime()
{
  return _elapsedTime;
}

/**
 * \fn float Timer::GetDeltaTime()
 * \brief returns the change in time
 */
float Timer::GetDeltaTime()
{
  return _deltaTime;
}

/**
 * \fn float Timer::GetDuration()
 * \brief returns the duration
 */
float Timer::GetDuration()
{
  return _duration;
}

/**
 * \fn void Timer::SetDuration(Float)
 * \brief sets the duration
 * \param duration duration to set
 */
void Timer::SetDuration(float duration)
{
  _duration = duration;
}

/**
 * \fn void Timer::SetTimerEvent(TimerEvent)
 * \brief sets the timer event to passed event
 * \param evt TimerEvent to set
 */
void Timer::SetTimerEvent(TimerEvent evt)
{
  _timerEvt = nullptr;
  _timerInstEvt = nullptr;

  _timerEvt = evt;
}

/**
 * \fn void Timer::SetTimerEvent(TimerInstanceEvent)
 * \brief sets the timer event to passed event
 * \param evt TimerInstnaceEvent to set
 */
void Timer::SetTimerEvent(TimerInstanceEvent evt)
{
  _timerEvt = nullptr;
  _timerInstEvt = nullptr;

  _timerInstEvt = evt;
}