#include "fixture-tmpdir.h"

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

static void remove_directory_recursive(const std::string& dirname)
{
    DIR* dir = opendir(dirname.c_str());
    if (dir == nullptr) {
        std::cerr << "Cannot open directory " << dirname << '\n';
        perror("opendir");
        return;
    }

    for (;;) {
        dirent* entry = readdir(dir);
        switch (entry->d_type) {
            case DT_REG: {
                int error = unlink(entry->d_name);
                if (error)
                    perror("unlink");
                break;
            }
            case DT_DIR:
                remove_directory_recursive(entry->d_name);
                break;
            default:
                std::cerr << "Don't know how to remove entry " << entry->d_name << " of type " << entry->d_type << '\n';
                break;
        }
    }

    int error = closedir(dir);
    if (error)
        perror("closedir");
}


tmpdir_fixture::tmpdir_fixture()
{
    std::string tmpdir;
    const char* tmpdir_c = getenv("TMPDIR");
    if (tmpdir_c == nullptr)
        tmpdir = "/tmp";
    else
        tmpdir = tmpdir_c;

    std::string tmpdir_template = tmpdir + "/jfasch-suite-XXXXXX";
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
    remove_directory_recursive(dirname.c_str());
}
