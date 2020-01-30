#define SIMUL "/secure/simul_efun"

cmd_update(string str) {
    int i,num,no_load;
    object ob,stuff;
    string kapy,tmp;
    if (!str) {
        write("Usage: update [<file> | room | all | <object>] [no_load]\n");
        return 1;
    }
    if (sscanf(str, "%s no_load", str)) {
        no_load = 1;
    }
    if(str == "all") {
      ob = all_inventory(environment(this_player()));
      while(i<sizeof(ob)) {
        tmp = file_name(ob[i]);  
        if(sscanf(tmp, "%s#%d", tmp, num) == 2) {  
          write(tmp+"'s clone.\n");
        }
        if(ob[i] != this_player()) update_object(tmp);
        i += 1;
      }
      write("Done.\n");
      return 1;
    }

    /* single object handle */
    ob = present(str, environment(this_player()));
    if(!ob) ob = present(str, this_player());
    if(ob) {
      str = file_name(ob);
      if(sscanf(str, "%s#%d", str, num) == 2) {  
        write(str+"'s clone.\n");
      }
    }
    if(str == "room") {
      str = file_name(environment(this_player()));
    }
    str = (string)SIMUL->valid_read(str, this_player());
    if (!str) {
        write("Sorry, update access denied.\n");
        return 1;   
    }
    if (!no_load)
      call_other(str, "????", 0);
    if(file_size(str+".c") < 1) {
      write("No such file.\n");
      return 1;
    }
    ob = find_object(str); 
    if (!ob) {
        write("No such object.\n");
        return 1;
    }
    kapy = "/obj/update_dest";
    stuff = all_inventory(ob);
    while(stuff && i<sizeof(stuff)) {
        if(!stuff[i]->query_npc() && living(stuff[i])) {
          move_object(stuff[i],kapy);
        }
        i += 1;
    }
    destruct(ob);
    if (!no_load)
      call_other(str, "????", 0);
    i = 0;
    while(stuff && i<sizeof(stuff)) {
      if(stuff[i]) { move_object(stuff[i],find_object(str)); }
      i += 1;
    }
    if (!no_load) {
      write(str + " is updated and loaded.\n");
    } else {
      write(str + " is updated and not loaded.\n");
    }
    
    return 1;
}

