/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>
#include <etk/Vector.hpp>
#include <etk/String.hpp>

namespace algue {
	class Sha512 {
		public:
			Sha512();
			/**
			 * @brief Add data to the sha512 calculation
			 * @param[in] _data Pointer on the data
			 * @param[in] _len Lenght of the data to add
			 */
			void update(const uint8_t* _data, uint32_t _len);
			/**
			 * @brief get digest value
			 * @return the digest sha512 value
			 */
			etk::Vector<uint8_t> finalize();
		protected:
			void transform(const uint8_t* _data, uint32_t _blockNb);
			uint32_t m_totLen;
			uint32_t m_len;
			etk::Vector<uint8_t> m_block;
			uint64_t m_h[8];
	};
	namespace sha512 {
		etk::Vector<uint8_t> encode(const uint8_t* _data, int32_t _len);
		inline etk::Vector<uint8_t> encode(const etk::Vector<uint8_t>& _data) {
			return algue::sha512::encode(&_data[0], _data.size());
		}
		inline etk::Vector<uint8_t> encode(const etk::String& _data) {
			return algue::sha512::encode(reinterpret_cast<const uint8_t*>(&_data[0]), _data.size());
		}
		etk::Vector<uint8_t> encodeFromFile(const etk::String& _filename);
	}
	etk::String stringConvert(etk::Vector<uint8_t> _data);
}
