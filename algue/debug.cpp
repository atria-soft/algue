/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license MPL v2.0 (see license file)
 */

#include <algue/debug.hpp>

int32_t algue::getLogId() {
	static int32_t g_val = elog::registerInstance("algue");
	return g_val;
}

