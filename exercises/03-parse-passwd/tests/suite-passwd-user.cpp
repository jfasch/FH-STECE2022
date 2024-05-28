#include <parse-passwd.h>

#include <gtest/gtest.h>


// how to create a User object
TEST(passwd_user_suite, object_construction_and_member_access)
{
    User user;    // <--- calls default constructor

    // all default-initialized (even the numbers)
    ASSERT_EQ(user.name, "");
    ASSERT_EQ(user.passwd, "");
    ASSERT_EQ(user.uid, -1);
    ASSERT_EQ(user.gid, -1);
    ASSERT_EQ(user.descr, "");
    ASSERT_EQ(user.homedir, "");
    ASSERT_EQ(user.shell, "");
}
