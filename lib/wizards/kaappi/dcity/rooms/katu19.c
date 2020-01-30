inherit "room/room";
object mob,mob2,fountain;

reset(arg) {
  if(!fountain) {
  fountain = clone_object("/wizards/kaappi/dcity/items/fountain.c");
  move_object(fountain, this_object()); }

  if(!mob2) {
  mob2 = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob2, this_object()); }

  if(!mob) {
  mob = clone_object("/wizards/kaappi/dcity/mobs/cityguard.c");
  move_object(mob, this_object()); }
{
  if(arg) return;

  add_exit("north", "katu26.c");
  add_exit("west", "katu18.c");
  add_exit("east", "katu20.c");
  add_exit("south", "katu12.c");
  
  short_desc = "The central square";
  long_desc = ""
" | #   # |      You are standing in the middle of the central square. You see\n"+
"G| ##-## |G     beautiful fountain decorated with fine golden runes and various\n"+
" | p | p |      gems. In the north there are gates made of pure mithril\n"+
"-+---*---+-     decorated with pictures of ancient heroes. You see lots of\n"+
" |   |   |      dwarves gathering near town hall. They are spending most of\n"+
"H3  H4H  5H     their free time here. A fountain is circled with numerous marble\n"+
"                lanterns which are lightening the whole central square.\n";

  set_light(2);
}
}
