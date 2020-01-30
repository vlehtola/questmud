inherit "room/room";
object mob;

reset(arg) {
  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }

{
  if(arg) return;

  add_exit("west", "katu8.c");
  add_exit("north", "katu14.c");
  
  short_desc = "The crossing";
  long_desc = ""
"-o---+---+#     You are standing at the southeast corner of the city,\n"+ 
" |   | H |#     crossing of Thrmo and Bila street. There are houses\n"+   
"H4H  5H H|#     in north and west. Some small dwarves are walking on \n"+  
" |   | H |#     the street. A lantern post is standing at the crossing.\n"+   
"-+---+---*#     The wall is gently sloping to the west in the height of\n"+  
"#E#########     150 feet.\n";

  set_light(2);
}
}
