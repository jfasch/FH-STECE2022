#include <parse-passwd.h>

#include <gtest/gtest.h>


TEST(passwd_line_suite, sunny_without_linefeed)
{
    User user = parse_passwd_line("jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash");

    ASSERT_EQ(user.name, "jfasch");
    ASSERT_EQ(user.passwd, "x");
    ASSERT_EQ(user.uid, 1000);
    ASSERT_EQ(user.gid, 1000);
    ASSERT_EQ(user.descr, "Joerg Faschingbauer");
    ASSERT_EQ(user.homedir, "/home/jfasch");
    ASSERT_EQ(user.shell, "/bin/bash");
}

TEST(passwd_line_suite, sunny_with_linefeed)
{
    User user = parse_passwd_line("jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash\n");

    ASSERT_EQ(user.name, "jfasch");
    ASSERT_EQ(user.passwd, "x");
    ASSERT_EQ(user.uid, 1000);
    ASSERT_EQ(user.gid, 1000);
    ASSERT_EQ(user.descr, "Joerg Faschingbauer");
    ASSERT_EQ(user.homedir, "/home/jfasch");
    ASSERT_EQ(user.shell, "/bin/bash");
}

TEST(passwd_line_suite, error_line_empty)
{
    try {
        parse_passwd_line("");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "");
    }
}

TEST(passwd_line_suite, error_passwd_missing)
{
    try {
        parse_passwd_line("jfasch:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:");
    }
}

TEST(passwd_line_suite, error_uid_missing)
{
    try {
        parse_passwd_line("jfasch:x:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:");
    }
}

TEST(passwd_line_suite, error_uid_not_numeric)
{
    try {
        parse_passwd_line("jfasch:x:not-numeric:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash");
        // -------------------------^^^^^^^^^^^
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:not-numeric:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash");
    }
}

TEST(passwd_line_suite, error_gid_missing)
{
    try {
        parse_passwd_line("jfasch:x:1000:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:1000:");
    }
}

TEST(passwd_line_suite, error_gid_not_numeric)
{
    try {
        parse_passwd_line("jfasch:x:1000:not-numeric:Joerg Faschingbauer:/home/jfasch:/bin/bash");
        // ------------------------------^^^^^^^^^^^
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:1000:not-numeric:Joerg Faschingbauer:/home/jfasch:/bin/bash");
    }
}

TEST(passwd_line_suite, error_descr_missing)
{
    try {
        parse_passwd_line("jfasch:x:1000:1000:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:1000:1000:");
    }
}

TEST(passwd_line_suite, error_homedir_missing)
{
    try {
        parse_passwd_line("jfasch:x:1000:1000:Joerg Faschingbauer:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:1000:1000:Joerg Faschingbauer:");
    }
}

TEST(passwd_line_suite, error_shell_missing)
{
    try {
        parse_passwd_line("jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:");
        FAIL();
    }
    catch (const PasswdError& e) {
        ASSERT_EQ(e.code, PasswdError::LINE_INVALID);
        ASSERT_EQ(e.msg, "jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:");
    }
}

