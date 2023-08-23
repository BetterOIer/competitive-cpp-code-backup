#pragma GCC system_header
#include<bits/c++config.h>
#include<stdio.h>
#ifndef _GLIBCXX_CSTDIO
#define _GLIBCXX_CSTDIO 1
#if __cplusplus<=201103L&&!defined(_GLIBCXX_HAVE_GETS)
extern"C"char*gets(char*__s)__attribute__((__deprecated__));
#endif
#undef clearerr
#undef fclose
#undef feof
#undef ferror
#undef fflush
#undef fgetc
#undef fgetpos
#undef fgets
#undef fopen
#undef fprintf
#undef fputc
#undef fputs
#undef fread
#undef freopen
#undef fscanf
#undef fseek
#undef fsetpos
#undef ftell
#undef fwrite
#undef getc
#undef getchar
#if __cplusplus<=201103L
#undef gets
#endif
#undef perror
#undef printf
#undef putc
#undef putchar
#undef puts
#undef remove
#undef rename
#undef rewind
#undef scanf
#undef setbuf
#undef setvbuf
#undef sprintf
#undef sscanf
#undef tmpfile
#undef tmpnam
#undef ungetc
#undef vfprintf
#undef vprintf
#undef vsprintf
namespace std{using::FILE;using::fpos_t;using::clearerr;using::fclose;using::feof;using::ferror;using::fflush;using::fgetc;using::fgetpos;using::fgets;using::fopen;using::fprintf;using::fputc;using::fputs;using::fread;using::freopen;using::fscanf;using::fseek;using::fsetpos;using::ftell;using::fwrite;using::getc;using::getchar;
#if __cplusplus<=201103L
using::gets;
#endif
using::perror;using::printf;using::putc;using::putchar;using::puts;using::remove;using::rename;using::rewind;using::scanf;using::setbuf;using::setvbuf;using::sprintf;using::sscanf;using::tmpfile;
#if _GLIBCXX_USE_TMPNAM
using::tmpnam;
#endif
using::ungetc;using::vfprintf;using::vprintf;using::vsprintf;}
#if _GLIBCXX_USE_C99_STDIO
#undef snprintf
#undef vfscanf
#undef vscanf
#undef vsnprintf
#undef vsscanf
namespace __gnu_cxx{
#if _GLIBCXX_USE_C99_CHECK||_GLIBCXX_USE_C99_DYNAMIC
extern"C"int(snprintf)(char*__restrict,std::size_t,const char*__restrict,...)throw();extern"C"int(vfscanf)(FILE*__restrict,const char*__restrict,__gnuc_va_list);extern"C"int(vscanf)(const char*__restrict,__gnuc_va_list);extern"C"int(vsnprintf)(char*__restrict,std::size_t,const char*__restrict,__gnuc_va_list)throw();extern"C"int(vsscanf)(const char*__restrict,const char*__restrict,__gnuc_va_list)throw();
#endif
#if!_GLIBCXX_USE_C99_DYNAMIC
using::snprintf;using::vfscanf;using::vscanf;using::vsnprintf;using::vsscanf;
#endif
}namespace std{using::__gnu_cxx::snprintf;using::__gnu_cxx::vfscanf;using::__gnu_cxx::vscanf;using::__gnu_cxx::vsnprintf;using::__gnu_cxx::vsscanf;}
#endif
#endif
#ifndef _GLIBCXX_ALGORITHM
#define _GLIBCXX_ALGORITHM 1
#pragma GCC system_header
#ifndef _GLIBCXX_UTILITY
#define _GLIBCXX_UTILITY 1
#pragma GCC system_header
#include<bits/c++config.h>
#ifndef _STL_RELOPS_H
#define _STL_RELOPS_H 1
namespace std _GLIBCXX_VISIBILITY(default){_GLIBCXX_BEGIN_NAMESPACE_VERSION namespace rel_ops{template<class _Tp>inline bool operator!=(const _Tp&__x,const _Tp&__y){return!(__x==__y);}template<class _Tp>inline bool operator>(const _Tp&__x,const _Tp&__y){return __y<__x;}template<class _Tp>inline bool operator<=(const _Tp&__x,const _Tp&__y){return!(__y<__x);}template<class _Tp>inline bool operator>=(const _Tp&__x,const _Tp&__y){return!(__x<__y);}}_GLIBCXX_END_NAMESPACE_VERSION}
#endif
#include<bits/stl_pair.h>
#if __cplusplus>=201103L
#include<type_traits>
#include<bits/move.h>
#include<initializer_list>
#if __cplusplus>201703L
#include<ext/numeric_traits.h>
#endif
namespace std _GLIBCXX_VISIBILITY(default){_GLIBCXX_BEGIN_NAMESPACE_VERSION template<typename _Tp>struct tuple_size;template<typename _Tp,typename _Up=typename remove_cv<_Tp>::type,typename=typename enable_if<is_same<_Tp,_Up>::value>::type,size_t=tuple_size<_Tp>::value>using __enable_if_has_tuple_size=_Tp;template<typename _Tp>struct tuple_size<const __enable_if_has_tuple_size<_Tp>>:public tuple_size<_Tp>{};template<typename _Tp>struct tuple_size<volatile __enable_if_has_tuple_size<_Tp>>:public tuple_size<_Tp>{};template<typename _Tp>struct tuple_size<const volatile __enable_if_has_tuple_size<_Tp>>:public tuple_size<_Tp>{};template<std::size_t __i,typename _Tp>struct tuple_element;template<std::size_t __i,typename _Tp>using __tuple_element_t=typename tuple_element<__i,_Tp>::type;template<std::size_t __i,typename _Tp>struct tuple_element<__i,const _Tp>{typedef typename add_const<__tuple_element_t<__i,_Tp>>::type type;};template<std::size_t __i,typename _Tp>struct tuple_element<__i,volatile _Tp>{typedef typename add_volatile<__tuple_element_t<__i,_Tp>>::type type;};template<std::size_t __i,typename _Tp>struct tuple_element<__i,const volatile _Tp>{typedef typename add_cv<__tuple_element_t<__i,_Tp>>::type type;};
#if __cplusplus>=201402L
#define __cpp_lib_tuple_element_t 201402L
template<std::size_t __i,typename _Tp>using tuple_element_t=typename tuple_element<__i,_Tp>::type;
#endif
template<typename _T1,typename _T2>struct __is_tuple_like_impl<std::pair<_T1,_T2>>:true_type{};template<class _Tp1,class _Tp2>struct tuple_size<std::pair<_Tp1,_Tp2>>:public integral_constant<std::size_t,2>{};template<class _Tp1,class _Tp2>struct tuple_element<0,std::pair<_Tp1,_Tp2>>{typedef _Tp1 type;};template<class _Tp1,class _Tp2>struct tuple_element<1,std::pair<_Tp1,_Tp2>>{typedef _Tp2 type;};template<std::size_t _Int>struct __pair_get;template<>struct __pair_get<0>{template<typename _Tp1,typename _Tp2>static constexpr _Tp1&__get(std::pair<_Tp1,_Tp2>&__pair)noexcept{return __pair.first;}template<typename _Tp1,typename _Tp2>static constexpr _Tp1&&__move_get(std::pair<_Tp1,_Tp2>&&__pair)noexcept{return std::forward<_Tp1>(__pair.first);}template<typename _Tp1,typename _Tp2>static constexpr const _Tp1&__const_get(const std::pair<_Tp1,_Tp2>&__pair)noexcept{return __pair.first;}template<typename _Tp1,typename _Tp2>static constexpr const _Tp1&&__const_move_get(const std::pair<_Tp1,_Tp2>&&__pair)noexcept{return std::forward<const _Tp1>(__pair.first);}};template<>struct __pair_get<1>{template<typename _Tp1,typename _Tp2>static constexpr _Tp2&__get(std::pair<_Tp1,_Tp2>&__pair)noexcept{return __pair.second;}template<typename _Tp1,typename _Tp2>static constexpr _Tp2&&__move_get(std::pair<_Tp1,_Tp2>&&__pair)noexcept{return std::forward<_Tp2>(__pair.second);}template<typename _Tp1,typename _Tp2>static constexpr const _Tp2&__const_get(const std::pair<_Tp1,_Tp2>&__pair)noexcept{return __pair.second;}template<typename _Tp1,typename _Tp2>static constexpr const _Tp2&&__const_move_get(const std::pair<_Tp1,_Tp2>&&__pair)noexcept{return std::forward<const _Tp2>(__pair.second);}};template<std::size_t _Int,class _Tp1,class _Tp2>constexpr typename tuple_element<_Int,std::pair<_Tp1,_Tp2>>::type&get(std::pair<_Tp1,_Tp2>&___in)noexcept{return __pair_get<_Int>::__get(___in);}template<std::size_t _Int,class _Tp1,class _Tp2>constexpr typename tuple_element<_Int,std::pair<_Tp1,_Tp2>>::type&&get(std::pair<_Tp1,_Tp2>&&___in)noexcept{return __pair_get<_Int>::__move_get(std::move(___in));}template<std::size_t _Int,class _Tp1,class _Tp2>constexpr const typename tuple_element<_Int,std::pair<_Tp1,_Tp2>>::type&get(const std::pair<_Tp1,_Tp2>&___in)noexcept{return __pair_get<_Int>::__const_get(___in);}template<std::size_t _Int,class _Tp1,class _Tp2>constexpr const typename tuple_element<_Int,std::pair<_Tp1,_Tp2>>::type&&get(const std::pair<_Tp1,_Tp2>&&___in)noexcept{return __pair_get<_Int>::__const_move_get(std::move(___in));}
#if __cplusplus>=201402L
#define __cpp_lib_tuples_by_type 201304
template<typename _Tp,typename _Up>constexpr _Tp&get(pair<_Tp,_Up>&__p)noexcept{return __p.first;}template<typename _Tp,typename _Up>constexpr const _Tp&get(const pair<_Tp,_Up>&__p)noexcept{return __p.first;}template<typename _Tp,typename _Up>constexpr _Tp&&get(pair<_Tp,_Up>&&__p)noexcept{return std::move(__p.first);}template<typename _Tp,typename _Up>constexpr const _Tp&&get(const pair<_Tp,_Up>&&__p)noexcept{return std::move(__p.first);}template<typename _Tp,typename _Up>constexpr _Tp&get(pair<_Up,_Tp>&__p)noexcept{return __p.second;}template<typename _Tp,typename _Up>constexpr const _Tp&get(const pair<_Up,_Tp>&__p)noexcept{return __p.second;}template<typename _Tp,typename _Up>constexpr _Tp&&get(pair<_Up,_Tp>&&__p)noexcept{return std::move(__p.second);}template<typename _Tp,typename _Up>constexpr const _Tp&&get(const pair<_Up,_Tp>&&__p)noexcept{return std::move(__p.second);}
#define __cpp_lib_exchange_function 201304
template<typename _Tp,typename _Up=_Tp>_GLIBCXX20_CONSTEXPR inline _Tp exchange(_Tp&__obj,_Up&&__new_val){return std::__exchange(__obj,std::forward<_Up>(__new_val));}
#endif
template<size_t..._Indexes>struct _Index_tuple{};
#ifdef __has_builtin
#if __has_builtin(__make_integer_seq)
#define _GLIBCXX_USE_MAKE_INTEGER_SEQ 1
#endif
#endif
template<size_t _Num>struct _Build_index_tuple{
#if _GLIBCXX_USE_MAKE_INTEGER_SEQ
template<typename,size_t..._Indices>using _IdxTuple=_Index_tuple<_Indices...>;using __type=__make_integer_seq<_IdxTuple,size_t,_Num>;
#else
using __type=_Index_tuple<__integer_pack(_Num)...>;
#endif
};
#if __cplusplus>201103L
#define __cpp_lib_integer_sequence 201304
template<typename _Tp,_Tp..._Idx>struct integer_sequence{typedef _Tp value_type;static constexpr size_t size()noexcept{return sizeof...(_Idx);}};template<typename _Tp,_Tp _Num>using make_integer_sequence
#if _GLIBCXX_USE_MAKE_INTEGER_SEQ
=__make_integer_seq<integer_sequence,_Tp,_Num>;
#else
=integer_sequence<_Tp,__integer_pack(_Num)...>;
#endif
#undef _GLIBCXX_USE_MAKE_INTEGER_SEQ
template<size_t..._Idx>using index_sequence=integer_sequence<size_t,_Idx...>;template<size_t _Num>using make_index_sequence=make_integer_sequence<size_t,_Num>;template<typename..._Types>using index_sequence_for=make_index_sequence<sizeof...(_Types)>;
#endif
#if __cplusplus>201402L
struct in_place_t{explicit in_place_t()=default;};inline constexpr in_place_t in_place{};template<typename _Tp>struct in_place_type_t{explicit in_place_type_t()=default;};template<typename _Tp>inline constexpr in_place_type_t<_Tp>in_place_type{};template<size_t _Idx>struct in_place_index_t{explicit in_place_index_t()=default;};template<size_t _Idx>inline constexpr in_place_index_t<_Idx>in_place_index{};template<typename>struct __is_in_place_type_impl:false_type{};template<typename _Tp>struct __is_in_place_type_impl<in_place_type_t<_Tp>>:true_type{};template<typename _Tp>struct __is_in_place_type:public __is_in_place_type_impl<_Tp>{};
#define __cpp_lib_as_const 201510
template<typename _Tp>constexpr add_const_t<_Tp>&as_const(_Tp&__t)noexcept{return __t;}template<typename _Tp>void as_const(const _Tp&&)=delete;
#if __cplusplus>201703L
#define __cpp_lib_integer_comparison_functions 202002L
template<typename _Tp,typename _Up>constexpr bool cmp_equal(_Tp __t,_Up __u)noexcept{static_assert(__is_standard_integer<_Tp>::value);static_assert(__is_standard_integer<_Up>::value);if constexpr(is_signed_v<_Tp>==is_signed_v<_Up>)return __t==__u;else if constexpr(is_signed_v<_Tp>)return __t>=0&&make_unsigned_t<_Tp>(__t)==__u;else return __u>=0&&__t==make_unsigned_t<_Up>(__u);}template<typename _Tp,typename _Up>constexpr bool cmp_not_equal(_Tp __t,_Up __u)noexcept{return!std::cmp_equal(__t,__u);}template<typename _Tp,typename _Up>constexpr bool cmp_less(_Tp __t,_Up __u)noexcept{static_assert(__is_standard_integer<_Tp>::value);static_assert(__is_standard_integer<_Up>::value);if constexpr(is_signed_v<_Tp>==is_signed_v<_Up>)return __t<__u;else if constexpr(is_signed_v<_Tp>)return __t<0||make_unsigned_t<_Tp>(__t)<__u;else return __u>=0&&__t<make_unsigned_t<_Up>(__u);}template<typename _Tp,typename _Up>constexpr bool cmp_greater(_Tp __t,_Up __u)noexcept{return std::cmp_less(__u,__t);}template<typename _Tp,typename _Up>constexpr bool cmp_less_equal(_Tp __t,_Up __u)noexcept{return!std::cmp_less(__u,__t);}template<typename _Tp,typename _Up>constexpr bool cmp_greater_equal(_Tp __t,_Up __u)noexcept{return!std::cmp_less(__t,__u);}template<typename _Up,typename _Tp>constexpr bool in_range(_Tp __t)noexcept{static_assert(__is_standard_integer<_Up>::value);static_assert(__is_standard_integer<_Tp>::value);using __gnu_cxx::__int_traits;if constexpr(is_signed_v<_Tp>==is_signed_v<_Up>)return __int_traits<_Up>::__min<=__t&&__t<=__int_traits<_Up>::__max;else if constexpr(is_signed_v<_Tp>)return __t>=0&&make_unsigned_t<_Tp>(__t)<=__int_traits<_Up>::__max;else return __t<=make_unsigned_t<_Up>(__int_traits<_Up>::__max);}
#endif
#endif
_GLIBCXX_END_NAMESPACE_VERSION}
#endif
#endif
#include<bits/stl_algobase.h>
#include<bits/stl_algo.h>
#if __cplusplus>201703L
#include<bits/ranges_algo.h>
#endif
#if __cplusplus>201402L
#if _PSTL_EXECUTION_POLICIES_DEFINED
#include<pstl/glue_algorithm_impl.h>
#else
#include<pstl/glue_algorithm_defs.h>
#define _PSTL_ALGORITHM_FORWARD_DECLARED 1
#endif
#define __cpp_lib_parallel_algorithm 201603L
#endif
#ifdef _GLIBCXX_PARALLEL
#include<parallel/algorithm>
#endif
#endif
#pragma GCC system_header
#include<bits/c++config.h>
#include<ctype.h>
#ifndef _GLIBCXX_CCTYPE
#define _GLIBCXX_CCTYPE 1
#undef isalnum
#undef isalpha
#undef iscntrl
#undef isdigit
#undef isgraph
#undef islower
#undef isprint
#undef ispunct
#undef isspace
#undef isupper
#undef isxdigit
#undef tolower
#undef toupper
namespace std{using::isalnum;using::isalpha;using::iscntrl;using::isdigit;using::isgraph;using::islower;using::isprint;using::ispunct;using::isspace;using::isupper;using::isxdigit;using::tolower;using::toupper;}
#if __cplusplus>=201103L
#ifdef _GLIBCXX_USE_C99_CTYPE_TR1
#undef isblank
namespace std{using::isblank;}
#endif
#endif
#endif
#define maxn 100007
#define MAXN 200007
#define ll long long
#define ls pos<<1
#define rs pos<<1|1
using namespace std;int n,head[maxn],d[maxn],size[maxn],son[maxn],a[maxn],tag[MAXN];int p[maxn],id[maxn],top[maxn],num,cnt,lazy[MAXN],fa[maxn],maxx[MAXN];char s[10];int read(){char c=getchar();int num=0,f=1;for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())num=num*10+c-'0';return num*f;}struct node{int v,w,nxt;}e[maxn<<1];void ct(int u,int v,int w){e[++num].v=v;e[num].w=w;e[num].nxt=head[u];head[u]=num;}void pushup(int pos){maxx[pos]=max(maxx[ls],maxx[rs]);}void pushdown(int pos){if(tag[pos]>=0){lazy[ls]=lazy[rs]=0;maxx[ls]=maxx[rs]=tag[ls]=tag[rs]=tag[pos];tag[pos]=-1;}if(lazy[pos]){lazy[ls]+=lazy[pos];lazy[rs]+=lazy[pos];maxx[ls]+=lazy[pos];maxx[rs]+=lazy[pos];lazy[pos]=0;}}void build(int pos,int l,int r){tag[pos]=-1;if(l==r){maxx[pos]=a[l];return;}int mid=(l+r)>>1;build(ls,l,mid);build(rs,mid+1,r);maxx[pos]=max(maxx[ls],maxx[rs]);}void query1(int pos,int l,int r,int x,int y,int data){if(x>r||y<l)return;if(x<=l&&r<=y){lazy[pos]+=data;maxx[pos]+=data;return;}pushdown(pos);int mid=(l+r)>>1;if(x<=mid)query1(ls,l,mid,x,y,data);if(y>mid)query1(rs,mid+1,r,x,y,data);maxx[pos]=max(maxx[ls],maxx[rs]);}void query2(int pos,int l,int r,int x,int y,int data){if(x>r||y<l)return;if(x<=l&&r<=y){maxx[pos]=tag[pos]=data;lazy[pos]=0;return;}pushdown(pos);int mid=(l+r)>>1;query2(ls,l,mid,x,y,data),query2(rs,mid+1,r,x,y,data);maxx[pos]=max(maxx[ls],maxx[rs]);}int cmax(int pos,int l,int r,int x,int y){if(x<=l&&r<=y)return maxx[pos];int ans=0;int mid=(l+r)>>1;pushdown(pos);if(x<=mid)ans=max(ans,cmax(ls,l,mid,x,y));if(y>mid)ans=max(ans,cmax(rs,mid+1,r,x,y));return ans;}void dfs1(int u,int f){size[u]=1;for(int i=head[u];i;i=e[i].nxt){int v=e[i].v;if(v!=f){d[v]=d[u]+1;fa[v]=u;p[v]=e[i].w;dfs1(v,u);size[u]+=size[v];if(size[v]>size[son[u]])son[u]=v;}}}void dfs2(int u,int t){id[u]=++cnt;top[u]=t;a[cnt]=p[u];if(son[u])dfs2(son[u],t);for(int i=head[u];i;i=e[i].nxt){int v=e[i].v;if(v!=fa[u]&&v!=son[u])dfs2(v,v);}}void prequery1(int x,int y,int data){int fx=top[x],fy=top[y];while(fx!=fy){if(d[fx]<d[fy])swap(x,y),swap(fx,fy);query1(1,1,n,id[fx],id[x],data);x=fa[fx],fx=top[x];}if(id[x]>id[y])swap(x,y);query1(1,1,n,id[x]+1,id[y],data);}void prequery2(int x,int y,int data){int fx=top[x],fy=top[y];while(fx!=fy){if(d[fx]<d[fy])swap(x,y),swap(fx,fy);query2(1,1,n,id[fx],id[x],data);x=fa[fx],fx=top[x];}if(id[x]>id[y])swap(x,y);query2(1,1,n,id[x]+1,id[y],data);}int query(int x,int y){int ans=0,fx=top[x],fy=top[y];while(fx!=fy){if(d[fx]<d[fy])swap(x,y),swap(fx,fy);ans=max(ans,cmax(1,1,n,id[fx],id[x]));x=fa[fx],fx=top[x];}if(id[x]>id[y])swap(x,y);ans=max(ans,cmax(1,1,n,id[x]+1,id[y]));return ans;}int main(){n=read();for(int i=1,u,v,w;i<n;++i){u=read(),v=read(),w=read();ct(u,v,w);ct(v,u,w);}dfs1(1,0),dfs2(1,1);build(1,1,n);while(1){scanf("%s",s);if(s[0]=='S')break;int x=read(),y=read();if(s[1]=='h'){x=d[e[x*2-1].v]<d[e[x<<1].v]?e[x<<1].v:e[x*2-1].v;query2(1,1,n,id[x],id[x],y);}if(s[1]=='o'){int zrj=read();prequery2(x,y,zrj);}if(s[1]=='d'){int zrj=read();prequery1(x,y,zrj);}if(s[1]=='a')printf("%d\n",query(x,y));}return 0;}