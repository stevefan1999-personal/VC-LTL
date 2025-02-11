//
// legacy_stdio_definitions.cpp
//
//      Copyright (c) Microsoft Corporation. All rights reserved.
//
// Provides external definitions of the inline stdio printf and scanf functions
// for use by objects compiled with older versions of the CRT headers.
//

// Our references to "unsafe" functions count as "use" so we need to suppress
// the deprecation warnings.  Note that any clients using these symbols will
// also get these deprecation warnings.
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NON_CONFORMING_SWPRINTFS
#define _CRT_SECURE_CPP_OVERLOAD_SECURE_NAMES 0
#define _NO_CRT_STDIO_INLINE 1
#define _CRT_STDIO_ARBITRARY_WIDE_SPECIFIERS
#define _CRT_STDIO_LEGACY_WIDE_SPECIFIERS

#define _INC_SWPRINTF_INL_
#define _CRT_STDIO_INLINE extern
#include <stdio.h>
#include <sdkddkver.h>


// Define the __imp_- or _imp__-prefixed IAT symbols, for compatibility with
// objects that were compiled with /MD or /MDd.
#include <vcstartup_internal.h>

#undef _NO_CRT_STDIO_INLINE

#if _CRT_NTDDI_MIN < NTDDI_WIN6
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fprintf_l(
        _Inout_                                 FILE*       const _Stream,
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fprintf_p(
        _Inout_                       FILE*       const _Stream,
        _In_z_ _Printf_format_string_ char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vfprintf_p_l(_Stream, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fprintf_p_l(
        _Inout_                                 FILE*       const _Stream,
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fprintf_s_l(
        _Inout_                                 FILE*       const _Stream,
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fprintf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _fscanf_l(
        _Inout_                                FILE*       const _Stream,
        _In_z_ _Scanf_format_string_params_(0) char const* const _Format,
        _In_opt_                               _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfscanf_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fscanf_s_l(
        _Inout_                                  FILE*       const _Stream,
        _In_z_ _Scanf_s_format_string_params_(0) char const* const _Format,
        _In_opt_                                 _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fwprintf_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fwprintf_p(
        _Inout_                       FILE*          const _Stream,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vfwprintf_p_l(_Stream, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fwprintf_p_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_p_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fwprintf_s_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_s_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwprintf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_fwscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _fwscanf_l(
        _Inout_                                FILE*          const _Stream,
        _In_z_ _Scanf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                               _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwscanf_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _fwscanf_s_l(
        _Inout_                                  FILE*          const _Stream,
        _In_z_ _Scanf_s_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                 _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwscanf_s_l(_Stream, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_fwscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _printf_l(
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_printf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _printf_p(
        _In_z_ _Printf_format_string_ char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vfprintf_p_l(stdout, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_printf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _printf_p_l(
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_p_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_printf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _printf_s_l(
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfprintf_s_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_printf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_scanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _scanf_l(
        _In_z_ _Scanf_format_string_params_(0) char const* const _Format,
        _In_opt_                               _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfscanf_l(stdin, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _scanf_s_l(
        _In_z_ _Scanf_s_format_string_params_(0) char const* const _Format,
        _In_opt_                                 _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfscanf_s_l(stdin, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _scprintf_l(
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vscprintf_l(_Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _scprintf_p_l(
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vscprintf_p_l(_Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scprintf_p_l);

    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _scwprintf_l(
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vscwprintf_l(_Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scwprintf_l);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _scwprintf_p_l(
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vscwprintf_p_l(_Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scwprintf_p_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snprintf_c(
        _Out_writes_opt_(_BufferCount) char*       const _Buffer,
        _In_                           size_t      const _BufferCount,
        _In_z_ _Printf_format_string_  char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf_c);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snprintf_c_l(
        _Out_writes_opt_(_BufferCount)          char*       const _Buffer,
        _In_                                    size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsnprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf_c_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _snprintf_l(
        _Out_writes_opt_(_BufferCount) _Post_maybez_ char*       const _Buffer,
        _In_                                         size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)      char const* const _Format,
        _In_opt_                                     _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        _Result = _vsnprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        #pragma warning(pop)

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snprintf_s(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                              size_t      const _BufferCount,
        _In_                                              size_t      const _MaxCount,
        _In_z_ _Printf_format_string_                     char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf_s);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snprintf_s_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                              size_t      const _BufferCount,
        _In_                                              size_t      const _MaxCount,
        _In_z_ _Printf_format_string_params_(0)           char const* const _Format,
        _In_opt_                                          _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _snscanf_l(
        _In_reads_bytes_(_BufferCount) _Pre_z_ char const* const _Buffer,
        _In_                                   size_t      const _BufferCount,
        _In_z_ _Scanf_format_string_params_(0) char const* const _Format,
        _In_opt_                               _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        _Result = __stdio_common_vsscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snscanf_s(
        _In_reads_bytes_(_BufferCount) _Pre_z_ char const* const _Buffer,
        _In_                                   size_t      const _BufferCount,
        _In_z_ _Scanf_s_format_string_         char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);

        _Result = __stdio_common_vsscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Buffer, _BufferCount, _Format, NULL, _ArgList);

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snscanf_s);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snscanf_s_l(
        _In_reads_bytes_(_BufferCount) _Pre_z_   char const* const _Buffer,
        _In_                                     size_t      const _BufferCount,
        _In_z_ _Scanf_s_format_string_params_(0) char const* const _Format,
        _In_opt_                                 _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        _Result = __stdio_common_vsscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snscanf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _snwprintf_l(
        _Out_writes_opt_(_BufferCount) _Post_maybez_ wchar_t*       const _Buffer,
        _In_                                         size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)      wchar_t const* const _Format,
        _In_opt_                                     _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        _Result = _vsnwprintf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        #pragma warning(pop)

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snwprintf_s(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_                                              size_t         const _MaxCount,
        _In_z_ _Printf_format_string_                     wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwprintf_s);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snwprintf_s_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_                                              size_t         const _MaxCount,
        _In_z_ _Printf_format_string_params_(0)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwprintf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_snwscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _snwscanf_l(
        _In_reads_(_BufferCount) _Pre_z_       wchar_t const* const _Buffer,
        _In_                                   size_t         const _BufferCount,
        _In_z_ _Scanf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                               _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        _Result = _vsnwscanf_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        #pragma warning(pop)

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwscanf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snwscanf_s(
        _In_reads_(_BufferCount) _Pre_z_  wchar_t const* const _Buffer,
        _In_                              size_t         const _BufferCount,
        _In_z_ _Scanf_s_format_string_    wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwscanf_s);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snwscanf_s_l(
        _In_reads_(_BufferCount) _Pre_z_         wchar_t const* const _Buffer,
        _In_                                     size_t         const _BufferCount,
        _In_z_ _Scanf_s_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                 _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsnwscanf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snwscanf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_sprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _sprintf_l(
        _Pre_notnull_ _Always_(_Post_z_)        char*       const _Buffer,
        _In_z_ _Printf_format_string_params_(0) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);

        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        _Result = _vsprintf_l(_Buffer, _Format, _Locale, _ArgList);
        #pragma warning(pop)

        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _sprintf_p_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)       char const* const _Format,
        _In_opt_                                      _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sprintf_p_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _sprintf_s_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)       char const* const _Format,
        _In_opt_                                      _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sprintf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_sscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _sscanf_l(
        _In_z_                                 char const* const _Buffer,
        _In_z_ _Scanf_format_string_params_(0) char const* const _Format,
        _In_opt_                               _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsscanf_l(_Buffer, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _sscanf_s_l(
        _In_z_                                   char const* const _Buffer,
        _In_z_ _Scanf_s_format_string_params_(0) char const* const _Format,
        _In_opt_                                 _locale_t   const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vsscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sscanf_s_l);


	extern "C" int __CRTDECL _swprintf(
		_Pre_notnull_ _Always_(_Post_z_) wchar_t* const _Buffer,
		_In_z_ _Printf_format_string_    wchar_t const* const _Format,
		...)
	{
		int _Result;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		#pragma warning(suppress : 4996)
		_Result = _vsnwprintf(_Buffer, _CRT_STDIO_SIZE_MAX, _Format, _ArgList);
		__crt_va_end(_ArgList);
		return _Result;
	}
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf);

	extern "C" int __CRTDECL _swprintf_c(
		_Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
		_In_                                              size_t         const _BufferCount,
		_In_z_ _Printf_format_string_                     wchar_t const* const _Format,
		...)
	{
		int _Result;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		_Result = _vsnwprintf(_Buffer, _BufferCount, _Format, _ArgList);
		__crt_va_end(_ArgList);
		return _Result;
	}
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_c);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swprintf_c_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_c_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swprintf_p_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)       wchar_t const* const _Format,
        _In_opt_                                      _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_p_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swprintf_s_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)       wchar_t const* const _Format,
        _In_opt_                                      _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_swscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _swscanf_l(
        _In_z_                                 wchar_t const* const _Buffer,
        _In_z_ _Scanf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                               _locale_t            _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswscanf_l(_Buffer, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swscanf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swscanf_s_l(
        _In_z_                                   wchar_t const* const _Buffer,
        _In_z_ _Scanf_s_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                 _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswscanf_s_l(_Buffer, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfprintf_l(
        _Inout_  FILE*       const _Stream,
        _In_z_   char const* const _Format,
        _In_opt_ _locale_t   const _Locale,
                 va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfprintf_p(
        _Inout_                       FILE*       const _Stream,
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfprintf_p_l(_Stream, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfprintf_p_l(
        _Inout_  FILE*       const _Stream,
        _In_z_   char const* const _Format,
        _In_opt_ _locale_t   const _Locale,
                 va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfprintf_s_l(
        _Inout_  FILE*       const _Stream,
        _In_z_   char const* const _Format,
        _In_opt_ _locale_t   const _Locale,
                 va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfprintf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwprintf_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfwprintf(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwprintf_p(
        _Inout_                       FILE*          const _Stream,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwprintf_p_l(_Stream, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwprintf_p_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfwprintf_p(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwprintf_s_l(
        _Inout_                                 FILE*          const _Stream,
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfwprintf_s(_CRT_INTERNAL_LOCAL_PRINTF_OPTIONS, _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwprintf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vprintf_l(
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfprintf_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vprintf_p(
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfprintf_p_l(stdout, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vprintf_p_l(
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfprintf_p_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vprintf_s_l(
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfprintf_s_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vprintf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vscprintf_l(
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR,
            NULL, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vscprintf_p_l(
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf_p(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR,
            NULL, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscprintf_p_l);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _vscwprintf(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vscwprintf_l(_Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscwprintf);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _vscwprintf_l(
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR,
            NULL, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscwprintf_l);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _vscwprintf_p_l(
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf_p(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR,
            NULL, 0, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscwprintf_p_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnprintf_c(
        _Out_writes_opt_(_BufferCount) char*       const _Buffer,
        _In_                           size_t      const _BufferCount,
        _In_z_ _Printf_format_string_  char const* const _Format,
                                       va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vsnprintf_c_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnprintf_c);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnprintf_c_l(
        _Out_writes_opt_(_BufferCount)          char*       const _Buffer,
        _In_                                    size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(2) char const* const _Format,
        _In_opt_                                _locale_t   const _Locale,
                                                va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnprintf_c_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _vsnprintf_l(
        _Out_writes_opt_(_BufferCount) _Post_maybez_ char*       const _Buffer,
        _In_                                         size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)      char const* const _Format,
        _In_opt_                                     _locale_t   const _Locale,
                                                     va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnprintf_s(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                              size_t      const _BufferCount,
        _In_                                              size_t      const _MaxCount,
        _In_z_ _Printf_format_string_                     char const* const _Format,
                                                          va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vsnprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnprintf_s);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnprintf_s_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                              size_t      const _BufferCount,
        _In_                                              size_t      const _MaxCount,
        _In_z_ _Printf_format_string_params_(2)           char const* const _Format,
        _In_opt_                                          _locale_t   const _Locale,
                                                          va_list          _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsnprintf_s(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnprintf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnwprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _vsnwprintf_l(
        _Out_writes_opt_(_BufferCount) _Post_maybez_ wchar_t*       const _Buffer,
        _In_                                         size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)      wchar_t const* const _Format,
        _In_opt_                                     _locale_t      const _Locale,
                                                     va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS | _CRT_INTERNAL_PRINTF_LEGACY_VSPRINTF_NULL_TERMINATION,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnwprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnwprintf_s(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_                                              size_t         const _MaxCount,
        _In_z_ _Printf_format_string_                     wchar_t const* const _Format,
                                                          va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vsnwprintf_s_l(_Buffer, _BufferCount, _MaxCount, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnwprintf_s);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnwprintf_s_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_                                              size_t         const _MaxCount,
        _In_z_ _Printf_format_string_params_(2)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsnwprintf_s(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _MaxCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnwprintf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsprintf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _vsprintf_l(
        _Pre_notnull_ _Always_(_Post_z_) char*       const _Buffer,
        _In_z_                           char const* const _Format,
        _In_opt_                         _locale_t   const _Locale,
                                         va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        return _vsnprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
        #pragma warning(pop)
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsprintf_p(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_                 char const* const _Format,
                                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vsprintf_p_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsprintf_p);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsprintf_p_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)       char const* const _Format,
        _In_opt_                                      _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf_p(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsprintf_s_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)       char const* const _Format,
        _In_opt_                                      _locale_t   const _Locale,
                                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vsprintf_s(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsprintf_s_l);

	extern "C" int __CRTDECL _vswprintf(
		_Pre_notnull_ _Always_(_Post_z_) wchar_t* const _Buffer,
		_In_z_ _Printf_format_string_    wchar_t const* const _Format,
		va_list              _ArgList
		)
	{
		#pragma warning(suppress : 4996)
		return _vsnwprintf(_Buffer, _CRT_STDIO_SIZE_MAX, _Format, _ArgList);
	}

	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf);

	//_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_c); = _vsnwprintf 转发 //此处存在特性损失，当缓冲区长度刚好为实际使用长度时会null终止，不过这个情况没有变的更坏就这样吧……

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswprintf_c_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_c_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswprintf_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
                                                          va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        #pragma warning(push)
        #pragma warning(disable: 4996) // Deprecation
        return _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        #pragma warning(pop)
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswprintf_p_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)       wchar_t const* const _Format,
        _In_opt_                                      _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf_p(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_p_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswprintf_s_l(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(2)       wchar_t const* const _Format,
        _In_opt_                                      _locale_t      const _Locale,
                                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int const _Result = __stdio_common_vswprintf_s(
            _CRT_INTERNAL_LOCAL_PRINTF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);

        return _Result < 0 ? -1 : _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vwprintf_l(
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwprintf_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vwprintf_p(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwprintf_p_l(stdout, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vwprintf_p_l(
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwprintf_p_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vwprintf_s_l(
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwprintf_s_l(stdout, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwprintf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _wprintf_l(
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wprintf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _wprintf_p(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vfwprintf_p_l(stdout, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _wprintf_p_l(
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_p_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wprintf_p_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _wprintf_s_l(
        _In_z_ _Printf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwprintf_s_l(stdout, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wprintf_s_l);

    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_wscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _wscanf_l(
        _In_z_ _Scanf_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                               _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwscanf_l(stdin, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _wscanf_s_l(
        _In_z_ _Scanf_s_format_string_params_(0) wchar_t const* const _Format,
        _In_opt_                                 _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vfwscanf_s_l(stdin, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_wscanf_s_l);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL fprintf_s(
            _Inout_                       FILE*       const _Stream,
            _In_z_ _Printf_format_string_ char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfprintf_s_l(_Stream, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(fprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL fscanf_s(
            _Inout_                        FILE*       const _Stream,
            _In_z_ _Scanf_s_format_string_ char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfscanf_s_l(_Stream, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(fscanf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL fwprintf_s(
            _Inout_                       FILE*          const _Stream,
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfwprintf_s_l(_Stream, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(fwprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL fwscanf_s(
            _Inout_                        FILE*          const _Stream,
            _In_z_ _Scanf_s_format_string_ wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfwscanf_s_l(_Stream, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(fwscanf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL printf_s(
            _In_z_ _Printf_format_string_ char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfprintf_s_l(stdout, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(printf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL scanf_s(
            _In_z_ _Scanf_s_format_string_ char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfscanf_s_l(stdin, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(scanf_s);

        _Success_(return >= 0)
        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL sprintf_s(
            _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
            _In_                                          size_t      const _BufferCount,
            _In_z_ _Printf_format_string_                 char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vsprintf_s_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(sprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL sscanf_s(
            _In_z_                         char const* const _Buffer,
            _In_z_ _Scanf_s_format_string_ char const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
            ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);

            #pragma warning(push)
            #pragma warning(disable: 4996) // Deprecation
            _Result = vsscanf_s(_Buffer, _Format, _ArgList);
            #pragma warning(pop)

            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(sscanf_s);

        _Success_(return >= 0)
        _CRT_STDIO_INLINE int __CRTDECL swprintf_s(
            _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
            _In_                                          size_t         const _BufferCount,
            _In_z_ _Printf_format_string_                 wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vswprintf_s_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(swprintf_s);

        _Success_(return >= 0)
        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL swscanf_s(
            _In_z_                         wchar_t const* const _Buffer,
            _In_z_ _Scanf_s_format_string_ wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
        ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vswscanf_s_l(_Buffer, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(swscanf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vfprintf_s(
            _Inout_                       FILE*       const _Stream,
            _In_z_ _Printf_format_string_ char const* const _Format,
                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfprintf_s_l(_Stream, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vfwprintf_s(
            _Inout_                       FILE*          const _Stream,
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfwprintf_s_l(_Stream, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfwprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vprintf_s(
            _In_z_ _Printf_format_string_ char const* const _Format,
                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfprintf_s_l(stdout, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vprintf_s);

        _Success_(return >= 0)
        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vsprintf_s(
            _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
            _In_                                          size_t      const _BufferCount,
            _In_z_ _Printf_format_string_                 char const* const _Format,
                                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vsprintf_s_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vsprintf_s);

        _Success_(return >= 0)
        _CRT_STDIO_INLINE int __CRTDECL vswprintf_s(
            _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
            _In_                                          size_t         const _BufferCount,
            _In_z_ _Printf_format_string_                 wchar_t const* const _Format,
                                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vswprintf_s_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vswprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vwprintf_s(
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfwprintf_s_l(stdout, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vwprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL wprintf_s(
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfwprintf_s_l(stdout, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(wprintf_s);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL wscanf_s(
            _In_z_ _Scanf_s_format_string_ wchar_t const* const _Format,
            ...)
    #if defined _NO_CRT_STDIO_INLINE // SCANF
            ;
    #else
        {
            int _Result;
            va_list _ArgList;
            __crt_va_start(_ArgList, _Format);
            _Result = _vfwscanf_s_l(stdin, _Format, NULL, _ArgList);
            __crt_va_end(_ArgList);
            return _Result;
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(wscanf_s);
#endif


    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL __swprintf_l(
        _Pre_notnull_ _Always_(_Post_z_)        wchar_t*       const _Buffer,
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = __vswprintf_l(_Buffer, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(__swprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL __vswprintf_l(
        _Pre_notnull_ _Always_(_Post_z_)        wchar_t*       const _Buffer,
        _In_z_ _Printf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                _locale_t      const _Locale,
                                                va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vswprintf_l(_Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(__vswprintf_l);

    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _scprintf_p(
        _In_z_ _Printf_format_string_ char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vscprintf_p(_Format, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scprintf_p);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _scwprintf_p(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vscwprintf_p_l(_Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_scwprintf_p);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _snprintf(
        _Out_writes_opt_(_BufferCount) _Post_maybez_ char*       const _Buffer,
        _In_                                         size_t      const _BufferCount,
        _In_z_ _Printf_format_string_                char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
    #pragma warning(suppress:28719)    // 28719
        _Result = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_snprintf);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _sprintf_p(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                          size_t      const _BufferCount,
        _In_z_ _Printf_format_string_                 char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vsprintf_p_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_sprintf_p);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swprintf_l(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                              size_t         const _BufferCount,
        _In_z_ _Printf_format_string_params_(0)           wchar_t const* const _Format,
        _In_opt_                                          _locale_t      const _Locale,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Locale);
        _Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, _Locale, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _swprintf_p(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_                 wchar_t const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
        _Result = _vswprintf_p_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_swprintf_p);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfscanf_l(
        _Inout_                       FILE*       const _Stream,
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfscanf_s_l(
        _Inout_                       FILE*       const _Stream,
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwscanf_l(
        _Inout_ FILE*                                const _Stream,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfwscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vfwscanf_s_l(
        _Inout_                       FILE*          const _Stream,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vfwscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Stream, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vfwscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vscanf_l(
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfscanf_l(stdin, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vscanf_s_l(
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfscanf_s_l(stdin, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscanf_s_l);

    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _vscprintf_p(
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vscprintf_p_l(_Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscprintf_p);

    _Success_(return >= 0)
    _Check_return_
    _CRT_STDIO_INLINE int __CRTDECL _vscwprintf_p(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vscwprintf_p_l(_Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vscwprintf_p);

    _Success_(return >= 0)
    _Check_return_opt_ _CRT_INSECURE_DEPRECATE(_vsnwscanf_s_l)
    _CRT_STDIO_INLINE int __CRTDECL _vsnwscanf_l(
        _In_reads_(_BufferCount) _Pre_z_       wchar_t const* const _Buffer,
        _In_                                   size_t         const _BufferCount,
        _In_z_ _Scanf_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                               _locale_t      const _Locale,
                                               va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vswscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnwscanf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsnwscanf_s_l(
        _In_reads_(_BufferCount) _Pre_z_         wchar_t const* const _Buffer,
        _In_                                     size_t         const _BufferCount,
        _In_z_ _Scanf_s_format_string_params_(2) wchar_t const* const _Format,
        _In_opt_                                 _locale_t      const _Locale,
                                                 va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vswscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Buffer, _BufferCount, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsnwscanf_s_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsscanf_l(
        _In_z_                        char const* const _Buffer,
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vsscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vsscanf_s_l(
        _In_z_                        char const* const _Buffer,
        _In_z_ _Printf_format_string_ char const* const _Format,
        _In_opt_                      _locale_t   const _Locale,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vsscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vsscanf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswprintf_p(
        _Out_writes_(_BufferCount) _Always_(_Post_z_) wchar_t*       const _Buffer,
        _In_                                          size_t         const _BufferCount,
        _In_z_ _Printf_format_string_                 wchar_t const* const _Format,
                                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vswprintf_p_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswprintf_p);


    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswscanf_l(
        _In_z_                        wchar_t const* const _Buffer,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vswscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS,
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswscanf_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vswscanf_s_l(
        _In_z_                        wchar_t const* const _Buffer,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return __stdio_common_vswscanf(
            _CRT_INTERNAL_LOCAL_SCANF_OPTIONS | _CRT_INTERNAL_SCANF_SECURECRT,
            _Buffer, (size_t)-1, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vswscanf_s_l);

    _CRT_STDIO_INLINE int __CRTDECL _vwscanf_l(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwscanf_l(stdin, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwscanf_l);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL _vwscanf_s_l(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
        _In_opt_                      _locale_t      const _Locale,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwscanf_s_l(stdin, _Format, _Locale, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(_vwscanf_s_l);

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL snprintf(
        _Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
        _In_                                              size_t      const _BufferCount,
        _In_z_ _Printf_format_string_                     char const* const _Format,
        ...)
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        int _Result;
        va_list _ArgList;
        __crt_va_start(_ArgList, _Format);
    #pragma warning(suppress:28719)    // 28719
        _Result = vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);
        __crt_va_end(_ArgList);
        return _Result;
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(snprintf);


	extern "C" int __CRTDECL swprintf(
		_Out_writes_opt_(_BufferCount) _Always_(_Post_z_) wchar_t* const _Buffer,
		_In_                                              size_t         const _BufferCount, //msvcrt.dll 没有此参数
		_In_z_ _Printf_format_string_                     wchar_t const* const _Format,
		...)
	{
	#if _CRT_NTDDI_MIN < 0x06000000
		int _Result;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		#pragma warning(suppress : 4996)
		_Result = _vsnwprintf(_Buffer, _BufferCount, _Format, _ArgList);
		__crt_va_end(_ArgList);
		return _Result;
	#else
		int _Result;
		va_list _ArgList;
		__crt_va_start(_ArgList, _Format);
		_Result = _vswprintf_c_l(_Buffer, _BufferCount, _Format, NULL, _ArgList);
		__crt_va_end(_ArgList);
		return _Result;
	#endif
	}
	_VCRT_DEFINE_IAT_SYMBOL(swprintf);
	
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vfscanf(
        _Inout_                       FILE*       const _Stream,
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfscanf_l(_Stream, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfscanf);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vfscanf_s(
            _Inout_                       FILE*       const _Stream,
            _In_z_ _Printf_format_string_ char const* const _Format,
                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfscanf_s_l(_Stream, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfscanf_s);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vfwscanf(
        _Inout_ FILE*                                const _Stream,
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwscanf_l(_Stream, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfwscanf);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vfwscanf_s(
            _Inout_                       FILE*          const _Stream,
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfwscanf_s_l(_Stream, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vfwscanf_s);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vscanf(
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfscanf_l(stdin, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vscanf);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vscanf_s(
            _In_z_ _Printf_format_string_ char const* const _Format,
                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfscanf_s_l(stdin, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vscanf_s);

	//msvcrt.dll 没有_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR特性
	extern "C" int __CRTDECL vsnprintf(
		_Out_writes_opt_(_BufferCount) _Always_(_Post_z_) char*       const _Buffer,
		_In_                                              size_t      const _BufferCount,
		_In_z_ _Printf_format_string_                     char const* const _Format,
		va_list           _ArgList
		)
	{
		auto Count = _vsnprintf(_Buffer, _BufferCount, _Format, _ArgList);

		//模拟_CRT_INTERNAL_PRINTF_STANDARD_SNPRINTF_BEHAVIOR特性
		if (_Buffer != nullptr && _BufferCount != 0)
		{
			if (Count < 0)
			{
				*_Buffer = '\0';
			}
			else if ((size_t)Count == _BufferCount)
			{
				_Buffer[Count - 1] = '\0';
			}
			else
			{
				_Buffer[Count] = '\0';
			}
		}

		return Count;
	}
	_VCRT_DEFINE_IAT_SYMBOL(vsnprintf);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vsscanf(
        _In_z_                        char const* const _Buffer,
        _In_z_ _Printf_format_string_ char const* const _Format,
                                      va_list           _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vsscanf_l(_Buffer, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vsscanf);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vsscanf_s(
            _In_z_                        char const* const _Buffer,
            _In_z_ _Printf_format_string_ char const* const _Format,
                                          va_list           _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vsscanf_s_l(_Buffer, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vsscanf_s);
	//_VCRT_DEFINE_IAT_SYMBOL(vswprintf); _vswprintf_c转发

    _Success_(return >= 0)
    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vswscanf(
        _In_z_                        wchar_t const* _Buffer,
        _In_z_ _Printf_format_string_ wchar_t const* _Format,
                                      va_list        _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vswscanf_l(_Buffer, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vswscanf);

        _Success_(return >= 0)
        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vswscanf_s(
            _In_z_                        wchar_t const* const _Buffer,
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vswscanf_s_l(_Buffer, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vswscanf_s);

    _Check_return_opt_
    _CRT_STDIO_INLINE int __CRTDECL vwscanf(
        _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                      va_list              _ArgList
        )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
    {
        return _vfwscanf_l(stdin, _Format, NULL, _ArgList);
    }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vwscanf);

        _Check_return_opt_
        _CRT_STDIO_INLINE int __CRTDECL vwscanf_s(
            _In_z_ _Printf_format_string_ wchar_t const* const _Format,
                                          va_list              _ArgList
            )
    #if defined _NO_CRT_STDIO_INLINE
    ;
    #else
        {
            return _vfwscanf_s_l(stdin, _Format, NULL, _ArgList);
        }
    #endif
	_VCRT_DEFINE_IAT_SYMBOL(vwscanf_s);
