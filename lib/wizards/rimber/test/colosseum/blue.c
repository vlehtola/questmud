inherit "room/room";
string DIR = "/wizards/rimber/test/colosseum/";
int attack, defence;
int a, d, r = 0;
int attack1, attack2, attack3;
int defence1, defence2, defence3;
string blue_player;

reset(arg) {
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Control room";
 long_desc = "In this room players control their pets.\n See 'do_attack' and 'do_defence'.\n";
 add_exit("southwest", "/wizards/rimber/test/colosseum/room1.c");
}

init() {
 ::init();
 add_action("enter", "enter");
 add_action("do_attack", "do_attack");
 add_action("do_defence", "do_defence");
 add_action("start", "start");
}

enter(string str) {
 if(str != "arena") { write("Enter what?\n");
 return 1;
 }
 move_object(this_player(), DIR+"room1.c");
 write("You enter the arena.\n");
 say(this_player()->query_name()+" enters the arena.\n");
 return 1;
}

 // Attacks:  Bodyrush   = 1
 //           Tailsweep  = 2
 //           Firebreath = 3
 // Defences: Block = 1
 //           Jump  = 2
 //           Swift = 3

do_attack(string str) {
 if(a == 3) {
  write("You have already put three attacks.\n");
  return 1;
 }
 switch(str) {
 case "bodyrush" : attack = 1;
  a++;
  break;
 case "tailsweep" : attack = 2;
  a++;
  break;
 case "firebreath" : attack = 3;
  a++;
  break;
 default : write("Attacks:\n Firebeath, Bodyrush, Tailsweep\nUse what?\n");
  return 1;
  break;
 }
 if(a == 1) { attack1 = attack; }
 if(a == 2) { attack2 = attack; }
 if(a == 3) { attack3 = attack; }
 write("You command your pet to use "+str+" attack.\n");
 return 1;
}

do_defence(string str) {
 if(d == 3) {
  write("You have already put three defences.\n");
  return 1;
 }
 switch(str) {
 case "block" : defence = 1;
  d++;
  break;
 case "jump" : defence = 2;
  d++;
  break;
 case "swift" : defence = 3;
  d++;
  break;
 default : write("Defences:\n Block, Jump, Swift\nUse what?\n");
  return 1;
  break;
 }
 if(d == 1) { defence1 = defence; }
 if(d == 2) { defence2 = defence; }
 if(d == 3) { defence3 = defence; }
 write("You command your pet to use "+str+" defence.\n");
 return 1;
}

start() {
 int i;
 // Checkataan et kaikki on rdy
 if(a < 3) {
  write("You have to put three attacks.\n");
  i = 3-a;
  write("You still need "+i+" attacks.\n");
 return 1;
 }
 if(d < 3) {
  write("You have to put three defences.\n");
  i = 3-d;
  write("You still need "+i+" defences.\n");
 return 1;
 }
 // Loppu osa
 r = 1;
 blue_player = this_player()->query_name();
 write("You are ready.\n");
 "/wizards/rimber/test/colosseum/arena.c"->start();
 return 1;
}

string blue_player() { return blue_player; }

int blue() {
 return r;
}

int attack1() { return attack1; }
int attack2() { return attack2; }
int attack3() { return attack3; }

int defence1() { return defence1; }
int defence2() { return defence2; }
int defence3() { return defence3; }

string resetoi() {
 a = 0, d = 0, r = 0;
 return "Game data cleared.";
}
