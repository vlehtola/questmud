#define burning_messages ({ "Flame on the "+name+" flickers little.", "Sound of crackling wood comes from the "+name+".", "Thick smoke is rising from the "+name+".", "Flames of "+name+" flicker in the wind.", })
int value, weight, fuel, max_fuel, light_quality;
string name;
string short_desc, long_desc, label;
status light;

reset(arg) {
  if (arg)
    return;
    this_object()->create();
}
void set_light_quality(int i) { light_quality=i; }
void set_value(int i) { value=i; }
void set_weight(int i) { weight=i; }
void set_name(string w) { name=w; }
void set_short(string w) { short_desc=w; }
void set_long(string w) { long_desc=w; }
void set_fuel(int i) { max_fuel=i; fuel=i; }

set_label(string w) { label=w; }
query_can_label() { return 1; }

query_weight() { return weight; }
query_fuel() { return fuel; }
query_max_fuel() { return max_fuel; }
query_label() { return label; }

id(str) { return str == name || str == label; }

query_value() { if(light) { return 0; } else if(!fuel) { return 0; } return value; }

get() { return 1; }
drop() { return 0; }

prevent_insert() { if(light) { write("You should extinguish it first.\n"); return 0; } return 1; }

query_name() {  return name; }
query_lighted() { return light; }
query_light_source() { return 1; }

short() {
  string tmp;
  tmp = "";
  if(label) tmp += " named '"+label+"'";
  if(light) tmp += " (lighted)";
  if(environment(this_object()) && environment(this_object())->query_keep(this_object())) tmp += " [keep]";
  return short_desc+tmp;
}

long() {
	write(long_desc+".\n");
	write("You can nlight it and nextinguish it.\n");
	write("It is a light source.\n");
	if(light)write("It is lighted.\n");
	write(""+get_fuel_left((query_fuel()*100)/query_max_fuel())+".\n");
	return 1;
}

get_fuel_left(int i) {
	switch(i) {
		case 0:return "It is out of fuel";
		case 1..9:return "It is almost empty";
		case 10..19:return "It has a very little fuel left";
		case 20..29:return "It has a little fuel left";
		case 30..39:return "It has a bit fuel left";
		case 40..49:return "It has a below half fuel left";
		case 50..59:return "It has a half fuel left";
		case 60..69:return "It has above half fuel left";
		case 70..79:return "It has much fuel left";
		case 80..89:return "It has very much fuel left";
		case 90..99:return "It is almost full";
}
return "It is fully fueled";
}
query_long() { return short_desc+"\n"+long_desc+"You can nlight it and nextinguish it.\n"+"It is a light source.\n"; }

set_lighted() {
	set_light(light_quality);
	light = 1;
	call_out("burning", 15);
	call_out("out_of_fuel", fuel);
	return 1;
}

set_extinguish() {
	int i, x;
    set_light(-light_quality);
    light = 0;
    i = remove_call_out("out_of_fuel");
    x = remove_call_out("burning");
    fuel = i;
    return 1;
}

out_of_fuel() {
	int i;
	i = remove_call_out("burning");
    light = 0;
    fuel = 0;
	set_light(-light_quality);
	set_short("A burned out "+name+"");
	set_long("Once this was a "+name+" but now it is just a useless piece of wood");
	if(present(this_object(), this_player())) {
	tell_room(environment(this_player()), "The "+name+" flickers and flame is gone.\n"); return 1; }
	else {
	tell_room(environment(this_object()), "The "+name+" flickers and flame is gone.\n");  }
	return 1;
}

burning() {
	int i;
	i = remove_call_out("out_of_fuel");
	if(i < 1) { out_of_fuel(); return 1; }
	fuel = i;
	call_out("out_of_fuel", i);
	call_out("burning", 15);
	if(!random(10))generate_messages();
	return 1;
}

generate_messages() {
	if(present(this_object(), this_player())) {
	tell_room(environment(this_player()), burning_messages[random(4)]+"\n");
	return 1;
} else { tell_room(environment(this_object()),burning_messages[random(4)]+"\n"); return 1; }
}