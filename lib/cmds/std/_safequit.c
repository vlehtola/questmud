#define MAX_ITEMS 20

cmd_safequit() {
    object ob;
    int i;
    ob = first_inventory(this_player());
    while(ob) {
        if (!ob->query_auto_load() && ob->short() && !ob->query_no_save()) {
            i += 1;
        }
        else if(ob->query_weapon()) {
          write("You can't quit safely with damaged weapon.\n");
          return 1;
          write("Damaged weapons are not saveable.. dropped: "+ob->short()+"\n");
          say(this_player()->query_name()+" leaves "+ob->short()+" behind.\n");
          move_object(ob, this_object());
        }
        if (i > MAX_ITEMS) {
            write("You have more than "+MAX_ITEMS+" items, cannot safe_quit.\n");
            return 1;
        }
        ob = next_inventory(ob);
    }
    this_player()->compute_safe_str();
    if(this_player()->quit() != -1) {
      write("Safe_quitting..\n");
    }
  write("done\n");
  return 1;
}

