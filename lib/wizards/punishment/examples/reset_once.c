inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
  if (!monster) {
      monster = clone_object("/wizards/irmeli/jorma.c"); 
      move_object(monster, this_object());
}

/* WITH THIS WAY THE MONSTER IN THIS ROOM WILL RESET ONLY ONCE IN REBOOT! */

/* PUT THIS PART IN THE BEGINNING OF THE ROOM FILE, MAKE EXITS
AND DESCS BELOW. */

/* EVERY EQ MONSTER MUST RESET ONLY ONCE IN REBOOT */







