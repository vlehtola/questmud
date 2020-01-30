inherit "room/room";
object mob,mob2;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob, this_object()); }

  if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/jannut.c");
  move_object(mob2, this_object()); }
{
  if(arg) return;

  add_exit("south", "katu9.c");
  add_exit("north", "katu23.c");
  add_exit("west", "house8.c");
  
  short_desc = "The Bila street";
  long_desc = ""
" | p |   |#      You are standing in Bila street. There are a small doorway\n"+
"-o---+-6-+#      leading to west. The wall on the east side of you rises\n"+ 
" |   | H |#     straight up until it reaches the height of 150 feet when\n"+   
"H4H  5H H*#     it turns gently sloping to the west. Some citizens are walking\n"+  
" |   | H |#     on the street. A stone lantern is hanging on the wall giving\n"+   
"-+---+---+#     light.\n";

  set_light(2);

  }
}
