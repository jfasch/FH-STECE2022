#include "fixture-tmpdir.h"

tmpdir_fixture::tmpdir_fixture()
{
    auto tmpdir = std::filesystem::temp_directory_path();
    std::string tmpdir_template = tmpdir / "jfasch-suite-XXXXXX";
    char* tmpdir_template_c = new char[tmpdir_template.size()+1];
    strcpy(tmpdir_template_c, tmpdir_template.c_str());

    char* retname = mkdtemp(tmpdir_template_c);
    if (retname == NULL) {
        delete[] tmpdir_template_c;
        throw std::runtime_error(strerror(errno));
    }

    dirname = retname;
    delete[] tmpdir_template_c;
}

tmpdir_fixture::~tmpdir_fixture()
{
    std::filesystem::remove_all(dirname);
}
