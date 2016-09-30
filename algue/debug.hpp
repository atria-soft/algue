/** @file
 * @author Edouard DUPIN
 * @copyright 2011, Edouard DUPIN, all right reserved
 * @license APACHE v2.0 (see license file)
 */
#pragma once

#include <elog/log.hpp>

namespace algue {
	int32_t getLogId();
};
#define ALGUE_BASE(info,data)  ELOG_BASE(algue::getLogId(),info,data)

#define ALGUE_CRITICAL(data)      ALGUE_BASE(1, data)
#define ALGUE_ERROR(data)         ALGUE_BASE(2, data)
#define ALGUE_WARNING(data)       ALGUE_BASE(3, data)
#ifdef DEBUG
	#define ALGUE_INFO(data)          ALGUE_BASE(4, data)
	#define ALGUE_DEBUG(data)         ALGUE_BASE(5, data)
	#define ALGUE_VERBOSE(data)       ALGUE_BASE(6, data)
	#define ALGUE_TODO(data)          ALGUE_BASE(4, "TODO : " << data)
#else
	#define ALGUE_INFO(data)          do { } while(false)
	#define ALGUE_DEBUG(data)         do { } while(false)
	#define ALGUE_VERBOSE(data)       do { } while(false)
	#define ALGUE_TODO(data)          do { } while(false)
#endif

#define ALGUE_ASSERT(cond,data) \
	do { \
		if (!(cond)) { \
			JSON_CRITICAL(data); \
			assert(!#cond); \
		} \
	} while (0)

