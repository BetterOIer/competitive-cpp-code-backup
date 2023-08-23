#ifndef _GLIBCXX_IOSTREAM
#define _GLIBCXX_IOSTREAM 1

#pragma GCC system_header

#include <bits/c++config.h>
#ifndef _GLIBCXX_OSTREAM
#define _GLIBCXX_OSTREAM 1

#pragma GCC system_header

#include <ios>
#include <bits/ostream_insert.h>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  template<typename _CharT, typename _Traits>
    class basic_ostream : virtual public basic_ios<_CharT, _Traits>
    {
    public:
      // Types (inherited from basic_ios):
      typedef _CharT			 		char_type;
      typedef typename _Traits::int_type 		int_type;
      typedef typename _Traits::pos_type 		pos_type;
      typedef typename _Traits::off_type 		off_type;
      typedef _Traits			 		traits_type;

      // Non-standard Types:
      typedef basic_streambuf<_CharT, _Traits> 		__streambuf_type;
      typedef basic_ios<_CharT, _Traits>		__ios_type;
      typedef basic_ostream<_CharT, _Traits>		__ostream_type;
      typedef num_put<_CharT, ostreambuf_iterator<_CharT, _Traits> >
      							__num_put_type;
      typedef ctype<_CharT>	      			__ctype_type;

      /**
       *  @brief  Base constructor.
       *
       *  This ctor is almost never called by the user directly, rather from
       *  derived classes' initialization lists, which pass a pointer to
       *  their own stream buffer.
      */
      explicit
      basic_ostream(__streambuf_type* __sb)
      { this->init(__sb); }

      /**
       *  @brief  Base destructor.
       *
       *  This does very little apart from providing a virtual base dtor.
      */
      virtual
      ~basic_ostream() { }

      /// Safe prefix/suffix operations.
      class sentry;
      friend class sentry;

      //@{
      /**
       *  @brief  Interface for manipulators.
       *
       *  Manipulators such as @c std::endl and @c std::hex use these
       *  functions in constructs like "std::cout << std::endl".  For more
       *  information, see the iomanip header.
      */
      __ostream_type&
      operator<<(__ostream_type& (*__pf)(__ostream_type&))
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// DR 60. What is a formatted input function?
	// The inserters for manipulators are *not* formatted output functions.
	return __pf(*this);
      }

      __ostream_type&
      operator<<(__ios_type& (*__pf)(__ios_type&))
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// DR 60. What is a formatted input function?
	// The inserters for manipulators are *not* formatted output functions.
	__pf(*this);
	return *this;
      }

      __ostream_type&
      operator<<(ios_base& (*__pf) (ios_base&))
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// DR 60. What is a formatted input function?
	// The inserters for manipulators are *not* formatted output functions.
	__pf(*this);
	return *this;
      }
      //@}

      //@{
      /**
       *  @name Inserters
       *
       *  All the @c operator<< functions (aka <em>formatted output
       *  functions</em>) have some common behavior.  Each starts by
       *  constructing a temporary object of type std::basic_ostream::sentry.
       *  This can have several effects, concluding with the setting of a
       *  status flag; see the sentry documentation for more.
       *
       *  If the sentry status is good, the function tries to generate
       *  whatever data is appropriate for the type of the argument.
       *
       *  If an exception is thrown during insertion, ios_base::badbit
       *  will be turned on in the stream's error state without causing an
       *  ios_base::failure to be thrown.  The original exception will then
       *  be rethrown.
      */

      //@{
      /**
       *  @brief Integer arithmetic inserters
       *  @param  __n A variable of builtin integral type.
       *  @return  @c *this if successful
       *
       *  These functions use the stream's current locale (specifically, the
       *  @c num_get facet) to perform numeric formatting.
      */
      __ostream_type&
      operator<<(long __n)
      { return _M_insert(__n); }

      __ostream_type&
      operator<<(unsigned long __n)
      { return _M_insert(__n); }

      __ostream_type&
      operator<<(bool __n)
      { return _M_insert(__n); }

      __ostream_type&
      operator<<(short __n);

      __ostream_type&
      operator<<(unsigned short __n)
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// 117. basic_ostream uses nonexistent num_put member functions.
	return _M_insert(static_cast<unsigned long>(__n));
      }

      __ostream_type&
      operator<<(int __n);

      __ostream_type&
      operator<<(unsigned int __n)
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// 117. basic_ostream uses nonexistent num_put member functions.
	return _M_insert(static_cast<unsigned long>(__n));
      }

#ifdef _GLIBCXX_USE_LONG_LONG
      __ostream_type&
      operator<<(long long __n)
      { return _M_insert(__n); }

      __ostream_type&
      operator<<(unsigned long long __n)
      { return _M_insert(__n); }
#endif
      //@}

      //@{
      /**
       *  @brief  Floating point arithmetic inserters
       *  @param  __f A variable of builtin floating point type.
       *  @return  @c *this if successful
       *
       *  These functions use the stream's current locale (specifically, the
       *  @c num_get facet) to perform numeric formatting.
      */
      __ostream_type&
      operator<<(double __f)
      { return _M_insert(__f); }

      __ostream_type&
      operator<<(float __f)
      {
	// _GLIBCXX_RESOLVE_LIB_DEFECTS
	// 117. basic_ostream uses nonexistent num_put member functions.
	return _M_insert(static_cast<double>(__f));
      }

      __ostream_type&
      operator<<(long double __f)
      { return _M_insert(__f); }
      //@}

      /**
       *  @brief  Pointer arithmetic inserters
       *  @param  __p A variable of pointer type.
       *  @return  @c *this if successful
       *
       *  These functions use the stream's current locale (specifically, the
       *  @c num_get facet) to perform numeric formatting.
      */
      __ostream_type&
      operator<<(const void* __p)
      { return _M_insert(__p); }

#if __cplusplus >= 201703L
      __ostream_type&
      operator<<(nullptr_t)
      { return *this << "nullptr"; }
#endif

      /**
       *  @brief  Extracting from another streambuf.
       *  @param  __sb  A pointer to a streambuf
       *
       *  This function behaves like one of the basic arithmetic extractors,
       *  in that it also constructs a sentry object and has the same error
       *  handling behavior.
       *
       *  If @p __sb is NULL, the stream will set failbit in its error state.
       *
       *  Characters are extracted from @p __sb and inserted into @c *this
       *  until one of the following occurs:
       *
       *  - the input stream reaches end-of-file,
       *  - insertion into the output sequence fails (in this case, the
       *    character that would have been inserted is not extracted), or
       *  - an exception occurs while getting a character from @p __sb, which
       *    sets failbit in the error state
       *
       *  If the function inserts no characters, failbit is set.
      */
      __ostream_type&
      operator<<(__streambuf_type* __sb);
      //@}

      //@{
      /**
       *  @name Unformatted Output Functions
       *
       *  All the unformatted output functions have some common behavior.
       *  Each starts by constructing a temporary object of type
       *  std::basic_ostream::sentry.  This has several effects, concluding
       *  with the setting of a status flag; see the sentry documentation
       *  for more.
       *
       *  If the sentry status is good, the function tries to generate
       *  whatever data is appropriate for the type of the argument.
       *
       *  If an exception is thrown during insertion, ios_base::badbit
       *  will be turned on in the stream's error state.  If badbit is on in
       *  the stream's exceptions mask, the exception will be rethrown
       *  without completing its actions.
      */

      /**
       *  @brief  Simple insertion.
       *  @param  __c  The character to insert.
       *  @return  *this
       *
       *  Tries to insert @p __c.
       *
       *  @note  This function is not overloaded on signed char and
       *         unsigned char.
      */
      __ostream_type&
      put(char_type __c);

      /**
       *  @brief  Core write functionality, without sentry.
       *  @param  __s  The array to insert.
       *  @param  __n  Maximum number of characters to insert.
      */
      void
      _M_write(const char_type* __s, streamsize __n)
      {
	const streamsize __put = this->rdbuf()->sputn(__s, __n);
	if (__put != __n)
	  this->setstate(ios_base::badbit);
      }

      /**
       *  @brief  Character string insertion.
       *  @param  __s  The array to insert.
       *  @param  __n  Maximum number of characters to insert.
       *  @return  *this
       *
       *  Characters are copied from @p __s and inserted into the stream until
       *  one of the following happens:
       *
       *  - @p __n characters are inserted
       *  - inserting into the output sequence fails (in this case, badbit
       *    will be set in the stream's error state)
       *
       *  @note  This function is not overloaded on signed char and
       *         unsigned char.
      */
      __ostream_type&
      write(const char_type* __s, streamsize __n);
      //@}

      /**
       *  @brief  Synchronizing the stream buffer.
       *  @return  *this
       *
       *  If @c rdbuf() is a null pointer, changes nothing.
       *
       *  Otherwise, calls @c rdbuf()->pubsync(), and if that returns -1,
       *  sets badbit.
      */
      __ostream_type&
      flush();

      /**
       *  @brief  Getting the current write position.
       *  @return  A file position object.
       *
       *  If @c fail() is not false, returns @c pos_type(-1) to indicate
       *  failure.  Otherwise returns @c rdbuf()->pubseekoff(0,cur,out).
      */
      pos_type
      tellp();

      /**
       *  @brief  Changing the current write position.
       *  @param  __pos  A file position object.
       *  @return  *this
       *
       *  If @c fail() is not true, calls @c rdbuf()->pubseekpos(pos).  If
       *  that function fails, sets failbit.
      */
      __ostream_type&
      seekp(pos_type);

      /**
       *  @brief  Changing the current write position.
       *  @param  __off  A file offset object.
       *  @param  __dir  The direction in which to seek.
       *  @return  *this
       *
       *  If @c fail() is not true, calls @c rdbuf()->pubseekoff(off,dir).
       *  If that function fails, sets failbit.
      */
       __ostream_type&
      seekp(off_type, ios_base::seekdir);

    protected:
      basic_ostream()
      { this->init(0); }

#if __cplusplus >= 201103L
      // Non-standard constructor that does not call init()
      basic_ostream(basic_iostream<_CharT, _Traits>&) { }

      basic_ostream(const basic_ostream&) = delete;

      basic_ostream(basic_ostream&& __rhs)
      : __ios_type()
      { __ios_type::move(__rhs); }

      // 27.7.3.3 Assign/swap

      basic_ostream& operator=(const basic_ostream&) = delete;

      basic_ostream&
      operator=(basic_ostream&& __rhs)
      {
	swap(__rhs);
	return *this;
      }

      void
      swap(basic_ostream& __rhs)
      { __ios_type::swap(__rhs); }
#endif

      template<typename _ValueT>
	__ostream_type&
	_M_insert(_ValueT __v);
    };

  /**
   *  @brief  Performs setup work for output streams.
   *
   *  Objects of this class are created before all of the standard
   *  inserters are run.  It is responsible for <em>exception-safe prefix and
   *  suffix operations</em>.
  */
  template <typename _CharT, typename _Traits>
    class basic_ostream<_CharT, _Traits>::sentry
    {
      // Data Members.
      bool 				_M_ok;
      basic_ostream<_CharT, _Traits>& 	_M_os;

    public:
      /**
       *  @brief  The constructor performs preparatory work.
       *  @param  __os  The output stream to guard.
       *
       *  If the stream state is good (@a __os.good() is true), then if the
       *  stream is tied to another output stream, @c is.tie()->flush()
       *  is called to synchronize the output sequences.
       *
       *  If the stream state is still good, then the sentry state becomes
       *  true (@a okay).
      */
      explicit
      sentry(basic_ostream<_CharT, _Traits>& __os);

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
      /**
       *  @brief  Possibly flushes the stream.
       *
       *  If @c ios_base::unitbuf is set in @c os.flags(), and
       *  @c std::uncaught_exception() is true, the sentry destructor calls
       *  @c flush() on the output stream.
      */
      ~sentry()
      {
	// XXX MT
	if (bool(_M_os.flags() & ios_base::unitbuf) && !uncaught_exception())
	  {
	    // Can't call flush directly or else will get into recursive lock.
	    if (_M_os.rdbuf() && _M_os.rdbuf()->pubsync() == -1)
	      _M_os.setstate(ios_base::badbit);
	  }
      }
#pragma GCC diagnostic pop

      /**
       *  @brief  Quick status checking.
       *  @return  The sentry state.
       *
       *  For ease of use, sentries may be converted to booleans.  The
       *  return value is that of the sentry state (true == okay).
      */
#if __cplusplus >= 201103L
      explicit
#endif
      operator bool() const
      { return _M_ok; }
    };
  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& ___out, _CharT __c)
    { return __ostream_insert(___out, &__c, 1); }

  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& ___out, char __c)
    { return (___out << ___out.widen(__c)); }

  // Specialization
  template<typename _Traits>
    inline basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& ___out, char __c)
    { return __ostream_insert(___out, &__c, 1); }

  // Signed and unsigned
  template<typename _Traits>
    inline basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& ___out, signed char __c)
    { return (___out << static_cast<char>(__c)); }

  template<typename _Traits>
    inline basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& ___out, unsigned char __c)
    { return (___out << static_cast<char>(__c)); }

#if __cplusplus > 201703L
  // The following deleted overloads prevent formatting character values as
  // numeric values.

#ifdef _GLIBCXX_USE_WCHAR_T
  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, wchar_t) = delete;
#endif // _GLIBCXX_USE_WCHAR_T

#ifdef _GLIBCXX_USE_CHAR8_T
  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, char8_t) = delete;
#endif

  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, char16_t) = delete;

  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, char32_t) = delete;

#ifdef _GLIBCXX_USE_WCHAR_T
#ifdef _GLIBCXX_USE_CHAR8_T
  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, char8_t) = delete;
#endif // _GLIBCXX_USE_CHAR8_T

  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, char16_t) = delete;

  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, char32_t) = delete;
#endif // _GLIBCXX_USE_WCHAR_T
#endif // C++20
  //@}

  //@{
  /**
   *  @brief  String inserters
   *  @param  ___out  An output stream.
   *  @param  __s  A character string.
   *  @return  out
   *  @pre  @p __s must be a non-NULL pointer
   *
   *  Behaves like one of the formatted arithmetic inserters described in
   *  std::basic_ostream.  After constructing a sentry object with good
   *  status, this function inserts @c traits::length(__s) characters starting
   *  at @p __s, widened if necessary, followed by any required padding (as
   *  determined by [22.2.2.2.2]).  @c ___out.width(0) is then called.
  */
  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& ___out, const _CharT* __s)
    {
      if (!__s)
	___out.setstate(ios_base::badbit);
      else
	__ostream_insert(___out, __s,
			 static_cast<streamsize>(_Traits::length(__s)));
      return ___out;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits> &
    operator<<(basic_ostream<_CharT, _Traits>& ___out, const char* __s);

  // Partial specializations
  template<typename _Traits>
    inline basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& ___out, const char* __s)
    {
      if (!__s)
	___out.setstate(ios_base::badbit);
      else
	__ostream_insert(___out, __s,
			 static_cast<streamsize>(_Traits::length(__s)));
      return ___out;
    }

  // Signed and unsigned
  template<typename _Traits>
    inline basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& ___out, const signed char* __s)
    { return (___out << reinterpret_cast<const char*>(__s)); }

  template<typename _Traits>
    inline basic_ostream<char, _Traits> &
    operator<<(basic_ostream<char, _Traits>& ___out, const unsigned char* __s)
    { return (___out << reinterpret_cast<const char*>(__s)); }

#if __cplusplus > 201703L
   // The following deleted overloads prevent formatting strings as
   // pointer values.

#ifdef _GLIBCXX_USE_WCHAR_T
  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, const wchar_t*) = delete;
#endif // _GLIBCXX_USE_WCHAR_T

#ifdef _GLIBCXX_USE_CHAR8_T
  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, const char8_t*) = delete;
#endif // _GLIBCXX_USE_CHAR8_T

  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, const char16_t*) = delete;

  template<typename _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>&, const char32_t*) = delete;

#ifdef _GLIBCXX_USE_WCHAR_T
#ifdef _GLIBCXX_USE_CHAR8_T
  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, const char8_t*) = delete;
#endif

  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, const char16_t*) = delete;

  template<typename _Traits>
    basic_ostream<wchar_t, _Traits>&
    operator<<(basic_ostream<wchar_t, _Traits>&, const char32_t*) = delete;
#endif // _GLIBCXX_USE_WCHAR_T
#endif // C++20
  //@}

  // Standard basic_ostream manipulators
  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    endl(basic_ostream<_CharT, _Traits>& __os)
    { return flush(__os.put(__os.widen('\n'))); }

  /**
   *  @brief  Write a null character into the output sequence.
   *
   *  <em>Null character</em> is @c CharT() by definition.  For CharT
   *  of @c char, this correctly writes the ASCII @c NUL character
   *  string terminator.
  */
  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    ends(basic_ostream<_CharT, _Traits>& __os)
    { return __os.put(_CharT()); }

  /**
   *  @brief  Flushes the output stream.
   *
   *  This manipulator simply calls the stream's @c flush() member function.
  */
  template<typename _CharT, typename _Traits>
    inline basic_ostream<_CharT, _Traits>&
    flush(basic_ostream<_CharT, _Traits>& __os)
    { return __os.flush(); }

#if __cplusplus >= 201103L
  template<typename _Ch, typename _Up>
    basic_ostream<_Ch, _Up>&
    __is_convertible_to_basic_ostream_test(basic_ostream<_Ch, _Up>*);

  template<typename _Tp, typename = void>
    struct __is_convertible_to_basic_ostream_impl
    {
      using __ostream_type = void;
    };

  template<typename _Tp>
    using __do_is_convertible_to_basic_ostream_impl =
    decltype(__is_convertible_to_basic_ostream_test
	     (declval<typename remove_reference<_Tp>::type*>()));

  template<typename _Tp>
    struct __is_convertible_to_basic_ostream_impl
    <_Tp,
     __void_t<__do_is_convertible_to_basic_ostream_impl<_Tp>>>
    {
      using __ostream_type =
	__do_is_convertible_to_basic_ostream_impl<_Tp>;
    };

  template<typename _Tp>
    struct __is_convertible_to_basic_ostream
    : __is_convertible_to_basic_ostream_impl<_Tp>
    {
    public:
      using type = __not_<is_void<
        typename __is_convertible_to_basic_ostream_impl<_Tp>::__ostream_type>>;
      constexpr static bool value = type::value;
    };

  template<typename _Ostream, typename _Tp, typename = void>
    struct __is_insertable : false_type {};

  template<typename _Ostream, typename _Tp>
    struct __is_insertable<_Ostream, _Tp,
			   __void_t<decltype(declval<_Ostream&>()
					     << declval<const _Tp&>())>>
				    : true_type {};

  template<typename _Ostream>
    using __rvalue_ostream_type =
      typename __is_convertible_to_basic_ostream<
	_Ostream>::__ostream_type;

  /**
   *  @brief  Generic inserter for rvalue stream
   *  @param  __os  An input stream.
   *  @param  __x  A reference to the object being inserted.
   *  @return  os
   *
   *  This is just a forwarding function to allow insertion to
   *  rvalue streams since they won't bind to the inserter functions
   *  that take an lvalue reference.
  */
  template<typename _Ostream, typename _Tp>
    inline
    typename enable_if<__and_<__not_<is_lvalue_reference<_Ostream>>,
			      __is_convertible_to_basic_ostream<_Ostream>,
			      __is_insertable<
				__rvalue_ostream_type<_Ostream>,
				const _Tp&>>::value,
		       __rvalue_ostream_type<_Ostream>>::type
    operator<<(_Ostream&& __os, const _Tp& __x)
    {
      __rvalue_ostream_type<_Ostream> __ret_os = __os;
      __ret_os << __x;
      return __ret_os;
    }
#endif // C++11

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace std

#include <bits/ostream.tcc>

#endif	/* _GLIBCXX_OSTREAM */

#include <istream>

namespace std _GLIBCXX_VISIBILITY(default)
{
_GLIBCXX_BEGIN_NAMESPACE_VERSION

  extern istream cin;		/// Linked to standard input
  extern ostream cout;		/// Linked to standard output
  extern ostream cerr;		/// Linked to standard error (unbuffered)
  extern ostream clog;		/// Linked to standard error (buffered)

#ifdef _GLIBCXX_USE_WCHAR_T
  extern wistream wcin;		/// Linked to standard input
  extern wostream wcout;	/// Linked to standard output
  extern wostream wcerr;	/// Linked to standard error (unbuffered)
  extern wostream wclog;	/// Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;

_GLIBCXX_END_NAMESPACE_VERSION
} // namespace

#endif /* _GLIBCXX_IOSTREAM */

#define I using
#define AK namespace
#define IOI std
#define ll long long
I AK IOI;
const int mxn=5e5+5;
const int B=32;
const int K=40;
int a[mxn];
int bet[mxn];
int n;
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s;
}
struct segc
{
	int l,r;
	bool fl;
}T[mxn/K<<4];
#define ls w<<1
#define rs ls|1
int wz[mxn];
void build(int w,int l,int r)
{
	T[w].l=l,T[w].r=r;
	if(r-l>K)
	{
		int mid=l+r>>1;
		build(ls,l,mid);
		build(rs,mid+1,r);
	}
	else
		for(T[w].fl=1;l<=r;l++)
			wz[l]=w;
}
int mn,mx;
ll sum;
int down[mxn];
int dcnt;
struct STR
{
	ll L,R;
	int id;
	struct seg
	{	
		int mn,mx,cnt;
		ll tag,sum;
		seg()
		{
			mn=2e9;
		}
	}t[mxn/K<<4];
	void update(int w)
	{
		t[w].sum=t[w].cnt=t[w].mx=0,t[w].mn=2e9;
		for(int i=T[w].l;i<=T[w].r;i++)
			if(bet[i]==id)
				t[w].cnt++,
				t[w].sum+=a[i],
				t[w].mn=min(t[w].mn,a[i]),
				t[w].mx=max(t[w].mx,a[i]);
	}
	inline void pushup(int w)
	{
		if(T[w].fl) update(w);
		else
		{
			t[w].sum=t[ls].sum+t[rs].sum;
			t[w].cnt=t[ls].cnt+t[rs].cnt;
			t[w].mn=min(t[ls].mn,t[rs].mn);
			t[w].mx=max(t[ls].mx,t[rs].mx);
		}
	}
	inline void pushto(int w,int c)
	{
		t[c].tag+=t[w].tag;
		t[c].mn+=t[w].tag;
		t[c].mx+=t[w].tag;
		t[c].sum+=t[c].cnt*t[w].tag;
	}
	inline void pushdown(int w)
	{
		if(!t[w].tag) return;
		if(T[w].fl)
		{
			for(int i=T[w].l;i<=T[w].r;i++)
				if(bet[i]==id)
					a[i]+=t[w].tag;
		}	
		else
			pushto(w,ls),
			pushto(w,rs);
		t[w].tag=0;
	}
	void pushall(int w)
	{
		if(w>1) pushall(w>>1);
		pushdown(w);
	}
	void add(int w)
	{
		int c=a[w];
		pushall(wz[w]);
		a[w]=c;
		pushup(w=wz[w]);
		for(w>>=1;w;w>>=1)
			pushup(w);
	}
	void ask(int w,int l,int r)
	{
		if(T[w].l>=l&&T[w].r<=r)
		{
			mn=min(mn,t[w].mn);
			mx=max(mx,t[w].mx);
			sum+=t[w].sum;
			return;
		}
		pushdown(w);
		if(T[w].fl)
		{
			for(int i=T[w].l;i<=T[w].r;i++)
				if(i>=l&&i<=r&&bet[i]==id)
					mn=min(mn,a[i]),
					mx=max(mx,a[i]),
					sum+=a[i];
			return;
		}
		if(T[ls].r>=l) ask(ls,l,r);
		if(T[rs].l<=r) ask(rs,l,r);
	}
	void add(int w,int l,int r,ll x)
	{
		if(t[w].mx<=x) return;
		if(T[w].l>=l&&T[w].r<=r)
		{
			if(t[w].mn>x)
			{
				t[w].tag-=x;
				t[w].mn-=x;
				t[w].mx-=x;
				t[w].sum-=t[w].cnt*x;
				return;
			}
			pushdown(w);
			if(T[w].fl)
			{
				for(int i=T[w].l;i<=T[w].r;i++)
					if(bet[i]==id)
						a[i]-=(a[i]>x)*x;
				pushup(w);
				return;
			}
			add(ls,l,r,x),add(rs,l,r,x);
			pushup(w);
			return;
		}
		pushdown(w);
		if(T[w].fl)
		{
			for(int i=T[w].l;i<=T[w].r;i++)
				if(i>=l&&i<=r&&bet[i]==id)
					a[i]-=(a[i]>x)*x;
			pushup(w);
			return;
		}
		if(T[ls].r>=l) add(ls,l,r,x);
		if(T[rs].l<=r) add(rs,l,r,x);
		pushup(w);
	}
	void del(int w)
	{
		if(t[w].mn>=L) return;
		pushdown(w);
		if(T[w].fl)
		{
			t[w].sum=t[w].cnt=t[w].mx=0,t[w].mn=2e9;
				for(int i=T[w].l;i<=T[w].r;i++)
					if(bet[i]==id)
						if(a[i]>=L)
							t[w].cnt++,
							t[w].sum+=a[i],
							t[w].mn=min(t[w].mn,a[i]),
							t[w].mx=max(t[w].mx,a[i]);
						else
							down[++dcnt]=i,bet[i]=0;
			return;
		}
		del(ls),del(rs);
		pushup(w);
	}
}t[7];
int cnt;
void add(int w)
{
	for(int i=1;;i++)
		if(t[i].L<=a[w]&&t[i].R>=a[w])
		{
			bet[w]=i,t[i].add(w);
			break;
		}	
}
void init(){
	build(1,1,n);
	int i;
	for(ll j=1;;j*=B){
		t[++cnt].L=j;
		t[cnt].id=cnt;
		if((t[cnt].R=j*B-1)>=1e9)
			break;
	}
	for(i=1;i<=n;i++)
		add(i);
}
void ask(int l,int r){
	mn=2e9,mx=sum=0;
	for(int i=1;i<=cnt;i++)
		t[i].ask(1,l,r);	
}
void add(int l,int r,int x){
	for(int i=1;i<=cnt;i++)
		t[i].add(1,l,r,x),
		t[i].del(1);
	for(;dcnt;dcnt--)
		add(down[dcnt]);
}
int main(){
	n=read();
	int m=read(),i,last=0,opt,l,r;
	for(i=1;i<=n;i++)
		a[i]=read();
	init();
	while(m--)
    {
		opt=read(),l=read()^last,r=read()^last;
		if(opt==1) add(l,r,read()^last);
		else
		{
			ask(l,r);
			printf("%lld %d %d\n",sum,mn,mx);
			last=sum&(1<<20)-1;
		}
	}
}

