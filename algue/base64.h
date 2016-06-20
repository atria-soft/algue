/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <etk/types.h>

namespace algue {
	namespace base64 {
		std::string encode(const uint8_t* _data, int32_t _len);
		inline std::string encode(const std::vector<uint8_t>& _data) {
			return algue::base64::encode(&_data[0], _data.size());
		}
		inline std::string encode(const std::string& _data) {
			return algue::base64::encode(reinterpret_cast<const uint8_t*>(&_data[0]), _data.size());
		}
		std::vector<uint8_t> decode(const std::string& _data);
	}
}
