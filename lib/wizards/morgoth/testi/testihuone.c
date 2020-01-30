#include "room.h"
 
short() { return "Banishment room"; }
 
long() {
  if(this_player()->query_wiz() > 1) {
    write(short()+"\nAvailable command:\n\tbanish\n\tunbanish\n\tlist\n\tinfo\n");
  }
}
 
init() {
  add_action("banish", "banish");
  add_action("unbanish", "unbanish");
  add_action("list", "list");
  add_action("info", "info");
}
 
list() {
  string str;
  ls("/banish/");
  return 1;
}
 
info(str) {
  if(!str) {
    write("Usage: info <player>\n");
    return 1;
  }
  if (file_size("/banish/"+str) != -1) {
    int aika;
    string tim,reason;
    tim=read_file("/banish/"+str,1);
    sscanf(tim,"time %d",aika);
    reason=read_file("/banish/"+str,2);
    write(capitalize(str)+" is banished until "+ctime(aika)+" because of "+
        reason+".\n");
    return 1;
  }
  write("No such a player in ban right now.\n");
  return 1;
}
 
unbanish(name) {
  object ob;
  if(this_player()->query_wiz() < 1) {
    return;
  }
  if(!name) {
    write("Usage: unbanish <player>\n");
    return 1;
  }
  ob = clone_object("obj/player.c");
  if (!ob->restore_player(name)) {
    write("No such a player.\n");
    destruct(ob);
    return 1;
  }
  if(!rm("/banish/"+name)) {
    write(ob->query_name()+" is not banished.\n");
  } else {
    write(ob->query_name()+" is no more banished.\n");
  }
  destruct(ob);
  return 1;  
}
 
banish(str) {
  object ob;
  int days,hours,online;
  string name,reason,aika;
  if(this_player()->query_wiz() < 1) {
    return;
  }
  if(!str) {
    write("Usage: banish <player> for <number> days because <reason>\n");
    return 1;
  }
  if(sscanf(str, "%s for %d days because %s", name, days, reason) == 3) {
    ob = find_player(name);
    if (!ob) {
        ob = clone_object("obj/player.c");
        if (!ob->restore_player(name)) {
            write("No such a player.\n");
            return 1;
        }
        online = 0;
    } else {
        online = 1;
    }
    rm("/banish/"+name);
    days = (3600*24*days+time());
    write(days+"\n");
    aika = "time "+days;
    write_file("/banish/"+name, aika+"\n");
    write_file("/banish/"+name, reason+" ("+this_player()->query_name()+")");
    ob->save_me(1);
    tell_object(ob, "You have been banished because: "+reason+".\n");
    write(ob->query_name()+" has been banished for "+days+" days because "+reason+".\n");
    destruct(ob);
    return 1;
  }
  banish();
  return 1;
}
