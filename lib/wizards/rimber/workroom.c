inherit "room/room";
string DIR = "/wizards/rimber/";
object dum;

reset(status arg) {
 if(!dum) {
 dum = clone_object("/wizards/rimber/dum.c");
 move_object(dum, this_object());
 }
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("cave", "/wizards/rimber/cave/room1.c");
  add_exit("castle", "/wizards/rimber/cloudc/land.c");
  add_exit("temple", "/wizards/rimber/temple/room1.c");
  add_exit("tests", DIR+"test/room1.c");
        short_desc = "Workroom in hell";
        long_desc = "This is a workroom.\n";
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
 items = allocate(2);
 items[0] = "machine";
 items[1] = "There is a sign: 'Pull the lever and beat the dummy up'";
}

init() {
 ::init();
 add_action("pull", "pull");
}
pull(str) {
 object dummie;
 if(str == "lever") {
  write("As you pull the lever a dummy pops out of the machine.\n");
 dummie = clone_object("/wizards/rimber/dum.c");
 move_object(dummie, this_object());
 }
 else { write("Pull what?\n"); }
 return 1;
}
