
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:

		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed &);

		Fixed &operator=(const Fixed &);
		std::ostream &operator<<(const Fixed &);

		~Fixed();

		int getRawBits() const;
		void setRawBits(int const);

		float toFloat() const;
		int toInt() const;

	private:
		int _value;
		static const int _rawBits = 8;

};

std::ostream &operator<<(std::ostream &, const Fixed &);

#endif
