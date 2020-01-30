#define STACK_D "/daemons/string_stack_d"
string _name, _short, _long, _label;
int _max_weight, local_weight, _size;
reset(arg) {
   if (arg) return;
}

void create() {
}
automatic_weight() { return 1; }

void set_name(string str) {  _name=str; }
string query_name() { return _name; }
void set_short(string str) { _short=str; }
string short() { if(_label) { return _short+" named as '"+_label+"'"; } return _short; }
void set_long(string str) { _long=str; }
string query_long() { return _long+".\n"; }
void set_size(int i) { _size=i; _max_weight = 1000*_size; }
int query_size() { return _size; }
int query_value() { return _size*100; }
int query_max_weight() { return _max_weight; }
int query_weight() { return local_weight/5; }
query_can_label() { return 1; }
void set_label(string str) { _label=str; }

id(str) { return str == _name || str == _label; }

add_weight(w) {
    if (w + local_weight > _max_weight)
	return 0;
	calc_weight();
	return 1;
}

calc_weight() {
 int i;
 object *obs;
 local_weight = 0;
 obs = all_inventory(this_object());
 for(i=0;i<sizeof(obs);i++) {
 if(local_weight < _max_weight) {
	 local_weight += obs[i]->query_weight();
} else if(local_weight > _max_weight) {
  move_object(obs[i], this_player());
}
 }
}


can_put_and_get(object ob) { return 1; }

get() { return 1; }

drop() { return 0; }

long() {
  object ob;
  int i;
  string lista, *list;
  write(_long+"\n");
  if(local_weight) write("It contains:\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
  list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
  write("It is a "+get_size(_size)+" sized container and "+get_weight((local_weight*100)/_max_weight)+"");
  if(this_player()->query_wiz()) { write("Total weight is "+query_weight()+" from "+local_weight+".\n"); }
  return 1;
}

get_weight(int i) {
	if(i>100)i=100;
	switch (i) {
	case 0 : return "it is empty.\n";
	case 1..20 : return "it is almost empty.\n";
	case 21..40 : return "it is below half full.\n";
	case 41..60 : return "it is about half full.\n";
	case 61..80 : return "it is above half full.\n";
	case 81..99 : return "it is almost full.\n";
	case 100 : return "it is full.\n";
	}
	return "it is somehow broken.\n";
}

get_size(int i) {
	switch(i) {
		case 1:return "tiny";
		case 2:return "very small";
		case 3:return "small";
		case 4:return "below medium";
		case 5:return "medium";
		case 7:return "above medium";
		case 8:return "large";
		case 9:return "very large";
		case 10:return "huge";
}
return "No size";
}