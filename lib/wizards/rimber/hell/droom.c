inherit "room/room";
object mosa;

reset(arg) {
 if(!mosa) {
 mosa = clone_object("/wizards/rimber/hell/mobs/diablo.c");
 move_object(mosa, this_object());
 }
 if(arg) return;
 set_light(3);
 set_not_out(1);
 short_desc = "Diablo's chamber";
 long_desc = "Long desc\n";
}
