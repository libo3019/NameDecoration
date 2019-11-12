#pragma once
#include <vector>
#include <string>
#include <stdarg.h>

namespace NameDecoration {
	enum DataType
	{
		NULL_TYPE = 0,
		BYTE_TYPE,
		CHAR_TYPE,
		SHORT_TYPE,
		INT_TYPE,
		BOOL_TYPE,
		LONG_TYPE,
		FLOAT_TYPE,
		DOUBLE_TYPE,
		STRING_TYPE,
		PRIMARY_TYPE,
		COMPLEX_TYPE,
		CLASS_OR_INTERFACE_TYPE,
		CLASS_TYPE,
		INTERFACE_TYPE,
		ARRAY_TYPE,
		GENERIC_TYPE, //32bit system: 4 bytes address, 64bit system: 8 bytes address
		AUTO_TYPE,
		VOID_TYPE,
		UNKNOWN_TYPE,

	};
	enum NodeType
	{
		classif_decoration_name_without_typelist_product_node,
		classif_decoration_name_with_typelist_product_node,
		type_list_type_product_node,
		array_type_product_node,
		basic_type_product_node,
		class_decoration_name_product_node,
		method_decoration_name_product_node,
		type_basic_type_product_node,
		type_classif_decoration_name_product_node,
		type_array_type_product_node,
		class_or_method_decoration_name_class_product_node,
		class_or_method_decoration_name_method_product_node,
		class_or_method_decoration_name_list_product_node,
		compile_unit_product_node,
	};
}