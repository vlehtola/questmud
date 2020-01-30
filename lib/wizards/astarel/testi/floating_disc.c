int time;
string owner, height;

short() {
  return owner+"'s floating disc (flying "+height+")";
}

/* voi lisaa kamaa */
add_weight(int i) {
  return 1;
}

can_put_and_get() {
  return 1;
}

long() {
int i;
object ob;
  write(
"A magically created disc is suitable for carrying items. It floats above the ground.\n"+
"It seems to follow it's creator where ever he goes.\n");
  write("The disc contains:\n");
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    if(ob[i]->short()) write(ob[i]->short()+"\n");
    i += 1;
  }
}

move_after_owner() {
  object ob;
  ob = find_player(lower_case(owner));
  if(!ob) return 0;
  if(environment(ob) != environment(this_object())) {
    tell_room(environment(this_object()), short()+" floats after it's creator.\n");
    move_object(this_object(), environment(ob));
    tell_room(environment(this_object()), short()+" floats in.\n");
  }
}

fall() {
  string tmp;
  time -= 1;
  if(time < 0) {
    tell_room(environment(this_object()), short()+" disappears and everything on it drops on the ground!\n");
    filter_array(all_inventory(this_object()), #'move_object, environment(this_object()));
    destruct(this_object());
    return 1;
  }
  move_after_owner();
  tmp = height;
  change_height();
  if(tmp != height) tell_room(environment(this_object()), short()+" seems to lose some of it's magical powers.\n");
  call_out("fall", 10);
}

id(str) { return str == "disc" || str == "floating disc"; }

set_power(int bonus, object ob, refresh) {
  owner = ob->query_name();
  time = bonus*6/10+2*6;
  if(time > 15*6) time = 15*6;
  time += ob->query_skills("mastery of commerce")*6/10;
  change_height();
  if (!refresh) { call_out("fall", 10); }
}

change_height() {
  if(time == 0) height = "very low";
  if(time > 0) height = "low";
  if(time > 40) height = "high";
  if(time > 70) height = "very high";
}

reset(arg) {
  if(arg) return;
  time = 1;
}

void init() {
  add_action("unload","unload");
}

status unload(string str) {
  object *ob;
  int i;
  if(this_player()->query_real_name() != lower_case(owner)) return 0;
 if(str != "disc") return 0;
  i = 0;
  ob = all_inventory(this_object());
  while(i<sizeof(ob)) {
    move_object(ob[i],environment(this_object()));
    i += 1;
  }
  write("You unload the floating disc.\n");
  return 1;
}

string query_disc_owner() { return owner; }