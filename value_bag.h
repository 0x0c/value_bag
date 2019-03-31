#pragma once

namespace m2d
{
template <typename T>
class value_bag
{
protected:
	T _value;

public:
	value_bag(T value)
	{
		this->_value = value;
	}

	virtual void set(T value) = 0;
	virtual T peek() = 0;
	virtual T take() = 0;
};

template <typename T>
class default_value_bag : public value_bag<T>
{
private:
	T _default_value;

public:
	default_value_bag(T value, T default_value)
	    : value_bag<T>(value)
	{
		this->_default_value = default_value;
	}

	void set(T value)
	{
		this->_value = value;
	}

	T peek()
	{
		return this->_value;
	}

	T take()
	{
		auto v = this->_value;
		this->revert();
		return v;
	}

	void revert()
	{
		this->_value = this->_default_value;
	}
};

template <typename T>
class toggle_value_bag : public value_bag<T>
{
private:
	T _value1;
	T _value2;

public:
	toggle_value_bag(T value1, T value2)
	    : value_bag<T>(value1)
	{
		this->_value1 = value1;
		this->_value2 = value2;
	}

	toggle_value_bag(T value1, T value2, T current_value)
	    : value_bag<T>(current_value)
	{
		this->_value1 = value1;
		this->_value2 = value2;
	}

	void set(T value)
	{
	}

	T peek()
	{
		return this->_value;
	}

	T take()
	{
		auto v = this->_value;
		this->toggle();
		return v;
	}

	void toggle()
	{
		auto v = this->_value;
		if (v == this->_value1) {
			this->_value = this->_value2;
		}
		else {
			this->_value = this->_value1;
		}
	}
};

template <typename T>
class once_value_bag : public value_bag<T>
{
private:
	T _invalid_value;

public:
	once_value_bag(T value, T invalid_value)
	    : value_bag<T>(value)
	{
		this->_invalid_value = invalid_value;
	}

	void set(T value)
	{
	}

	T peek()
	{
		return this->_value;
	}

	T take()
	{
		auto v = this->_value;
		this->invalidate();
		return v;
	}

	void invalidate()
	{
		this->_value = this->_invalid_value;
	}
};
} // namespace m2d