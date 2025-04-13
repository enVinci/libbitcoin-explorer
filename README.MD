For mode details see README.md

# Install Dependencies

## Ubuntu

`$ sudo apt install git wget autoconf automake cmake g++ clang pkg-config libtool-bin`

# Known Errors

## Error 1

<pre>********************** Prepairing to build secp256k1 **********************
configure.ac:41: warning: The macro `AC_PROG_CC_C89&apos; is obsolete.
configure.ac:41: You should run autoupdate.
./lib/autoconf/c.m4:1652: AC_PROG_CC_C89 is expanded from...
configure.ac:41: the top level
configure.ac:37: installing &apos;build-aux/compile&apos;
configure.ac:10: installing &apos;build-aux/config.guess&apos;
configure.ac:10: installing &apos;build-aux/config.sub&apos;
configure.ac:14: installing &apos;build-aux/install-sh&apos;
configure.ac:14: installing &apos;build-aux/missing&apos;
Makefile.am:3: error: Libtool library used but &apos;LIBTOOL&apos; is undefined
Makefile.am:3:   The usual way to define &apos;LIBTOOL&apos; is to add &apos;LT_INIT&apos;
Makefile.am:3:   to &apos;configure.ac&apos; and run &apos;aclocal&apos; and &apos;autoconf&apos; again.
Makefile.am:3:   If &apos;LT_INIT&apos; is in &apos;configure.ac&apos;, make sure
Makefile.am:3:   its definition is in aclocal&apos;s search path.
Makefile.am: installing &apos;build-aux/depcomp&apos;
parallel-tests: installing &apos;build-aux/test-driver&apos;
autoreconf: error: automake failed with exit status: 1</pre>

## Solution

`$  sudo apt install libtool-bin`

## Error 2

<pre><font color="#C01C28">Make Error at /usr/share/cmake-3.28/Modules/FindPackageHandleStandardArgs.cmake:230 (message):</font>
<font color="#C01C28">  Could NOT find Boost: missing: atomic chrono date_time filesystem iostreams</font>
<font color="#C01C28">  locale log_setup log program_options regex system thread</font>
<font color="#C01C28">  unit_test_framework (found</font>
<font color="#C01C28">  /usr/local/bx/lib/cmake/Boost-1.73.0/BoostConfig.cmake (found suitable</font>
<font color="#C01C28">  version &quot;1.73.0&quot;, minimum required is &quot;1.73.0&quot;))</font>
<font color="#C01C28">Call Stack (most recent call first):</font>
<font color="#C01C28">  /usr/share/cmake-3.28/Modules/FindPackageHandleStandardArgs.cmake:243 (_FPHSA_FAILURE_MESSAGE)</font>
<font color="#C01C28">  /usr/share/cmake-3.28/Modules/FindPackageHandleStandardArgs.cmake:585 (_FPHSA_HANDLE_FAILURE_CONFIG_MODE)</font>
<font color="#C01C28">  /usr/share/cmake-3.28/Modules/FindBoost.cmake:626 (find_package_handle_standard_args)</font>
<font color="#C01C28">  CMakeLists.txt:183 (find_package)</font>
</pre>

### Cause

Empty file: `/usr/local/bx/lib/cmake/Boost-1.73.0/BoostConfig.cmake`

### Solution

`$ sudo rm -r /usr/local/bx/`

## Error 3

In file included from /usr/include/c++/13/ext/alloc_traits.h:34,
                 from /usr/include/c++/13/bits/stl_tree.h:67,
                 from /usr/include/c++/13/map:62,
                 from src/metadata.hpp:33,
                 from src/msg.hpp:40,
                 from src/curve_server.cpp:35:
/usr/include/c++/13/bits/alloc_traits.h: In instantiation of ‘struct std::__allocator_traits_base::__rebind<zmq::secure_allocator_t<unsigned char>, unsigned char, void>’:
/usr/include/c++/13/bits/alloc_traits.h:94:11:   required by substitution of ‘template<class _Alloc, class _Up> using std::__alloc_rebind = typename std::__allocator_traits_base::__rebind<_Alloc, _Up>::type [with _Alloc = zmq::secure_allocator_t<unsigned char>; _Up = unsigned char]’
/usr/include/c++/13/bits/alloc_traits.h:228:8:   required by substitution of ‘template<class _Alloc> template<class _Tp> using std::allocator_traits< <template-parameter-1-1> >::rebind_alloc = std::__alloc_rebind<_Alloc, _Tp> [with _Tp = unsigned char; _Alloc = zmq::secure_allocator_t<unsigned char>]’
/usr/include/c++/13/ext/alloc_traits.h:126:65:   required from ‘struct __gnu_cxx::__alloc_traits<zmq::secure_allocator_t<unsigned char>, unsigned char>::rebind<unsigned char>’
/usr/include/c++/13/bits/stl_vector.h:88:21:   required from ‘struct std::_Vector_base<unsigned char, zmq::secure_allocator_t<unsigned char> >’
/usr/include/c++/13/bits/stl_vector.h:428:11:   required from ‘class std::vector<unsigned char, zmq::secure_allocator_t<unsigned char> >’
src/curve_server.cpp:184:72:   required from here
/usr/include/c++/13/bits/alloc_traits.h:70:31: error: static assertion failed: allocator_traits<A>::rebind_alloc<A::value_type> must be A
   70 |                         _Tp>::value,
      |                               ^~~~~
/usr/include/c++/13/bits/alloc_traits.h:70:31: note: ‘std::integral_constant<bool, false>::value’ evaluates to false
  CXX      src/libzmq_la-devpoll.lo
make[1]: *** [Makefile:5409: src/libzmq_la-curve_server.lo] Error 1
make[1]: *** Waiting for unfinished jobs....
In file included from /usr/include/c++/13/ext/alloc_traits.h:34,
                 from /usr/include/c++/13/bits/stl_tree.h:67,
                 from /usr/include/c++/13/map:62,
                 from src/metadata.hpp:33,
                 from src/msg.hpp:40,
                 from src/curve_client.cpp:35:
/usr/include/c++/13/bits/alloc_traits.h: In instantiation of ‘struct std::__allocator_traits_base::__rebind<zmq::secure_allocator_t<unsigned char>, unsigned char, void>’:
/usr/include/c++/13/bits/alloc_traits.h:94:11:   required by substitution of ‘template<class _Alloc, class _Up> using std::__alloc_rebind = typename std::__allocator_traits_base::__rebind<_Alloc, _Up>::type [with _Alloc = zmq::secure_allocator_t<unsigned char>; _Up = unsigned char]’
/usr/include/c++/13/bits/alloc_traits.h:228:8:   required by substitution of ‘template<class _Alloc> template<class _Tp> using std::allocator_traits< <template-parameter-1-1> >::rebind_alloc = std::__alloc_rebind<_Alloc, _Tp> [with _Tp = unsigned char; _Alloc = zmq::secure_allocator_t<unsigned char>]’
/usr/include/c++/13/ext/alloc_traits.h:126:65:   required from ‘struct __gnu_cxx::__alloc_traits<zmq::secure_allocator_t<unsigned char>, unsigned char>::rebind<unsigned char>’
/usr/include/c++/13/bits/stl_vector.h:88:21:   required from ‘struct std::_Vector_base<unsigned char, zmq::secure_allocator_t<unsigned char> >’
/usr/include/c++/13/bits/stl_vector.h:428:11:   required from ‘class std::vector<unsigned char, zmq::secure_allocator_t<unsigned char> >’
src/curve_client_tools.hpp:64:76:   required from here
/usr/include/c++/13/bits/alloc_traits.h:70:31: error: static assertion failed: allocator_traits<A>::rebind_alloc<A::value_type> must be A
   70 |                         _Tp>::value,
      |                               ^~~~~
/usr/include/c++/13/bits/alloc_traits.h:70:31: note: ‘std::integral_constant<bool, false>::value’ evaluates to false

### Solution

Use older g++ compiler

`$ sudo apt install g++-11`

`$ sudo CXX=/usr/bin/g++-11 ./install-cmake.sh --with-icu --build-icu --build-boost --build-zmq --disable-shared --prefix=/usr/local/bx/`

