inherit "room/room";
string DIR = "/wizards/rimber/test/colosseum/";
int red, blue;
string str;
int i = random(2), r = 0;
string tmp, tmp2;
object red_player, blue_player;
int red_one = 0, blue_one = 0;

reset(arg) {
 set_light(3);
 set_not_out(1);
 short_desc = "Pet arena";
 long_desc = "A large circular arena. The ground is sand and the walls"+
  " are made\nof some unknown black material.\n";

 add_exit("out", DIR+"room1.c");
}

string start() {
 red = "/wizards/rimber/test/colosseum/red.c"->red();
 blue = "/wizards/rimber/test/colosseum/blue.c"->blue();
 if(red == 1 && blue == 0) { str = "Blue one is not ready."; }
 if(red == 0 && blue == 1) { str = "Red one is not ready."; }
 if(red == 1 && blue == 1) { str = "The battle starts."; }
 call_out("battle", 0);
 return str;
}

status battle() {
 if(red == 0 || blue == 0) { return 1; }
 tmp = "/wizards/rimber/test/colosseum/red.c"->red_player();
 tmp2 = "/wizards/rimber/test/colosseum/blue.c"->blue_player();
 red_player = find_player(lower_case(tmp));
 blue_player = find_player(lower_case(tmp2));
 red_one = "/wizards/rimber/test/colosseum/messaget.c"->red_one();
 blue_one = "/wizards/rimber/test/colosseum/messaget.c"->blue_one();
 if(red_one >= 500 && blue_one < 500) {
 r = 7;
 tell_object(blue_player, "You have WON the battle.\n");
 tell_object(red_player, "You LOST the battle.\n");
 }
 if(red_one < 500 && blue_one >= 500) {
 r = 7;
 tell_object(blue_player, "You LOST the battle.\n");
 tell_object(red_player, "You have WON the battle.\n");
 }
 if(r < 6) {
 if(i == 0) {
  call_out("red_attack", 1);
  call_out("blue_defence", 3);
  i = 1;
  tell_object(red_player, "*** NEW ROUND ***\n");
  tell_object(blue_player, "*** NEW ROUND ***\n");
  r++;
 }
 else {
 call_out("blue_attack", 1);
  call_out("red_defence", 3);
 i = 0;
  tell_object(red_player, "*** NEW ROUND ***\n");
  tell_object(blue_player, "*** NEW ROUND ***\n");
  r++;
 }
 }
 else {
  tell_object(red_player, "Game over.\n");
  tell_object(blue_player, "Game over.\n");
 if(red_one < blue_one) {
 tell_object(red_player, "You LOST the battle.\n");
 tell_object(blue_player, "You WON the battle.\n");
 }
 else {
 tell_object(red_player, "You WON the battle.\n");
 tell_object(blue_player, "You LOST the battle.\n");
 }
 red_one = 0, blue_one = 0;
 "/wizards/rimber/test/colosseum/red.c"->resetoi();
 "/wizards/rimber/test/colosseum/blue.c"->resetoi();
 "/wizards/rimber/test/colosseum/messaget.c"->reset();
 r = 0;
 reset();
 }
 return 1;
}

string red_attack(string str) {
 str = "/wizards/rimber/test/colosseum/messaget.c"->red_attack();
 return str;
}

string red_defence(string str) {
 str = "/wizards/rimber/test/colosseum/messaget.c"->red_defence();
 return str;
}

string blue_attack(string str) {
 str = "/wizards/rimber/test/colosseum/messaget.c"->blue_attack();
 return str;
}

string blue_defence(string str) {
 str = "/wizards/rimber/test/colosseum/messaget.c"->blue_defence();
 return str;
}
