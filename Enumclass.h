#include <string>
#ifndef ENUM_HEADER
#define ENUM_HEADER

using namespace std;
using namespace N;

	enum class RentalType
	{
		MOVIERECORDS,
		DVD,
		VIDEOGAMES
	};

	enum class RentalStatus
	{
		NOT_AVAILABLE,
		AVAILABLE
	};

	enum class Genres
	{
		ACTION,
		HORROR,
		DRAMA,
		COMEDY
	};

	enum class LoanType
	{
		TWO_DAYS,
		ONE_WEEK
	};

	enum class CustomerType
	{
		GUEST,
		REGULAR,
		VIP
	};


#endif
