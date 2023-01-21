
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:

		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);

		Fixed &operator=(const Fixed &);

		bool operator<(const Fixed &) const;
		bool operator<=(const Fixed &) const;

		bool operator>(const Fixed &) const;
		bool operator>=(const Fixed &) const;

		bool operator==(const Fixed &) const;
		bool operator!=(const Fixed &) const;

		Fixed operator+(const Fixed &) const;
		Fixed operator-(const Fixed &) const;
		Fixed operator*(const Fixed &) const;
		Fixed operator/(const Fixed &) const;

		Fixed &operator++();
		Fixed operator++(int);

		~Fixed();

		int getRawBits() const;
		void setRawBits(int const);

		float toFloat() const;
		int toInt() const;

		static Fixed &min(Fixed &, Fixed &);
		static const Fixed &min(const Fixed &, const Fixed &);
		static Fixed &max(Fixed &, Fixed &);
		static const Fixed &max(const Fixed &, const Fixed &);

	private:
		int _value;
		static const int _rawBits = 8;

};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
