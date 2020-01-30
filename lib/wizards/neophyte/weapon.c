#include "/sys/ansi.h"
#define BASE_WEAPON_WEIGHT 300
#define SUBTYPES "/wizards/neophyte/weapon_sub_types"
#define MATERIAL_D "/wizards/neophyte/material_d"
#define SIZE_D "/wizards/neophyte/size_d"

int class_of_weapon, value, weight, class, length, to_hit, to_damage, damage_chance;
static object wielded_by;
static int max_dur, dur;
static string color;
string short_desc, long_desc, additional_desc;
string slot, weapon_type, sub_type, name, alias, label, material;
string wiz_flag, damage_type;
string slayer;
mapping stats;

reset(arg) {
  if (arg)
    return;
   stats = ([ ]);
  this_object()->start();
  if(query_wc() > 55)
    call_other("/std/eq_track", "add_weapon_data", this_object());
}
init() {
    add_action("wield", "wield");
    add_action("unwield", "unwield");
}
/* Sets */
/* class,name,alias,desc,short,long,material,stats,dur,maxdur,tohit,todamage,slayer, subtype,label,wielder,wiz_flag,slot*/
set_class(c) {
  if(c<1||c>10) return;
  class = c;
}

set_name(s) { name = s; }

set_alias(s) { alias = s; }

set_desc(w) { additional_desc = w; }

set_short(s) {
  short_desc = s;
}

set_long(l) {
  long_desc = l;
}

set_material(string str) {
	if(!MATERIAL_D->get_valid_material(str)) {
		invalid_weapon("Invalid material");
		return 1;
	}
	material = str;
}

set_stats(string st, nu) {
  if(nu > 10 || nu < -10) return;
  st = lower_case(st);
  if (st != "str" && st != "dex" && st != "con" && st != "wis" && st != "int") return;
	stats[st] = nu;
}

void set_dur(int i, status arg) {
  dur = i;
  if(!arg && dur > max_dur) dur = max_dur;
}

void set_max_dur(int i) {
  max_dur = i;
  if(dur > max_dur) dur = max_dur;
}

set_to_hit(int i) { to_hit = i; }

set_to_damage(int i) { to_damage = i; }

set_slayer(string str) {
  if(!str) return 0;
  str = lower_case(str);
  if(file_size("/data/races/"+str) == -1) {
    if(!SUBTYPES->query_special_slayer(str))
      return 0;
  }
  slayer = str;
}

set_damage_type(string type, int chance) {
   invalid_weapon("set_damage_type is no longer in use");
}

set_sub_type(string s) {
  int i;
  i = call_other(SUBTYPES, "valid_type", s);
  weapon_type = weapon_names(i);

  if(!i) {
    sub_type = "illegal sub type";
    return;
  } else {
    sub_type = s;
    name = s;
  }
  if(!material) material = call_other(MATERIAL_D, "get_weapon_material", class);
  do_long();
  do_short();
  calculate_weight();
  calculate_value();
  calculate_wc();
  do_color();
}
void set_label(string str) {
	 label = str;
 }

set_wielder(object ob) { wielded_by = ob; }

set_wiz_flag() {
  if(!this_player()->query_wiz() || this_player()->query_wiz() > 2) return;
  if(!wiz_flag) wiz_flag = "";
  wiz_flag += this_player()->query_name()+
        " "+file_name(previous_object())+". ";
}

set_slot(sl) {
  slot = sl;
  wielded_by = this_player();
  log_check();
}
/* Querys */
query_slayer() {
  return slayer;
}
query_label() { return label; }
query_can_label() { return 1; }
query_dur() {
  return dur;
}

query_max_dur() {
  return max_dur;
}
query_damage_type() { return "physical"; }
query_sub_type() { return sub_type; }
query_name() { return sub_type; }
query_wc() { return class_of_weapon; }
query_wielded() { return wielded_by; }
query_class() { return class; }

query_weapon() { return 1; }
query_damage(string type) {
  return call_other(SUBTYPES, "query_damage_amount", sub_type, type);
}

query_stats(sta) { return stats[sta]; }
query_no_save(string arg) {
  if(arg != "recovery" && dur < max_dur) {
    write("Damaged weapons cannot be saved.\n");
    return 1;
  }
  return 0;
}
query_shield_factor() {
  return class_of_weapon;
}
query_wielder() { return wielded_by; }
query_value() {
    return value;
}
query_weight() { return weight; }
query_type() { return weapon_type; }
query_slot() { return slot; }
query_to_hit() { return to_hit; }
query_to_damage() { return to_damage; }
query_material() { return material; }
query_size() { return SIZE_D->get_weapon_size(class_of_weapon); }
string query_long() { return long_desc; }

query_hit_bonus(int str) {
  int hb, size;
  size = class*10;
  /* hb = [-2,2] */
  hb = call_other(SUBTYPES, "query_hit_bonus", sub_type);
  /* hb = [90,100] + [-40,40] = [50,140] */
  hb += class*3;
  hb -= this_player()->query_size()-size;
  if(hb < 20) { hb = 20; }
  return hb;
}

/*Misc*/
void repair_weapon(int i) {
  if(i) dur += i;
  else dur = max_dur;
  if(dur > max_dur) dur = max_dur;
}

check_weapon_break() {
  dur -= 1;
  if(dur < 0) {
    log_file("WEAPON_BREAK", ctime(time()) +" "+wielded_by->query_name()+" WEAPON: "+short()+" MAX_DUR: "+query_max_dur()+"\n");
    tell_object(wielded_by, "You hear a sickening crack as "+short()+" breaks!\n");
    wielded_by->stop_wielding(this_object());
    destruct(this_object());
  }
}
static log_check() {
  int i, tmp;
  if(wiz_flag && !this_player()->query_wiz())
    log_file("WIZ_EQ", ctime(time())+" "+this_player()->query_name()
    +" "+file_name(this_object())+" "+wiz_flag+"\n");
  return 1;
}
short() {
  string keep, tmp;
  keep = "";
  tmp = color;
  if(!tmp) tmp = "";
  else {
	  if(this_player()->query_terminal() && color)
	  tmp = color_for_short(color);
	  tmp = " "+tmp;
}
  if(environment(this_object()) && environment(this_object())->query_keep(this_object())) keep = " [keep]";
  return short_desc+tmp+keep;
}
long(str) {
  string tmp;
  tmp = "";
  tmp = short_desc+"";
  write(short_desc+"\n"+long_desc);
}

weapon_class() {
  return class_of_weapon;
}

id(str) {
  string tmp1, tmp2;
  if (sub_type) { if(sscanf(sub_type, "%s %s", tmp1, tmp2)) { } }
  return str == name || str == alias || str == sub_type || str == tmp1 || str == label || str == tmp2;
}
drop(silently, arg) {
    if (arg) { return 0; }
    if (wielded_by) {
        call_other(wielded_by, "stop_wielding", this_object());
        if (!silently)
            tell_object(previous_object(), "You drop your wielded weapon.\n");
	wielded_by->update_stats();
    }
    wielded_by = 0;
    return 0;
}
hit(attacker) {
    return 0;
}
can_wield(int str) {
  if(str > class_of_weapon) return 1;
  if(str < class_of_weapon) return 2;
  return 1;
}
get() { set_wiz_flag(); return 1; }

weapon_names(num) {
    if (num == 1) { return "bludgeon"; }
    if (num == 2) { return "axe"; }
    if (num == 3) { return "blade"; }
    if (num == 4) { return "shield"; }
    return "Illegal weapon type (range [1,4])";
}

weapon_types(str) {
    if (str == "bludgeon") { return 1; }
    if (str == "axe") { return 2; }
    if (str == "blade") { return 3; }
    if (str == "shield") { return 4; }
    return "Illegal weapon type (range [1,4])";
}

/*Calc*/
calculate_value() {
  int c;
  c = class*30; /* 10-300*/
  c = class*call_other(MATERIAL_D, "query_material_value", material); /*10-~3000*/
  value = c;
}
calculate_weight() {
  int tmp;
  tmp = call_other(SUBTYPES, "query_weapon_size", sub_type);
  tmp *= call_other(MATERIAL_D, "query_material_weight", material);
  tmp += BASE_WEAPON_WEIGHT;
  weight = tmp;
}
calculate_wc() {
  int c, tmp, i;
  /* c = [1,9]  */
  c = call_other(SUBTYPES, "query_damage_bonus", sub_type);
  /* tmp = ( [1,9] * 10) + class + 20 = [30,120] */
  tmp = c * 5 + (class*3) + 20;

  /* blunt (1): 30,80 blade (3): 50,110 axes (2): 60,140 */
  i = call_other(SUBTYPES, "valid_type", sub_type);
  if(i==1 && tmp>80) tmp = 65;
  if(i==2 && tmp>150) tmp = 100;
  if(i==3 && tmp>110) tmp = 80;

  class_of_weapon = tmp;
  /* durability set */
  max_dur = class*10+10;
  dur = max_dur;
}
invalid_weapon(string str) {
	if(!this_object()) return;
	call_out("self_dest", 1, str);
}

self_dest(string str) {
	write(str+".\n");
	destruct(this_object());
}
do_short() {
	if(!short_desc) {
		short_desc = "A ";
	if(additional_desc) short_desc += additional_desc+" ";
	short_desc += material+" ";
	short_desc += sub_type+"";
}
}

do_long() {
  string str;
  long_desc = call_other(SUBTYPES, "get_long_desc",this_object());
  if(!long_desc) long_desc = "It's of type "+weapon_type+" and its a "+call_other(SUBTYPES, "query_class_adjective", class)+" quality.\n";
  else long_desc = long_desc + "It's of type "+weapon_type+" and its a "+call_other(SUBTYPES, "query_class_adjective", class)+" quality.\n";
}

string color_for_short(string c) {
  string dim, vari;
  if(sscanf(c, "<%s %s glow>", dim, vari) == 2) { dim = dim + " "; }
  else if(sscanf(c, "<%s glow>", vari) == 1) { dim = ""; }
  c = vari;
  switch(c) {
    case "red": c = RED_F+c+OFF;
    case "yellow": c = YELLOW_F+c+OFF;
    case "blue": c = BLUE_F+c+OFF;
    case "green": c = GREEN_F+c+OFF;
    case "magenta": c = MAGENTA_F+c+OFF;
    case "white": c = BOLD+c+OFF;
  }
  c = "<"+dim+""+c+" glow>";
  return c;
}

do_color() {
  int f,m,r;
  f = query_stats("str") + query_stats("dex") + query_stats("con");
  m = query_stats("int") + query_stats("wis");
  r = query_stats("spregen");
  if(f>0) color = "blue glow>";
  if(r>0) color = "red glow>";
  if(m>0) color = "yellow glow>";
  if(m>0 && r>0) color = "magenta glow>";
  if(f>0 && m>0) color = "green glow>";
  if(f>0 && m>0 && r>0) color = "white glow>";
  f = f+m+r;
  if(!color) return;
  if(f < 11) color = "<dim "+color;
  else if(f > 25) color = "<bright "+color;
  else if(f > 10) color = "<"+color;
}

wield(str) {
    object obj;
    int c_str, size;
    if(!str) {
	write("Wield what?\n");
	return 1;
    }
    obj = present(lower_case(str), this_player());
    if (!obj) {
        write("Wield what?\n");
        return 1;
    }
    if(obj != this_object()) return;
    if (environment() != this_player()) {
        write("You must get it first!\n");
        return 1;
    }
    if (query_wielded()) {
        write("You are already wielding "+short()+"!\n");
        return 1;
    }
    c_str = this_player()->query_str();
    size = this_player()->query_size();
    if (can_wield(c_str, size) == 0) {
      write("This weapon is too big for you to wield.\n");
      return 1;
    }
    /* wield possible shield in left hand */
    if(query_type() == "shield") {
      if(this_player()->query_right_weapon()) {
        if(this_player()->query_right_weapon()->query_slot() == "both hands") {
          write("You are already wielding a weapon in both hands.\n");
          return 1;
        }
      }
      if(this_player()->query_left_weapon()) {
        write("You are already wielding something in your left hand.\n");
        return 1;
      }
      if(this_player()->query_limb("left arm")) return 0;
      set_slot("left hand");
      this_player()->wield(this_object());
      this_player()->update_stats();
      return 1;
    }
    /* wield in left hand */
    if(this_player()->query_right_weapon()) {
/* && this_player()->query_skills("two weapons combat")) { turha, kun molemmat hit% kurmauttuu enivei */
      if(this_player()->query_limb("left arm")) return 0;
      if(this_player()->query_left_weapon()) {
	write("You already have a weapon in your left hand.\n");
	return 1;
      }
      if(can_wield(c_str/2, size) == 1) {
        set_slot("left hand");
        this_player()->wield(this_object());
        this_player()->update_stats();
        return 1;
      } else {
        write("That weapon is too heavy for your left hand\n");
        return 1;
      }
    } else if(this_player()->query_right_weapon()) {
      write("You are already wielding a weapon in your right hand.\n");
      return 1;
    }
    /* process wield in right hand | in both hands */
    if(this_player()->query_limb("right arm")) return 0;
    if (can_wield(c_str, size) == 2) {
      if(this_player()->query_left_weapon()) {
        write("You don't have enough free limbs.\n");
        return 1;
      }
      set_slot("both hands");
      this_player()->wield(this_object());
      this_player()->update_stats();
    } else {
      set_slot("right hand");
      this_player()->wield(this_object());
      this_player()->update_stats();
    }
    return 1;
}

unwield(str, int arg) {
  object ob;
 if(!arg) {
  if(!str) {
    write("Usage: unwield <weapon>\n");
    return 1;
  }
  ob = present(str, this_player());
  if(!ob) {
    write("You don't have any "+str+".\n");
    return 1;
  }
  if(ob != this_object()) return;
 }
  if (query_wielded()) {
    write("You unwield your " + query_name() + ".\n");
    this_player()->stop_wielding(this_object());
    this_player()->update_stats();
    wielded_by = 0;
    return 1;
  } else {
    write("You are not wielding it.\n");
    return 1;
  }
  return 1;
}