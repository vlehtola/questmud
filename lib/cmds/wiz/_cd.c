cmd_cd(string str) {
  int i;
  string old_path, current_path;
  current_path = this_player()->query_current_path();
    old_path = current_path;
    if (str == "..") {
        if (current_path == "")
            return 0;
        i = strlen(current_path) - 1;
        while(i > 0 && current_path[i] != '/')
            i -= 1;
        if (i == 0) 
            current_path = "";
        else
            current_path = extract(current_path, 0, i-1);
    } else if (!str)      
        current_path = "wizards/" + this_player()->query_real_name();
    else if (str == "/")
        current_path = "";
    else if (str[0] != '/') {
        if (current_path == "")
            current_path = str;
        else
            current_path += "/" + str;
    } else { 
        current_path = extract(str, 1);
    } 
    if(file_size("/"+current_path) != -2) {
        write("No such a directory.\n");
        current_path = old_path;
        return 1; 
    }
    write("/" + current_path +"\n"); 
  this_player()->set_path(current_path);
  return 1; 
} 
             

