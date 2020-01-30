#define BASE_WEAPON_WEIGHT 100

int class_of_weapon, value, weight, class;
int in_keep;
static object wielded_by;
string short_desc, long_desc, additional_desc;
mapping stats;
string slot, weapon_type, sub_type, name, alias;
string wiz_flag;

query_sub_type() { return sub_type; }
query_name() { return sub_type; }
query_wc() { return class_of_weapon; }
query_wielded() { return wielded_by; }
query_weapon() { return 1; }
query_damage(string type) {
  return call_other("/obj/weapon_sub_types", "query_damage_amount", sub_type, type);
}

reset(arg) {
  if (arg)
    return;
  stats = ([ ]);
  this_object()->start();
}

init() {
    add_action("wield", "wield");
    add_action("unwield", "unwield");
}

wield(str) {
    object obj;
    int c_str;
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
    if (can_wield(c_str) == 0) {
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
    if(this_player()->query_right_weapon() && this_player()->query_skills("two weapons combat")) {
      if(this_player()->query_limb("left arm")) return 0;
      if(this_player()->query_left_weapon()) {
	write("You already have a weapon in your left hand.\n");
	return 1;
      }
      if(can_wield(c_str/2) == 1) {
        set_slot("left hand");
        this_player()->wield(this_object());
        return 1;
      } else {
        write("You can only wield light weapons in your left hand.\n");
        return 1;
      }
    } else if(this_player()->query_right_weapon()) {
      write("You are already wielding a weapon in your right hand.\n");
      return 1;
    }
    /* process wield in right hand | in both hands */
    if(this_player()->query_limb("right arm")) return 0;
    if (can_wield(c_str) == 2) {
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
  tmp = m_values(stats);
        while(i<sizeof(tmp)) {
          if(this_object()->query_stats(i) > 40) {
                log_file("ILLEGAL_EQ", ctime(time())+
                " "+this_player()->query_name()+" "+short_desc+" "+
                file_name(this_object())+" "+i+": "+
                this_object()->query_stats(i)+"\n");
          }
          i += 1;
        }
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

unwield(str) {
  object ob;
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
  if (query_wielded()) {
    write("You unwield your " + query_name() + ".\n");
    this_player()->stop_wielding(this_object());
    wielded_by = 0;
    return 1;
  } else {
    write("You are not wielding it.\n");
    return 1;
  }
  return 1;
}

short() {
  string desc;
  desc = short_desc;
  if (in_keep) { desc += " [in keep]"; }
  return desc;
}

long(str) {
  write(long_desc);
}

weapon_class() {
  return class_of_weapon;
}

query_shield_factor() {
  return class_of_weapon;
}

query_hit_bonus(int str) {
  int hb;
  /* hb = [-20,20] */
  hb = call_other("/obj/weapon_sub_types", "query_hit_bonus", sub_type);
  hb += call_other("/obj/weapon_sub_types", "query_bonus", "hit", stats["hit"]);
  /* hb = [-28,30] */
  hb += (class-4)*2;
  hb -= weight/(str+100);
  return hb;
}

id(str) {
  string tmp1,tmp2;
  if(sscanf(sub_type, "%s %s", tmp1, tmp2)) { }
  return str == name || str == alias || str == sub_type ||
        str == tmp1 || str == tmp2 || str == lower_case(weapon_type);
}

set_keep() {
   if (in_keep) { in_keep = 0; return; }
   if (!in_keep) { in_keep = 1; return; }
}

keep() { return in_keep; }

drop(silently) {
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
can_wield(int str) {
  if(str > weight/10) return 1;
  if(str > weight/50) return 2;
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
query_stats(sta) {
  if(stats) {
    return call_other("/obj/weapon_sub_types", "query_bonus", sta,stats[sta]);
  }
}
set_stats(string st, nu) { 
  /* st = 1.Str 2.Dex 3.Con 4.Int 5.Wis 6.Hpregen 7.Spregen, hit, damage
     nu = how much 
  */
  if(nu > 10 || nu < -10) return;
  st = lower_case(st);
  if(st == "spr") st = "spregen";
  if(st == "hpr") st = "hpregen";
  stats[st] = nu; 
  if(st == "damage") calculate_wc();
}

set_sub_type(string s) {
  int i;
  i = call_other("/obj/weapon_sub_types", "valid_type", s);
  weapon_type = weapon_names(i);

  if(!i) {
    sub_type = "illegal sub type";
    return;
  } else {
    sub_type = s;
    name = s;
  }
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
  int w;
  if(weapon_type == "bludgeon") w = 100;
  if(weapon_type == "axe") w = 70;
  if(weapon_type == "blade") w = 50;
  if(weapon_type == "shield") w = 80;
  w += call_other("/obj/weapon_sub_types", "query_damage_bonus", sub_type)*w/50;
  w -= class*2;
  weight = w*BASE_WEAPON_WEIGHT/10;
}
calculate_wc() {
  int c;
  c = 50;
  /* [35,80] */
  c += (class-3)*5;
  /* ([35,80] + [40,80]) / 2 + [-5,5] = [27,85] */
  c = (c + 60+call_other("/obj/weapon_sub_types", "query_damage_bonus", sub_type))/2
	+cc) long_desc = "It's of type "+weapon_type+".\n";
  else long_desc = long_desc + "It's of type "+weapon_type+".\n";
}

/* Old weapon funcs, just not to bug old weapons */

set_wc() {
  old_weapon();
}
set_short(s) {
  short_desc = s;
}
set_long(l) {
  long_desc = l;
}
set_value() { old_weapon(); }
set_weight() { old_weapon(); }
set_weapon_type() { old_weapon(); }
set_material() { old_weapon(); }
set_name(s) { name = s; }
set_alias(s) { alias = s; }

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
