#ifndef __name_scanner_hpp__
#define __name_scanner_hpp__

#if ! defined(yyFlexLexerOnce)
#include "FlexLexer.h"
#endif

#include "name.grammar.hh"
#include "location.hh"

namespace NameDecoration {

class NameDecorationScanner : public yyFlexLexer {
public:

	explicit NameDecorationScanner(std::istream *in) : yyFlexLexer(in) {
	};

	~NameDecorationScanner() override = default;

	//get rid of override virtual function warning
	using FlexLexer::yylex;

	virtual int yylex(NameDecoration::NameDecorationParser::semantic_type *const lval, NameDecoration::NameDecorationParser::location_type *location);
	// YY_DECL defined in scanner.ll
	// Method body created by flex in lexer.yy.cc

private:
	NameDecoration::NameDecorationParser::semantic_type *yylval = nullptr;
};

}

#endif /* END __name_scanner_hpp__ */
