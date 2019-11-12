#pragma once
#include <string>
#include <vector>
namespace NameDecoration
{	
	enum type_kind
	{
		basic_type,
		classif_type,
		array_type,
	};
	class CompilerContext
	{
	public:
		type_kind current_type_kind;
		std::string current_basic_type;
		std::string current_array_type;
		std::string current_classif_type;
		std::string current_method_full_name;
		std::vector<std::string> current_classif_types;
		std::vector<std::string> current_method_full_names;
		std::string current_type;
		CompilerContext();
		virtual ~CompilerContext();	
	};
}