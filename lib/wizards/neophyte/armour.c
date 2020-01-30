#include "/sys/ansi.h"

#define SUBTYPES "/daemons/armour_sub_types"
#define MATERIAL_D "/wizards/neophyte/material_d"
int class, misc_eq, ac;
string wiz_flag;
static string color;

mapping stats;		// statbonuses
string *resists; 	// ({ pref, amount [0,100], }) one pref per item

/* Must be static if we want to save_object some special items */
static int worn;
static object worn_by;
mapping skill_bonus;
string name, alias, short_desc, long_desc, value, weight;
string slot, sub_type, drop_str, additional_desc;
string race_only;
query_name() { if (!sub_type) { return name; } return sub_type; }
query_worn() { return worn_by; }
query_value() { return value; }
query_armour() { return 1; }

reset(arg) {
  if(arg)
    return;
  skill_bonus = ([ ]);
  stats = ([ ]);
  this_object()->start();
}

init() {
    add_action("wear", "wear");
    add_action("remove", "remove");
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

short() {
  string keep, tmp;
  keep = "";
  if(environment(this_object()) && environment(this_object())->query_keep(this_object()))
    keep = " [keep]";
  tmp = color;
  if(!tmp) tmp = "";
  else {
    if(this_player()->query_terminal() && color)
      tmp = color_for_short(color);
    tmp = " "+tmp;
  }
  return short_desc+tmp+keep;
}

long(str) {
  write(long_desc);
}

id(str) {
  string tmp1,tmp2;
  if (sub_type) {
    if(sscanf(sub_type, "%s %s", tmp1, tmp2)) { }
  }
  return str == name || str == alias || str == sub_type ||
	str == tmp1 || str == tmp2;
}

query_ac() {
  return ac;
}
armour_class() {
  return ac;
}
query_slot() { return slot; }

display_msg(str) {
  object ob, obj;
  int i;
  if(!str) {
    write("Wear what?\n");
    return 1;
  }
  obj = present(lower_case(str), this_player());
  if (!obj) {
    write("Wear what?\n");
    return 1;
  }
  if(obj != this_object()) { return; }
  if (!slot) {
    write("BUG! This eq has no slot!\n");
    return 0;
  }
  if (environment() != this_player()) {
    write("You must get it first!\n");
    return 1;
  }
  if (worn) {
    write("You already wear it!\n");
    return 1;
  }
}


wear(str) {
  object ob;
  int i, done;
  ob = call_other("/daemons/filter", "EQ_FILTER", str, this_player());
  if(!ob) {
    display_msg(str);
    return 1;
  }
  while(i<sizeof(ob)) {
    if(ob[i]->query_slot() && !ob[i]->query_worn()) {
		if(race_only != this_player()->query_race()) {
			write("You can't wear it!\n");
			return 1;
		}
    	ob[i]->do_wear();
	done = 1;
    }
    i += 1;
  }
  if(!done) write("Nothing to wear.\n");
  return 1;
}

do_wear() {
  object ob;
  int i;
  ob = call_other(this_player(), "wear", this_object());
  if(ob) {
    worn_by = this_player();
    worn = 1;
    this_player()->update_stats();
    if(!ac) ac = 1;
    while(i<sizeof(stats)) {
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
  write("You already have a " + slot + " slot eq worn.\n");
  return 1;
}

make_skill_shadow() {
  object ob;
  ob = this_player()->query_skill_shadow();
  if(!ob) ob = clone_object("/daemons/skill_shadow");
  ob->add_skill_bonus(this_player(),skill_bonus);
}

get() { set_wiz_flag(); return 1; }

stop_wearing(silently) {
 if (worn) {
   if (worn_by)
     call_other(worn_by, "stop_wearing",short_desc,silently);
   worn = 0;
   worn_by = 0;
   if (!silently)
     tell_object(environment(this_object()),"You drop your worn armour.\n");
   if(worn_by) worn_by->update_stats();
 }
}

drop() {
  if(sizeof(m_values(stats))) {
    if(this_player()->query_wiz()) write("EQtrack update.\n");
    call_other("/std/eq_track", "add_armour_data", this_object());
  }
  return 0;
}

remove(str,arg) {
  object obj;
  if(!arg) {
    if(!str) {
      write("Remove what?\n");
      return 1;
    }
    obj = present(lower_case(str), this_player());
    if (!obj) {
        write("Remove what?\n");
        return 1;
    }
    if(obj != this_object()) { return; }
  }
  if (!worn) {
    if(!arg) write("You are not wearing it.\n");
    return 1;
  }
  call_other(worn_by, "stop_wearing",short_desc);
  worn_by = 0;
  worn = 0;
  this_player()->fix_ac();
  this_player()->update_stats();
  return 1;
}

query_weight() { return weight; }

string *query_resists() {
  return resists;
}

query_stats(sta) {
  if (stats) { return stats[sta]; }
  return 0;
}

set_wiz_flag() {
  if(!this_player()->query_wiz() || this_player()->query_wiz() > 2) return;
  if(!wiz_flag) wiz_flag = "";
  wiz_flag += this_player()->query_name()+
        " "+file_name(previous_object())+". ";
}

void set_resists(mixed pref, int num) {
  if(intp(pref)) pref = call_other("/obj/resists", "resist_names", pref);
  if(num < 0) { num = 0; }
  if(num > 80) { num = 80; }
  resists = ({ (string) pref, (int) num, });
}

void clear_stats() {
  stats = ([ ]);
  resists = 0;
}

set_stats(string st, nu) {
  if(nu > 30 || nu < -30) return;
  if(!st || intp(st)) return;
  st = lower_case(st);
  if(st == "spr") st = "spregen";
  stats[st] = nu;
  if(st == "ac") calculate_ac();
  do_color();
}

set_skill_bonus(skill,pros) {
  if(pros > 15) log_file("SKILL_EQ", ctime(time())+" "+file_name(this_object())+"\n");
  skill_bonus += ([ skill:pros ]);
}
set_id(n) { name = n; }
set_name(n) { name = n; }
set_short(s) { short_desc = s; long_desc = s + ".\n"; }
set_long(s) { long_desc = s + ".\n"; }
set_value(v) { if (!misc_eq) return; value = v; }
force_set_value(v) { value = v; }
set_weight(w) { if (!misc_eq) return; weight = w; }

/* Just to prevent old misc eq from bugging.. */
set_ac() { return; }

set_slot(sl) {
   misc_eq = 1;
   slot = sl;
}

set_alias(a) { alias = a; }
set_arm_light(l) { set_light(l); }

set_sub_type(string str) {
  if (misc_eq) { return 1; }
  if (!call_other(SUBTYPES,"query_number",str,"ac")) {
    sub_type = "illegal sub type";
    short_desc = "illegal sub type armour";
    name = str;
    return 1;
  } else {
    sub_type = str;
    name = str;
  }
  get_slot();
  calculate_weight();
  calculate_ac();
  calculate_value();
  do_short();
  do_long();
}

set_class(c) {
  if(c<1||c>12) return;
  class = c;
}
set_race_only(string str) { race_only=str; }
calculate_ac() {
  int i;
  ac = call_other(SUBTYPES, "query_number", sub_type, "ac") + (class - 6)*2;
  if(ac > 120) ac = 120;
}

calculate_weight() {
  int w, base_weight;
  base_weight = 7;
  if(slot == "helm") w = 18 * base_weight;
  if(slot == "hands") w = 7 * base_weight;
  if(slot == "arms") w = 11 * base_weight;
  if(slot == "legs") w = 13 * base_weight;
  if(slot == "feet") w = 5 * base_weight;
  if(slot == "torso") w = 50 * base_weight;
  w=(call_other(SUBTYPES, "query_number", sub_type,"weight")*w)/(20+class);
  weight = w;
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

do_short() {
  string str, vo, last_letter, color;
  str = call_other(SUBTYPES,
	"query_type",class,sub_type);
  str = str+" "+sub_type;
  if (additional_desc) { str = " "+additional_desc+str; }

  vo = extract(str, 1, 1);
  last_letter = extract(str, (strlen(str)-1),(strlen(str)-1));

  if (last_letter != "s") {
    if (vo == "i" || vo == "a" || vo == "o" || vo == "e" ||
        vo == "u" || vo == "y")
          str = "An"+str;

    else str = "A"+str;
  } else {
    str = extract(str, 1, strlen(str));
    str = capitalize(str);
  }
  short_desc = str;
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

do_long() {
  long_desc = call_other(SUBTYPES, "query_sub_long", sub_type);
  if (!long_desc) long_desc = short_desc+"\n";
}

get_slot() {
  slot=call_other(SUBTYPES,"query_number",sub_type,"slot");
}

string query_long() { return long_desc; }
