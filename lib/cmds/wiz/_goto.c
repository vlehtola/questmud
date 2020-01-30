#define SIMUL "/secure/simul_efun"

cmd_goto(string dest) {
    object ob;
    int i, x, y;
    string tmp1;
    string mapfile;
    if (!dest) {
        write("Goto where ?\n");
        return 1;
    }
    ob = find_player(dest);
    if(ob) {
      this_player()->move_player("X", environment(ob));
      return 1;
    }
    if(sscanf(dest, "%d %d", x, y) == 2) {
      mapfile = environment(this_player())->query_mainfile();
      if(!mapfile) mapfile = "/room/out/outmap";
      this_player()->move_player("virtual "+mapfile+" "+x+" "+y);
      return 1;
    }
    if (sscanf(dest, "%s.c", tmp1) != 1) {
        dest += ".c";
    }
    dest = (string)SIMUL->valid_read(dest, this_player());
    if (!dest || file_size(dest) <= 0) {
        write("Invalid monster name or file name: " + dest + "\n");
        return 1;
    }
    this_player()->move_player("X#" + dest);
    return 1;
}   

