inherit "/obj/weapon";
#define BOW_D "/wizards/siki/bow_d"

//NOSAVE LAPAT, arrow sun muut
static int reloaded;
static int arrow_dam, arrow_hit, arrow_crit, arrow_stun;
static string arrow_desc;
static string label;
static int durability;
static string aim_target;
static object wielded_by;

string short_desc, long_desc, missile_type, bow_type;
string slot, type;
string maker, crafted;
int weight, quality, base_damage, base_hit, shoot_time, reload_time, size;

short() {
  string tmp;
  tmp = "";
  tmp +=capitalize(short_desc);
  if(label)tmp += " named as '"+label+"'";
  if(reloaded)tmp += " (Reloaded)";
  if(environment(this_object()) && environment(this_object())->query_keep(this_object()))tmp += " [keep]";
  return tmp;
}
id(str) {
  return str == bow_type || str == label || str == short_desc;
}

long() {
	string tmp;
	tmp ="";
	tmp =short();
	tmp +="\n"+long_desc+"\n";
	tmp +="It is a "+crafted+" crafted "+short_desc+".\n";
	tmp +="It is made by "+maker+".\n";
	if(reloaded)tmp +=arrow_desc;
    write(tmp);
    if(this_player()->query_wiz()) {
	write("Base dam: "+base_damage+" Base hit: "+base_hit+".\n");
	write("Quality: "+quality+" Durability: "+durability+".\n");
	write("Arrow dam: "+arrow_dam+" Hit: "+arrow_hit+" Crit: "+arrow_crit+" Stun: "+arrow_stun+".\n");
	write("Shoot time: "+shoot_time+" Reload time: "+reload_time+".\n");
	write("Size: "+size+" Weight: "+weight+".\n");
}
}

query_long() {
	string tmp;
	tmp ="";
	tmp =short();
	tmp +="\nIt is a "+crafted+" crafted "+short_desc+".\n";
	tmp +="It is made by "+maker+".\n";
	if(reloaded)tmp +=arrow_desc;
return tmp;
}

drop() {
  return 0;
}

get() {
  return 1;
}

query_weight() { return weight; }

query_no_save() { return 1; }
query_can_label() { return 1; }
set_label(to) { label=to; }

//Set this bow reloaded
//Str is the arrow
//i is the quality of arrow
set_reload(string str, int hit, int dam, int crit, int stun, int arq) {
	arrow_desc = "It is loaded with "+str+".\n";
	arrow_hit = hit+arq;
	arrow_dam = dam+arq;
	arrow_crit = crit+arq;
	arrow_stun = stun+arq;
	reloaded = 1;
}
query_arrow_hit() { return arrow_hit; }
query_arrow_dam() { return arrow_dam; }
query_arrow_crit() { return arrow_crit; }
query_arrow_stun() { return arrow_stun; }


//Ends the shooting attempt
end_shoot() {
	reloaded = 0;
	arrow_desc = "";
	arrow_dam = 0;
	arrow_hit = 0;
	arrow_crit = 0;
	durability -= 1;
	if(durability < 0) {
	write(short()+" breaks due the high usage.\n");
	destruct(this_object());
}
}

is_shootable() { return 1; }

query_reload() { return reloaded; }
query_reload_time() { return reload_time; }
query_shoot_time() { return shoot_time; }
query_maker() { return maker; }
query_base_damage() { return base_damage; }
query_base_hit() { return base_hit; }
query_quality() { return quality; }
query_missile_type() { return missile_type; }
query_name() { return short(); }
query_size() { return size; }
query_bow_type() { return bow_type; }

//Settings
set_short(str) { short_desc=str; }
set_long(str) { long_desc=str; }
set_weight(i) { weight=i; }
set_base_damage(i) { base_damage=i; }
set_base_hit(i) { base_hit=i; }
set_size(i) { size=i; }
set_shoot_time(i) { shoot_time=i; }
set_reload_time(i) { reload_time=i; }
set_maker(str) { maker=str; }
set_missile_type(str) { missile_type=str; }
set_bow_type(str) { bow_type=str; }

set_quality(i) {
	quality = i;
	durability = i*5;
	switch(i) {
	case 0..10:
	crafted="awfully";
	break;
	case 11..20:
	crafted="badly";
	break;
	case 21..30:
	crafted="basically";
	break;
	case 31..40:
	crafted="adequately";
	break;
	case 41..50:
	crafted="moderately";
	break;
	case 51..60:
	crafted="finely";
	break;
	case 61..70:
	crafted="flawlessly";
	break;
	case 71..80:
	crafted="superbly";
	break;
	case 81..90:
	crafted="perfectly";
	break;
	case 91..100:
	crafted="divinely";
	break;
}
}

query_weapon() { return 1; }
query_type() { return "bludgeon"; }
query_weapon_type() { return "bow"; }
query_dur() { return 2; }
query_max_dur() { return 2; }