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

  add_exit("west", "katu6.c");
  add_exit("east", "katu8.c");
  add_exit("north", "katu13.c");

  short_desc = "The crossing";
  long_desc = ""
"-o---+---+#     You are standing at the crossing of Thrmo and Gimbar\n"+ 
" |   | H |#     street. Gimbar street continues far to the north and Thrmo\n"+   
"H4H  5H H|#     street continues to west and east. A lantern post is\n"+   
" |   | H |#     giving light here.\n"+   
"-+---*---+#\n"+  
"#E#########\n";

  set_light(2);
}
}
