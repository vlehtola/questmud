#include "room.h"
#define BANISH_D "/wizards/cendor/banish/banish_d"

ONE_EXIT("/world/city/cs", "cs",
         "Banish room.",
"You are in the room where archwizards can handler their banishment\n"+
"stuffs. Available commands are : "+
" List,nbanish,sbanish,check,unbans,unbann\n",3)

void init() {
  ::init();
add_action("list", "list");
add_action("nbanish", "nbanish");
add_action("sbanish", "sbanish");
add_action("check", "check");
add_action("unbans","unbans");
add_action("unbann","unbann");
}

status list(string str) {
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
    if(!str) {
    notify_fail("Banish who?\n");
    return 0;
}
    write("Enter the amount of time [can only use one].\n");
    write("Examples:  3h == 3 hours\n" +
      "          5m == t minutes.\n" +
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

write("Enter reason for banishing " + capitalize(name) + " > ");
input_to("add_name_2", 0, time, name);
return 1;
}

status add_name_2(string reason, int time, string who) {
if(!reason) {
notify_fail("No reason given.\n");
return 0;
}

if(strlen(reason) > 32) {
notify_fail("Max 32 characters allowed in reason.\n");
return 0;
}

 BANISH_D -> add_banish_name(who, time, reason);
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

