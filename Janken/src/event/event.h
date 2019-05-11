#pragma once

#include <functional>

template <typename ret, typename arg>
class Event
{
public:
	void set(const std::function<ret(arg)>& callback)
	{
		callback_ = callback;
	}

	inline ret invoke(arg rhs = arg())
	{
		if (callback_) {
			callback_(rhs);
		}
	}

private:
	std::function<ret(arg)> callback_;
};

template <>
class Event<void, void>
{
public:
	void set(const std::function<void()>& callback)
	{
		callback_ = callback;
	}

	inline void invoke()
	{
		if (callback_) {
			callback_();
		}
	}

private:
	std::function<void()> callback_;
};