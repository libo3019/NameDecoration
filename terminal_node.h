#pragma once
#include <vector>
#include <string>
#include "parser_tree.h"
#include "common_enum.h"
namespace NameDecoration {
	class DecorationCompiler;
	class terminal_node : public parser_node
	{
	public:
		DataType type_;
		struct
		{
			uint8_t byte_value_;
			int16_t short_value_;
			int32_t int_value_;
			bool bool_value_;
			long long long_value_;
			float float_value_;
			double double_value_;
			std::string string_value_;
			void *ref_value_;
		};

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, uint8_t byte_value)
			:parser_node(DecorationCompiler, lineno)
			, byte_value_(byte_value)
			, type_(BYTE_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, int16_t short_value)
			:parser_node(DecorationCompiler, lineno) 
			, short_value_(short_value)
			, type_(SHORT_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, int32_t int_value)
			:parser_node(DecorationCompiler, lineno) 
			, int_value_(int_value)
			, type_(INT_TYPE)
		{
		}
		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, bool bool_value)
			:parser_node(DecorationCompiler, lineno) 
			, bool_value_(bool_value)
			, type_(BOOL_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, long long long_value)
			:parser_node(DecorationCompiler, lineno)
			, long_value_(long_value)
			, type_(LONG_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, float float_value)
			:parser_node(DecorationCompiler, lineno)
			, float_value_(float_value)
			, type_(FLOAT_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, double double_value)
			:parser_node(DecorationCompiler, lineno)
			, double_value_(double_value)
			, type_(DOUBLE_TYPE)
		{
		}

		terminal_node(DecorationCompiler *DecorationCompiler, int lineno, std::string string_value)
			:parser_node(DecorationCompiler, lineno)
			, string_value_(string_value)
			, type_(STRING_TYPE)
		{
		}

		terminal_node& operator = (uint8_t byte_value)
		{
			byte_value_ = byte_value;
			type_ = BYTE_TYPE;
			return *this;
		}

		terminal_node& operator = (int16_t short_value)
		{
			short_value_ = short_value;
			type_ = SHORT_TYPE;
			return *this;

		}

		terminal_node& operator = (int32_t int_value)
		{
			int_value_ = int_value_;
			type_ = INT_TYPE;
			return *this;
		}
		terminal_node& operator = (bool bool_value)
		{
			bool_value_ = bool_value;
			type_ = BOOL_TYPE;
			return *this;
		}

		terminal_node& operator = (long long long_value)
		{
			long_value_ = long_value;
			type_ = LONG_TYPE;
			return *this;
		}

		terminal_node& operator = (float float_value)
		{
			float_value_ = float_value;
			type_ = FLOAT_TYPE;
			return *this;

		}

		terminal_node& operator = (double double_value)
		{
			double_value_ = double_value;
			type_ = DOUBLE_TYPE;
			return *this;
		}

		terminal_node& operator = (std::string string_value)
		{
			new(&string_value_) std::string(); //reconstruct the string because of bad memory caused by other union members.
			string_value_ = string_value;
			type_ = STRING_TYPE;
			return *this;

		}
		
		virtual void walk1() {}

		virtual ~terminal_node() {}
	};
}