#define LEADER_D "/daemons/leader_d"
#include <ansi.h>
int souls;

id(str) {
return str == "pendant" || str == "warlock_pendant";
}

short() { return "A bloody pendant of souls"; }

long() {
string str;
str =   "The pendant is made from somekind of black opal. It is covered\n"+
        "with blood and moss. Something little reddish is moving inside\n"+
        "the pendant. You can use it drain corpses and chat in the warlock\n"+
        "channel. The following commands are available:\n"+
        "warlock <something> | drain | souls";
write(str+"\n");
}

init() {
  add_action("drain_soul","drain");
  add_action("warlock", "warlock");
  add_action("souls", "souls");
}
query_souls() { return souls; }

set_souls(int i) { souls=i; }

reduce_souls(int i) { souls-=i; if((souls<0) || (souls>2000000)) souls=0;}

drop() { return 1; }

get() { return 0; }

souls() {
        write("You have collected in the pendant total of "+souls+" souls.\n");
        return 1;
}

drain_soul() {
        object ob;
        int i;
        int tmp;
        ob = present("corpse", environment(this_player()));
        if(ob && ob->query_corpse()) {
    write("You place to pendant above the corpse and collect the soul.\n");
    say(this_player()->query_name()+" places pendant above the corpse and drain something.\n");
        tmp = ob->query_level()*this_player()->query_skills("knowledge of chaos")/20+this_player()->query_skills("soul channeling");
        i = ob->query_level()+tmp;
        souls += i;
        ob->autoextract_obj(ob);
        destruct(ob);
        return 1;
}
write("There aren't any corpses here.\n");
return 1;
}

status warlock(string str) {
  int i;
  object *us;
  if(!str) { write("Usage: warlock (msg)\n"); return 1; }
  us = users();
  if(str == "last") { tail("/log/WARLOCK"); return 1; }
  if(this_player()->query_wiz()) {
  str = this_player()->query_name()+" "+BOLD+"<warlock>"+OFF+": "+str+"\n";
  } else if(LEADER_D->test_leader(this_player()->query_name(),this_player()->query_race())) {
  str = this_player()->query_name()+" "+BOLD+"{warlock}"+OFF+": "+str+"\n";
  } else if(this_player()->query_rebirth()) {
  str = this_player()->query_name()+" "+BOLD+"(warlock)"+OFF+": "+str+"\n";
  } else {
  str = this_player()->query_name()+" "+BOLD+"[warlock]"+OFF+": "+str+"\n";
  }
  for(i=0;i<sizeof(us);i++)
  if(present("warlock_pendant",us[i]))
  tell_object(us[i],str);
  write_file("/log/WARLOCK","["+ctime()[11..15]+"] "+str);
  return 1;
}

string query_auto_load() { return "/guilds/warlock/obj/pendant.c:"; }
