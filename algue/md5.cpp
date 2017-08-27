/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */
#include <etk/types.hpp>
#include <algue/md5.hpp>
#include <openssl/md5.h>

etk::Vector<uint8_t> algue::md5::encode(const uint8_t* _data, int32_t _len) {
	etk::Vector<uint8_t> out;
	out.resize(MD5_DIGEST_LENGTH);
	MD5(_data, _len, &out[0]);
	return out;
}


