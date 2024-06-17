#include <parse-passwd.h>

#include <gtest/gtest.h>


// how to create an error
TEST(passwd_error_suite, object_construction_and_member_access)
{
    PasswdError error(/*code*/PasswdError::LINE_INVALID, /*msg*/"howdy");

    PasswdError::Code code = error.code;
    std::string msg = error.msg;

    ASSERT_EQ(code, PasswdError::LINE_INVALID);
    ASSERT_EQ(msg, "howdy");
}

// how to throw an error
static User parse_passwd_line__fake(std::string line)
{
    User u;

    // lets say we see an error during parsing the line
    if (false /*error :-)*/) {
        throw PasswdError(PasswdError::LINE_INVALID, "howdy");
    }

    return u;   // never reached. in this fake-function, we only
                // demonstrate how to cause an error.
}

// how to call code that might throw an error of type PasswdError
TEST(passwd_error_suite, throwing_and_catching)
{
    try {
        parse_passwd_line__fake("some:line:with:an:error");
    }
    catch (const PasswdError& error) {           // <--- catch-block entered if a PasswdError object is thrown
        PasswdError::Code code = error.code;
        std::string msg = error.msg;

        ASSERT_EQ(code, PasswdError::LINE_INVALID);
        ASSERT_EQ(msg, "howdy");
    }
}
