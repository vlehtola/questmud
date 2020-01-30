inherit "/obj/base_object";
#define TP this_player()
#define TPN this_player()->query_name()
int drinks_left, max_drinks, drink_value, can_fill;
string drink_message, last_drink_message, liquid_type;

//How many times player can drink from this object
set_max_drinks(i) {
	max_drinks=i;
	drinks_left=i;
}

//drink_cmd calls this
set_drinks_left(i) {
	drinks_left=i;
}
//How much this object gives 'drink' value
set_drink_value(i) {
	drink_value=i;
}

//Can this object be filled from another object, like fountain in cs
set_can_fill(i) {
	can_fill=i;
}
//Sets the drinking message what gets printed when player drinks this
set_drink_message(str) {
	drink_message=str;
}
//Sets the last drinkning message what gets printed when player takes last quaff
set_last_drink_message(str) {
	last_drink_message=str;
}
set_liquid_type(str) {
liquid_type=str;
}

query_potion() { return 1; }
query_max_drinks() { return max_drinks; }
query_drinks_left() { return drinks_left; }
query_drink_value() { return drink_value; }
query_can_fill() { return can_fill; }
query_drink_message() { return drink_message; }
query_last_drink_message() { return last_drink_message; }
query_liquid_type() { return liquid_type; }
can_be_drinked() { return 1; }


short() {
 string str;
 str = "";
 str += short_desc;
 if(!drinks_left) str = "A empty "+name+"";
 if(label) { str +=" named as '"+label+"'"; }
 return str;
}

long() {
  string str;
  str = "";
  str += long_desc+".\n";
  str += get_drinks_left();
  write(str);
  return 1;
}

get_drinks_left() {
int d;
mixed txt;
string n;
txt = "";
if (liquid_type) n = liquid_type;
else n = query_name();
if (drinks_left > 0) {
if (drinks_left >= max_drinks) txt += "It is full of " + n;
else {
d = ((100 * drinks_left) / max_drinks);
if (d > 80) txt += "It is almost full of " + n;
else if (d > 60) txt += "It is more than a half filled with " + n;
else if (d > 40) txt += "It is about half full of " + n;
else if (d > 20) txt += "It is less than a half filled with " + n;
else txt += "There's only a small amount of " + n + " left";
}
txt += ".\n";
}
else txt += "It's empty.\n";
return txt;
}
