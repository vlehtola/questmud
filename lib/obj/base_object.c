string name, short_desc, long_desc, extra_long, label, prevent_insert_message, material, size, alias;
int weight, prevent_insert, value, no_drop, no_get, no_save, no_label;

reset(arg) {
   if (arg) return;
}

id(str) { return str == name || str == label || str == alias; }

get() { return no_get; }

query_weight() { return weight; }

query_size() { return size; }

query_can_label() { return no_label; }
query_label() { return label; }
query_short() { return short_desc; }

query_value() { return value; }

query_no_save() { return no_save; }

drop() { return no_drop; }

prevent_insert() {
if(prevent_insert && prevent_insert_message) {
write(prevent_insert_message+".\n");
return 1;
} else if(prevent_insert && !prevent_insert_message) {
write("You can't put this item there.\n");
return 1;
}
return 0;
}

short() {
 string str;
 str = "";
 str += short_desc;
 if(label) { str +=" named as '"+label+"'"; }
 return str;
}

long() {
  string str;
  str = "";
  str += long_desc+".\n";
  if(extra_long) { str += extra_long+".\n"; }
  if(material) { str += "It is made from "+material+".\n"; }
  if(size) { str += "It is "+get_size(size)+" sized "+name+".\n"; }
  write(str);
  return 1;
}
query_long() { return long_desc+".\n"; }

//Sets the name of this object
set_name(str) { name=str; }
//Sets the short of this object
set_short(str) { short_desc=str; }
//Sets the long desc of this object
set_long(str) { long_desc=str; }

set_extra_long(str) { extra_long=str; }

//Sets the label of this object
set_label(str) { label=str; }
//Use this if you don't wan't that object to be inserted anywhere
set_prevent_insert() { prevent_insert=1; }
//sets the message what is printed to player if he/she tries to insert this somewhere
set_prevent_insert_message(str) { prevent_insert_message=str; }
//Sets the weight of this object
set_weight(i) { weight=i; }
//Sets the value of this object
set_value(i) { value=i; }
//Sets if this object can be dropped, 1 cant be dropped, 0 can be dropped
set_no_drop(i) { no_drop=i; }
//Sets that this object can be taken, 1 can be taken, 0 can't.
set_no_get(i) { no_get=i; }
//Prevent this object to be saved somewhere
set_no_save(i) { no_save=i; }
//If you don't want to this object to be labeled use: set_can_label(i);
set_can_label(i) { no_label=i; }

set_size(i) { size=i; }

set_alias(str) { alias=str; }

//Something useless tms
set_material(string str) {
	material=str;
}



stat_me() {
write("Short desc: '"+short_desc+"'\n");
write("Long desc: '"+long_desc+".'\n");
write("Name: '"+name+"'.\n");
write("Label: '"+label+"'.\n");
write("Prevent insert: '"+prevent_insert+"' Message: '"+prevent_insert_message+"'.\n");
write("Weight: '"+weight+"' Value: '"+value+"'.\n");
write("Drop: '"+no_drop+"' Get '"+no_get+"' Save '"+no_save+"'.\n");
return 1;
}

get_size(int i) {
        switch(i) {
                case 0..10:return "tiny";
                case 11..20:return "very small";
                case 21..30:return "small";
                case 31..40:return "below medium";
                case 41..50:return "medium";
                case 51..60:return "above medium";
                case 61..70:return "large";
                case 71..80:return "very large";
                case 81..90:return "huge";
                case 91..100:return "gigantic";
			}
			return "Invalid size set";
}