inherit "obj/monster";

#define DEMON_POOL "/daemons/warlock_d"
#define EMOTE_D "/daemons/emote_d"
string master, alias;
string skill_name;
string spell_name;
int follow, share, today_xp;
int skill_chance, spell_chance;
int chaos_shield, life_link, chaos_hp, chaos_stat, chaos_skill, chaos_sk;
int hpreg, epreg, spreg;
int tank, food;
int spboost;
int base_hp_max, base_sp_max, base_ep_max;
//dam = (dam * attacker->query_ep()) / attacker->query_max_ep();

add_exp(int i, string str, mixed arg) {
  object ob;
  int master_xp, pool_xp;
  ob = find_player(master);
  if(!ob) return;
  if(ob->query_alignment() >=0) {
  tell_object(ob, "You get feeling that dark gods are not pleased by your deeds!\n");
  i = i/10;
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
set_spell_name(string str) {
        if(!str) {
         write("What?\n");
         return 1;
     }
    if(str == "stop") {
         spell_name="stop";
         spell_chance=0;
     DEMON_POOL->do_say("I don't anymore trying to cast spells in battle", this_object());
     return 1;
    }
        spell_name=str;
        spell_chance=100;
        skill_name="stop";
        debug_warlock("Called set_spell_name: "+str+" | chance "+spell_chance+"");
        DEMON_POOL->do_say("I will now try to cast "+spell_name+" at my opponents if i am in battle.", this_object());
}
set_skill_name(string str) {
        if(!str) {
         write("What?\n");
         return 1;
     }
    if(str == "stop") {
         skill_name="stop";
         skill_chance=0;
     DEMON_POOL->do_say("I don't anymore trying to use skills in battle", this_object());
    }
        if(this_object()->query_skill(str)) {
     DEMON_POOL->do_say("Master, i don't have that skill!", this_object());
        return 1;
    }
    spell_name="stop";
        skill_name=str;
        skill_chance=this_object()->query_skills(str)/3+5;
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
eat_food(int i) {
food += i;
if(food > 60) {
food = 60;
}

}
query_hungry() { return food; }

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
if(str == "tank" && !tank) {
DEMON_POOL->do_say("I will now try to tank for you.", this_object());
tank = 1;
return 1;
}
if(str == "tank" && tank) {
DEMON_POOL->do_say("I will now not try to tank for you.", this_object());
tank = 0;
return 1;
}
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

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_dead_ob(this_object());
  enable_commands();
  call_out("heal_slowly", 30);
  eat_food(60);
  set_extra(1);
}
//Tahen tulee skill starttaus lappa!
extra() {
string str;
if(!query_spell() && spell_name != "stop" && this_object()->query_attacker()) {
str = spell_name;
DEMON_POOL->do_spell(str, this_object());
return 1;
}
if(!query_use_skill() && skill_name != "stop" && this_object()->query_attacker()) {
str = skill_name;
DEMON_POOL->do_skill(str, this_object());
return 1;
}
}

set_controller(string str) {
  master = str;
}

query_controller() {
  return master;
}

monster_died() {
if(find_player(master)) {
tell_object(find_player(master), "As your demon dies you lose some of the demon experience.\n");
}
DEMON_POOL->do_say("I will return to revenge my death!", this_object());
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
if(query_use_skill()) {
query_use_skill()->interrupt_skill();
tell_room(environment(this_object()), query_name()+" loses its skill concentration.\n", ({ this_object(), }));
}
if(query_spell()) {
query_spell()->interrupt_spell();
tell_room(environment(this_object()), query_name()+" loses its spell concentration.\n", ({ this_object(), }));
}

}
if(sscanf(str, "%s is in vigorous combat with %s.", tmp1, tmp2) == 2) {
enemy = present(lower_case(tmp2), environment(this_object()));
if(lower_case(tmp1) == master && tank) {
this_object()->attack_object(enemy);
enemy->change_attacker(this_object());
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
  if(life_link==1 && demon_master && !random(3)) {
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

effect=effect/2; // Nalletune

//this_object()->set_max_hp(this_object()->query_max_hp()+effect);
this_object()->set_max_ep(this_object()->query_max_ep()+effect);
this_object()->set_max_sp(this_object()->query_max_sp()+effect);

call_out("end_chaos_hp", time, effect);
DEMON_POOL->do_say("Powers of Chaos, I call thee to aid my futile body!", this_object());
}

end_chaos_hp(int effect) {

effect=effect/2; // Nalletune

//this_object()->set_max_hp(this_object()->query_max_hp()-effect);
this_object()->set_max_ep(this_object()->query_max_ep()-effect);
this_object()->set_max_sp(this_object()->query_max_sp()-effect);
chaos_hp=0;
DEMON_POOL->do_say("Is this a curse? My durability is fading away!", this_object());
this_object()->heal_self(1);
return 1;
}
query_chaos_stat() { return chaos_stat; }

start_chaos_stat(int time, int effect) {

effect=effect/2; // Nalletune
if(effect>this_object()->query_str()) effect=this_object()->query_str();

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

effect=effect/2; // Nalletune
if(effect>(this_object()->query_str()/2)) 
   effect=this_object()->query_str()/2;

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
if(str == "head") return 1;
if(str == "right arm") return 1;
if(str == "left arm") return 1;
return ::remove_limb(str);
}

reduce_ep(i) {
  endurance_points -= i;
  if(query_ep() < query_ep() / 10) {
  tell_object(this_object(),"You will FAINT soon from exhaustion!\n");
  DEMON_POOL->do_say("I will FAINT soon from exhaustion!", this_object());
} else if(query_ep() < query_ep() / 6) {
    tell_object(this_object(),"You feel very exhausted!\n");
      DEMON_POOL->do_say("I am starting to feel very exhausted!", this_object());
  } else if(query_ep() < query_ep() / 3) {
    tell_object(this_object(),"You start feeling exhausted.\n");
      DEMON_POOL->do_say("I am starting to feel exhausted!", this_object());
  }
}
set_hpreg(int i) {
        hpreg = i;
        call_out("demon_regen", 50);
}
set_epreg(int i) {
        epreg = i;
}
set_spreg(int i) {
        spreg = i;
}
query_hpreg() { return hpreg; }
query_epreg() { return epreg; }
query_spreg() { return spreg; }

demon_regen() {
  if(!attacker_ob) {
  hit_point += hpreg;
  if (hit_point > max_hp) hit_point = max_hp;
  spell_points += spreg;
  if (spell_points > max_sp) spell_points = max_sp;
  endurance_points += epreg;
  if (endurance_points> max_ep) endurance_points = max_ep;
  }
  call_out("demon_regen", 50);
}

set_level(int i) {
size = i * 3 + 10;
weapon_class = i * 2+10;
experience = 666;
random_combat_tactic();
level=i;
if(!random(15)) {
level+=random(3)+1;
write("You masterfully summon a much more powerful demon.\n");
}
}

set_hp(int i) {
hit_point = i;
}
set_max_hp(int i) {
max_hp = i;
if(!base_hp_max)base_hp_max=i;
}

set_sp(int i) {
spell_points = i;
}
set_max_sp(int i) {
max_sp = i;
if(!base_sp_max)base_sp_max=i;
}
set_ep(int i) {
endurance_points = i;
}
set_max_ep(int i) {
max_ep = i;
if(!base_ep_max)base_ep_max=i;
}

set_str(int i) {
Str=i;
c_str=i;
}
set_int(int i) {
Int = i;
c_int=i;

}
set_wis(int i) {
Wis=i;
c_wis=i;

}
set_con(int i) {
Con=i;
c_con=i;
}
set_dex(int i) {
Dex=i;
c_dex=i;
}
set_sp_boost(string str, int i) {
spboost=i;
DEMON_POOL->do_say("I will now boost my spells at "+i+" spellpoints.", this_object());
}
query_sp_boost() {
if(!spboost) { return level*5; }
return spboost;
}
update_stats() {
object *ob;
int i;
ob = all_inventory(this_object());
for(i=0;i<sizeof(ob);i++) {
if(ob[i]->query_worn()) {
this_object()->set_str(this_object()->query_str()+ob[i]->query_stats("str"));
this_object()->set_dex(this_object()->query_dex()+ob[i]->query_stats("dex"));
this_object()->set_con(this_object()->query_con()+ob[i]->query_stats("con"));
this_object()->set_int(this_object()->query_int()+ob[i]->query_stats("int"));
this_object()->set_wis(this_object()->query_wis()+ob[i]->query_stats("wis"));
}
}
write("Stats updated.\n");
}
