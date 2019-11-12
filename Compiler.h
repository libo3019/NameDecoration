#ifndef __Compiler_h__
#define __Compiler_h__

#include <string>
#include <cstddef>
#include <istream>
#include "DLL.h"
#include "common_enum.h"
#include <map>
#include <fstream>
#include <istream>
#include <ostream>

#define DEFAULT_HEAP_SIZE 1024*1024*300

#ifdef WIN32
#define PATH_SEPARATOR '\\'
#else
#define PATH_SEPARATOR '/'
#endif

namespace NameDecoration {
	class parser_node;
	class NameDecorationParser;
	class NameDecorationScanner;	

	class CompilerContext;
	
	enum DLL_EXPORT_IMPORT name_type
	{
		CLASS_NAME_TYPE,
		METHOD_NAME_TYPE,
	};

	class DLL_EXPORT_IMPORT DecorationCompiler 
	{
	public:
		parser_node * syntax_tree;
		name_type a_name_type;
	public:
class DLL_EXPORT_IMPORT Builder {
		private:
			std::istream* in;
			std::ostream* out;
			std::ostream* deb;
			int heapSize = DEFAULT_HEAP_SIZE;

		public:
			Builder();

			DecorationCompiler::Builder input(std::istream& is);

			DecorationCompiler::Builder input(std::string filename);

			DecorationCompiler::Builder output(std::ostream& os);

			DecorationCompiler::Builder output(std::string filename);

			DecorationCompiler::Builder debug(std::ostream& os);

			DecorationCompiler::Builder debug(std::string filename);

			DecorationCompiler::Builder heap(int heapSize);

			DecorationCompiler build();

		};
		int parse(); //successful: 0, otherwise: failed

		int walk1();

		virtual ~DecorationCompiler();

	private:
		DecorationCompiler(std::istream* in,
			   std::ostream* out,
			   std::ostream* deb,
			   int heapSize);
		std::istream* in;
		std::ostream* out;
		std::ostream* deb;
		int heapSize;

		NameDecoration::NameDecorationParser* parser = nullptr;
		NameDecoration::NameDecorationScanner* scanner = nullptr;
	public:
		CompilerContext* ctx;
		
	public:		
		static void error(const char *fmt, ...);
		
		static void FreeAllNodes();
	};

} /* end namespace NameDecoration */

#endif /* END _compiler_h__ */
