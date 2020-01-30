#define TIME_TO_ZAP 4
#define TIME_TO_RELOAD 14
string name, _label, _long;
int charges;
status can_zap;
reset(arg) {
  if(arg) return;
  name = "wand";
  can_zap = 1;
  charges = 5;
  _long = "A wand of identify\n"+
          "The wand made from strong looking wooden stick and on the wand\n"+
          "is layd an ancient magic to identify things.\n";
}

string query_name() { return name; }

string short() { if(_label) { return "A wand of identify named '"+_label+"'"; } return "A wand of identify"; }
query_can_label() { return 1; }
set_label(string w) { _label=w; }

id(str) { return str == name || str == _label; }

get() { return 1; }

drop() { return 0; }

query_long() { return _long; }
query_charges() { return charges; }

query_weight() { return 200; }

long() {
	_long = "";
    _long += short();
    _long += "\nThe wand made from strong looking wooden stick and on the wand\n";
    _long += "is layd an ancient magic to identify things.\n";
	_long += "\nIt has a "+get_charges_left(charges)+" charges left.\n";
	write(_long);
return 1;
}

get_charges_left(int i) {
	switch(i) {
		case 0 : return "zero";
		case 1 : return "one";
		case 2 : return "two";
		case 3 : return "three";
		case 4 : return "four";
		case 5 : return "five";
	}
	return charges;
}

init() {
	add_action("zap_wand","wzap");
}

zap_wand(str) {
	string wand,tgt;
	object target, rwand;
	if(!this_player()->check_condis()) return;
	if(!present(this_object(),this_player())) { write("You have to pick it up first before zapping.\n"); return 1; }
	if(!str) { write("Zap wand at what?\n"); return 1; }
	if(sscanf(str, "%s at %s", wand, tgt) != 2) {
		write("Zap wand at what?\n");
		return 1;
	}
	rwand = present(wand, this_player());
	if(!rwand) { write("You don't have such thing as "+capitalize(wand)+".\n"); return 1; }
	target = present(tgt,this_player());
	if(!target) { write("You don't have such thing as "+capitalize(tgt)+".\n"); return 1; }
	if(!charges) { write("The wand is without any charge and cannot be zapped anymore.\n"); return 1; }
	if(!can_zap) { write("You can't zap the wand just yeat.\n"); return 1; }
	write("You start repairing to zap the wand at "+capitalize(tgt)+".\n");
	charges -= 1;
	can_zap = 0;
	call_out("real_zap", TIME_TO_ZAP, tgt);
	call_out("reload", TIME_TO_RELOAD);
	return 1;
}

real_zap(str) {
object ob;
ob = present(str, this_player());
if(!ob) { write("You don't have such thing as "+capitalize(str)+".\n"); return 1; }
write("You zap the wand at "+str+".\n");
if(ob->query_armour()) {
	identify_armour(ob);
	return 1;
}
if(ob->query_weapon()) {
	identify_weapon(ob);
	return 1;
}
write("You can't make anysense from "+capitalize(str)+".\n");
return 1;
}

reload() {
	can_zap = 1;
}

identify_weapon(object ob) {
	write("It is a "+ob->query_type()+" type of weapon.\n");
	write("It has a weapon class about "+get_weapon_wc(ob->query_wc())+".\n");
	write("It increases hit chance about "+get_weapon_id(ob->query_hit_bonus())+".\n");
	write("It is about "+(ob->query_dur()*100)/ob->query_max_dur()+"% from its orinal shape.\n");
	write("Is cost about "+ob->query_value()+" bronze.\n");
	write("It weights about "+ob->query_weight()+"g.\n");
return 1;
}

get_weapon_wc(int i) {
	switch(i) {
		case 0..20: return "tiny";
		case 21..40: return "very little";
		case 41..60: return "little";
		case 61..80: return "below average";
		case 81..100: return "average";
		case 101..120: return "above average";
		case 121..140: return "much";
		case 141..160: return "very much";
		case 161..180: return "greatly";
		case 181..200: return "insane";
	}
	return "hmm?";
}

get_weapon_id(int i) {
	switch(i) {
	case 0..10: return "very little";
	case 11..30: return "little";
	case 31..40: return "below average";
	case 41..60: return "average";
	case 61..80: return "above average";
	case 81..90: return "much";
	case 91..100: return "very much";
}
return "hmm hmm";
}
