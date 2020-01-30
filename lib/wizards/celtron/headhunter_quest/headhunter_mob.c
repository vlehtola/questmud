inherit "/obj/monster";

#define SACK "/wizards/celtron/headhunter_quest/sack_for_the_head"
#define MONSTER_D "/daemons/monster_track_d"

string player_list;

reset(int arg) {
  ::reset(arg);
  if(arg) return;
  player_list = "blah,";
}

start() {
  string *chat_str, *a_chat_str;

  set_level(30);
  set_hp(10000000);
  set_name("assassin");
  set_alias("headhunter");
  set_short("A hooded assassin called 'Headhunter', wearing a dark cloak");
  set_long("A dark figure standing in a shadowy corner. He doesn't look friendly at all,\n"+
	"wearing but colors of black and dim grey. He makes a hollow and quiet sound what you\n"+
          "guess might be him breathing. His face is not visible under his dark hood.\n");
  set_al(-200);  
  set_undead(1);

  if (!chat_str) {
        chat_str = allocate(3);
        chat_str[0] =
	"Headhunter's chuckles with his hollow voice: 'Har har! We shall kill them living!'\n";
        chat_str[1] =
	"Headhunter grins evilly and whispers: 'Interested in some work?'\n";
        chat_str[2] =
	"Headhunter says: 'Please tell me, if you want an easy task for which you will be rewarded.'\n";

    }
    if (!a_chat_str) {
        a_chat_str = allocate(1);
        a_chat_str[0] = "Headhunter screams: 'Death to the living!'\n";
    }
    load_chat(5, chat_str);
    load_a_chat(80, a_chat_str);
  set_special(70);
}

// intentionally made insta kill maneuver. Celtron 2006. this mob is meant to be unkillable.
combat_special() {
  tell_room(environment(this_object()), "Headhunter slits your throat open with one swift move!\n");
  if(!query_attacker()) return 0;
  query_attacker()->hit_player(10000);
}

catch_tell(str) {
    string giver,item,tmp;
    object ob, sack;
    if (!str) { return 1; }
    if (sscanf(str, "%s gives %s to %s", giver, item, tmp) == 3) {
      sack = present(item, this_object());
      if(!sack) return 0;
      if(sack->query_mark_dead()) {
        write("Headhunter cheers with his hollow voice, 'Good! More death!'\n");
        write("### Rewards will come after test phase.\n");
      }
      destruct(sack);
      return 1;
    }

    if (sscanf(str, "%s says '%s'", giver, tmp) == 2) {
      if(lower_case(tmp) == "yes") {
        if(check_player(giver)) {
          tell_room(environment(this_object()), "Headhunter says: 'You are already on a mission..come back later.'\n");
	  return 1;
        }
        tell_room(environment(this_object()), "Headhunter says: 'Take this and bring me the proof of your deed.'\n");
        write("You receive a sack.\n");
        move_object(ob = clone_object(SACK), this_player());
	call_out("give_target",0, this_player(), ob);
	player_list += this_player()->query_name()+",";
        return 1;
      }
    }

}

check_player(string giver) {
  string *list;
  int i;
  list = explode(player_list, ",");
  for(i=1; i < sizeof(list); i++) {
    if(this_player()->query_name() == list[i]) {
      return 1;
    }
  }
  return 0;
}

give_target(object player, object sack) {
  string file, msg;
  object mob;
  int level;
  level = player->query_level() / 2;

  while(!mob) {
    file = MONSTER_D->get_random_monster_filename(level, 0);
    msg = catch(mob = clone_object(file));
    if(!mob) {
       log_file("HEADHUNTER", ctime(time())+" PLAYER: "+this_player()->query_name()+" "+file+" "+msg+"\n",1);
       write("trying lower levels..");
    }
    level = level - 7;
  }
  sack->set_target_short(mob->short());
  tell_object(player, "Your mission is to find and terminate "+mob->short()+".\nRemember to 'mark' your target before killing.\n");
  return 1;  
}

/*
string get_random_monster_filename(int level, int eqmob);
string get_random_eq_monster_filename(int level);
 	ob->set_target_short("");

*/
