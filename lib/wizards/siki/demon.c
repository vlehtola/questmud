inherit "obj/monster";

#define DEMON_POOL "/daemons/warlock_d"
#define EMOTE_D "/daemons/emote_d"
string master, alias;
string skill_name;
int follow, share, today_xp;
int skill_chance;
int chaos_shield, life_link, chaos_hp, chaos_stat, chaos_skill, chaos_sk;

//dam = (dam * attacker->query_ep()) / attacker->query_max_ep();
add_exp(int i, string str, mixed arg) {
  object ob;
  int master_xp, pool_xp;
  ob = find_player(master);
  if(!ob) return;
  if(ob->query_alignment() >=0) {
  tell_object(ob, "You get feeling that dark gods are not pleased by your deeds!\n");
  i = i/2;
  }
  if(!share)share=15;
  pool_xp = (i * share) / ob->query_exp_rate();
  master_xp = i-pool_xp;
  DEMON_POOL->add_demon_xp(master, pool_xp);
  today_xp += pool_xp;
  debug_warlock("Pool "+pool_xp+" Master: "+master_xp+" Today: "+today_xp+"");
  ob->add_exp(master_xp, str, arg);
}

set_alias(string str) {
	if(strlen(str) > 15) {
	write("Too long label.\n");
	return 1;
}
	alias = str;
}
set_skill_name(string str) {
	if(this_object()->query_skill(str)) {
     DEMON_POOL->do_say("Master, i don't have that skill!", this_object());
	return 1;
    }
	skill_name=str;
	skill_chance=this_object()->query_skills(str)/3;
	debug_warlock("Called set_skill_name: "+str+" | chance "+skill_chance+"");
	DEMON_POOL->do_say("I will now try to use the skill "+skill_name+" when i am in battle.", this_object());
}
set_chaos_shield(int i) {
chaos_shield=1;
call_out("end_chaos_shield", i);
}
set_life_link(int i) {
life_link=1;
call_out("end_life_link", i);
}
end_life_link() {
life_link=0;
DEMON_POOL->do_say("I am not anymore under influence of life link", this_object());
}

end_chaos_shield() {
chaos_shield=0;
DEMON_POOL->do_say("I am not anymore under influence of chaos shield", this_object());
}
query_chaos_shield() { return chaos_shield; }
query_life_link() { return life_link; }

string query__alias() {
	return alias;
}
query_prevent_shadow() { return 1; }

debug_warlock(string str) {
object ob;
ob = find_player(master);
if(ob && ob->query_wiz()) {
tell_object(ob, "Debug: "+str+".\n");
}
write_file("/log/WARLOCK_INFO", ctime()+" ("+master+") "+str+".\n");
}

query_demon() {
	return 1;
}
query_share() { return share; }
set_demon(string str, int i) {
object armour, w1, w2;
if(!str) { write("Set what?\n"); return 1; }

str = lower_case(str);
debug_warlock("Called set_demon with "+str+" and "+i+"");
if(str == "exp") {
if(i > 30) {
write("Too much exp share set.\n");
return 1;
}
if(i < 5) {
write("Too low exp share set.\n");
return 1;
}
DEMON_POOL->do_say("I will now leech "+i+"% experience from kills.", this_object());
share=i;
return 1;
}

if(str == "armour") {
armour = present("warlock_armour", this_object());
if(armour) {
DEMON_POOL->do_say("I already have an chaos armour.", this_object());
return 1;
}
armour = clone_object("/guilds/warlock/obj/armour");
armour->set_class(i/10);
armour->set_stats("str",i/8);
armour->set_stats("con",i/8);
armour->set_stats("int",i/8);
armour->set_stats("dex",i/8);
armour->set_stats("wis",i/8);
armour->set_stats("spr",i/8);
move_object(armour, this_object());
DEMON_POOL->do_say("I will wear this chaos armour proudly!", this_object());
this_object()->init_command("wear armour");
return 1;
}
if(str != "axe" && str != "sword" && str != "bludgeon") {
DEMON_POOL->do_say("I can't call that kind of chaos weapons.", this_object());
return 1;
}
w1 = clone_object("/guilds/warlock/obj/"+str+"");
move_object(w1, this_object());
w1->set_class(i);
w2 = clone_object("/guilds/warlock/obj/"+str+"");
move_object(w2, this_object());
w2->set_class(i);
DEMON_POOL->do_say("I will wield these chaos weapons proudly!",this_object());
this_object()->init_command("wield "+str+"");
this_object()->init_command("wield "+str+" 2");
return 1;
}

query_demon_master() {
	return master;
}

query_hunter_list() { return 0; }

query_follow() {
  return follow;
}
set_follow(int i) {
follow=i;
}
do_summon() {
object ob;
ob = find_player(master);
if(!master) return 1;
if(ob->query_attacker()) {
write("Demon fails to summon you from battle.\n");
return 1;
}
tell_room(environment(ob), capitalize(master)+" disappears in a puff of smoke.\n", ({ this_object(), ob }));
move_object(find_player(master), environment(this_object()));
tell_room(environment(ob), capitalize(master)+" arrives in a puff of smoke.\n", ({ this_object(), ob }));
write("Demon summons you!\n");
return 1;
}
do_teleport() {
tell_room(environment(this_object()), "Demon disappears in a puff of smoke.\n", ({ this_object(), }));
move_object(this_object(), environment(find_player(master)));
tell_room(environment(this_object()), "Demon arrives in a puff of smoke.\n", ({ this_object(), }));
return 1;
}

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_dead_ob(this_object());
  set_extra(1);
  enable_commands();
}
//Tahen tulee skill starttaus lappa!
extra() {
object skill;
string str;
if(random(skill_chance+chaos_sk) < random(200) && this_object()->query_attacker() && !this_object()->query_use_skill() && skill_name) {
str = skill_name+" at "+lower_case(this_object()->query_attacker()->query_name());
DEMON_POOL->do_skill(str, this_object());
}
}

set_controller(string str) {
  master = str;
}

query_controller() {
  return master;
}
dest_items() {
object *obs;
int i;
obs = all_inventory(this_object());
for(i=0;i<sizeof(obs);i++) {
if(obs[i]->drop()) {
destruct(obs[i]);
}
}
}

monster_died() {
dest_items();
if(find_player(master)) {
tell_object(find_player(master), "As your demon dies you lose some of the demon experience.\n");
}
DEMON_POOL->do_say("I will return to revenge my death!", this_object());
write_file("/log/DEMON_KILLS", ctime()+" ("+master+") demon was killed by: "+attacker_ob->query_name()+" it reduce "+today_xp/10+" xp from pool.\n");
DEMON_POOL->add_demon(master, 0);
DEMON_POOL->reduce_demon_xp(master, today_xp/10);
return 0;
}

catch_tell(string str) {
string tmp1;
string dir;
string tmp2;
object enemy;
if(sscanf(str, "%s leaves %s.", tmp1, dir) == 2) {
if(lower_case(tmp1) != master) return 0;
if(!follow) return 0;
init_command(dir);
}
if(sscanf(str, "%s disappears in a puff of smoke.", tmp1) == 1) {
if(lower_case(tmp1) != master) return 0;
call_out("do_teleport", 2);
}

if(sscanf(str, "%s is in vigorous combat with %s.", tmp1, tmp2) == 2) {
enemy = present(lower_case(tmp2), environment(this_object()));
if(lower_case(tmp1) == master && !this_object()->query_attack()) {
say(this_object()->query_name()+" attacks "+enemy->query_name()+"!\n");
this_object()->attack_object(enemy);
}
}
}
query_commands() { return query_actions(this_object()); }

hit_player(int dam, mixed dam_type, ob) {
  int i;
  object pre;
  object demon_master;
  string *lappaa;
  lappaa = ({ "I will kill you!", "Even your pitifull hits don't harm me!", "Master. Lets kill that son of bitch!", })[random(3)];
  if(!random(50)) {
  DEMON_POOL->do_say(lappaa, this_object());
  }
  if(chaos_shield==1 && !random(8)) {
  tell_object(this_object(), "The chaos shield around you flashes rapidly!\n");
  tell_room(environment(this_object()), "The chaos shield around "+this_object()->short()+" flashes rapidly!\n");
  return 0;
  }
  demon_master = present(master, environment(this_object()));
  if(life_link==1 && demon_master && !random(4)) {
  tell_object(this_object(), "A life link directs some of the damage to your master!\n");
  tell_object(demon_master, "A life link around "+this_object()->short()+" directs some of the damage to you!\n");
  dam = dam/3*2;
  demon_master->hit_player(dam, dam_type, ob);
  }
  /* Don't damage wizards too much ! */
  if (query_wiz() > 0 && dam >= query_hp()) {
    tell_object(this_object(), "Your wizardhood protects you from death.\n");
    return 0;
  }
  if(dead) {
    tell_object(this_object(),"You are dead, you cannot be hit.\n");
    return -1;
  }
  dam = this_object()->get_resists(dam, dam_type);
  if (dam <= 0)
    dam = 1;
  if (uncon && attacker_ob) { dam = hit_point + 1; }
  if (dam > 200) {
    tell_object(this_object(), "That really "); lited("HURT");
    tell_object(this_object(), "!\n");
    DEMON_POOL->do_say("Master, lets get the hell out of here!", this_object());
  }
  hit_point = hit_point - dam;
  if (hit_point < 1) {
    death = 1;
    dead_by_hit = dam_type;
  }
  if(ob) {
    ob->add_party_exp(random(dam)*10);
    return dam;
  }
  pre = previous_object();
  if(pre && living(pre) && !pre->query_npc()) {
    pre->add_party_exp(random(dam)*10);
  }
  if(this_object()->query_hp() < this_object()->query_max_hp() / 10) {
    tell_object(this_object(), "Your wounds are SEVERE!\n");
        DEMON_POOL->do_say("Master, i will die soon!", this_object());
  }
  return dam;
}
query_chaos_hp() { return chaos_hp; }

start_chaos_hp(int time, int effect) {
chaos_hp=1;
this_object()->set_max_hp(this_object()->query_hp()+effect);
this_object()->set_max_ep(this_object()->query_hp()+effect);
this_object()->set_max_sp(this_object()->query_hp()+effect);
call_out("end_chaos_hp", time, effect);
DEMON_POOL->do_say("Powers of Chaos, I call thee to aid my futile body!", this_object());
}
end_chaos_hp(int effect) {
this_object()->set_max_hp(this_object()->query_max_hp()-effect);
this_object()->set_max_ep(this_object()->query_max_ep()-effect);
this_object()->set_max_sp(this_object()->query_max_sp()-effect);
chaos_hp=0;
DEMON_POOL->do_say("Is this a curse? My durability is fading away!", this_object());
this_object()->heal_self(1);
return 1;
}
query_chaos_stat() { return chaos_stat; }

start_chaos_stat(int time, int effect) {
this_object()->set_str(this_object()->query_str()+effect);
this_object()->set_dex(this_object()->query_dex()+effect);
this_object()->set_con(this_object()->query_con()+effect);
this_object()->set_int(this_object()->query_int()+effect);
this_object()->set_wis(this_object()->query_wis()+effect);
chaos_stat=1;
call_out("end_chaos_stat", time, effect);
DEMON_POOL->do_say("Chaos flows into me!", this_object());

}

end_chaos_stat(int effect) {
this_object()->set_str(this_object()->query_str()-effect);
this_object()->set_dex(this_object()->query_dex()-effect);
this_object()->set_con(this_object()->query_con()-effect);
this_object()->set_int(this_object()->query_int()-effect);
this_object()->set_wis(this_object()->query_wis()-effect);
chaos_stat=0;
DEMON_POOL->do_say("I'm getting weaker, help me master...", this_object());
return 1;
}
query_chaos_skill() { return chaos_skill; }

start_chaos_skill(int time, int effect) {
chaos_skill=1;
chaos_sk=effect;
call_out("end_chaos_skill", time);
DEMON_POOL->do_say("My limbs are getting control from the dark side!", this_object());

}
end_chaos_skill(int effect) {
chaos_skill=0;
chaos_sk=0;
DEMON_POOL->do_say("I feel NUMB! My limbs don't obey me correctly!", this_object());
return 1;
}

short() {
string str;
str = "";
str += short_desc;
if(alias) {
str += " "+capitalize(alias);
}
return str;
}

remove_limb(string str) {
if(str == "right arm") return;
if(str == "left arm") return;
}

