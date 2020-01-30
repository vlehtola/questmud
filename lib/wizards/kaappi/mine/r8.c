inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
  if(!monster) {
    monster = clone_object("/wizards/kaappi/mine/mosat/pelokas.c");
    move_object(monster, this_object()); }
{

   add_exit("southwest", "r6.c");
   add_exit("northeast", "golem1.c");
  short_desc = "A tunnel";
   long_desc = "Your eyes hurt for a while as you step in to this room. There is much\n"+
               "more light than in the previous tunnels. Suddenly you start to shiver\n"+
              "and you feel cold. There is something strange in this place.\n";
set_light(3);
}
}
