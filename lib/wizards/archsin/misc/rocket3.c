string id;
int a;

short() {  
  string str;
  str = "A small rocket";
  return str;
}
  
long() {
  string str;
  str = "Try 'shoot' it.\n";
  return str;
}

set_id(arg) {
  if(!id) {
    id = arg;
  }
}

id(str) { return str == "rocket"; }

int boom() {
  string str;
  int tmp;
  tmp = random(4);
  switch(tmp) {
  case 0: str = "red"; break;
  case 1: str = "blue"; break;
  case 2: str = "green"; break;
  case 3: str = "white";
  }
  shout("Huge explosion of "+str+" light lights the sky as rocket blows high overhead.\n");
  write("Huge explosion of "+str+" light lights the sky as rocket blows high overhead.\n");
  destruct(this_object());
  return 1;
}

shoot() {
  if(!a) {
    write("You set this baby to ground, light it and watch it fly..\n");
    say(this_player()->query_name()+" sets up a small rocket..\n");
    shout("A small light swirls upwards, leaving glowing trail..\n");
    write("A small light swirls upwards, leaving glowing trail..\n");
    call_out("boom", 2);
    a = 1;
  }
  return 1;
}

init() {
  add_action("shoot", "shoot");
}
