int counter,is_light;
string name;
int bonus;

void reset(status arg) {
  if (arg) { return; }
  counter = 50;
  name = "campfire";
}

void set_name(string n) { name = n; }

string short() {
    return "A campfire";
}

void long() {
    write("A nice campfire warms the nearby place. It makes you feel more relaxed.\n");
}

status get() { return 0; }

void set_bonus(int n) { bonus = n; }

status warm() {
  object ob;
  int power;
  if (counter < 1) {
    tell_room(environment(this_object()), "The fire burns out.\n");
    destruct(this_object());
    return 1;
  }
  if(!is_light) {
    is_light = 1;
    set_light(3);
  }
  counter -= 1;
  ob = first_inventory(environment(this_object())); 
  while(ob) {
    power = 10 + bonus/3;
    if (living(ob)) {
      if(ob->query_attacker()) {
	power = power / 4;
        tell_object(ob, "You feel the warmth of the campfire even while in combat.\n");
      } else {
        tell_object(ob, "Campfire burns warmly.\n");
      }
      if(ob->query_max_hp() > ob->query_hp()) {
          ob->set_hp(ob->query_hp() + random(power) + power);
      }
      if(ob->query_max_sp() > ob->query_sp()) {
          ob->set_sp(ob->query_sp() + random(power) + power);
      }
      if(ob->query_max_ep() > ob->query_ep()) {
          ob->set_ep(ob->query_ep() + random(power) + power);
      }
    }
    ob = next_inventory(ob);
  }
  call_out("warm", 10);
  return 1;
}

status id(string str) { return str == name; }

status stomp(string str) {
  if(str != name) return 0;
  write("You stomp the campfire.\n");
  say(this_player()->query_name()+" stomps the campfire.\n");
  counter = 0;
  warm();
  return 1;
}

void init() {
  add_action("stomp","stomp");
}
