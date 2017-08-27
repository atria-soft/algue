/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>

namespace algue {
	namespace base64 {
		etk::String encode(const uint8_t* _data, int32_t _len);
		inline etk::String encode(const etk::Vector<uint8_t>& _data) {
			return algue::base64::encode(&_data[0], _data.size());
		}
		inline etk::String encode(const etk::String& _data) {
			return algue::base64::encode(reinterpret_cast<const uint8_t*>(&_data[0]), _data.size());
		}
		etk::Vector<uint8_t> decode(const etk::String& _data);
	}
}
