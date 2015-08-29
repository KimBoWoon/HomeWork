#ifdef _UNICODE
typedef std::wstring tstring;
typedef std::wostream tostream;
typedef std::wofstream tofstream;
typedef std::wostringstream tostringstream;
typedef std::wistringstream tistringstream;
typedef std::wstringstream tstringstream;
typedef std::wstreambuf tstreambuf;

#define _tcin  wcin
#define _tcout wcout
#define _tcerr wcerr
#define _tclog wclog
#define _tcstoul wcstoul
#define _tcschr wcschr
#define _tcsncmp wcsncmp
#define _tisdigit iswdigit
#define _tsprintf swprintf
#define _tcsncpy wcsncpy
#define _stol wcstol
#define _sntprintf _snwprintf

#ifndef _T
#define _T(x) L ## x
#endif
#else
typedef std::string tstring;
typedef std::ostream tostream;
typedef std::ofstream tofstream;
typedef std::ostringstream tostringstream;
typedef std::istringstream tistringstream;
typedef std::stringstream tstringstream;
typedef std::streambuf tstreambuf;

#define _tcin  cin
#define _tcout cout
#define _tcerr cerr
#define _tclog clog
#define _tcstoul strtoul
#define _tcschr strchr
#define _tcsncmp strncmp
#define _tisdigit isdigit
#define _tsprintf sprintf
#define _tcsncpy strncpy
#define _stol strtol
#define _sntprintf _snprintf

#ifndef _T
#define _T
#endif
#endif