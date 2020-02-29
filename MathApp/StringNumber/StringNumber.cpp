#include "StringNumber.h"
#include <algorithm>
#include <iostream>
#include <numeric>

namespace String_Number {

	StringNumber::StringNumber() :
		num_str("0"),
		sign(1),
		size(1),
		precision(100)
	{}	
	
	StringNumber::StringNumber(const string& _str) :
		num_str(_str),
		sign(Digitize(num_str)),
		size(num_str.size()),
		precision(100)
	{}

	StringNumber::StringNumber(const StringNumber& _str_num) :
		num_str(_str_num.GetNumberString()),
		sign(_str_num.GetSign()),
		size(_str_num.Size()),
		precision(_str_num.GetPrecision())
	{}

	StringNumber::StringNumber(StringNumber&& _str_num) noexcept :
		num_str(std::move(_str_num.GetNumberString())),
		sign(std::move(_str_num.GetSign())),
		size(std::move(_str_num.Size())),
		precision(std::move(_str_num.GetPrecision()))
	{}

	StringNumber::~StringNumber() {}

	// Set precision floating points
	void StringNumber::SetPrecision(size_t _precision) {
		precision = _precision;
	}

	// Calculate square root of a given number
	const string StringNumber::Sqrt() {

		if (GetSign() < 0) {
			cout << "Cannot calculate sqrt of a negative number!\n";
			return "-1";
		}

		cout << "Process of calculation of Sqrt("<< num_str <<") started.\n";

		StringNumber reminder{ num_str };

		bool isPerfect {false};
		string tmp (PerfectSquareLE(reminder.GetNumberString(), isPerfect));
		StringNumber accum{ tmp };

		StringNumber str_tmp (tmp);
		string res_sqrt(str_tmp.GetNumberString());

		if (isPerfect)
			return res_sqrt;

		res_sqrt.append(".");

		StringNumber tmp_pow_two = str_tmp * str_tmp;
		StringNumber dif = reminder - tmp_pow_two;
		reminder = dif * StringNumber("100");
		accum = accum + str_tmp;


		for (size_t i = 0; i < precision-1; i++)
		{
			str_tmp = FindOnesFor(accum, reminder);
			StringNumber next = accum * StringNumber("10");
			accum = next + str_tmp;
			StringNumber acc_tmp = accum * str_tmp;

			StringNumber rem_tmp = reminder - acc_tmp;

			reminder = rem_tmp * StringNumber("100");
			accum = accum + str_tmp;
			res_sqrt.append(str_tmp.GetNumberString());
		}

		return res_sqrt;
	}

	// Number of one digit X in sqrt
	size_t StringNumber::NumberOfOcceranceOfXIn(const size_t& x, const string& str) {
		if (x > 9) {
			cout << "Error: number should be less than 10;" << endl;
			return 0;
		}

		return  count_if(	str.begin(), str.end(),
							[&x, this](char c) {
							return isdigit(c) && c == NumToChar(x) ;
						});
	}

	// Sum of digits in string
	size_t StringNumber::SumOfDigitsIn(const string& str) {

		cout << "Process of calculation of sum of digits of the given started.\n";

		auto sum_func = [this](int sum, char a) {return isdigit(a) ? sum + CharToNum(a) : sum; };
		return accumulate(str.begin(), str.end(), 0, sum_func);
	}

	// Find perfect squar less than num (f)
	string StringNumber::PerfectSquareLE(const string& num, bool& perfect_found) {
		string res{ "" };

		for (size_t i = 0; i < SIZE_MAX; i++)
		{
			const string& tmp(to_string(i));
			StringNumber str_tmp(tmp);
			const string& pow(str_tmp * str_tmp);
			// For now use multiply but then it can be subsitute with power
			string calc = StringNumber(pow) - StringNumber(num);

			if (calc == "0" || tmp == "" || calc == "-0") {
				perfect_found = true;
				return tmp;
			}
			else if (str_tmp.Sign(calc) == -1)
				res = tmp;
			else
				break;
		}

		return res;
	}

	// remove non-digit & non-significant 0 and return sign
	int StringNumber::Digitize(string& str) {
		// Get sign of the give string
		int sign = Sign(str);

		bool act{ false };
		str.erase(std::remove_if(str.begin(), str.end(),
			[&act](unsigned char x) {
			if (!isdigit((int)x))
				return true;
			else {
				if (x == '0' && !act)
					return true;
				else {
					act = true;
					return false;
				}
			}
		}), str.end());

		if (str == "")
			str = "0";

		return sign;
	}

	// Character to number
	const int& StringNumber::CharToNum(const char& c)
	{
		return ((int)c - 48);
	}

	// Number to character
	const char& StringNumber::NumToChar(const int& x)
	{
		return (char)(x + 48);
	}

	const StringNumber StringNumber::FindOnesFor(StringNumber rem, StringNumber oldReminder)
	{
		StringNumber newReminder(rem * StringNumber("10"));
		StringNumber res("0");

		for (size_t i = 0; i < 10; i++)
		{
			StringNumber temp((newReminder + StringNumber(to_string(i))) * StringNumber(to_string(i)));

			if (temp == oldReminder) 
				return res;
			else if (temp <= oldReminder)
				res.num_str.assign(to_string(i));
			else
				break;
		}

		return res;
	}

	const string StringNumber::FindOnesForDivision(string& remainder, const string& denominator)
	{
		const StringNumber& denominator_sn(denominator);
		string res("0");
		string temp("");
		string rem("");
		for (size_t i = 1; i < 10; i++)
		{
			string i_str = to_string(i);
			temp = denominator_sn * StringNumber(i_str);

			if (temp.compare(remainder) == 0) {
				return i_str;
			}
			else if (remainder.size()>temp.size() || temp.compare(remainder) < 0) {
				res.assign(i_str);
				rem.assign(temp);
			}
			else
				break;
		}

		remainder = rem;
		return res;
	}

	// Pad string number with times:0 from left
	void StringNumber::PadNumber(int times)
	{
		num_str.insert(num_str.begin(), times, '0');
	}	
	
	// Pad string number with times:0 from right
	void StringNumber::PadNumberRight(int times)
	{
		num_str.insert(num_str.end(), times, '0');
	}

	// Pad string number with times:0 from right
	void StringNumber::PadNumberRight(string& str, int times)
	{
		str.insert(str.end(), times, '0');
	}

	// Remove leading zeros of num_str
	void StringNumber::RemoveLeadingZeros() {
		num_str.erase(0, min(num_str.find_first_not_of('0'), Size() - 1));
	}
	
	// Remove leading zeros of a given string number
	void StringNumber::RemoveLeadingZeros(string& str) {
		if (str.size() < 2)
			return;
		str.erase(0, min(str.find_first_not_of('0'), Size() - 1));
	}

	bool operator<(const StringNumber& str1, const StringNumber& str2)
	{
		if (str1.GetSign() == str2.GetSign()) {
			int tmp_cmp = (str1.GetNumberString().size() - str2.GetNumberString().size());

			if (str1.GetSign()==1)
				return (tmp_cmp == 0) ? str1.GetNumberString().compare(str2.GetNumberString()) < 0 : tmp_cmp < 0;
			else
				return (tmp_cmp == 0) ? str1.GetNumberString().compare(str2.GetNumberString()) > 0 : tmp_cmp > 0;
		} else {
			return str1.GetSign() == -1;
		}
	}

	bool operator<=(const StringNumber& str1, const StringNumber& str2)
	{
		if (str1.GetSign() == str2.GetSign()) {
			int tmp_cmp = (str1.GetNumberString().size() - str2.GetNumberString().size());

			if (str1.GetSign() == 1)
				return (tmp_cmp == 0) ? str1.GetNumberString().compare(str2.GetNumberString()) <= 0 : tmp_cmp < 0;
			else
				return (tmp_cmp == 0) ? str1.GetNumberString().compare(str2.GetNumberString()) >= 0 : tmp_cmp > 0;
		} else {
			return str1.GetSign() == -1;
		}
	}

	bool operator==(const StringNumber& str1, const StringNumber& str2) {
		return (str1.Size() != str2.Size()) ? false : str1.num_str.compare(str2.num_str) == 0;
	}

	StringNumber& StringNumber::operator=(const StringNumber& str1) {
		if (this != &str1)
		{
			num_str = str1.num_str;
			sign	= str1.sign;
			size	= str1.size;
		}

		return *this;
	}

	StringNumber& StringNumber::operator=(StringNumber&& str1) {
		if (this != &str1)
		{
			num_str = str1.num_str;
			sign	= str1.sign;
			size	= str1.size;
		}

		return *this;
	}

	bool operator>(const StringNumber& str1, const StringNumber& str2)
	{
		return !(str1 <= str2);
	}

	bool operator>=(const StringNumber& str1, const StringNumber& str2) {
		return !(str1 > str2);
	}

	const string operator+(const StringNumber& str1, const StringNumber& str2) {

		StringNumber str1_b(str1.GetNumberString());
		StringNumber str2_s(str2.GetNumberString());

		if (str2_s > str1_b || str2_s == str1_b && str1.GetSign()<0) {
			std::swap(str1_b, str2_s);
			str1_b.sign = str2.GetSign();
			str2_s.sign = str1.GetSign();
		} else {
			str1_b.sign = str1.GetSign();
			str2_s.sign = str2.GetSign();
		}

		// Remove non-digit str1_b
		int str1_b_sign = str1_b.GetSign();
		// Remove non-digit str2_s
		int str2_s_sign = str2_s.GetSign();
		// Get size of str1
		const int str1_b_size = str1_b.Size();
		// Get size of str2
		const int str2_s_size = str2_s.Size();

		int carry = 0;
		string rec("");

		if ((str1_b_size == 0) && (str2_s_size == 0))
			return "0";

		if (str1_b_size == 0 || str1_b_size == 1 && str1_b.GetNumberString()[0] == '0')
			return  (str2_s_sign == -1) ? str2_s.num_str.insert(0, "-") : str2_s.GetNumberString();

		if (str2_s_size == 0 || str2_s_size == 1 && str2_s.GetNumberString()[0] == '0')
			return  (str1_b_sign == -1) ? str1_b.num_str.insert(0, "-") : str1_b.GetNumberString();

		// Pad numbers if required
		int diff = str1_b_size - str2_s_size;
		if (diff > 0)
			str2_s.PadNumber(diff);

		for (int i = str1_b_size - 1; i >= 0; i--)
		{
			int newNum;
			// Both the same sign
			if (str1_b_sign == str2_s_sign)
			{
				newNum =  str1_b.CharToNum(str1_b.GetNumberString()[i]);
				newNum += str2_s.CharToNum(str2_s.GetNumberString()[i]);
				newNum += carry;

				carry = newNum / 10;
				newNum %= 10;
			}
			else
			{
				int str1_b_Digit_i = str1_b.CharToNum(str1_b.GetNumberString()[i]);
				int str2_s_Digit_i = str2_s.CharToNum(str2_s.GetNumberString()[i]);

				if (str1_b_Digit_i + carry < str2_s_Digit_i)
				{
					str1_b_Digit_i += 10 + carry;
					carry = -1;
				}
				else if (carry != 0 && str1_b_Digit_i != 0) {
					str1_b_Digit_i += carry;
					carry = 0;
				}
				else {
					carry = 0;
				}

				newNum = abs(str1_b_sign * str1_b_Digit_i + str2_s_sign * str2_s_Digit_i);
			}

			char newChar = str1_b.NumToChar(newNum);
			rec.insert(0, string(1, newChar));

			if (carry != 0 && i == 0)
				rec.insert(0, to_string(carry));
		}

		// Remove all zeros from left
		str2_s.RemoveLeadingZeros(rec);

		// Add - to the begining if the final result is negative
		if (str1_b_sign == -1 && str1_b.GetNumberString() != "0")
			rec.insert(0, "-");

		return rec;
	}
	
	StringNumber& StringNumber::operator+=(const StringNumber& rhs) {
		string res = StringNumber(*this) + StringNumber(rhs);

		this->sign = this->Sign(res);
		this->num_str = (this->sign > 0) ? res : res.substr(1);
		this->size = (this->num_str).size();
		return *this;
	}
	
	const string operator-(const StringNumber& str1, const StringNumber& str2) {
		StringNumber s2_tmp(str2.GetSign() < 0 ? str2.GetNumberString() : ("-" + str2.GetNumberString()));
		return (str1 + s2_tmp);
	}
	
	StringNumber& StringNumber::operator-=(const StringNumber& rhs) {
		string res = StringNumber(*this) - StringNumber(rhs);

		this->sign = this->Sign(res);
		this->num_str = (this->sign > 0) ? res : res.substr(1);
		this->size = (this->num_str).size();
		return *this;
	}

	const string operator*(const StringNumber& str1, const StringNumber& str2) {

		StringNumber str1_b(str1.GetNumberString());
		StringNumber str2_s(str2.GetNumberString());

		if (str2_s > str1_b || str2_s == str1_b && str1.GetSign() < 0) {
			std::swap(str1_b, str2_s);
			str1_b.sign = str2.GetSign();
			str2_s.sign = str1.GetSign();
		}
		else {
			str1_b.sign = str1.GetSign();
			str2_s.sign = str2.GetSign();
		}

		// Remove non-digit str1_b
		int str1_b_sign = str1_b.GetSign();
		// Remove non-digit str2_s
		int str2_s_sign = str2_s.GetSign();
		// Get size of str1
		const int str1_b_size = str1_b.Size();
		// Get size of str2
		const int str2_s_size = str2_s.Size();

		int carry = 0;
		string rec("0");

		// Result
		if (str1_b.GetNumberString() == "0" ||
			str2_s.GetNumberString() == "0" ||
			str1_b_size == 0 ||
			str2_s_size == 0)
			return rec;

		// Final result sign
		bool res_is_negative = (str1_b_sign != str2_s_sign);

		for (int i = str2_s_size - 1; i >= 0; i--)
		{
			if (str2_s.GetNumberString()[i] == '0')
				continue;

			string tmp_step("");

			for (int j = str1_b_size - 1; j >= 0; j--)
			{
				int newNum = str1_b.CharToNum(str1_b.GetNumberString()[j]);
				newNum *= str2_s.CharToNum(str2_s.GetNumberString()[i]);
				newNum += carry;

				carry = newNum / 10;
				newNum %= 10;
				tmp_step.insert(0, to_string(newNum));

				if (carry != 0 && j == 0)
					tmp_step.insert(0, to_string(carry));
			}

			tmp_step.insert(tmp_step.size(), str2_s_size - i - 1, '0');
			rec = StringNumber(rec) + StringNumber(tmp_step);
			carry = 0;
		}

		// Remove all zeros from left
		str2_s.RemoveLeadingZeros(rec);

		// Add - to the begining if the final result is negative
		if (res_is_negative)
			rec.insert(0, "-");

		return rec;
	}
	
	StringNumber& StringNumber::operator*=(const StringNumber& rhs) {
		string res = StringNumber(*this) * StringNumber(rhs);

		this->sign = this->Sign(res);
		this->num_str = (this->sign > 0) ? res : res.substr(1);
		this->size = (this->num_str).size();
		return *this;
	}

	const string operator/(const StringNumber& lhs, const StringNumber& rhs) {
		// denominator is zero
		if (rhs.GetNumberString() == "0" ||
			rhs.GetNumberString() == "")
			throw "Divide by zero exception!";
		// numerator is zero
		else if (lhs.GetNumberString() == "0" ||
			lhs.GetNumberString() == "")
			return "0";

		// Final result sign
		bool res_is_negative = (lhs.GetSign() != rhs.GetSign());
		string numerator(lhs.GetNumberString());
		const string denominator(rhs.GetNumberString());
		int cmp = numerator.compare(denominator);

		// denominator == numerator
		if (cmp == 0)
			return res_is_negative ? "-1" : "1";

		int carry = 0;
		string rec("");
		size_t seperator_size = denominator.size();

		// Precision will be the minimum of two StringNumber classes precision
		size_t precision = min(lhs.GetPrecision(), rhs.GetPrecision());
		StringNumber strn;
		bool hasDot = false;
		while (numerator!="0" && rec.size() < precision) {
			int diff = numerator.size() - seperator_size;
			
			cmp = numerator.compare(denominator);
			string tmp("");

			if (diff <= 0) {
				// If denominator is bigger
				if (diff == 0 && cmp < 0) {
					if (rec.size() == 0 && !hasDot) {
						rec.append("0.");
						hasDot = true;
					}
					else if (cmp < 0 && !hasDot) {
						rec.append("0.");
						hasDot = true;
					}
					else if (diff < 0)
						rec.append("0");

					numerator.push_back('0');

				// If numerator is bigger
				} else if (diff < 0) {

					if (rec.size() == 0) {
						rec.append("0.");
						hasDot = true;
					}

					if (!hasDot) {
						rec.append(".");
						hasDot = true;
					}

					rec.append(abs(diff) - 1, '0');

					numerator.append(abs(diff), '0');

					if (numerator.compare(denominator) < 0) {
						numerator.push_back('0');
						rec.push_back('0');
					}
				}
				tmp = numerator;
			} else {
				tmp = numerator.substr(0, min(numerator.size(), seperator_size));
				cmp = tmp.compare(denominator);

				if (cmp < 0)
				{
					diff = numerator.size() - seperator_size;

					if (diff == 0)
					{
						size_t found = rec.find(".");
						rec.append((found != string::npos)? "." : "0" );
						tmp = numerator.substr(0, seperator_size + 1);

					} if (diff > 0) {
						tmp = numerator.substr(0, seperator_size + 1);
					}
					else
					{
						rec.push_back('.');
						numerator.push_back('0');
					}
				}
			}

			string act = strn.FindOnesForDivision(tmp, denominator);
			bool should_add_zero = (StringNumber(numerator) - StringNumber(tmp)*StringNumber(tmp)) > StringNumber("0");
			if (numerator.size() != tmp.size() && should_add_zero && numerator.compare(tmp) != 0)
			{
				// add subtraction of the calculation in front
				string str_num = numerator.substr(0, seperator_size);
				int pad_size = (str_num > denominator) ? (numerator.size() - tmp.size()) : 1;
				strn.PadNumberRight(tmp, pad_size);
			}

			numerator.assign(StringNumber(numerator) - StringNumber(tmp));

			rec.append(act);
			//cout << "rec:" << rec << endl;
		}

		if (res_is_negative)
			rec.insert(rec.begin(), 1, '-');

		//cout << "rec:" << rec << endl;
		return rec;
	}
}
