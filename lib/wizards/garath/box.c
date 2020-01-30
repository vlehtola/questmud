#include <ansi.h>
inherit "obj/armour";
int times;

void reset(status x) {
  if(x) return;
  set_name("box");
  set_alias("weird box");
  set_short("Weird box with hole");
  set_long("There is a sign on it which says: 'put head in box'\n");
  set_class(0);
  set_slot("head");
}

void init() {
  add_action("put_head","put");
  add_action("check","check");
}

status put_head(string str) {
  if(str != "head in box") return 0;
  say(this_player()->query_name()+" puts his head in the box.\n");
  write("You put your head in the box and notice it empty.\n");
  times++;
  return 1;
}

status check(string str) {
  if(str != "box") return 0;
  if(this_player()->query_wiz() < 2) return 0;
  write(times+" stupid's has put his/her head in the box.\n");
  return 1;
}

status drop() { return 1; }
status give() { return 0; }
int query_weight() { return 1000000; }

