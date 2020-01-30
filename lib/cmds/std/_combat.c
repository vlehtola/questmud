#define COMBAT "/daemons/combat"

cmd_combat(string arg) {
  int dodge, parry, hit;
  string str,str2;
  object ob, player;
  if(this_player()->query_wiz() && arg) {
    player = find_player(arg);
  }
  if(!player) player = this_player();
  dodge = call_other(COMBAT, "dodge_chance", player)*2;
  parry = call_other(COMBAT, "parry_chance", player)*2+call_other(COMBAT, "parry_chance", player, 1)*2;
  hit = call_other(COMBAT, "hit_chance", player);

  if(parry > 250) parry = 250;
  ob = player->query_left_weapon();
  str2 = "You are fighting bare handed";

  if(player->query_right_weapon()) {
    str = "You have a weapon";
    str2 = str;
  }

  if(ob && ob->query_type() == "shield") {
    if(!str) str = "You are wielding a shield";
    else str += " and a shield";
  } else if(ob && str) {
    str = "You have two weapons";
    str2 = str;
  } else if (!str) {
    str = "You have nothing to parry with";
  }

  if(dodge < 0) dodge = 0;
  if(parry < 0) parry = 0;
  write("\n");
  write("Your combat factors:\n");
  write("  Hit:   "+hit+"% ("+str2+")\n");
  write("  Parry: "+parry+" ("+str+")\n");
  write("  Dodge: "+dodge+"\n");
  return 1;
}
