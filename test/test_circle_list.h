#include "../src/Task_2/circle_buffer_list.h"
#include <cassert>

namespace test_list {

    void TEST_LIST() {
        cycling_buffer_list<int, 3> buffer;
        assert(buffer.empty() == true);
        assert(buffer.size() == 3);
        buffer.push(1);
        buffer.push(2);
        buffer.push(3);
        assert(buffer.peek() == 1);
        assert(buffer.pop() == 1);
        assert(buffer.empty() == false);
        buffer.push(4);
        assert(buffer.peek() == 2);

        cycling_buffer_list<int, 3> buffer2(buffer);
        cycling_buffer_list<int, 3> buffer3(std::move(buffer2));
        assert(buffer2.empty() == true);
        assert(buffer3.peek() == 2);
    }
}
