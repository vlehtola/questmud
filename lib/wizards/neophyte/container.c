#define STACK_D "/daemons/string_stack_d"
string _name, _short, _long, _label;
int _max_weight, local_weight, _size;
status open;
reset(arg) {
   if (arg) return;
   local_weight = 0;
   open = 0;
}

void create() {
}
init() {
	add_action("open_container", "open");
	add_action("close_container", "close");
}
open_container(str) {
	  if(!this_player()->check_condis()) { return 1; }
      if(str == _name || str == _label) {
		  if(!open) {
			  write("You open your "+_name+".\n");
			  say(this_player()->query_name()+" opens a "+_name+".\n");
			  open = 1;
			  return 1;
		  } else if(open) {
			  write(_name+" is already opened.\n");
			  return 1;
		  }
	  }
  }
close_container(str) {
	  if(!this_player()->check_condis()) { return 1; }
      if(str == _name || str == _label) {
		  if(open) {
			  write("You close your "+_name+".\n");
			  say(this_player()->query_name()+" closes a "+_name+".\n");
			  open = 0;
			  return 1;
		  } else if(!open) {
			  write(_name+" is already closed.\n");
			  return 1;
		  }
	  }
  }


void set_name(string str) {  _name=str; }
string query_name() { return _name; }
void set_short(string str) { _short=str; }
string short() { if(_label) { return _short+" named as '"+_label+"'"; } return _short; }
void set_long(string str) { _long=str; }
string query_long() { return _long; }
void set_size(int i) { _size=i; _max_weight = 1000*_size; }
int query_size() { return _size; }
int query_value() { return _size*100; }
int query_max_weight() { return _max_weight; }
int query_weight() { return local_weight/2; }
query_can_label() { return 1; }
void set_label(string str) { _label=str; }
id(str) { return str == _name || str == _label; }

add_weight(w) {
    if (w + local_weight > _max_weight)
	return 0;
	calc_real_weight();
	this_player()->fix_weight();
    return 1;
}

calc_weight() {
  object ob;
  ob = first_inventory(this_object());
  local_weight = 0;
  while(ob) {
      add_weight(call_other(ob, "query_weight"));
      ob = next_inventory(ob);
  }
  return 1;
}

calc_real_weight() {
	object ob;
	int i;
	ob = all_inventory(this_object());
	for(i=0;i<sizeof(ob);i++) {
	if(ob[i]->query_weight()) {
		local_weight = ob[i]->query_weight();
	}
}
return local_weight;
}

can_put_and_get(object ob) {
        return open;
}

get() { return 1; }

drop() { return 0; }

long() {
  object ob;
  int i;
  string lista, *list;
  calc_weight();
  write(_long+"\n");
  if(!open) { write("It is closed.\n"); return 1; }
  if(local_weight) write("It contains:\n");
  ob = all_inventory(this_object());
  list = allocate(sizeof(ob));
  for(i=0; i<sizeof(ob); i++) {
          list[i] = ob[i]->short();
  }
  lista = STACK_D->stack_item_list(list);
  if(lista) write(lista+".\n");
    write("It is a "+get_size(_size)+" sized container and "+get_weight((local_weight*100)/_max_weight)+"");
  return 1;
}
get_weight(int i) {
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