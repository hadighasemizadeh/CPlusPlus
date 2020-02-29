#pragma once

#ifndef _STRINGNUMBER
#define _STRINGNUMBER

#include <string>
using namespace std;

namespace String_Number {

	class StringNumber
	{
	public:
		StringNumber();
		StringNumber(const string& _str);
		StringNumber(const StringNumber& _str_num);
		StringNumber(StringNumber&& _str_num) noexcept;

		~StringNumber();

		// Remove non-digit & non-significant 0 and return sign
		int Digitize(string& str);
		// Character to number
		const int& CharToNum(const char& c);
		// Number to character
		const char& NumToChar(const int& x);

		// Remove leading zero from string number
		void RemoveLeadingZeros();
		void RemoveLeadingZeros(string& str);

		const string Sqrt();

		// Sign of a given string number
		inline int				Sign(const string& str) const {
			size_t size = str.size();
			return (size < 2 || (size >= 2 & str[0] != '-')) ? 1 : -1;
		}
		inline const string&	GetNumberString()		const { return num_str; }
		inline const int&		GetSign()				const { return sign; }
		inline const size_t&	GetPrecision()			const { return precision; }
		inline const size_t&	Size()					const { return num_str.size(); }

		void SetPrecision(size_t precision);
		// Number of occarances of one digit X in sqrt
		size_t NumberOfOcceranceOfXIn(const size_t& x, const string& str);
		// Sum of digits in string
		size_t SumOfDigitsIn(const string& str);

		// *************************** Overloadings ****************************** 
		friend bool operator<  (const StringNumber& str1, const StringNumber& str2);
		friend bool operator<= (const StringNumber& str1, const StringNumber& str2);

		StringNumber& operator=(const StringNumber& str1);
		StringNumber& operator=(StringNumber&& str1);
		friend bool operator== (const StringNumber& str1, const StringNumber& str2);

		friend bool operator>  (const StringNumber& str1, const StringNumber& str2);
		friend bool operator>= (const StringNumber& str1, const StringNumber& str2);

		friend const string operator+(const StringNumber& str1, const StringNumber& str2);
		StringNumber& operator+=(const StringNumber& rhs);
		
		friend const string operator-(const StringNumber& str1, const StringNumber& str2);
		StringNumber& operator-=(const StringNumber& rhs);

		friend const string operator*(const StringNumber& str1, const StringNumber& str2);
		StringNumber& operator*=(const StringNumber& rhs);
		
		friend const string operator/(const StringNumber& lhs, const StringNumber& rhs);
	
	private:
		// Pad number with times:0 from left
		void PadNumber(int times);

		// Pad number x times from right with 0
		void PadNumberRight(int times);
		void PadNumberRight(string& str, int times);

		const string FindOnesForDivision(string& remainder, const string& denominator);
		const StringNumber FindOnesFor(StringNumber rem, StringNumber oldReminder);
		string PerfectSquareLE(const string& num, bool& perfect_found);

		string		num_str;
		int			sign;
		int			size;
		size_t		precision;
	};
}

#endif // !_STRINGNUMBER

