/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <etk/types.hpp>

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
			std::vector<uint8_t> finalize();
		protected:
			void transform(const uint8_t* _data, uint32_t _blockNb);
			uint32_t m_totLen;
			uint32_t m_len;
			std::vector<uint8_t> m_block;
			uint64_t m_h[8];
	};
	namespace sha512 {
		std::vector<uint8_t> encode(const uint8_t* _data, int32_t _len);
		inline std::vector<uint8_t> encode(const std::vector<uint8_t>& _data) {
			return algue::sha512::encode(&_data[0], _data.size());
		}
		inline std::vector<uint8_t> encode(const std::string& _data) {
			return algue::sha512::encode(reinterpret_cast<const uint8_t*>(&_data[0]), _data.size());
		}
		std::vector<uint8_t> encodeFromFile(const std::string& _filename);
	}
	std::string stringConvert(std::vector<uint8_t> _data);
}
