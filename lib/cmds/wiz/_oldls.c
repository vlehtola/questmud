#define SIMUL "/secure/simul_efun"

cmd_oldls(string path) { 
    string ls_path;
    if (!path) 
        path = "/" + this_player()->query_current_path();
    if (path != "/") 
        path = path + "/.";
    /* ask gently so no error if no access */
    path = SIMUL->valid_read(path, this_player());
    if (!path) {
        write("Sorry, browse access denied.\n");
        return 1; 
    } 
    else ls(path);
    return 1; 
}   

