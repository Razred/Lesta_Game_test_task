#include "../src/Task_2/circle_buffer_array.h"
#include <cassert>

namespace test_array {

    void TEST_ARRAY() {
        cycling_buffer_array<int, 3> buffer;
        assert(buffer.size() == 3);
        assert(buffer.empty() == true);
        buffer.push(1);
        buffer.push(2);
        buffer.push(3);
        assert(buffer.peek() == 1);
        assert(buffer.pop() == 1);
        buffer.push(4);
        assert(buffer.peek() == 2);

        cycling_buffer_array<int, 3> buffer2 = buffer;
        cycling_buffer_array<int, 3> buffer3(std::move(buffer2));
        assert(buffer.peek() == 2);
    }
}