inherit "obj/monster";

#define HORDE_SAVE "/data/necromancer/"+this_player()->query_real_name()

mapping undeads;
string master, l_desc,horde_alias;
int follow, special,dk_special,specboost,hpboost,statboost,specialboost,h_str,h_dex,h_wis,h_int,h_askill,h_dskill,h_hp,h_max_hp,h_level;

mapping query_undeads() {
  return undeads;
}

// added 3.5.2002 //Celtron
remove_limb(string str) {
  if(str == "left arm" || str == "right arm") return;
  return ::remove_limb(str);
}

add_exp(int i, string str, mixed arg) {
  object ob;
  ob = find_player(master);
  if(!ob) return;
  if(ob->query_alignment() >=0) {
  i = i/2;
  tell_object(ob, "You get feeling that dark gods are not pleased by your deeds!\n");
  }
  if(i<1 || i > 1000000)
  log_file("HORDE_XP", ctime(time())+" "+master+"'s horde proxied "+i+" xp.\n", 1);
  ob->add_exp(i, str, arg);
}

start_hpboost(int dur) {
	hpboost = 1;
	update_horde();
	call_out("remove_hpboost",dur+120);

}

set_horde_alias(string str) {
	horde_alias = str;
	this_object()->set_alias(horde_alias);
	update_horde();
}
string query_horde_alias() {
	return horde_alias;
}

start_statboost(int dur) {
	statboost = 1;
	update_horde();
	call_out("remove_statboost",dur+120);
}
start_specialboost(int dur,int effect) {
	specialboost = 1;
	specboost = effect;
	call_out("remove_specialboost",dur+120);
	update_horde();
}

remove_specialboost() {
	specialboost = 0;
	say("The unnatural blue glow surrounding "+short()+" disappears.\n");
	update_horde();
}

remove_hpboost() {
	say("The bright red aura surrounding "+short()+" slowly vanishes.\n");
	hpboost = 0;
	update_horde();
}
remove_statboost() {
	say("The bright brown aura surrounding "+short()+" slowly vanishes.\n");
	statboost = 0;
	update_horde();
}

query_necro_horde() {
	return 1;
}

query_hpboost() {
	return hpboost;
}
query_statboost() {
	return statboost;
}
query_specialboost() {
	return specialboost;
}
query_horde_master() {
	return master;
}

query_special() {
  return special;
}

init() {
	string temp;
	temp = master+"_horde";
  add_action("command", temp);
}

query_hunter_list() { return 0; }

secure_target() {
  object ob;
  ob = find_player(master);
  if(!ob) return 0;
  if(attacker_ob == ob) {
    tell_object(ob, "Horde refuses to attack it's master!\n");
    attacker_ob->stop_all();
    this_object()->stop_all();
    return 1;
  }
  return 0;
}
status viltteri(object ob) {
	if(ob->query_necro_horde())return 1;
	return 0;
}

command(string str) {
  string tmp,tmp1;
  int i;
  object ob;
  object *obs;
  object reclaim;
    if(lower_case(this_player()->query_name()) != master) {
      write("This is not your horde.\n");
      return 1;
    }
  if(this_player()->query_guild_level("Necromancers") < 1) {
  	tell_object(this_player(),"You cant control your horde anymore and it disappears.\n");
  	destruct(this_object());
  	return 1;
}
  if(str == "follow") {

    obs = all_inventory(environment(this_object()));
    obs = filter_array(obs,"viltteri");
  if(obs) {
    for(i=0;i<sizeof(obs);i++) {
    	if(obs[i] != this_object()) {
    		if(obs[i]->query_horde_master() == master) {
    			tell_room(environment(find_player(master)),"Both hordes goes insane and attacks against each other!\n");
    			destruct(obs[i]);
    			destruct(this_object());
			return 1;
    		}
    	}
}

}

    follow = !follow;
    if(follow) write("You make the horde to follow you.\n");
    else write("You make the horde to stop following you.\n");
    return 1;
}

  if(str == "status") {
    display_spcost_status();
    return 1;
  }
  if(str == "reclaim") {
	  if(query_horde_master() != lower_case(this_player()->query_name())) {
		  write("This is not your horde.\n");
		  return 1;
	  }
  if(present("horde_summon", this_player())) {
	  write("You are already owner of this horde.\n");
	  return 1;
  }
  reclaim = clone_object("/guilds/necro/obj/locate_ob");
  move_object(reclaim, this_player());
  reclaim->start(this_object());
  write("You reclaim your horde back.\n");
  return 1;
}
  if(str && sscanf(str, "attack %s", tmp) == 1) {
    ob = present(tmp, environment(this_object()));
    if(!ob) {
      write("There is no "+tmp+" present.\n");
      return 1;
    }
    if(!sp_cost("attack")) return 1;
    if (environment(this_player())->query_property("no_skill")) return 1;
    if(!living(ob)) return 1;
    if(ob->query_log()) return 1;
    write("The horde attacks "+tmp+".\n");
    attack_object(ob);
    return 1;
  }
if(str && sscanf(str, "alias %s",tmp) == 1) {
	if(strlen(tmp) > 15) { write("Too long alias.\n"); return 1; }
	write("You start to call your horde as '"+tmp+"'\n");
	set_horde_alias(tmp);
	return 1;
	}
/*
if(str == "fix") {
 write("Horde fixed!\n");
 if(this_object()->query_spell())this_object()->set_spell(0);
 return 1;
}
*/
  write("\nAvailable commands:\n");
  write("    "+master+"_horde follow\n");
  write("    "+master+"_horde attack <target>\n");
  write("    "+master+"_horde status\n");
  write("    "+master+"_horde alias <alias>\n");
  write("    "+master+"_horde reclaim\n");
//  write("    "+master+"_horde fix\n");
  return 1;
}

catch_tell(string str) {
  string dir, tmp, dest;
  if(sscanf(str, "%s leaves %s.", tmp, dir) == 2) {
    if(lower_case(tmp) != master) return 0;
    if(!query_follow()) return 0;
    if(attacker_ob && present(attacker_ob, environment(this_object()) )) {
      if(undeads["skeleton"]) {
        write("The horde is in combat and the skeletons refuse to leave!\n");
        return 0;
      }
    }
    if(!sp_cost("move")) return 1;
    init_command(dir);
  }
}

query_follow() {
  return follow;
}

sp_cost(string str) {
  int i;
  object ob;
  ob = find_player(master);
  if(!ob) return;
  i = query_control_cost(str);
  if(ob->query_sp() < i) {
    write("You don't have enough sp.\n");
    return 0;
  }
  ob->reduce_sp(i);
  return 1;
}

query_control_cost(string str) {
  int cost;
  if(str == "move") cost = total_undeads()/4;
  if(str == "attack") cost = total_undeads()*3;
  return cost;
}

display_spcost_status() {
  int i;
  write("Your horde contains the following undeads:\n");
  i = total_undeads(1);
    if(hpboost || statboost) {
  	if(hpboost && !statboost)write("The horde is surrounded by bright red aura.\n");
  	if(!hpboost && statboost)write("The horde is surrounded by bright brown aura.\n");
  	if(statboost && hpboost)write("The horde is surrounded by dark red aura.\n");
}
if(specialboost) {
write("The horde is surrounded by unnatural blue glow.\n");
}
  write("Your horde requires total of "+query_control_cost("attack")+" sps to attack\n"+
        "and "+query_control_cost("move")+" sps to move.\n");
}

total_undeads(int stat) {
  int i, c;
  c = undeads["skeleton"];
  if(c&&stat) write("Skeletons: "+c+"\n");
  i += c;

  /* halve the amount of skeletons for control costs */
  if(!stat) i = i / 2;

  c = undeads["zombie"];
  if(c&&stat) write("Zombies: "+c+"\n");
  i += c;

  c = undeads["flesh golem"];
  if(c&&stat) write("Flesh golems: "+c+"\n");
  i += c;

  c = undeads["wight"];
  if(c&&stat) write("Wights: "+c+"\n");
  i += c;

  c = undeads["ghost"];
  if(c&&stat) write("Ghosts: "+c+"\n");
  return i;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_short("A horde of wandering undeads");
  l_desc = "A horde that has been animated by a necromancer.\n"+
        "Reanimating dead bodies is an ultimately evil act which\n"+
        "steals the after-life of the dead persons. Undeads hate all\n"+
        "living ones and hunger for their blood.\n"+
        "The horde can be controlled with command 'yourname_horde' (ie. astarel_horde).\n";

  set_long(l_desc);
  undeads = ([ ]);
  set_dead_ob(this_object());
  set_alt_name("horde");
  set_alias("horde");
  set_level(5);
  set_undead();
  set_extra(1);
  set_random_pick(0);
  no_money();
}

extra() {

  int i;
  object enemy;

  enemy = this_object()->query_attacker();
  if(!enemy) return;
 // dk_special max 400
 if(undeads["death knight"] && ((dk_special/2)+(specboost*2)) > random(3750)) {
 	tell_room(environment(this_object()),"Death Knight stares at "+enemy->query_name()+" and orders the horde to charge with outrageous power.\n");
 enemy->hit_with_spell( ((dk_special*2)/5)+(specboost/2),"physical");
 }
 if(undeads["wraith"] && ((dk_special/3)+(specboost*2)) > random(3650)) {
 	tell_room(environment(this_object()),"A wraith appears above the horde and gazes "+enemy->query_name()+"!\n");
 enemy->set_stunned(random(4));

}
}

set_controller(string str) {
  master = str;
}

query_controller() {
  return master;
}

get_horde_adj() {
  int i;
  i = undeads["skeleton"]+undeads["wight"]+undeads["ghost"]+undeads["zombie"]+undeads["flesh golem"]+undeads["death knight"]+undeads["lich"];
  switch(i) {
  case  0 .. 1  : return "one";
  case  2 .. 7 : return "few";
  case 8 .. 15 : return "some";
  case 16 .. 25 : return "several";
  case 26 .. 35 : return "numerous";
  case 36 .. 51 : return "many";
  case 52 .. 1000 : return "dozens";
  }
}

update_horde(int flagutesti) {
  int i, wc, c_corp, c_ethe, c_grea, c_magi,temp,h_sp;
  string tmp, tmp2;
  object ob;
  ob = find_player(master);
  if(!ob) return;

  c_corp = ob->query_skills("control corporeal")+80;
  c_ethe = ob->query_skills("control ethereal")+80;
  c_grea = ob->query_skills("control greater undead")+80;
  c_magi = ob->query_skills("control dark magic")+80;

  /* max 15+5+5+5 <= 30 */
  if(undeads["death knight"]) {

    dk_special = (c_grea*2)+(c_corp/2);
  }

  /* max 80+160+50+10 = ~300 */
  i = undeads["skeleton"]*2*c_corp/160 + undeads["ghost"]*20*c_ethe/150 + wc/2
+ 10;
  if(i > 300) i = 300;

  if(undeads["lich"] && !mage) {
    set_mage(1,10);
    set_lich_skills(c_magi+c_grea);
  }
  set_size(65);
  set_name("horde");
  tmp = get_horde_adj();
  set_short("A horde of "+tmp+" wandering undeads called '"+horde_alias+"'");
  tmp = "";
  tmp2 = "";

  if(undeads["flesh golem"]) {
    tmp2 = "A flesh golem is protecting the horde.\n";
  }
  if(undeads["death knight"]) {
    tmp2 = tmp2 + "A death knight is leading the horde.\n";
  }
  if(undeads["lich"]) {
    tmp2 = tmp2 + "A lich stands in the back rank screaming words of dark magic.\n";
  }
  if(undeads["wraith"]) {
	  tmp2 = tmp2 + "A wraith is flying above the horde.\n";
  }
  if(hpboost || statboost) {
        if(hpboost && !statboost)tmp2 = tmp2 + "The horde is surrounded by bright red aura.\n";
        if(!hpboost && statboost)tmp2 = tmp2 + "The horde is surrounded by bright brown aura.\n";
        if(statboost && hpboost)tmp2 = tmp2 + "The horde is surrounded by dark red aura.\n";
}
if(specialboost) {
        tmp2 = tmp2 + "The horde is surrounded by unnatural blue glow.\n";
}
  set_long(l_desc +"The horde contains "+(undeads["skeleton"])+" skeletons,\n"+ (undeads["zombie"])+" zombies, "+(undeads["ghost"])+" ghosts and "+(undeads["wight"])+" wights.\n"+  tmp+tmp2);
  set_alias(horde_alias);
  set_max_ep(1000000);
  set_ep(1000000);
  set_exp(1);
  update_horde_stats();
  update_horde_hp();
}

monster_died() {
  if(find_player(master)) {
  tell_object(find_player(master), "Your horde is dead!\n");
  }
  rm(HORDE_SAVE);
  return 0;
}

save_horde() {
  save_object(HORDE_SAVE);
}
restore_horde() {
  restore_object(HORDE_SAVE);
}

add_undead(string str) {
  string type;
  int amount, spcost;
  if(valid_undead(str) <= undeads[str]) {
    write("You cannot add more undeads of this type.\n");
    return 1;
  }
  type = query_raise_cost(str);
  amount = query_raise_cost(str,1);
  if(undeads[type] < amount) {
    write("You need more "+type+"s, before you make this upgrade.\n");
    return 0;
  }
  spcost = 300 - valid_undead(str)*7;
  spcost = spcost*80/(80+this_player()->query_skills("knowledge of animation"));
  if(spcost < 0) spcost = 0;
  if(spcost > this_player()->query_sp()) {
    write("You do not have enough sps to add this corpse to your horde.\n");
    return 0;
  }
  this_player()->reduce_sp(spcost);
  if(amount) {
    write("Some "+type+"s transform into dust as the dark force leaves them and focuses\n"+
          "in one single creature, granting it more unholy power.\n");
    undeads[type] -= amount;
  }
  write("You add the animated "+str+" to the horde.\n");
  undeads[str] += 1;
  update_horde(1);
  update_horde_hp();
  update_horde_stats();
}

query_raise_cost(string str, int i) {
  if(!i) {
  switch(str) {
  case "flesh golem": return "skeleton";
  case "death knight": return "skeleton";
  case "lich": return "skeleton";
  case "wight": return "skeleton";
  case "ghost": return "skeleton";
  case "zombie": return "skeleton";
  case "wraith": return "ghost";
  }
  return 0;
  }
  switch(str) {
  case "flesh golem": return 10;
  case "death knight": return 15;
  case "lich": return 15;
  case "wight": return 2;
  case "ghost": return 2;
  case "zombie": return 2;
  case "wraith": return 3;
  }
}

valid_undead(string str) {
  switch(str) {
  case "skeleton": return 30;  /* hits */
  case "zombie": return 5;     /* hp */
  case "flesh golem": return 1; /* hc hp */
  case "wight": return 10;    /* ac */
  case "ghost": return 5;    /* str */
  case "death knight": return 1;
  case "lich": return 1;    /* mage */
  case "wraith": return 1;
  }
}

set_lich_skills(int i) {
  /* i [0,180] / 3 + 25 = [0,85] */
  i = i /3 + 25;
  set_skill("chanting", i);
  set_skill("cast essence", i);
  set_skill("cast bolt", i);
  set_skill("cast fire", i);
  set_skill("cast ice", i);
  set_skill("cast electric", i);
  set_skill("cast earth", i);
  i -= 20;
  set_skill("knowledge of heat", i);
  set_skill("lore of cold", i);
  set_skill("theory of electricity", i);
  set_skill("mana control", i);
  set_skill("power focusing", i);
  set_skill("power concentration", i);
  set_skill("power channeling", i);
}
update_horde_hp() {
	int i;
	object ob;
	ob = find_player(master);
	if(!ob) return;
	h_max_hp = (undeads["skeleton"]*5) + (undeads["wight"]*10) + (undeads["ghost"]*100) + (undeads["zombie"]*100) + (undeads["flesh golem"]*1000) + (undeads["death knight"]*500);
	h_max_hp += ob->query_skills("control corporeal")+ob->query_skills("control ethereal")+ob->query_skills("control greater undead")+ob->query_skills("control dark magic")*10;
	h_level = undeads["skeleton"]+undeads["wight"]+undeads["ghost"]+undeads["zombie"]+undeads["flesh golem"]+undeads["wraith"]+undeads["death knight"]+undeads["flesh golem"];
	h_level = h_level/2;
	i = this_object()->query_hp();
	set_level(h_level);
    if(h_max_hp > 5000) h_max_hp = 5000;
    if(query_hpboost() == 1) {
		h_max_hp += 1000;
	}
	set_max_hp(h_max_hp);
	set_max_sp(ob->query_skills("control dark magic")*5+500);
	set_hp(i);
    set_sp(query_max_sp());
    set_exp(1);
    set_max_ep(1000000);
    set_ep(1000000);
    set_random_pick(0);
    update_horde_stats();
}
update_horde_stats() {
object ob;
ob = find_player(master);
if(!ob) return;
h_str = undeads["skeleton"] + (undeads["wight"]*3) + (undeads["ghost"]*3) + (undeads["death knight"]*20) + (undeads["flesh golem"]*15)/2;
h_dex = undeads["skeleton"] + (undeads["ghost"]*10) + (undeads["death knight"]*20)/2;
h_int = undeads["skeleton"] + (undeads["lich"]*100) + (undeads["death knight"]*30)/2;
h_wis = undeads["skeleton"] + (undeads["lich"]*100) + (undeads["death knight"]*30)/2;
h_str += ob->query_skills("control corporeal")+ob->query_skills("control ethereal")+ob->query_skills("control greater undead")/2;
h_dex += ob->query_skills("control corporeal")+ob->query_skills("control ethereal")+ob->query_skills("control greater undead")/2;
h_int += ob->query_skills("control corporeal")+ob->query_skills("control ethereal")+ob->query_skills("control greater undead")+ob->query_skills("control dark magic")/2;
h_wis += ob->query_skills("control corporeal")+ob->query_skills("control ethereal")+ob->query_skills("control greater undead")+ob->query_skills("control dark magic")/2;
h_askill = undeads["skeleton"]+(undeads["wight"]*5)+(undeads["ghost"]*4)/2;
h_dskill = undeads["skeleton"]+(undeads["zombie"]*10)+(undeads["flesh golem"]*20)/2;
h_askill += ob->query_skills("control corporeal")+ob->query_skills("control greater undead")+ob->query_skills("control ethereal")/6;
h_dskill += ob->query_skills("control corporeal")+ob->query_skills("control greater undead")+ob->query_skills("control ethereal")/8;
if(query_statboost() == 1) {
	h_str = h_str*2;
	h_dex = h_dex*2;
	h_int = h_int*2;
	h_wis = h_wis*2;
}
set_str(h_str/2);
set_dex(h_dex/2);
set_int(h_int/2);
set_wis(h_wis/2);
set_skill("attack", h_askill);
set_skill("punch", h_askill);
set_skill("bare hands", h_askill);
set_skill("throw weight", h_askill);
set_skill("critical", h_askill);
set_skill("stun", h_askill);
set_skill("find weakness", h_askill);
set_skill("deceived attack",h_askill);
set_skill("enhance criticals", h_askill);
set_skill("dodge", h_dskill);
set_skill("alertness", h_dskill);
set_skill("ignore wrong strike", h_dskill);
set_skill("foresee attack", h_dskill);
}
/*
defend; dodge, alertness,ignore wrong strike, foresee attack
attack; attack, punch, bare hands, stun, critical,throw weight,find weakness
max 100%
*/
add_skeletons(int val) {
	undeads["skeleton"] += val;
	if(undeads["skeleton"] > 30) {
		undeads["skeleton"] = 30;
	}
	update_horde();
}
