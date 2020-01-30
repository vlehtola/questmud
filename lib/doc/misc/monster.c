/*
 * A general purpose monster. Clone this object,
 * and call local functions to configure it.
 */

/*
 * If you are going to copy this file, in the purpose of changing
 * it a little to your own need, beware:
 *
 * First try one of the following:
 *
 * 1. Do clone_object(), and then configure it. This object is specially
 *    prepared for configuration.
 *
 * 2. If you still is not pleased with that, create a new empty
 *    object, and make an inheritance of this objet on the first line.
 *    This will automatically copy all variables and functions from the
 *    original object. Then, add the functions you want to change. The
 *    original function can still be accessed with '::' prepended on the name.
 *
 * The maintainer of this LPmud might become sad with you if you fail
 * to do any of the above. Ask other wizards if you are doubtful.
 *
 * The reason of this, is that the above saves a lot of memory.
 */

#include "living.h"

/*
 * The heart beat is always sstarted in living.h when we are attacked.
 */

string short_desc, long_desc, alias, alt_name, alt_alias, race;
int move_at_reset, aggressive, move_at_random, count;
static object kill_ob;
static status healing;         /* True if this monster is healing itself. */

static string chat_head;       /* Vector with all chat strings. */
int chat_chance;
static mapping limbs;

static string a_chat_head;     /* Vector with all a_chat strings. */
int a_chat_chance;

object talk_ob;
string talk_func;       /* Vector of functions. */
string talk_match;      /* Vector of strings. */
string talk_type;       /* Vector of types. */
string the_text;
int have_text;
int kill_log;

object dead_ob;
object init_ob;

int random_pick, extra;
int animal;
int skill_chance;
string use_skill;
string spell_words;
int spell_chance, spell_dam;
string spell_mess1, spell_mess2;
static object me;
static object create_room;
static int no_money;
string block_direction, block_message;

string counter;
mapping skills;
mapping resists;
int regen;
int react_on_spell, react_on_combat, al_aggr;
int infravis;
string prom;
int follow_time,follow_chance;
int special_chance;
int undead, no_corpse;
int mage;			/* Defines if the monster is a mage. */


query_tester() { return; }
query_skill_map() { return skills; }
query_terminal() { return 0; }

parse_prompt() { return; }
reset(arg) {
    int i;
    object scroll;
    if (arg) {
        if (move_at_reset)
            random_move();
        return;
    }
    is_npc = 1;
    enable_commands();
    skills = ([ ]);
    limbs = ([ ]);
    resists = ([ ]);
    combat_tactic = ([ ]);
    me = this_object();
    this_object()->start();
    create_room = environment(me);
    if(random(300) == 0)
      move_object(clone_object("/world/objects/box"),this_object());
    if (random(100) == 99) {
        scroll = clone_object("/guilds/obj/spellscroll");
        move_object(scroll, this_object());
    }
}

query_counter() {
  return counter;
}

random_move() {
    int n,i;
    string str;
    if(!environment(this_object())) return;
    str = environment(this_object())->query_dest_dir();
    n = random(sizeof(str)+1)/2*2;
    if(!str) return;
    if(!n) n = 2;
    command(str[n-1], this_object());
    return (str[n-1]+" "+sizeof(str)+" "+(n-1));
}

write_error_log(arg) {
  object env, pre;
  string str, str2;
  if(query_wiz()) return;
  env = environment(this_object());
  if(env) str = file_name(env);
  pre = previous_object();
  if(pre) str2 = file_name(previous_object());
  log_file("BUG_ERROR", ctime(time())+" Player: "+short()+" Prev_ob: "+str2+"\n"+
        "Environment: "+str+" Problem: "+arg);
}

short() {
  string post;
  post = "";
  if (undead)   post += "(undead) ";
  if (kill_log) post += "(strong)";

  return short_desc + post;
}

string query_long() {
  return long_desc;
}

long() {
  string pro;
  pro = capitalize(this_object()->query_pronoun());
  write (long_desc);
  if(sizeof(m_indices(limbs)))
    write(pro+" has no "+query_limb()+".\n");
  if (animal) {
    write(pro+" is an animal.\n");
  } else if (undead) {
    write(pro+" is an undead.\n");
  } else if (race) {
    write(pro+" is a member of the "+this_object()->query_race()+" race.\n");
  }
}

id(str) {
    return str == name || str == alias || str == race ||
	str == alt_name || str == alt_alias || undead && str == "undead";
}

query_skills(string num) {
    if(!num) return skills;
    return skills[num];
}

remove_limb(string str) {
  object ob;
  if(!str) return;
  if(limbs[str]) return;
  if(str == "head") {
    say(capitalize(name)+"'s loosened head flies two metres before it drops on the ground!\n");
    death();
    return;
  }
  if(str == "torso") {
    say(capitalize(name)+"'s torso is cut in half!\n");
    death();
    return;
  }
  say(capitalize(name)+" grunts in pain as "+query_possessive()+" "+str+" is cut off!\n");
  if(str == "right arm" && query_right_weapon()) {
    say(query_name()+" drops its weapon!\n");
    move_object(query_right_weapon(), environment(this_object()));
  }
  if(str == "left arm" && query_left_weapon()) {
    say(query_name()+" drops its weapon!\n");
    move_object(query_left_weapon(), environment(this_object()));
  }
  limbs += ([str:1]);
  move_object(clone_object("/world/objects/blood"), environment(this_object()));
  ob = clone_object("/world/objects/limb");
  ob->set_short("A "+str);
  move_object(ob,environment(this_object()));
  this_object()->hit_with_spell(random(40)+10);
}

query_limb(string str) {
  if(!str) {
    str = implode(m_indices(limbs),", ");
    return str;
  }
  if(limbs[str]) { return 1; }
}

heart_beat() {
    int c, i;
    age += 1;
    if (move_at_random) { count += 1; }
    if (move_at_random != 0) {
         if (count == move_at_random) {
              count = 0;
              if (!this_object()->query_stun() && !attacker_ob) {
                  random_move();
              }
         }
    }

    if(!test_if_any_here()) {
        if(have_text && talk_ob) {
            have_text = 0;
            test_match(the_text);
        } else {
            if(!this_object()->dont_kill_hb()) set_heart_beat(0);
            set_heart_beat(0);
            if (!healing)
            call_out("heal_slowly", 30);
            return;
        }
    }
    if (kill_ob && present(kill_ob, environment(this_object()))) {
	check_al_aggr(kill_ob, 1);
        attack_object(kill_ob);
        kill_ob = 0;
        return;
    }
    if(!this_object()->query_stunned()) {
      if (attacker_ob && present(attacker_ob, environment(this_object())) && spell_chance > random(100)) {
        if (!spell) {
	    i = random(sizeof(spell_words));
            spell = clone_object("/guilds/obj/spell");
            spell->start_spell(spell_words[i] + " at "+lower_case(attacker_ob->query_name()));
        }
      }
      if (attacker_ob && present(attacker_ob, environment(this_object())) && special_chance > random(102)) {
	  this_object()->special_move();
      }
      if (attacker_ob && present(attacker_ob, environment(this_object())) && skill_chance) {
        if (!skill) {
	    int sc;
            string sk;
	    i = random(sizeof(use_skill));
	    sk = use_skill[i];
	    sc = skill_chance[i];
	    if(intp(sc) && sc > random(101)) {
              skill = clone_object("/guilds/obj/mskill");
              skill->start_skill(sk, attacker_ob->query_name());
	    }
        }
      }
    }
    this_object()->restore_time_points();
    if (attacker_ob && whimpy && hit_point < max_hp/5)
        random_move();
    if(chat_chance || a_chat_chance){
        c = random(100);
        if(attacker_ob && a_chat_head) {
            if(c < a_chat_chance){
                c = random(sizeof(a_chat_head));
                tell_room(environment(), a_chat_head[c]);
            }
        } else {
            if(c < chat_chance && chat_chance){
                c = random(sizeof(chat_head));
                tell_room(environment(), chat_head[c]);
            }
        }
    }
    if(random_pick) {
        c = random(100);
        if(c < random_pick)
            pick_any_obj();
    }
    if(have_text && talk_ob) {
        have_text = 0;
        test_match(the_text);
    }
    if (extra) {
       this_object()->extra();
    }
}

can_put_and_get(str) {
    if (!str)
        return 0;
    return 1;
}

int busy_catch_tell;

catch_tell(str, arg) {
    string attacker,who,dir;
    object ob, target;
    if(this_object()->query_control_shadow()) {
	this_object()->query_control_shadow()->send_msg(str);
	return;
    }
    if (busy_catch_tell)
        return;
    busy_catch_tell = 1;
    if(talk_ob) {
        if(have_text) {
            test_match(the_text);
            the_text = str;
        } else {
            the_text = str;
            have_text = 1;
        }
    }
    if(sscanf(str,"%s arrives %s",who,dir)) {
      target = present(lower_case(who), environment(this_object()));
      if(query_hunter_list(lower_case(who)) && target) {
        if (!animal) {
	  tell_object(target, cap_name +
		" grunts: 'I still remember you!'\n");
	}
	attack_object(target);
      }
    }
    if(follow_time && random(100) < follow_chance) follow(str);
    if (sscanf(str,"%s is in vigorous combat with "+cap_name+".",attacker) == 1) {
	ob = present(attacker, environment(this_object()));
	if (ob && !random(10)) {
	 if(random(3*level/2) > ob->query_level()) {
	  say(cap_name+" looks mad and attacks "+ob->query_name()+"!\n");
	  attack_object(ob);
	 } else {
	  say(cap_name+" looks horrified and flees "+ob->query_name()+"!\n");
	  move_away();
  	 }
	}
    }
    busy_catch_tell = 0;
    if (arg) { tell_object(arg, str + "" + the_text); }
}

query_hunter_list(string str, arg) {
  int i;
  if (arg) { return hunter_list; }
  if(!str) return;
  if(!hunter_list) {
	hunter_list = allocate(20);
  }
  while(i<sizeof(hunter_list)) {
    if(lower_case(str)==hunter_list[i]) {
	return 1;
    }
    i+=1;
  }
}

add_hunter_list(object ob) {
  int i;
  string str;
  if(!ob) return;
  if(!hunter_list) {
    hunter_list = allocate(20);
  }
  str = ob->query_name();
  while(i<sizeof(hunter_list)) {
    if(hunter_list[i] == lower_case(str)) { return; }
    if(!hunter_list[i]) {
        hunter_list[i] = lower_case(str);
	return;
    }
    i+=1;
  }
  hunter_list[random(20)] = lower_case(str);
}

remove_hunter_list(str) {
  int i;
  if (!hunter_list) { return; }
  if (!str) { return; }
  while(i<sizeof(hunter_list)) {
    if(hunter_list[i] == lower_case(str)) {
        hunter_list[i] = 0;
	return;
    }
    i+=1;
  }
}


follow(string str) {
    string tmp1,tmp2;
    object ob;
    if (sscanf(str, "%s leaves %s", tmp1, tmp2) == 2) {
        ob = find_player(lower_case(tmp1));
        if (!ob || ob != attacker_ob || ob->query_link_dead()) { return; }
        call_out("follow_move",follow_time,ob);
    }
}

follow_move(object ob) {
  object room;
  room = environment(ob);
  if(file_name(room)[0..8] != "/wizards/" &&
     file_name(room)[0..9] != "/room/out/") {
     call_out("follow_move", follow_time, ob);
     return;
  }
  move_player("after " + ob->query_name(), room);
  attack_object(ob);
}


/*
 * Call the following functions to setup the monster.
 * Call them in the order they appear.
 */

set_name(n) {
    name = n;
    set_living_name(n);
    alignment = 0;              /* Neutral monster */
    al_aggr = 90+random(60);
    cap_name = capitalize(n);
    short_desc = cap_name;
    long_desc = "You see nothing special.\n";
}


updatee_stats() {
    set_str(Str); set_dex(Dex); set_con(Con); set_int(Int); set_wis(Wis);
    set_size(size);
}

no_money() {
  no_money = 1;
}

set_level(int ll) {
    int i,ii,l,res, tmp_hp;
    int money, money_type;
    /* turbo monster chance 1.3.2001 //Celtron */
    if(!random(50)) ll += ll / 3;
    level = ll;
    l = ll * 5/2+10;
    if(ll>20) {
      l = (random(6)+(ll-18))*4+40;
    }
    Str = l+l/3; Int = l; Con = l+l/2; Dex = l; Wis = l;

/* Kattoo jos mokolla on race ni muuttaa stattei sen mukaan. Ona 22.9.98*/
    if (race) {
      Str = Str * call_other("/obj/race_selection","get_stats",race,"str")/50;
      Dex = Dex * call_other("/obj/race_selection","get_stats",race,"dex")/50;
      Con = Con * call_other("/obj/race_selection","get_stats",race,"con")/50;
      Int = Int * call_other("/obj/race_selection","get_stats",race,"int")/50;
      Wis = Wis * call_other("/obj/race_selection","get_stats",race,"wis")/50;
    }
    if (Str < 2) { /* Eli jos mokolla ei ollu mitaan player racee.. */
      Str = l+l/3; Int = l; Con = l+l/2; Dex = l; Wis = l;
    }
    size = level * 2 + 10;
    if(size>80) {
        size -= 80;
        size = size / 4;
        size += 80;
	if(size > 200) size = 200;
    }
    updatee_stats();
    weapon_class = level * 2;
    armour_class = level;
    hit_point = call_other("/obj/monster_data","get_hp",level);
    max_hp = hit_point;

    spell_points = max_hp;
    max_sp = spell_points;
    endurance_points = max_hp * 3 / 2;
    max_ep = endurance_points;

    experience = (75+query_max_hp()/100)*query_max_hp()+300*query_str();
    experience = (experience * 5) / 4;

/* expantaittokaava, ettei tuu mitaan alyttomia maaria */
    if(experience > 5000000)
      experience = 5000000 + (experience-5000000) / 5;

    if(!animal || no_money) {
      i = random(level/2)+level/2;
      money_type = random(6)+1;
      if(money_type < 1) money_type = 1;
      money = (random(4000) + 5000 + i * 500);
      i = 0;
      while(i < money_type) {
     	money = money / 10;
      	i += 1;
      }
      if (money && !no_money) { add_money(money/3*2, money_type); }
    }

    /* element resists by level */
    random_resists();

    set_skills("attack", level *10);
    set_skills("doublehit", level * 2 - 15);
    set_skills("critical", level * 2 - 30);
    set_skills("bare hands", level*10);
    set_skills("bludgeons", level * 5);
    set_skills("axes", level * 5);
    set_skills("blades", level * 5);
    set_skills("pound", level * 3);
    set_skills("slash", level * 3);
    set_skills("cut", level * 3);
    set_skills("dodge", level * 2 - 20);
    set_skills("parry", level * 2 - 30);
    set_skills("foresee attack", level*2-40);
    set_skills("stun", level * 3);
    set_skills("inner strength", level * 2 - 10);
    set_skills("two weapons combat", level * 2 - 5);
    set_skills("stunned maneuvers",level*2-10);
    set_skills("weapon parry",level*3-10);
    set_skills("shield parry",level*3-10);
    set_skills("find weakness",level*2-10);
    set_skills("kick", level * 10);
    set_skills("strike", level * 2);
    set_skills("agility", level*2-20);
    set_skills("ignore wrong strike",level*2-60);
    set_skills("deceived attack",level*2-60);
    set_skills("throw weight",level*2-10);
    set_skills("shield bash",level*2);
    set_skills("counter spell", level*2-60);

    set_skills("evading thought", level*2);
    set_skills("mental block", level*2);

    set_random_pick(20);
    random_combat_tactic();
}

random_resists(int lev) {
  int i,ii;
  if(!lev) lev = query_level();
    if (random(lev)+lev/4 > 15) {
      i = random(3) + 1;
      set_resists(i, 70+random(30));
    }
    if (random(lev)+lev/4 > 50) {
      ii = random(3) + 1;
      while(ii == i) {
        ii = random(3);
      }
      set_resists(ii, 70+random(30));
    }

    i = 1;
    while(i<m_sizeof(resists)) {
      if(query_resists(i) == 0) {
        set_resists(i, random(lev/3)+lev/3);
      }
      i += 1;
    }
}

random_combat_tactic() {
  string str;
  if(!random(2)) str = "torso";
  if(!random(2)) str = "head";
  else str = "legs";
  combat_tactic += (["hit":str]);
}

set_special(i) { special_chance = i; }
set_follow(f,i) { follow_time = i; follow_chance = f; }
/* Optional */
set_alias(a) { alias = a; }
/* Optional */
set_alt_name(a) { alt_name = a; }

set_alt_alias(a) { alt_alias = a; }

set_race(r) { race = r; }

set_mage(int m, int cast_frequency) {
  int alt_level;
  alt_level = level;
  if(!m) m = 1;
  level = level*m;

  set_skill("chanting", level*2);
  set_skill("mana control", level*3);
  set_skill("cast essence", level*3);
  set_skill("cast bolt", level*3);
  set_skill("cast fire", level*3);
  set_skill("cast ice", level*3);
  set_skill("cast electric", level*3);
  set_skill("cast earth", level*3);

  set_skill("knowledge of heat", level*2);
  set_skill("lore of cold", level*2);
  set_skill("theory of electricity", level*2);

  set_skill("power focusing", level*2);
  set_skill("power concentration", level*2);
  set_skill("power channeling", level*2);

  level = alt_level;

  set_int(query_int() * 3);

  mage = m;

  if(!m) alt_level = 0;
  else if(!cast_frequency) alt_level = 80;
  else alt_level = cast_frequency;

  if(!random(2)) set_spell_chance(alt_level, "exs fla blt");
  else 		 set_spell_chance(alt_level, "exs brr blt");

  if(!random(3)) set_spell_chance(alt_level, "exs sol blt");
  if(!random(3)) set_spell_chance(alt_level, "exs zzt blt");
}

query_sp_boost() {
  return level * 5;
}

/* optional */
set_max_hp(hp) { max_hp = hp; hit_point = hp; }
/* optional. Can only be lowered */
set_exp(exp) { experience = exp; }
/* optional */
set_al(al) { alignment = al; }
/* optional */
set_short(sh) { short_desc = sh; long_desc = short_desc + "\n";}
/* optional */
set_long(lo) { long_desc = lo; }
/* optional */
set_animal() {
animal = 1;
set_skill("stomp", level);
set_skill("bite", level);
set_skill_chance("stomp", level/2);
set_skill_chance("bite", level/2);
no_money();
}
set_ac(ac) { armour_class = ac; }
set_wc(wc) { if (animal) { weapon_class = wc; } }
/* optional */
set_move_at_reset() { move_at_reset = 1; }
set_move_at_random(time) { move_at_random = time; }
set_regen(r) { regen = r; }
set_extra(e) { extra = e; }
set_infravis(i) { infravis = i; }
set_log() {

  set_skills("reflect spell", level*2-30);
  kill_log = 1;
  Str = Str *4;
  set_max_hp(query_max_hp()*8);
  set_hp(query_max_hp());
  experience -= experience /4;
  random_resists(query_level()+10);
  counter = "all";
  /* maxx 100%. //Celtron */
  set_skill("counter spell", query_skills("counter spell") *2);
}

query_kill_log() { return kill_log; }
query_log() { return kill_log; }


/* optional
 * 0: Peaceful.
 * 1: Attack on sight.
 */

set_aggressive(a) { aggressive = a; }

int query_aggressive() { return aggressive; }

set_skills(num,pros, arg) {
  return set_skill(num,pros, arg);
}
set_undead() {
  set_resists("asphyxiation", 100);
  set_resists("poison", 100);
  set_resists("psionic", 100);
  undead = 1;
}
query_undead() {
  return undead;
}
set_no_corpse(i) {
  no_corpse = i;
}

query_no_corpse() {
  if (undead) { return 1; }
  if (no_corpse) { return 1; }
}

set_skill(string num, int pros, status force_over_100) {
  int tmp;
  if(!intp(pros) || intp(num)) {
    return;
  }
  if (pros < 0) { pros = 0; }
  if(!force_over_100 && pros > 100) { pros = 100; }
  if(!skills[num]) skills += ([ num:pros ]);
  else skills[num] = pros;
}

set_resists(mixed pref, int num) {
  if(num < 0) { num = 0; }
  if(num > 100) { num = 100; }
  if(intp(pref)) pref = call_other("/obj/resists", "resist_names", pref);
  resists += ([ (string) pref : (int) num ]);
}

set_al_aggr(arg) {
  al_aggr = arg;
}

check_al_aggr(player, arg) 
{

if(player->query_level() < 70) { return 0; } 

  if (alignment < 0 && player->query_alignment() > 10) {
        if (player->query_alignment() - alignment > al_aggr && !random(3)) {
	  if (arg && !animal)
            tell_object(player, capitalize(this_object()->query_name()) + " gives you an evil grin and attacks!\n");
          return 1;
        }
  }

  if (alignment > 0 && player->query_alignment() < -10) {
        if (alignment - player->query_alignment() > al_aggr && !random(3)) {
	  if (arg && !animal) {
            tell_object(player, capitalize(this_object()->query_name()) + " looks disgusted at your sight and attacks!\n");
	  }
          return 1;
        }
  }
}

query_resists(mixed pref) {
  if(intp(pref)) pref = call_other("/obj/resists", "resist_names", pref);
  return resists[pref];
}

/*
 * Now some functions for setting up spells !
 * The percent chance of casting a spell.
 */
set_spell_chance(int c, string wr) {
    string old_spell_words;
    int i;
    spell_chance = c;
    if (!spell_words) {
	spell_words = allocate(1);
	spell_words[0] = wr;
	return;
    }
    old_spell_words = spell_words;
    spell_words = allocate(sizeof(spell_words)+1);
    while(i<sizeof(old_spell_words)) {
	spell_words[i] = old_spell_words[i];
	i += 1;
    }
    spell_words[i] = wr;
}

set_skill_chance(string sk, int sc) {
  string tmp;
  int tmp2,i;
  if(!skill_chance) {
    skill_chance = allocate(1);
    use_skill = allocate(1);
  }
  tmp2 = skill_chance;
  tmp = use_skill;
  i = sizeof(use_skill);
  i += 1;
  skill_chance = allocate(i);
  use_skill = allocate(i);
  i = 0;
  while(i<sizeof(tmp2)) {
    skill_chance[i] = tmp2;
    use_skill[i] = tmp;
    i += 1;
  }
  skill_chance[i] = sc;
  use_skill[i] = sk;
}
/* Message to the victim. */
set_spell_mess1(m) {
    spell_mess1 = m;
}
set_spell_mess2(m) {
    spell_mess2 = m;
}
set_spell_dam(d) {
    spell_dam = d;
}

/* Set the frog curse. */
set_frog() {
    frog = 1;
}

/* Set the whimpy mode */
set_whimpy() {
    whimpy = 1;
}

set_block_dir(d) {
    block_direction = d;
}

/*
 * Force the monster to do a command. The force_us() function isn't
 * always good, because it checks the level of the caller, and this function
 * can be called by a room.
 */
init_command(cmd) {
    command(cmd, this_object());
}

load_chat(chance, strs) {
    sizeof(strs);               /* Just ensure that it is an array. */
    chat_head = strs;
    chat_chance = chance;
}

/* Load attack chat */

load_a_chat(chance, strs) {
    sizeof(strs);               /* Just ensure that it is an array. */
    a_chat_head = strs;
    a_chat_chance = chance;
}

/* Catch the talk */

set_match(ob, func, type, match) {
    object old;

    if (sizeof(func) != sizeof(type) || sizeof(match) != sizeof(type))
        return;
    talk_ob = ob;
    talk_func = func;
    talk_type = type;
    talk_match = match;
    say("talk match length " + sizeof(func) + "\n");
}

set_dead_ob(ob) {
    dead_ob = ob;
}

second_life() {
  string cre,str;
  object p_ob, members;
  int i;
  if(query_npc() && kill_log && attacker_ob && !attacker_ob->query_wiz()) {
    str = ctime(time())+" "+short()+" ("+file_name(this_object())+", "+query_level()+
	") killed by "+attacker_ob->query_name()+" ("+attacker_ob->query_level()+") ";
    if (attacker_ob->query_leader_ob()) {
      p_ob = present("party object", attacker_ob->query_leader_ob());
      if (p_ob && p_ob->query_members()) {
        str += "(";
        members = p_ob->query_members();
        while(i<sizeof(members)) {
          if (members[i]) { str += members[i]->query_name(); }
          if (i+1 != sizeof(members)) { str = str + ", "; }
	  i += 1;
        }
        str += ")";
      }
    }
    str += "\n";
    log_file("MONSTER_KILLED", str);
    cre = creator(this_object());
    if(cre) log_file(cre, str);
  }
  if(dead_ob)
    return call_other(dead_ob,"monster_died",this_object());
}

set_random_pick(r) {
    random_pick = r;
}

pick_any_obj() {
    object ob;
    int weight;

    if (this_object()->query_animal()) { return; }
     if(this_object()->query_dragonists()) { return; }
    ob = first_inventory(environment(this_object()));
    while(ob) {
        if (call_other(ob, "get", 0) && call_other(ob, "short")
		&& !ob->query_corpse()) {
            weight = call_other(ob, "query_weight", 0);
            if (!add_weight(weight)) {
                say(cap_name + " tries to take " + call_other(ob, "short", 0) +
                    " but fails.\n");
                return;
            }
            move_object(ob, this_object());
            say(cap_name + " takes " + call_other(ob, "short", 0) + ".\n");
            if (call_other(ob, "query_wc", 0))
                call_other(ob, "wield", call_other(ob,"query_name"));
            else if (call_other(ob, "query_ac", 0))
                call_other(ob, "wear", call_other(ob,"query_name"));
	    return;
        }
        ob = next_inventory(ob);
    }
}

set_init_ob(ob) {
    init_ob = ob;
}

init() {
    int i;
    create_room = environment(me);
    if(this_player() == me)
        return;
    if(init_ob)
        if(call_other(init_ob,"monster_init",this_object()))
            return;
    if (attacker_ob) {
        set_heart_beat(1); /* Turn on heart beat */
    }
    if(this_player() && !call_other(this_player(),"query_npc")) {
        set_heart_beat(1);
        if((aggressive == 1 || check_al_aggr(this_player())) && !this_player()->query_invisible()) 
	   {
	     if(!this_player()->query_wiz())
		{
		kill_ob = this_player();
		}
		else
		{
		 write(this_object()->query_name()+" trembles before your "+
			"immortal spirit and dares not attack.\n");
		}
	    }

    }
    if (block_direction) {
        add_action("block_move", block_direction);
    }
    add_action("kill", "monster_kill");
}

kill(str) {
  object ob;
  if(!str) { return; }
  if(!this_player()->query_wiz()) {
    return;
  }
  ob = present(str);
  if(!ob) { return; }
  attack_object(ob);
  write("Attacking "+str+"\n");
  return 1;
}

set_block_message(str) {
    block_message = str;
}

block_move() {
    if (block_message) 
    {
        write(block_message + "\n");
        return 1;
    }

    if(!this_player()->query_wiz())
    {
    write(capitalize(this_object()->query_name()) + " blocks your way.\n");
    return 1;
    }

    write(capitalize(this_object()->query_name()) + " stands aside, "+
		"recognizing your immortal spirit.\n");

}

query_create_room() { return create_room; }

query_race() { return race; }

query_animal() { return animal; }
test_match(str) {
    string who, str1, type, match, func;
    int i;

    while(i < sizeof(talk_match)) {
        if (talk_type[i])
            type = talk_type[i];
        match = talk_match[i];
        if (match == 0)
            match = "";
        if (talk_func[i])
            func = talk_func[i];
        if (sscanf(str,"%s " + type + match + " %s\n",who,str1) == 2 ||
           sscanf(str,"%s " + type + match + "\n",who) == 1 ||
           sscanf(str,"%s " + type + match + "%s\n",who,str1) == 2 ||
           sscanf(str,"%s " + type + " " + match + "\n",who) == 1 ||
           sscanf(str,"%s " + type + " " + match + " %s\n",who,str1) == 2)
        {
            return call_other(talk_ob, func, str);
        }
        i += 1;
    }
}

/*
 * The monster will heal itself (slowly?). ;)
 */
query_regen(int i) {
  int tmp;
  if(!regen && !i) return "Normal regen (0->max in 60mins. max 700)";
  if(!regen) tmp = i / 120;
  if(tmp > 700) tmp = 700;
  if(tmp) return tmp;
  return regen;
}

heal_slowly() {
  healing = 1;
  if (this_object()->query_resist_heal()) {
    call_out("heal_slowly", 30);
    return 0;
  }
  hit_point += query_regen(query_max_hp());
  if (hit_point > max_hp) hit_point = max_hp;
  spell_points += query_regen(query_max_sp());
  if (spell_points > max_sp) spell_points = max_sp;
  endurance_points += query_regen(query_max_ep());
  if (endurance_points> max_ep) endurance_points = max_ep;
  if (hit_point < max_hp || spell_points < max_hp)
    call_out("heal_slowly", 30);
  else
    healing = 0;
}


set_antiobjects() {
  object ob, antio;
  int i;
  ob = all_inventory(this_object());
  if (!ob) { return; }
  while(i < sizeof(ob)) {
    antio = clone_object("/obj/antiobject");
    move_object(antio, ob[i]);
    antio->init_antiobject(ob[i]);
    i += 1;
  }
}

status query_monster() { return 1; }
