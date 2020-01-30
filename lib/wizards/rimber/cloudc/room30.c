inherit "room/room";
object ed;

reset(arg) {
 if(!ed) {
 ed = clone_object("/wizards/rimber/cloudc/mobs/edgar.c");
 move_object(ed, this_object());
 }
 if(arg) return;
 set_light(3);
 short_desc = "In a red room";
 long_desc = "A red circular room.\n";
 add_exit("west", "/wizards/rimber/cloudc/room41.c");
}
