/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#include <etk/types.hpp>
#include <algue/sha512.hpp>
#include <openssl/sha.h>

std::vector<uint8_t> algue::sha512::encode(const uint8_t* _data, int32_t _len) {
	std::vector<uint8_t> out;
	out.resize(SHA512_DIGEST_LENGTH);
	SHA512(_data, _len, &out[0]);
	return out;
}


