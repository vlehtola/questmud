#include "room.h"
#define BANISH_D "/room/banish_d"
#define RECORD_D "/room/banrecord_d"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
    call_other(BANISH_D, "loadaa");
}

ONE_EXIT("/world/city/cs", "cs",
         "Banish room.",
"You are in the room where archwizards can handle their banishment\n"+
"business. Available commands are : "+
" rules,list,nbanish,sbanish,check,unbans,unbann,record\n",3)

void init() {
  ::init();
if(this_player() -> query_wiz() < 3) {
  write("You are not allowed to be here!\n");
  move_object(this_player(), "/world/city/cs");
}
add_action("list", "list");
add_action("rules", "rules");
add_action("nbanish", "nbanish");
add_action("sbanish", "sbanish");
add_action("check", "check");
add_action("unbans","unbans");
add_action("unbann","unbann");
add_action("show_record", "record");
}

show_record(string arg) {
  RECORD_D->list_record(arg);
  if(!arg)
    write("Try record <name> for details.\n");
  return 1;
}

rules(str) {
  if(!str) {
  write(
  "Mortals can be banished for 4 different causes:  (more info with rules [number])\n"+
  "1. Cheating for personal benefit\n"+
  "2. Harming other player(s)\n"+
  "3. Harming innocent player(s)\n"+
  "4. Harming the mud\n\n"+
  "Maximum banishment time that can be given to mortals by wiz rank:\n"+
  "Archs: 30d    Demi-Gods: 60d    Gods: not limited\n");
  return 1;
  }
  if(str == "1") {
    write(
"I) Cheating for personal benefit\n"+
" - robotting\n"+
" - abusing a bug to get anormal amounts of xp or money\n"+
" - cloning equipment due a bug\n"+
" - reporting the bug reduces the amount of banishment time\n"+
"Sanction: 0-7d + removal of illegaly achieved gain\n");
    return 1;
  } else if(str == "2") {
    write(
"II) Harming other player(s)\n"+
" - player killing without reason\n"+
" - continuous chasing\n"+
" - stating insulting arguments\n"+
"Sanction: 2-7d\n");
    return 1;
  } else if(str == "3") {
    write(
"III) Harming innocent player(s)\n"+
" - massacring\n"+
" - killing an obviously innocent player of lower level\n"+
" - killing players randomly\n"+
" - preventing other players to play normally\n"+
"Sanction: 3-14d\n");
    return 1;
  } else if(str == "4") {
    write(
"IV) Harming the mud\n"+
" - spamming the channels\n"+
" - trying to lag the mud\n"+
" - trying to hack to mud\n"+
" - trying to pingflood players or the mud\n"+
"Sanction: 7-30d\n");
  return 1;
  }
  write("Usage: rules [1-4]\n");
  return 1;
}

status list(string str) {
if(this_player() -> query_wiz() < 3) return 0;
  if(!str) {
    write("## Usage : List [names|sites]\n");
    return 1;
}

if(str == "names") {
  BANISH_D -> list_banished_names();
  return 1;
}

if(str == "sites") {
  BANISH_D -> list_banished_sites();
  return 1;
}

  write("## Usage : List [names|sites]\n");
  return 1;
}

status nbanish(string str) {
    string a;
    if(this_player() -> query_wiz() < 3) return 0;
    if(!str) {
    notify_fail("Banish who?\n");
    return 0;
}
    write("Enter the amount of time [can only use one].\n");
    write("Examples:  3h == 3 hours\n" +
      "          5m == 5 minutes.\n" +
      "          6d == 6 days.\n" );
    write("Enter banish time > ");
    input_to("add_name_1", 0, str);
    return 1;
}

status add_name_1(string str, string name) {
  int i, time;
  string piu;
  if(!str) {
    notify_fail("No time given.\n");
    return 0;
  }

  if(sscanf(str, "%d%s", i, piu)) {
        if(piu == "m")
            time = 60 * i;
        else if(piu == "h")
            time = i * (60 * 60);
        else if(piu == "d")
            time = i * (60 * 60 * 24);
        else
            time = 0;
  } else  time = 0;
  if(!time) {
    notify_fail("Invalid time.\n");
    return 0;
  }
  if(this_player()->query_wiz() == 3 && time > 60*60*24*30 ||
     this_player()->query_wiz() == 4 && time > 60*60*24*60) {
    notify_fail("No access.\n");
    return 0;
  }
  write("Enter reason (1-4) for banishing " + capitalize(name) + " > ");
  input_to("add_name_2", 0, time, name);
  return 1;
}

status add_name_2(string reason, int time, string who) {
  if(this_player()->query_wiz() != 5) {
    if(reason == "1") reason = "Cheating for personal benefit";
    else if(reason == "2") reason = "Harming other player";
    else if(reason == "3") reason = "Harming innocent player";
    else if(reason == "4") reason = "Harming the mud";
    else reason = 0;
  }

  if(!reason) {
    write("No reason given.\n");
    return 0;
  }

  if(strlen(reason) > 32) {
    write("Max 32 characters allowed in reason.\n");
    return 0;
  }
  BANISH_D -> add_banish_name(who, time, reason);
  write_file("/room/banish/"+lower_case(who),
      this_player()->query_name()+" banished me for "+time+" (reason: "+reason+")\n"); 

  return 1;
}


status sbanish(string str) {
    string a;
    if(this_player() -> query_wiz() < 4) return 0;
    if(!str) {
    notify_fail("Banish what site?\n");
    return 0;
}
    write("Enter the amount of time [can only use one].\n");
    write("Examples:  3h == 3 hours\n" +
      "          5m == t minutes.\n" +
      "          6d == 6 days.\n" );
    write("Enter banish time > ");
    input_to("add_site_1", 0, str);
    return 1;
}

status add_site_1(string str, string name) {
int i, time;
string piu;
  if(!str) {
    notify_fail("No time given.\n");
    return 0;
}

if(sscanf(str, "%d%s", i, piu)) {
        if(piu == "m")
            time = 60 * i;
        else if(piu == "h")
            time = i * (60 * 60);
        else if(piu == "d")
            time = i * (60 * 60 * 24);
        else
            time = 0;
    } else  time = 0;
if(!time) {
  notify_fail("Invalid time.\n");
  return 0;
}

write("Enter reason for banishing site " + capitalize(name) + " > ");
input_to("add_site_2", 0, time, name);
return 1;
}

status add_site_2(string reason, int time, string who) {
if(!reason) {
notify_fail("No reason given.\n");
return 0;
}

if(strlen(reason) > 32) {
notify_fail("Max 32 characters allowed in reason.\n");
return 0;
}

 BANISH_D -> add_banish_site(who, time, reason);
 return 1;
}


status check(string str) {
  string wh,ss;
  if(this_player() -> query_wiz() < 3) return 0;
  if(!str) {
    write("## Usage : Check [site|name] [what_site|what_name]\n");
    return 1;
}

if(sscanf(str, "%s %s",wh,ss) != 2) {
    write("## Usage : Check [site|name] [what_site|what_name]\n");
    return 1;
}

if(wh != "site" && wh != "name") {
    write("## Usage : Check [site|name] [what_site|what_name]\n");  
    return 1;
}

if(wh == "site") {
  BANISH_D -> info_site(ss);
  return 1;
}

if(wh == "name") {
  BANISH_D -> info_name(ss);
  return 1;
}
  write("## Usage : Info [site|name] [what_site|what_name]\n");  
  return 1;
}

status unbans(string str) {
  if(!str) {
    write("Unbanish what site?\n");
    return 1;
}
BANISH_D -> unbanish_site(str);
return 1;
}

status unbann(string str) {
  if(!str) {
    write("Unbanish what name?\n");
    return 1;
}
BANISH_D -> unbanish_name(str);
return 1;
}

