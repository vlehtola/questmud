inherit "obj/monster";
static string *commands;
string owner;
status follow;
int dsoul,dlvl;

void initialize();

void reset(status arg) {
  string *chat_str;
  ::reset(arg);
  if(arg) { return; }
  initialize();
  owner = "yodin";
  commands = ({ "newowner" });
  follow = 1;
  chat_str = ({ "Dragon looks at YOU angrily.\n",});
  load_chat(1,chat_str);
  set_special(50);
  set_heart_beat(1);
}

void init() {
  add_action("cmd_newowner","newowner");
  add_action("cmd_dkill","dkill");
  add_action("cmd_dscore","dscore");
  add_action("cmd_ddrain","ddrain");
}

#include "init.h"
#include "heart.h"
#include "command.h"

string query_owner() {return owner;}

void add_exp(int i,string sh, int leveli) {
  if(leveli < ((int)query_level()/5)) return;
  dsoul++;
  find_player(owner)->add_exp(i,sh,leveli);
}

status dont_kill_hb() { return 1; }

int set_dlvl(int i) { return dlvl = i; }
string set_owner(string str) { owner = lower_case(str); }
int set_dsoul(int i) { return dsoul = i; }

status special() {
  object ob;
  int i;
  i = random(2)+1;
  say("Dragon shoots a HUGE fireball at "+capitalize(query_attack()->query_real_name())+"!\n");
  if(i == 5) {
    say(capitalize(query_attack()->query_real_name())+" shivers from the attack and looks stunned.\n");
    query_attack()->set_stunned(random(dlvl)+1);
  }
  query_attack()->hit_with_spell(dlvl*100);
  return 1;
}

status query_animal_ob() { return 1; }
status query_dragonists() { return 1; }

