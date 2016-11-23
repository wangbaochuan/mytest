#pragma once
#include <Windows.h>
#include <Wincon.h>


//typedef function<bool(int, int)> type;
//ShowTypeTraitsHelper helper;
//helper.show2<type>();

class ShowTypeTraitsHelper
{
public:
	// type traits
	template <class T>
	void show(const T& , const string& info = "")
	{
		show2<T>(info);
	}

	template <class T>
	void show2(const string& info = "")
	{
		if (!info.empty()) std::cout << info << ' ';
		std::cout << typeid(T).name() << ":\n";

		//std::cout << "is_trivial : " << std::is_trivial<T>::value << '\n';
#define SHOWTRAITS(traits) std::cout << #traits " : "; showBoolean(##traits <T>::value);

		SHOWTRAITS(is_fundamental);
		SHOWTRAITS(is_arithmetic);
		SHOWTRAITS(is_scalar);
		SHOWTRAITS(is_object);
		SHOWTRAITS(is_compound);
		SHOWTRAITS(is_trivial);
		SHOWTRAITS(is_trivially_copyable);
		SHOWTRAITS(is_standard_layout);
		SHOWTRAITS(is_pod);
		SHOWTRAITS(is_empty);
		SHOWTRAITS(is_polymorphic);
		SHOWTRAITS(is_final);
		SHOWTRAITS(is_abstract);
		SHOWTRAITS(is_constructible);
		SHOWTRAITS(is_trivially_constructible);
		SHOWTRAITS(is_nothrow_constructible);
		SHOWTRAITS(is_default_constructible);
		SHOWTRAITS(is_trivially_default_constructible);
		SHOWTRAITS(is_nothrow_default_constructible);
		SHOWTRAITS(is_copy_constructible);
		SHOWTRAITS(is_trivially_copy_constructible);
		SHOWTRAITS(is_nothrow_copy_constructible);
		SHOWTRAITS(is_move_constructible);
		SHOWTRAITS(is_trivially_move_constructible);
		SHOWTRAITS(is_nothrow_move_constructible);
		//SHOWTRAITS(is_assignable);
		//SHOWTRAITS(is_trivially_assignable);
		//SHOWTRAITS(is_nothrow_assignable);
		SHOWTRAITS(is_copy_assignable);
		SHOWTRAITS(is_trivially_copy_assignable);
		SHOWTRAITS(is_nothrow_copy_assignable);
		SHOWTRAITS(is_move_assignable);
		SHOWTRAITS(is_trivially_move_assignable);
		SHOWTRAITS(is_nothrow_move_assignable);
		SHOWTRAITS(is_destructible);
		SHOWTRAITS(is_trivially_destructible);
		SHOWTRAITS(is_nothrow_destructible);
		SHOWTRAITS(has_virtual_destructor);

#undef SHOWTRAITS
	}


public:
	ShowTypeTraitsHelper()
	{
		m_hConsoleOutput = ::GetStdHandle(STD_OUTPUT_HANDLE);
		m_wOriginalAttr = 0;

		CONSOLE_SCREEN_BUFFER_INFO info;
		if (::GetConsoleScreenBufferInfo(m_hConsoleOutput, &info))
		{
			m_wOriginalAttr = info.wAttributes;
		}
	}

	void showBoolean(bool val)
	{
		if (val)
		{
			const WORD trueColor = FOREGROUND_INTENSITY | FOREGROUND_BLUE;
			SetConsoleTextAttribute(m_hConsoleOutput, trueColor);
			cout << "true\n";
			SetConsoleTextAttribute(m_hConsoleOutput, m_wOriginalAttr);
		}
		else
		{
			cout << "false\n";
		}
	}

private:
	HANDLE	m_hConsoleOutput;
	WORD	m_wOriginalAttr;
};

