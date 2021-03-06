#ifndef ARK_UTILITIES_SLOTS_H
#define ARK_UTILITIES_SLOTS_H

#include <cstdint>
#include <chrono>

namespace ARK {
namespace Utilities {

class slots {
public:
	static uint64_t get_epoch_time() {
		return get_epoch_time(now());
	}
	static uint64_t get_epoch_time(uint64_t time);
	static uint64_t begin_epoch_time();
	static uint64_t get_time() {
		return get_time(now());
	}
	static uint64_t get_time(uint64_t time);
	static uint64_t get_real_time() {
		return get_real_time(get_time());
	}
	static uint64_t get_real_time(uint64_t epoch_time);
	static uint64_t get_slot_number() {
		return get_slot_number(get_time());
	}
	static uint64_t get_slot_number(uint64_t epoch_time);
	static uint64_t get_slot_time(uint64_t slot);
	static uint64_t get_next_slot();
	static uint64_t get_last_slot(uint64_t next_slot);

	static bool is_forging_allowed() {
		return is_forging_allowed(get_time());
	}
	static bool is_forging_allowed(uint64_t epoch_time);

private:
	static uint64_t now() {
		return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	}
};

}
}
#endif
