#include <boost/filesystem.hpp>
using namespace boost::filesystem;

extern "C" {

int dir_delete(char * dir) {
    if(!dir){
        return -1;
    }

    path p(dir);

    if (exists(p) && is_directory(p))
        remove_all(p);
    else 
        return -1;

    return 0;
}

int ensure_dir_exists(char * dir) {
    if(!dir) {
        return -1;
    }

    path p(dir);

    if(exists(p)) {
        // exists
        return 0;
    } else {
        // doesn't exist
        return -1;
    }
}

}