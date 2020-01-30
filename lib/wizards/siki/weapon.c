#define BASE_WEAPON_WEIGHT 100  /* 0,5kg */
#define SUBTYPES "/daemons/weapon_sub_types"

int class_of_weapon, value, weight, class, damage_chance, forced2h=0;
static object wielded_by;
static int max_dur, dur;
string short_desc, long_desc, additional_desc;
string slot, weapon_type, sub_type, name, alias;
string wiz_flag;
string damage_type;
string slayer;

query_slayer() {
  return slayer;
}

void set_dur(int i, status arg) {
  dur = i;
  if(!arg && dur > max_dur) dur = max_dur;
}

void set_max_dur(int i) {
  max_dur = i;
  if(dur > max_dur) dur = max_dur;
}

void repair_weapon(int i) {
  if(i) dur += i;
  else dur = max_dur;
  if(dur > max_dur) dur = max_dur;
}

query_dur() {
  return dur;
}

query_max_dur() {
  return max_dur;
}

query_weapon_type() { return weapon_type; }

query_forced2h() { return forced2h; }
enable_forced2h() { forced2h=1; }
disable_forced2h() { forced2h=0; }

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
  damage_type = type;
  damage_chance = chance;
}
query_damage_type() {
  if(damage_chance > random(100))
    return damage_type;
  return "physical";
}
query_sub_type() { return sub_type; }
query_name() { return sub_type; }
query_wc() { return class_of_weapon; }
query_wielded() { return wielded_by; }

set_wielder(object ob) { wielded_by = ob; }

query_weapon() { return 1; }
query_damage(string type) {
  return call_other(SUBTYPES, "query_damage_amount", sub_type, type);
}

/* see if weapon breaks or not */
check_weapon_break() {
  dur -= 1;
  if(dur < 0) {
    log_file("WEAPON_BREAK", ctime(time()) +" "+wielded_by->query_name()+" WEAPON: "+short()+" MAX_DUR: "+query_max_dur()+"\n");
    tell_object(wielded_by, "You hear a sickening crack as "+short()+" breaks!\n");
    wielded_by->stop_wielding(this_object());
    destruct(this_object());
  }
}

set_stats() { } /* Ettei set_stattia callaavat asee bugais.. */

reset(arg) {
  if (arg)
    return;
  this_object()->start();
  if(query_wc() > 55)
    call_other("/std/eq_track", "add_weapon_data", this_object());
}

init() {
    add_action("wield", "wield");
    add_action("unwield", "unwield");
}

wield(str) {
    object obj;
    int c_str, size;
    write("Wield is disabled\nuse pwield instead!\n");
    return 1;
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
    } else {
      set_slot("right hand");
      this_player()->wield(this_object());
    }
    return 1;
}

static log_check() {
  int i, tmp;
  if(wiz_flag && !this_player()->query_wiz())
    log_file("WIZ_EQ", ctime(time())+" "+this_player()->query_name()
    +" "+file_name(this_object())+" "+wiz_flag+"\n");
  return 1;
}

set_wiz_flag() {
  if(!this_player()->query_wiz() || this_player()->query_wiz() > 2) return;
  if(!wiz_flag) wiz_flag = "";
  wiz_flag += this_player()->query_name()+
        " "+file_name(previous_object())+". ";
}

unwield(str, int arg) {
  object ob;
  write("unwield is disabled\nuse punwield instead!\n");
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
    wielded_by = 0;
    disable_forced2h();
    return 1;
  } else {
    write("You are not wielding it.\n");
    return 1;
  }
  return 1;
}

query_no_save(string arg) {
  if(arg != "recovery" && dur < max_dur) {
    write("Damaged weapons cannot be saved.\n");
    return 1;
  }
  return 0;
}

short() {
  string st, shape;
  shape = "";
  if(dur<max_dur/4) shape = " (badly damaged)";
  else if(dur<max_dur/2) shape = " (damaged)";
  else if(dur<max_dur) shape = " (slightly damaged)";

  if(query_dur() > query_max_dur()) shape = " {polished}";
  st = short_desc + shape;
  if(environment(this_object()) && environment(this_object())->query_keep(this_object()))
        st = st+" [keep]";
  return st;
}

long(str) {
  write(long_desc);
  if(slayer) write("A rune is carved to it: '"+slayer+"'\n");
}

weapon_class() {
  return class_of_weapon;
}

query_shield_factor() {
  return class_of_weapon;
}

/* [20,140] range */
query_hit_bonus(int str) {
  int hb;
  /* hb = [-2,2] */
  hb = call_other(SUBTYPES, "query_hit_bonus", sub_type);
  /* hb = [90,100] + [-40,40] = [50,140] */
  hb = (90+class) + (hb*20);
  /* weight = [100,800]? */
  /* 20kg ase & 100 str -> -25 hb. ^D^Dritapaus eli ei paljoo vaikutusta //Celtron */
  hb -= ( (weight/2) / (str+100) )*5;
  if(hb < 20) hb = 20;
  if(slot == "both hands")hb += 20;
  return hb;
}

id(str) {
  string tmp1,tmp2;
  if (sub_type) { if(sscanf(sub_type, "%s %s", tmp1, tmp2)) { } }
  return str == name || str == alias || str == sub_type ||
        str == tmp1 || str == tmp2 || str == lower_case(weapon_type);
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

query_wielder() { return wielded_by; }

hit(attacker) {
    return 0;
}

/* sets a slot when wielded */
set_slot(sl) {
  slot = sl;
  wielded_by = this_player();
  log_check();
}

/* returns 0 if cannot, 1 for 1h, and 2h for 2h */
/* str = [20,250] size = [25,100] */
can_wield(int str, int size) {
  str = str + size;
  if(str > weight/6) return 1;
  if(str > weight/30) return 2;
  return 0;
}

query_value() {
    return value;
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

query_weight() { return weight; }
query_type() { return weapon_type; }
query_slot() { return slot; }

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
  if(sub_type == "club" || sub_type == "staff") class = 0;
  calculate_weight();
  calculate_value();
  calculate_wc();
  do_short();
  do_long();
}
query_class() { return class; }
set_class(c) {
  if(c<1||c>12) return;
  if(sub_type == "club") return;
  if(sub_type == "staff") return;
  class = c;
}

set_desc(str) {
  additional_desc = str;
}

calculate_value() {
  int c,tmp;
  c = class;
  while(c) {
    c -= 1;
    tmp += tmp;
    tmp += 10;
  }
  value = tmp;
}

calculate_weight() {
  int w, tmp;
  if(weapon_type == "bludgeon") w = 100;
  if(weapon_type == "axe") w = 70;
  if(weapon_type == "blade") w = 50;
  if(weapon_type == "shield") w = 80;
  tmp = call_other(SUBTYPES, "query_damage_bonus", sub_type);
  /* w = (pros * (100 + [-20,20]*3)) * base = [50,100] * [40,160] *base = [2, 16]k * base */
  w = (w* (100 + tmp*3) ) * BASE_WEAPON_WEIGHT;
  /* class vaikuttaa [-20%max]. jakajana: k,classpros */
  w = w * (100 - class*2) / (1000*100);
  weight = w;
}

/* wc = [30,150] */
calculate_wc() {
  int c, tmp, i;
  /* c = [1,9]  */
  c = call_other(SUBTYPES, "query_damage_bonus", sub_type);
  /* tmp = ( [1,9] * 10) + class + 20 = [30,120] */
  tmp = c * 10 + class + 20;

  /* blunt (1): 30,80 blade (3): 50,110 axes (2): 60,140 */
  i = call_other(SUBTYPES, "valid_type", sub_type);
  if(i != 2) tmp = tmp*2/3;

  if(i==1) tmp += 10;
  else tmp += 30;

  /* just for sure. //Celtron */
  if(i==1 && tmp>80) tmp = 80;
  if(i==2 && tmp>150) tmp = 150;
  if(i==3 && tmp>110) tmp = 110;

  class_of_weapon = tmp;
  /* durability set */
  max_dur = class*10+10;
  dur = max_dur;
}

do_short() {
  string str, vo;
  str = call_other(SUBTYPES, "query_class_adjective", class);
  str = str+" "+sub_type;
  if (additional_desc) { str = " "+additional_desc+str; }

  vo = extract(str, 1, 1);
  if (vo == "i" || vo == "a" || vo == "o" || vo == "e" ||
      vo == "u" || vo == "y")
        str = "An"+str;

  else str = "A"+str;
  short_desc = str;
}

do_long() {
  long_desc = call_other(SUBTYPES, "get_long_desc",this_object());
  if(!long_desc) long_desc = "It's of type "+weapon_type+".\n";
  else long_desc = long_desc + "It's of type "+weapon_type+".\n";
}

set_name(s) { name = s; }
set_alias(s) { alias = s; }

set_short(s) {
  short_desc = s;
}

set_long(l) {
  long_desc = l;
}

/* Old weapon funcs, just not to bug old weapons */
/* Do not put any code under this line */

set_wc() {
  old_weapon();
}

set_value() { old_weapon(); }
set_weight() { old_weapon(); }
set_weapon_type() { old_weapon(); }
set_material() { old_weapon(); }

set_type() { old_weapon(); }

old_weapon() {
  if(!this_object()) return;
  call_out("dest",1);
}

dest() {
  if(this_player()->query_wiz()) {
  write("OLD WEAPON FUNCTIONS USED!\n");
  write("See /doc/build/weapon and fix "+file_name(this_object())+".\n");
  say("OLD WEAPON FUNCTIONS USED!\n");
  say("See /doc/build/weapon and fix "+file_name(this_object())+".\n");
  }
  destruct(this_object());
}

string query_long() { return long_desc; }
