/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>

/**
 * @brief Basic Algue library namespace
 */
namespace algue {
	namespace md5 {
		etk::Vector<uint8_t> encode(const uint8_t* _data, int32_t _len);
		inline etk::Vector<uint8_t> encode(const etk::Vector<uint8_t>& _data) {
			return algue::md5::encode(&_data[0], _data.size());
		}
		inline etk::Vector<uint8_t> encode(const etk::String& _data) {
			return algue::md5::encode(reinterpret_cast<const uint8_t*>(&_data[0]), _data.size());
		}
	}
}
