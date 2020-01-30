#define burning_messages ({ "Flame on the "+_name+" flickers little.", "Sound of crackling wood comes from the "+_name+".", "Thick smoke is rising from the "+_name+".", "Flames flickers in the wind.", })
int _value, _weight, _fuel, _max_fuel, _light_quality;
string _name;
string _short, _long, _label;
status _light;
status normal_light;

reset(arg) {
  if (arg)
    return;
}
void create() {
}
void set_light_quality(int i) { _light_quality=i; }
void set_value(int i) { _value=i; }
void set_weight(int i) { _weight=i; }
void set_max_fuel(int i) { _max_fuel=i; }
void set_name(string w) { _name=w; }
void set_short(string w) { _short=w; }
void set_long(string w) { _long=w; }
void set_fuel(int i) { _fuel=i; }
void set_normal_light(int i) { normal_light; }

set_label(string w) { _label=w; }
query_can_label() { return 1; }

query_weight() { return _weight; }
query_fuel() { return _fuel; }
query_max_fuel() { return _max_fuel; }
query_label() { return _label; }

id(str) { return str == _name || str == _label; }

query_value() { if(_light) { return 0; } return _value; }

get() { return 1; }
drop() { return 0; }

prevent_insert() { if(_light) { write("You should extinguish it first.\n"); return 0; } return 1; }

query_name() {  return _name; }
query_lighted() { return _light; }
query_light_source() { return 1; }

short() {
  if(_label && _light) { return _short+" named '"+_label+"' (lighted)"; } if(_light) { return _short+" (light)"; } if(_label) { return _short+" named '"+_label+"'"; }
  return _short;
}

long() {
	write(_long+"");
	write("You can nlight it and nextinguish it.\n");
	write("It is a light source.\n");
	if(_light)write("It is lighted.\n");
	if(find_call_out("out_of_fuel") < 0) {
	write(""+get_fuel_left((query_fuel()*100)/query_max_fuel())+".\n");
    return 1;
}
	write(""+get_fuel_left((find_call_out("out_of_fuel")*100)/query_max_fuel())+".\n");
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
query_long() { return _short+"\n"+_long+"You can nlight it and nextinguish it.\n"+"It is a light source.\n"; }

set_lighted() {
	set_light(_light_quality);
	_light = 1;
	call_out("out_of_fuel", _fuel);
	return 1;
}

set_extinguish() {
	int i;
    set_light(-_light_quality);
    _light = 0;
    i = remove_call_out("out_of_fuel");
    _fuel = i;
    return 1;
}

out_of_fuel() {
    _light = 0;
    _fuel = 0;
	set_light(-_light_quality);
	if(present(this_object(), this_player())) {
	tell_room(environment(this_player()), "The "+_name+" flickers and flame is gone.\n"); return 1; }
	else {
	tell_room(environment(this_object()), "The "+_name+" flickers and flame is gone.\n");  }
	return 1;
}