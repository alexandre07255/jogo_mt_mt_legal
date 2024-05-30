#pragma once


namespace Math {

	template <class TYPE>
	class Coord {
	public:
		TYPE x;
		TYPE y;

	public:
		Coord(TYPE x, TYPE y);
		Coord();
		~Coord() {}

		void operator=(Coord<TYPE> other);
		void operator+=(Coord<TYPE> other);
		void operator-=(Coord<TYPE> other);
		void operator/=(Coord<TYPE> other);
		void operator*=(Coord<TYPE> other);
		void operator*=(double scalar);
		void operator/=(double scalar);

		bool operator==(Coord<TYPE> other);

		Coord<TYPE> operator+(Coord<TYPE> other);
		Coord<TYPE> operator-(Coord<TYPE> other);
		Coord<TYPE> operator*(Coord<TYPE> other);
		Coord<TYPE> operator/(Coord<TYPE> other);
		Coord<TYPE> operator/(double scalar);
		Coord<TYPE> operator*(double scalar);
	};

	template <class TYPE>
	Coord<TYPE>::Coord(TYPE x, TYPE y) :
		x(x),
		y(y)
	{ }

	template <class TYPE>
	Coord<TYPE>::Coord() :
		x(0),
		y(0)
	{ }

	template <class TYPE>
	void Coord<TYPE>::operator=(Coord<TYPE> other) {
		x = other.x;
		y = other.y;
	}

	template <class TYPE>
	void Coord<TYPE>::operator+=(Coord<TYPE> other) {
		x += other.x;
		y += other.y;
	}

	template <class TYPE>
	void Coord<TYPE>::operator-=(Coord<TYPE> other) {
		x -= other.x;
		y -= other.y;
	}

	template <class TYPE>
	void Coord<TYPE>::operator/=(Coord<TYPE> other) {
		x /= other.x;
		y /= other.y;
	}

	template <class TYPE>
	void Coord<TYPE>::operator*=(Coord<TYPE> other) {
		x *= other.x;
		y *= other.y;
	}

	template <class TYPE>
	void Coord<TYPE>::operator*=(double scalar) {
		x *= scalar;
		y *= scalar;
	}

	template <class TYPE>
	void Coord<TYPE>::operator/=(double scalar) {
		x /= scalar;
		y /= scalar;
	}

	template <class TYPE>
	bool Coord<TYPE>::operator==(Coord<TYPE> other) {
		return (x == other.x && y == other.y);
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator+(Coord<TYPE> other) {
		Coord<TYPE> result(x + other.x, y + other.y);
		return result;
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator-(Coord<TYPE> other) {
		Coord<TYPE> result(x - other.x, y - other.y);
		return result;
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator*(Coord<TYPE> other) {
		Coord<TYPE> result(x * other.x, y * other.y);
		return result;
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator/(Coord<TYPE> other) {
		Coord<TYPE> result(x / other.x, y / other.y);
		return result;
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator/(double scalar) {
		Coord<TYPE> result(x / scalar, y / scalar);
		return result;
	}

	template <class TYPE>
	Coord<TYPE> Coord<TYPE>::operator*(double scalar) {
		Coord<TYPE> result(x * scalar, y * scalar);
		return result;
	}

}