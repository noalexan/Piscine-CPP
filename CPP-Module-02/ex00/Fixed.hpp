
#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

	public:

		Fixed();
		Fixed(const Fixed &);

		Fixed &operator=(const Fixed &);

		~Fixed();

		int getRawBits() const;
		void setRawBits(int const);

	private:
		int _value;
		static const int _rawBits = 8;

};

#endif
